#include "BattleMenu.h"
#include "BattleScene.h"
#include "Event.h"
#include "PotConv.h"
#include "Random.h"
#include "Save.h"
#include "convert.h"


BattleActionMenu::BattleActionMenu(BattleScene* b)
{
    setStrings({ "移動", "武學", "毒术", "专注", "醫療", "暗器", "藥品", "等待", "狀態", "自動", "休息" });
    distance_layer_.resize(BATTLEMAP_COORD_COUNT);
    battle_scene_ = b;
}

BattleActionMenu::~BattleActionMenu()
{
}

void BattleActionMenu::setRole(Role* r)
{
    role_ = r;
    setVisible(true);
    for (auto c : childs_)
    {
        c->setVisible(true);
        c->setState(Normal);
    }

    //显示人物状态

    //battle_scene_->calMoveStep(role_);
    //移动过则不可移动
    if (role_->Moved || role_->PhysicalPower < 10)
    {
        childs_text_["移動"]->setVisible(false);
    }
    if (role_->getLearnedMagicCount() <= 0 || role_->PhysicalPower < 20)
    {
        childs_text_["武學"]->setVisible(false);
    }
    if (role_->AttackWithPoison <= 0 || role_->PhysicalPower < 30)
    {
        childs_text_["毒术"]->setVisible(false);
    }
    if (role_->AntiPoison <= 0 || role_->PhysicalPower < 30)
    {
        childs_text_["专注"]->setVisible(false);
    }
    if (role_->Medicine <= 0 || role_->PhysicalPower < 10)
    {
        childs_text_["醫療"]->setVisible(false);
    }
    if (role_->HiddenWeapon <= 15 || role_->PhysicalPower < 10)
    {
        childs_text_["暗器"]->setVisible(false);
    }

    if (role_->Competing)
    {
        childs_text_["藥品"]->setVisible(false);
        childs_text_["暗器"]->setVisible(false);
    }

    childs_text_["等待"]->setVisible(false);    //禁用等待

    setFontSize(20);
    arrange(0, 0, 0, 28);
    if (start_ == 0 || !getChild(active_child_)->getVisible())
    {
        active_child_ = findFristVisibleChild();
        forceActiveChild();
    }
    if (!role_->Moved)
    {
        role_->AI_Action = -1;
    }    //设置为未计算过ai的行动
}

void BattleActionMenu::dealEvent(BP_Event& e)
{
    if (battle_scene_ == nullptr)
    {
        return;
    }
    //如果是ai，计算行动，不再进入其他循环
    if (role_->isAuto())
    {
        int act = autoSelect(role_);
        setResult(act);
        setAllChildState(Normal);
        childs_[act]->setState(Press);
        setExit(true);
        setVisible(false);    //AI不画菜单了，太乱
        return;
    }
    Menu::dealEvent(e);
}

//"0移動", "1武學", "2用毒", "3解毒", "4醫療", "5暗器", "6藥品", "7等待", "8狀態", "9自動", "10休息"
int BattleActionMenu::autoSelect(Role* role)
{
    std::vector<Role*> friends, enemies;
    for (auto r : battle_scene_->getBattleRoles())
    {
        if (r->Team == role->Team)
        {
            friends.push_back(r);
        }
        else
        {
            enemies.push_back(r);
        }
    }

    //ai为每种行动评分
    std::vector<AIAction> ai_action;

    Random<double> rand;    //梅森旋转法随机数
    rand.set_seed();
    rand.set_parameter(0, 1);

    if (role->AI_Action == -1)
    {
        auto _role_temp = *role;
        auto role_temp = &_role_temp;    //临时人物指针，用于一些含有距离衰减的计算

        //开始计算本轮的策略
        role->AI_Action = getResultFromString("休息");
        role->AI_MoveX = role->X();
        role->AI_MoveY = role->Y();
        role->AI_ActionX = role->X();
        role->AI_ActionY = role->Y();
        role->AI_Magic = nullptr;
        role->AI_Item = nullptr;

        //若有一方为空，没有战斗下去的意义
        if (!friends.empty() && !enemies.empty())
        {
            //计算可以移动的位置
            
            battle_scene_->calSelectLayer(role, 0, battle_scene_->calMoveStep(role));

            //考虑吃药
            std::string action_text = "藥品";
            if (childs_text_[action_text]->getVisible() && (role->HP < 0.2 * role->MaxHP || role->MP < 0.2 * role->MaxMP || role_->PhysicalPower < 0.2 * Save::getInstance()->MaxPhysicalPower))
            {
                AIAction aa;
                aa.Action = getResultFromString(action_text);
                auto items = BattleItemMenu::getAvaliableItems(role, 2);
                for (auto item : items)
                {
                    //分数计算，后面的差是尽量吃刚刚好的药
                    aa.point = 0;
                    if (item->AddHP > 0)
                    {
                        aa.point += (std::min)(item->AddHP, role->MaxHP - role->HP) - item->AddHP / 10;
                    }
                    if (item->AddMP > 0)
                    {
                        aa.point += (std::min)(item->AddMP, role->MaxMP - role->MP) / 2 - item->AddMP / 10;
                    }
                    else if (item->AddPhysicalPower > 0)
                    {
                        aa.point += (std::min)(item->AddPhysicalPower, Save::getInstance()->MaxPhysicalPower - role->PhysicalPower)
                            - item->AddPhysicalPower / 10;
                    }
                    if (aa.point > 0)
                    {
                        aa.item = item;
                        aa.point *= 1.5;    //自保的系数略大
                        getFarthestToAll(role, enemies, aa.MoveX, aa.MoveY);
                        ai_action.push_back(aa);
                    }
                }
            }

            //专注，增加各种状态，满值后不再显示
            if (role->Zhuanzhu < 5)
            {
                action_text = "专注";
                //会解毒的，检查队友中有无中毒较深者，接近并解毒
                if (childs_text_[action_text]->getVisible())
                {
                    for (auto r2 : friends)
                    {
                        if (r2->Poison > 50)
                        {
                            AIAction aa;
                            calAIActionNearest(r2, aa);                                             //计算目标，和离目标最近的点，下同
                            int action_dis = battle_scene_->calActionStep(role->AntiPoison);    //计算可以行动的距离
                            if (action_dis >= calNeedActionDistance(aa))                            //与需要行动的距离比较
                            {
                                //若在距离之内则考虑使用，以下各个都类似
                                aa.Action = getResultFromString(action_text);
                                aa.point = r2->Poison;
                                ai_action.push_back(aa);
                            }
                        }
                    }
                }
                action_text = "醫療";
                if (childs_text_[action_text]->getVisible())
                {
                    for (auto r2 : friends)
                    {
                        if (r2->HP < 0.2 * r2->MaxHP)
                        {
                            AIAction aa;
                            calAIActionNearest(r2, aa);
                            int action_dis = battle_scene_->calActionStep(role->Medicine);
                            if (action_dis >= calNeedActionDistance(aa))
                            {
                                aa.Action = getResultFromString(action_text);
                                aa.point = r2->Medicine;
                                ai_action.push_back(aa);
                            }
                        }
                    }
                }
            }
            else
            {
                //考虑用毒
                action_text = "毒术";
                if (childs_text_[action_text]->getVisible())
                {
                    auto r2 = getNearestRole(role, enemies);
                    AIAction aa;
                    calAIActionNearest(r2, aa);
                    int action_dis = battle_scene_->calActionStep(role->AttackWithPoison);
                    if (action_dis >= calNeedActionDistance(aa))
                    {
                        aa.Action = getResultFromString(action_text);
                        aa.point = (std::min)(Save::getInstance()->MaxPosion - r2->Poison, role->AttackWithPoison) / 2;
                        if (r2->HP < 10)
                        {
                            aa.point = 1;
                        }
                        ai_action.push_back(aa);
                    }
                }
            }

            //使用暗器
            action_text = "暗器";
            if (childs_text_[action_text]->getVisible())
            {
                auto r2 = getNearestRole(role, enemies);
                AIAction aa;
                calAIActionNearest(r2, aa, role_temp);    //临时人物指针用来计算伤害，因为含有距离衰减，武学同
                int action_dis = battle_scene_->calActionStep(role->HiddenWeapon);
                if (action_dis >= calNeedActionDistance(aa))
                {
                    aa.Action = getResultFromString(action_text);
                    auto items = BattleItemMenu::getAvaliableItems(role, 3);
                    for (auto item : items)
                    {
                        aa.point = battle_scene_->calHiddenWeaponHurt(role_temp, r2, item);
                        if (aa.point > r2->HP)
                        {
                            aa.point = r2->HP * 1.25;
                        }
                        aa.point *= 0.5;    //暗器分值略低
                        aa.item = item;
                        ai_action.push_back(aa);
                    }
                }
            }

            //使用武学
            action_text = "武學";
            if (childs_text_[action_text]->getVisible())
            {
                AIAction aa;
                aa.Action = getResultFromString(action_text);
                auto r2 = getNearestRole(role, enemies);
                calAIActionNearest(r2, aa, role_temp);
                //遍历武学
                for (int i = 0; i < ROLE_MAGIC_COUNT; i++)
                {
                    auto magic = Save::getInstance()->getRoleLearnedMagic(role, i);
                    if (magic == nullptr)
                    {
                        continue;
                    }
                    if (magic->MagicType < 0 || magic->MagicType > 4)
                    {
                        continue;
                    }
                    //遍历招式
                    for (int j = 0; j < 5; j++) {
                        int max_hurt = -1;                      
                        auto zhaoshi = Save::getInstance()->getRoleLearnedZhaoshi(role, magic, j);
                        if (zhaoshi == nullptr)
                        {
                            continue;
                        }
                        int level_index = role->getRoleMagicLevelIndex(i);

                        battle_scene_->calSelectLayerByMagic(aa.MoveX, aa.MoveY, role->Team, magic, level_index);
                        //对所有能选到的点测试，估算收益
                        for (int ix = 0; ix < BATTLEMAP_COORD_COUNT; ix++)
                        {
                            for (int iy = 0; iy < BATTLEMAP_COORD_COUNT; iy++)
                            {
                                int total_hurt = 0;
                                if (battle_scene_->canSelect(ix, iy))
                                {
                                    battle_scene_->calEffectLayer(aa.MoveX, aa.MoveY, ix, iy, magic, level_index);
                                    total_hurt = battle_scene_->calMagiclHurtAllEnemies(role_temp, magic, zhaoshi, true);
                                    if (total_hurt > max_hurt)
                                    {
                                        max_hurt = total_hurt;
                                        aa.magic = magic;
                                        aa.zhaoshi = zhaoshi;
                                        aa.ActionX = ix;
                                        aa.ActionY = iy;
                                    }
                                    if (total_hurt > -1)
                                    {
                                        //printf("AI %s %s (%d, %d): %d\n", PotConv::to_read(role->Name).c_str(), PotConv::to_read(magic->Name).c_str(), ix, iy, total_hurt);
                                    }
                                }
                            }
                        }
                        aa.point = max_hurt;
                        //if (role->AttackTwice) { aa.point *= 2; }
                        ai_action.push_back(aa);
                    }
                    
                }
            }
        }
        //查找最大评分的行动
        double max_point = -1;
        for (auto aa : ai_action)
        {
            printf("AI %s: %s ", PotConv::to_read(role->Name).c_str(), PotConv::to_read(getStringFromResult(aa.Action)).c_str());
            if (aa.item) { printf("%s ", PotConv::to_read(aa.item->Name).c_str()); }
            if (aa.magic) { printf("%s ", PotConv::to_read(aa.magic->Name).c_str()); }
            if (aa.zhaoshi) { printf("%s ", PotConv::to_read(aa.zhaoshi->Name).c_str()); }
            double r = rand.rand() * 10;    //用于同分的情况，可以随机选择
            printf("score %.2f(%.2f)\n", aa.point, r);
            //若评分仅有一个随机数的值，说明不在范围内，仅移动并结束
            if (aa.point == 0)
            {
                aa.Action = getResultFromString("休息");
            }
            double p = aa.point + r;
            if (p > max_point)
            {
                max_point = p;
                setAIActionToRole(aa, role);
            }
        }
    }

    if (!role->Moved)
    {
        //未移动则返回移动
        return getResultFromString("移動");
    }
    else
    {
        return role->AI_Action;
    }
}

//计算距离
void BattleActionMenu::calDistanceLayer(int x, int y, int max_step /*=64*/)
{
    distance_layer_.setAll(max_step + 1);
    std::vector<Point> cal_stack;
    distance_layer_.data(x, y) = 0;
    cal_stack.push_back({ x, y });
    int count = 0;
    int step = 0;
    while (step <= 64)
    {
        std::vector<Point> cal_stack_next;
        auto check_next = [&](Point p1) -> void
        {
            //未计算过且可以走的格子参与下一步的计算
            if (distance_layer_.data(p1.x, p1.y) == max_step + 1 && battle_scene_->canWalk(p1.x, p1.y))
            {
                distance_layer_.data(p1.x, p1.y) = step + 1;
                cal_stack_next.push_back(p1);
                count++;
            }
        };
        for (auto p : cal_stack)
        {
            distance_layer_.data(p.x, p.y) = step;
            check_next({ p.x - 1, p.y });
            check_next({ p.x + 1, p.y });
            check_next({ p.x, p.y - 1 });
            check_next({ p.x, p.y + 1 });
            if (count >= distance_layer_.squareSize())
            {
                break;
            }    //最多计算次数，避免死掉
        }
        if (cal_stack_next.size() == 0) { break; }    //无新的点，结束
        cal_stack = cal_stack_next;
        step++;
    }
}

void BattleActionMenu::getFarthestToAll(Role* role, std::vector<Role*> roles, int& x, int& y)
{
    Random<double> rand;    //梅森旋转法随机数
    rand.set_seed();
    //选择离所有敌方距离和最大的点
    double max_dis = 0;
    for (int ix = 0; ix < BATTLEMAP_COORD_COUNT; ix++)
    {
        for (int iy = 0; iy < BATTLEMAP_COORD_COUNT; iy++)
        {
            if (battle_scene_->canSelect(ix, iy))
            {
                double cur_dis = rand.rand();
                for (auto r2 : roles)
                {
                    cur_dis += battle_scene_->calDistance(ix, iy, r2->X(), r2->Y());
                }
                if (cur_dis > max_dis)
                {
                    max_dis = cur_dis;
                    x = ix;
                    y = iy;
                }
            }
        }
    }
}

void BattleActionMenu::getNearestPosition(int x0, int y0, int& x, int& y)
{
    Random<double> rand;    //梅森旋转法随机数
    rand.set_seed();
    calDistanceLayer(x0, y0);
    double min_dis = BATTLEMAP_COORD_COUNT * BATTLEMAP_COORD_COUNT;
    for (int ix = 0; ix < BATTLEMAP_COORD_COUNT; ix++)
    {
        for (int iy = 0; iy < BATTLEMAP_COORD_COUNT; iy++)
        {
            if (battle_scene_->canSelect(ix, iy))
            {
                double cur_dis = distance_layer_.data(ix, iy) + rand.rand();
                if (cur_dis < min_dis)
                {
                    min_dis = cur_dis;
                    x = ix;
                    y = iy;
                }
            }
        }
    }
}

Role* BattleActionMenu::getNearestRole(Role* role, std::vector<Role*> roles)
{
    int min_dis = 4096;
    Role* r2 = nullptr;
    //选择离得最近的敌人
    for (auto r : roles)
    {
        auto cur_dis = battle_scene_->calRoleDistance(role, r);
        if (cur_dis < min_dis)
        {
            r2 = r;
            min_dis = cur_dis;
        }
    }
    return r2;
}

//需事先计算好可以移动的范围
void BattleActionMenu::calAIActionNearest(Role* r2, AIAction& aa, Role* r_temp)
{
    getNearestPosition(r2->X(), r2->Y(), aa.MoveX, aa.MoveY);
    aa.ActionX = r2->X();
    aa.ActionY = r2->Y();
    if (r_temp)
    {
        r_temp->setPositionOnly(aa.MoveX, aa.MoveY);
    }
}

int BattleActionMenu::calNeedActionDistance(AIAction& aa)
{
    return battle_scene_->calDistance(aa.MoveX, aa.MoveY, aa.ActionX, aa.ActionY);
}

void BattleMagicMenu::onEntrance()
{
    if (role_ == nullptr)
    {
        return;
    }
    if (role_->isAuto())
    {
        magic_ = role_->AI_Magic;
        setAllChildState(Normal);
        setResult(0);
        setExit(true);
        setVisible(false);
        return;
    }
    forceActiveChild();
}

void BattleMagicMenu::setRole(Role* r)
{
    role_ = r;
    result_ = -1;
    magic_ = nullptr;
    setVisible(true);
    std::vector<std::string> magic_names;
    for (int i = 0; i < ROLE_ACTIVE_MAGIC_COUNT; i++)
    {
        auto m = Save::getInstance()->getRoleActiveMagic(role_,i);
        if (m!=nullptr&& m->MagicType<5 )
        {
            magic_names.push_back(convert::formatString("%-12s%4d  ", m->Name, role_->getRoleShowLearnedMagicLevel(role_->JhMagic[i])));
        }
        else
        {
            magic_names.push_back("");
        }
    }
    setStrings(magic_names);
    setPosition(160, 200);

    //如果宽度为0的项隐藏
    for (auto child : childs_)
    {
        int w, h;
        child->getSize(w, h);
        if (w <= 0)
        {
            child->setVisible(false);
        }
    }
    arrange(0, 0, 0, 30);
}

void BattleMagicMenu::onPressedOK()
{
    checkActiveToResult();
    magic_ = Save::getInstance()->getRoleActiveMagic(role_, result_);
    if (magic_)
    {
        setExit(true);
    }
}

void BattleZhaoshiMenu::onEntrance()
{
    if (role_ == nullptr)
    {
        return;
    }
    if (role_->isAuto())
    {
        zhaoshi_ = role_->AI_Zhaoshi;
        setAllChildState(Normal);
        setResult(0);
        setExit(true);
        setVisible(false);
        return;
    }
    zhaoshi_state_ = std::make_shared<ZhaoshiStateMenu>();
    addChild(zhaoshi_state_);
    forceActiveChild();
}

void BattleZhaoshiMenu::draw() {
    int i = getActiveChildIndex();
    if (i != current_ac_id) {
        if (role_ != nullptr && i >= 0 && i < zhaoshis_.size()) {
            //auto zhaoshi = Save::getInstance()->getRoleLearnedZhaoshi(role_, magic_, i);;
            zhaoshi_state_->setZhaoshi(zhaoshis_[i]);
        }
    }  
    TextBox::draw();
}

void BattleZhaoshiMenu::setRole(Role* r)
{
    role_ = r;
    result_ = -1;
    zhaoshi_ = nullptr;
    setVisible(true);
    std::vector<std::string> zhaoshi_names;
    std::vector<Zhaoshi*> zhaoshis;
    int zs_state = r->LZhaoshi[r->getMagicOfRoleIndex(magic_)];
    int zs_array[5];
    for (int j = 0; j < 5; j++) {
        if (((zs_state >> j) & 1) == 1) {
            zs_array[j] = magic_->Zhaoshi[j];
        }
        else { zs_array[j] = 0; }
    }
    for (auto j : zs_array) {

        if (j > 0)
        {
            auto m = Save::getInstance()->getZhaoshi(j);
            if (m->ygongji) {
                zhaoshi_names.push_back(convert::formatString("%-12s  ", m->Name));
                zhaoshis.push_back(m);
            }
        }
        else
        {
            zhaoshi_names.push_back("");
        }        
    }       

    zhaoshis_ = zhaoshis;
    setStrings(zhaoshi_names);
    setPosition(160, 200);

    //如果宽度为0的项隐藏
    for (auto child : childs_)
    {
        int w, h;
        child->getSize(w, h);
        if (w <= 0)
        {
            child->setVisible(false);
        }
    }
    arrange(0, 0, 0, 30);
}

void BattleZhaoshiMenu::onPressedOK()
{
    checkActiveToResult();
    zhaoshi_ = Save::getInstance()->getRoleLearnedZhaoshi(role_, magic_, result_);
    if (zhaoshi_)
    {
        setExit(true);
    }
}

BattleItemMenu::BattleItemMenu()
{
    setSelectUser(false);
}

void BattleItemMenu::onEntrance()
{
    if (role_ == nullptr)
    {
        return;
    }
    if (role_->isAuto())
    {
        if (role_->AI_Item)
        {
            current_item_ = role_->AI_Item;
            setExit(true);
            setVisible(false);
        }
    }
}

void BattleItemMenu::addItem(Item* item, int count)
{
    if (role_->Team == 0)
    {
        Event::getInstance()->addItemWithoutHint(item->ID, count);
    }
    else
    {
        Event::getInstance()->roleAddItem(role_->ID, item->ID, count);
    }
}

std::vector<Item*> BattleItemMenu::getAvaliableItems()
{
    //选出物品列表
    if (role_->Team == 0)
    {
        geItemsByType(force_item_type_);
    }
    else
    {
        available_items_.clear();
        for (int i = 0; i < ROLE_TAKING_ITEM_COUNT; i++)
        {
            auto item = Save::getInstance()->getItem(role_->TakingItem[i]);
            if (getItemDetailType(item) == force_item_type_)
            {
                available_items_.push_back(item);
            }
        }
    }
    return available_items_;
}

std::vector<Item*> BattleItemMenu::getAvaliableItems(Role* role, int type)
{
    BattleItemMenu item_menu;
    item_menu.setRole(role);
    item_menu.setForceItemType(type);
    return item_menu.getAvaliableItems();
}


BattleStateMenu::BattleStateMenu()
{

    setTexture("menu", 68);
    //setHaveBox(true);
    int x = 20;
    int y = 45;
    int x_bias = 70;
    int y_bias = 30;

    //显示名字
    txt_name_ = std::make_shared<TextBox>();
    txt_name_->setText("");
    addChild(txt_name_, x+90, y-50);

    //显示专注标志
    zz_name_ = std::make_shared<TextBox>();
    zz_name_->setText("专注：");
    addChild(zz_name_, x, y - 30);
    for (int i = 0; i < 5; i++) {
        zz_value_[i] = std::make_shared<TextBox>();
        zz_value_[i]->setTexture("menu", 20);
        zz_value_[i]->setSize(20, 20);
        zz_value_[i]->setVisible(false);
        addChild(zz_value_[i], x + 80 + i * 30, y - 27);
    }


    //显示战斗属性
    txt_qf_ = std::make_shared<TextBox>();
    txt_qf_->setText("气防");
    addChild(txt_qf_, x, y);
    txt_qf_value_ = std::make_shared<TextBox>();
    txt_qf_value_->setText("0");
    addChild(txt_qf_value_, x+ x_bias, y);
    txt_yg_ = std::make_shared<TextBox>();
    txt_yg_->setText("硬功");
    addChild(txt_yg_, x, y+y_bias);
    txt_yg_value_ = std::make_shared<TextBox>();
    txt_yg_value_->setText("0");
    addChild(txt_yg_value_, x+x_bias, y+y_bias);
    txt_lh_ = std::make_shared<TextBox>();
    txt_lh_->setText("灵活");
    addChild(txt_lh_, x, y + 2*y_bias);
    txt_lh_value_ = std::make_shared<TextBox>();
    txt_lh_value_->setText("0");
    addChild(txt_lh_value_, x + x_bias, y + 2*y_bias);
    txt_xq_ = std::make_shared<TextBox>();
    txt_xq_->setText("行气");
    addChild(txt_xq_, x, y + 3 * y_bias);
    txt_xq_value_ = std::make_shared<TextBox>();
    txt_xq_value_->setText("0");
    addChild(txt_xq_value_, x + x_bias, y + 3 * y_bias);
    txt_sf_ = std::make_shared<TextBox>();
    txt_sf_->setText("身法");
    addChild(txt_sf_, x, y + 4 * y_bias);
    txt_sf_value_ = std::make_shared<TextBox>();
    txt_sf_value_->setText("0");
    addChild(txt_sf_value_, x + x_bias, y + 4 * y_bias);

    txt_ff_ = std::make_shared<TextBox>();
    txt_ff_->setText("奋发");
    addChild(txt_ff_, x+2*x_bias, y);
    txt_ff_value_ = std::make_shared<TextBox>();
    txt_ff_value_->setText("0");
    addChild(txt_ff_value_, x + 3*x_bias, y);
    txt_zy_ = std::make_shared<TextBox>();
    txt_zy_->setText("战意");
    addChild(txt_zy_, x + 2 * x_bias, y + y_bias);
    txt_zy_value_ = std::make_shared<TextBox>();
    txt_zy_value_->setText("0");
    addChild(txt_zy_value_, x + 3*x_bias, y + y_bias);
    txt_jz_ = std::make_shared<TextBox>();
    txt_jz_->setText("精准");
    addChild(txt_jz_, x + 2 * x_bias, y + 2 * y_bias);
    txt_jz_value_ = std::make_shared<TextBox>();
    txt_jz_value_->setText("0");
    addChild(txt_jz_value_, x + 3*x_bias, y + 2 * y_bias);
    txt_js_ = std::make_shared<TextBox>();
    txt_js_->setText("急速");
    addChild(txt_js_, x + 2 * x_bias, y + 3 * y_bias);
    txt_js_value_ = std::make_shared<TextBox>();
    txt_js_value_->setText("0");
    addChild(txt_js_value_, x + 3*x_bias, y + 3 * y_bias);
    txt_sd_ = std::make_shared<TextBox>();
    txt_sd_->setText("闪躲");
    addChild(txt_sd_, x + 2 * x_bias, y + 4 * y_bias);
    txt_sd_value_ = std::make_shared<TextBox>();
    txt_sd_value_->setText("0");
    addChild(txt_sd_value_, x + 3*x_bias, y + 4 * y_bias);


}
void BattleStateMenu::draw() {
    if (role_ == nullptr) {
        setAllChildVisible(false);
        return;
    }
    else {
        setAllChildVisible(true);
        Menu::draw();
    }
}

void BattleStateMenu::setRole(Role* r)
{
    role_ = r;
    if (role_ == nullptr) {return;}

    BP_Color c_red = { 255, 0, 0 };

    txt_name_->setText(convert::formatString("%s", role_->Name));

    for (int i = 0; i < 5; i++) {
        if (i < role_->Zhuanzhu) {
            zz_value_[i]->setTexture("menu",19);
        }
        else {
            zz_value_[i]->setTexture("menu", 20);
        }
    }

    txt_qf_value_->setText(convert::formatString("%d", role_->qf_));
    txt_yg_value_->setText(convert::formatString("%d", role_->yg_));
    txt_lh_value_->setText(convert::formatString("%d", role_->lh_));
    txt_xq_value_->setText(convert::formatString("%d", role_->xq_));
    txt_sf_value_->setText(convert::formatString("%d", role_->sf_));
    txt_ff_value_->setText(convert::formatString("%d", role_->ff_));
    txt_zy_value_->setText(convert::formatString("%d", role_->zy_));
    txt_jz_value_->setText(convert::formatString("%d", role_->jz_));
    txt_js_value_->setText(convert::formatString("%d", role_->js_));
    txt_sd_value_->setText(convert::formatString("%d", role_->sd_));

    //颜色随数值大小变化，0为大红，100为绿
    if (role_->qf_ <= 100) {
        txt_qf_value_->setTextColor({ (Uint8)(200 - 2 * role_->qf_), (Uint8)(2 * role_->qf_), 0 });
    }
    if (role_->yg_ <= 100) {
        txt_yg_value_->setTextColor({ (Uint8)(200 - 2 * role_->yg_), (Uint8)(2 * role_->yg_), 0 });
    }
    if (role_->lh_ <= 100) {
        txt_lh_value_->setTextColor({ (Uint8)(200 - 2 * role_->lh_), (Uint8)(2 * role_->lh_), 0 });
    }
    if (role_->xq_ <= 100) {
        txt_xq_value_->setTextColor({ (Uint8)(200 - 2 * role_->xq_), (Uint8)(2 * role_->xq_), 0 });
    }
    if (role_->sf_ <= 100) {
        txt_sf_value_->setTextColor({ (Uint8)(200 - 2 * role_->sf_), (Uint8)(2 * role_->sf_), 0 });
    }
    if (role_->ff_ <= 100) {
        txt_ff_value_->setTextColor({ (Uint8)(200 - 2 * role_->ff_), (Uint8)(2 * role_->ff_), 0 });
    }
    if (role_->zy_ <= 100) {
        txt_zy_value_->setTextColor({ (Uint8)(200 - 2 * role_->zy_), (Uint8)(2 * role_->zy_), 0 });
    }
    if (role_->jz_ <= 100) {
        txt_jz_value_->setTextColor({ (Uint8)(200 - 2 * role_->jz_), (Uint8)(2 * role_->jz_), 0 });
    }
    if (role_->js_ <= 100) {
        txt_js_value_->setTextColor({ (Uint8)(200 - 2 * role_->js_), (Uint8)(2 * role_->js_), 0 });
    }
    if (role_->sd_ <= 100) {
        txt_sd_value_->setTextColor({ (Uint8)(200 - 2 * role_->sd_), (Uint8)(2 * role_->sd_), 0 });
    }
}


ZhaoshiStateMenu::ZhaoshiStateMenu()
{
    setTexture("menu", 68);
    setText("招式效果");
    setTextPosition(20, 5);
    setHaveBox(false);
    setFontSize(30);

    setPosition(300, 300);
    setSize(400, 220);
    setVisible(true);

}


void ZhaoshiStateMenu::setZhaoshi(Zhaoshi* zhaoshi) {
    zhaoshi_ = zhaoshi;
    if (zhaoshi_ == nullptr) {
        return;
    }
    clearChilds();
    setVisible(true);

    std::string strs[69] = {""};
    strs[0] = "削气";
    strs[1] = "削硬";
    strs[2] = "削灵";
    strs[3] = "削行";
    strs[4] = "削身";
    strs[10] = "奋发";
    strs[11] = "战意";
    strs[12] = "精准";
    strs[13] = "急速";
    strs[14] = "躲闪";
    strs[15] = "愤力";
    strs[16] = "免疫";
    strs[17] = "储力";
    strs[18] = "机敏";
    strs[20] = "御气";
    strs[21] = "御硬";
    strs[22] = "御灵";
    strs[23] = "御行";
    strs[24] = "御身";
    strs[25] = " ";
    strs[30] = "加气";
    strs[31] = "加硬";
    strs[32] = "加灵";
    strs[33] = "加行";
    strs[34] = "加身";
    strs[40] = "回气";
    strs[41] = "回硬";
    strs[42] = "回灵";
    strs[43] = "回行";
    strs[44] = "回身";
    strs[45] = "回命";
    strs[46] = "回内";
    strs[50] = "耗气";
    strs[51] = "耗硬";
    strs[52] = "耗灵";
    strs[53] = "耗行";
    strs[54] = "耗身";
    strs[60] = "气防";
    strs[61] = "硬功";
    strs[62] = "灵活";
    strs[63] = "行气";
    strs[64] = "身法";
    strs[65] = "奋发";
    strs[66] = "战意";
    strs[67] = "精准";
    strs[68] = "急速";


    int x = 20;
    int y = 45;
    int x_bias = 50;
    int y_bias = 30;

    //显示招式属性
    if (zhaoshi->gongji) {
        auto jiagong = std::make_shared<TextBox>();
        jiagong->setHaveBox(false);
        jiagong->setText(convert::formatString("%s", "攻击加成"));
        addChild(jiagong, x, y);
        auto jiagong_value = std::make_shared<TextBox>();
        jiagong_value->setHaveBox(false);
        jiagong_value->setText(convert::formatString("%d", zhaoshi->gongji));
        addChild(jiagong_value, x + 2*x_bias, y);
        x = x + 4*x_bias;
    }
    if (zhaoshi->fangyu) {
        auto fangyu = std::make_shared<TextBox>();
        fangyu->setHaveBox(false);
        fangyu->setText(convert::formatString("%s", "防御加成"));
        addChild(fangyu, x, y);
        auto fangyu_value = std::make_shared<TextBox>();
        fangyu_value->setHaveBox(false);
        fangyu_value->setText(convert::formatString("%d", zhaoshi->fangyu));
        addChild(fangyu_value, x + 2 * x_bias, y);
    }
    
    x = 20;
    y = 75;
    int j = 0;
    for (auto i : zhaoshi_->texiao) {
        if (i.Type > 0 && i.Type < 69) {
            auto texiao = std::make_shared<TextBox>();
            texiao->setHaveBox(false);
            texiao->setText(strs[i.Type]);
            addChild(texiao, x, y);
            auto texiao_value = std::make_shared<TextBox>();
            texiao_value->setHaveBox(false);
            texiao_value->setText(convert::formatString("%d", i.Value));
            addChild(texiao_value, x + x_bias, y);
            j++;
            if (j % 3==0) {
                y = y + y_bias;
            }
            else {
                x = x + 2*x_bias;
            }
        }
    }
}

MagicStateMenu::MagicStateMenu()
{
    setTexture("menu", 68);
    setText("武功属性");
    setTextPosition(20, 5);
    setHaveBox(false);
    setFontSize(30);

    setPosition(300, 300);
    setSize(380, 240);
    setVisible(true);

}

void MagicStateMenu::setMagic(Magic* magic) {
    magic_ = magic;
    if (magic_ == nullptr || role_ == nullptr) {
        setVisible(false);
        return;
    }    
    clearChilds();
    setVisible(true);   

    std::string strs[166] = { "" };
    strs[1] = "體力不減";
    strs[2] = "女性加成";
    strs[3] = "飲酒加倍";
    strs[4] = "乾坤大挪移";
    strs[5] = "斗轉星移";
    strs[6] = "內傷免疫";
    strs[7] = "殺體";
    strs[8] = "增加閃躲";
    strs[9] = "每級傷害+";
    strs[10] = "耗內減少";
    strs[11] = "恢復生命";
    strs[12] = "全負免疫";
    strs[13] = "全武加成";
    strs[14] = "左右互搏";
    strs[15] = "拳掌加成";
    strs[16] = "劍術加成";
    strs[17] = "刀法加成";
    strs[18] = "奇門加成";
    strs[19] = "內傷加成";
    strs[20] = "封穴加成";
    strs[21] = "吸血";
    strs[22] = "攻擊增距";
    strs[23] = "恢復內力";
    strs[24] = "暗器增距";
    strs[25] = "吸內";
    strs[26] = "弱點";
    strs[27] = "殺內";
    strs[28] = "抵消傷害";
    strs[29] = "反彈傷害";
    strs[30] = "真傷";
    strs[31] = "傷害減免";
    strs[32] = "吸內反噬";
    strs[33] = "劇毒反噬";
    strs[34] = "復活";
    strs[35] = "精準";
    strs[36] = "免傷";
    strs[37] = "怒氣";
    strs[38] = "冰凍";
    strs[39] = "流血";
    strs[40] = "回气";
    strs[41] = "回硬";
    strs[42] = "回灵";
    strs[43] = "回行";
    strs[44] = "回身";
    strs[45] = "回命";
    strs[46] = "回内";
    strs[50] = "耗气";
    strs[51] = "耗硬";
    strs[52] = "耗灵";
    strs[53] = "耗行";
    strs[54] = "耗身";
    strs[60] = "气防";
    strs[61] = "硬功";
    strs[62] = "灵活";
    strs[63] = "行气";
    strs[64] = "身法";
    strs[65] = "奋发";
    strs[66] = "战意";
    strs[67] = "精准";
    strs[68] = "急速";
    strs[100] = "眩暈";
    strs[101] = "目盲";
    strs[102] = "灼燒";
    strs[103] = "斷筋";
    strs[104] = "暴擊";
    strs[105] = "攻擊";
    strs[106] = "防禦";
    strs[107] = "輕功";
    strs[108] = "拳掌";
    strs[109] = "御劍";
    strs[110] = "耍刀";
    strs[111] = "奇門";
    strs[112] = "暗器";
    strs[113] = "經驗";
    strs[114] = "瘋魔";
    strs[115] = "封穴免疫";
    strs[116] = "冰凍免疫";
    strs[117] = "流血免疫";
    strs[118] = "眩晕免疫";
    strs[119] = "目盲免疫";
    strs[120] = "灼燒免疫";
    strs[121] = "断筋免疫";
    strs[122] = "商店折扣";
    strs[123] = "商店卖价";
    strs[124] = "天資過人";
    strs[125] = "血量過人";
    strs[126] = "連擊抵抗";
    strs[127] = "暴擊免疫";
    strs[128] = "羈絆";
    strs[129] = "橫練";
    strs[130] = "截脈";
    strs[131] = "破行";
    strs[132] = "輕靈";
    strs[133] = "滲勁";
    strs[134] = "奮勇";
    strs[135] = "清心";
    strs[136] = "氣療";
    strs[137] = "調息";
    strs[138] = "回體";
    strs[139] = "移動距離";
    strs[140] = "破行免疫";
    strs[141] = "七傷";
    strs[142] = "混亂";
    strs[143] = "混亂免疫";
    strs[144] = "連擊";
    strs[145] = "军阵";
    strs[146] = "攻击潜力";
    strs[147] = "防御潜力";
    strs[148] = "轻功潜力";
    strs[149] = "拳掌潜力";
    strs[150] = "御剑潜力";
    strs[151] = "耍刀潜力";
    strs[152] = "奇门潜力";
    strs[153] = "暗器潜力";
    strs[154] = "生命回复";
    strs[155] = "内力回复";
    strs[156] = "爆发";
    strs[157] = "气劲";
    strs[158] = "暴击伤害";
    strs[159] = "战意";
    strs[160] = "奋发";
    strs[161] = "格挡";
    strs[162] = "拳法距离";
    strs[163] = "剑法距离";
    strs[164] = "刀法距离";
    strs[165] = "奇门距离";


    BP_Color color_gray = { 130, 130, 130, 255 };
    BP_Color color_red = { 255, 90, 60, 255 };
    BP_Color color_gold = { 205, 149, 12, 255 };


    //自动调节界面的位置
    auto engine = Engine::getInstance();

    while (x_ + w_ > engine->getWindowWidth()) {
        x_ -= w_;
    }
    while (y_ + h_ > engine->getWindowHeight()) {
        y_ -= h_;
    }

    int x, y;
    int x_t = 20;
    int y_t = 40;
    int x_bias = 80;
    int y_bias = 25;

    //判断武功类型
    if (magic->MagicType > 4) {
        int i = 0;
        int level = Save::getInstance()->getRoleLearnedMagicLevelIndex(role_, magic);
        if (magic->AddHP[level]) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto hp = std::make_shared<TextBox>();
            hp->setHaveBox(false);
            hp->setText(convert::formatString("%4s", "生命"));
            addChild(hp, x, y);
            auto hp_value = std::make_shared<TextBox>();
            hp_value->setHaveBox(false);
            hp_value->setText(convert::formatString("%d", magic->AddHP[level]));
            addChild(hp_value, x + x_bias, y);

        }
        if (magic->AddMP[level]) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto mp = std::make_shared<TextBox>();
            mp->setHaveBox(false);
            mp->setText(convert::formatString("%4s", "内力"));
            addChild(mp, x, y);
            auto mp_value = std::make_shared<TextBox>();
            mp_value->setHaveBox(false);
            mp_value->setText(convert::formatString("%d", magic->AddMP[level]));
            addChild(mp_value, x + x_bias, y);

        }
        if (magic->AddAttack[level]) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto jiagong = std::make_shared<TextBox>();
            jiagong->setHaveBox(false);
            jiagong->setText(convert::formatString("%4s", "攻击"));
            addChild(jiagong, x, y);
            auto jiagong_value = std::make_shared<TextBox>();
            jiagong_value->setHaveBox(false);
            jiagong_value->setText(convert::formatString("%d", magic->AddAttack[level]));
            addChild(jiagong_value, x + x_bias, y);

        }
        if (magic->AddDefence[level]) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias/2;
            i++;
            auto fangyu = std::make_shared<TextBox>();
            fangyu->setHaveBox(false);
            fangyu->setText(convert::formatString("%4s", "防御"));
            addChild(fangyu, x, y);
            auto fangyu_value = std::make_shared<TextBox>();
            fangyu_value->setHaveBox(false);
            fangyu_value->setText(convert::formatString("%d", magic->AddDefence[level]));
            addChild(fangyu_value, x + x_bias, y);
        }
        if (magic->AddSpeed[level]) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto qinggong = std::make_shared<TextBox>();
            qinggong->setHaveBox(false);
            qinggong->setText(convert::formatString("%4s", "轻功"));
            addChild(qinggong, x, y);
            auto qinggong_value = std::make_shared<TextBox>();
            qinggong_value->setHaveBox(false);
            qinggong_value->setText(convert::formatString("%d", magic->AddSpeed[level]));
            addChild(qinggong_value, x + x_bias, y);
        }

        x = 20;
        y_t = y + y_bias;
        int k = 0;
        for (int j = 0; j < 10; j++) {
            if (magic_->SelectDistance[j] > 0 && magic_->AttackDistance[j]!=0) {
                y = y_t + (k / 3) * y_bias;
                x = x_t + (k % 3) * 3 * x_bias / 2;
                k++;
                auto texiao = std::make_shared<TextBox>();
                texiao->setHaveBox(false);
                texiao->setText(strs[magic_->SelectDistance[j]].c_str());
                texiao->setTextColor(color_gold);
                addChild(texiao, x, y);
                auto texiao_value = std::make_shared<TextBox>();
                texiao_value->setHaveBox(false);
                texiao_value->setText(convert::formatString("%d", magic_->AttackDistance[j]));
                texiao_value->setTextColor(color_gold);
                addChild(texiao_value, x + x_bias, y);

            }
        }
    }else {
        int i = 0;
        if (magic->NeedMP) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto needmp = std::make_shared<TextBox>();
            needmp->setHaveBox(false);
            needmp->setText(convert::formatString("%4s", "消耗内力"));
            addChild(needmp, x, y);
            auto needmp_value = std::make_shared<TextBox>();
            needmp_value->setHaveBox(false);
            needmp_value->setText(convert::formatString("%d", magic->NeedMP));
            addChild(needmp_value, x + x_bias, y);

        }
        if (magic->MaxHurt) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto maxhurt = std::make_shared<TextBox>();
            maxhurt->setHaveBox(false);
            maxhurt->setText(convert::formatString("%4s", "最大伤害"));
            addChild(maxhurt, x, y);
            auto maxhurt_value = std::make_shared<TextBox>();
            maxhurt_value->setHaveBox(false);
            maxhurt_value->setText(convert::formatString("%d", magic->MaxHurt));
            addChild(maxhurt_value, x + x_bias, y);

        }
        if (magic->BattleState) {
            y = y_t + (i / 3) * y_bias;
            x = x_t + (i % 3) * 3 * x_bias / 2;
            i++;
            auto bs = std::make_shared<TextBox>();
            bs->setHaveBox(false);
            bs->setText(strs[magic->BattleState/100]);
            addChild(bs, x, y);
            auto bs_value = std::make_shared<TextBox>();
            bs_value->setHaveBox(false);
            bs_value->setText(convert::formatString("%d", magic->BattleState % 100));
            addChild(bs_value, x + 2 * x_bias, y);
        }

    }

    x = 20;
    y += y_bias;

    setText(convert::formatString("%s", magic->Name));
    setTextColor(color_red);

    auto devide = std::make_shared<TextBox>();
    devide->setHaveBox(false);
    devide->setText("--------------------------------");
    devide->setTextColor(color_gray);
    addChild(devide, x, y);

    y += y_bias;

    auto str = convert::formatString("%s", magic->Introduction);

    int i = 0;
    int k = 0;
    while(i < str.size()) {
        int line_length = 51;
        if (i + line_length >= str.size()) {
            line_length = str.size() - i; 
        }
        //计算英文个数
        int eng_count = 0;
        auto line = str.substr(i, line_length);
        for (int j = 0; j < line.size();)
        {
            if (uint8_t(line.at(j)) > 128)
            {
                j += 3;
            }
            else
            {
                eng_count++;
                j++;
            }
        }
        //若英文字符为奇数个，且最后一个字为中文，则多算一个字符
        if (eng_count % 2 == 1 && line_length == 51 && uint8_t(str.at(i + line_length)) >= 128)
        {
            line_length++;
            line = str.substr(i, line_length);
        }
        auto intro = std::make_shared<TextBox>();
        intro->setHaveBox(false);
        intro->setText(line);
        addChild(intro, x, y + k * 25);
        i += line_length;
        k++;
    }

    //自动调节界面的大小
    h_ = y + k * 25 + 20;
}






