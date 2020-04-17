#include "UIMagic.h"
#include "Font.h"
#include "Convert.h"
#include "Save.h"
#include "Event.h"


BP_Color color_white = { 255, 255, 255, 255 };
BP_Color color_name = { 255, 215, 0, 255 };
BP_Color color_ability1 = { 255, 250, 205, 255 };
BP_Color color_ability2 = { 236, 200, 40, 255 };
BP_Color color_red = { 255, 90, 60, 255 };
BP_Color color_magic = { 236, 200, 40, 255 };
BP_Color color_magic_level1 = { 253, 101, 101, 255 };
BP_Color color_purple = { 208, 152, 208, 255 };
BP_Color color_magic_empty = { 236, 200, 40, 255 };
BP_Color color_equip = { 165, 28, 218, 255 };
BP_Color color_seagreen = { 84, 255, 159, 255 };

UIMagic::UIMagic()
{
    neigong_menu_ = std::make_shared<MagicMenu>(this);
    teji_menu_ = std::make_shared<MagicMenu>(this);
    waigong_menu_ = std::make_shared<MagicMenu>(this);
    waigong_menu_->setMaxOptions(10);

    all_value_menu_ = std::make_shared<Menu>();

    addChild(neigong_menu_);
    addChild(teji_menu_);
    addChild(waigong_menu_);
    addChild(all_value_menu_);


    int font_size = 22;
    
    int x, y;

    x = x_ + 20;
    y = y_ + 270;
    ng_title_ = std::make_shared<TextBox>();
    ng_title_->setText("所学内功");
    ng_title_->setFontSize(25);
    ng_title_->setPosition(x - 10, y);
    ng_title_->setHaveBox(false);
    ng_title_->setVisible(false);
    ng_title_->setTextColor(color_name);
    addChild(ng_title_);
    jhng_title_ = std::make_shared<TextBox>();
    jhng_title_->setText("激活的内功");
    jhng_title_->setFontSize(25);
    jhng_title_->setPosition(x + 350, y);
    jhng_title_->setHaveBox(false);
    jhng_title_->setVisible(false);
    jhng_title_->setTextColor(color_name);
    addChild(jhng_title_);

    jh_neigong_ = std::make_shared<TextBox>();
    jh_neigong_->setText("无");
    jh_neigong_->setVisible(false);
    jh_neigong_->setHaveBox(false);
    jh_neigong_->setFontSize(25);
    jh_neigong_->setPosition(x + 500, y);
    addChild(jh_neigong_);

    neigong_menu_->setPosition(x, y);
    for (int i = 0; i < 10; i++)
    {
            int x1 = x + i % 4 * 150;
            int y1 = y + 30 + i / 4 * 25;
            neigong_btn_[i] = std::make_shared<Button>();
            neigong_btn_[i]->setPosition(x1, y1);
            neigong_btn_[i]->setTextColor(color_ability1);
            neigong_btn_[i]->setHaveBox(false);
            neigong_btn_[i]->setVisible(false);
            neigong_btn_[i]->setTexture("background", -1, -1, 34);
            neigong_menu_->addChild(neigong_btn_[i]);
            neigong_value_[i] = std::make_shared<TextBox>();
            neigong_value_[i]->setPosition(x1 + 100, y1);
            neigong_value_[i]->setHaveBox(false);
            neigong_value_[i]->setVisible(false);
            all_value_menu_->addChild(neigong_value_[i]);
    }

    x = x_ + 20;
    y = y_ + 330;
    
    tj_title_ = std::make_shared<TextBox>();
    tj_title_->setText("所学特技");
    tj_title_->setFontSize(25);
    tj_title_->setPosition(x - 10, y);
    tj_title_->setHaveBox(false);
    tj_title_->setVisible(false);
    tj_title_->setTextColor(color_name);
    addChild(tj_title_);
    jhtj_title_ = std::make_shared<TextBox>();
    jhtj_title_->setText("激活的特技");
    jhtj_title_->setFontSize(25);
    jhtj_title_->setPosition(x + 350, y);
    jhtj_title_->setHaveBox(false);
    jhtj_title_->setVisible(false);
    jhtj_title_->setTextColor(color_name);
    addChild(jhtj_title_);

    jh_teji_ = std::make_shared<TextBox>();
    jh_teji_->setText("无");
    jh_teji_->setVisible(false);
    jh_teji_->setHaveBox(false);
    jh_teji_->setFontSize(25);
    jh_teji_->setPosition(x + 500, y);
    addChild(jh_teji_);


    teji_menu_->setPosition(x, y);

    for (int i = 0; i < 10; i++)
    {
        int x1 = x + i % 4 * 150;
        int y1 = y + 30 + i / 4 * 25;
        teji_btn_[i] = std::make_shared<Button>();
        teji_btn_[i]->setPosition(x1, y1);
        teji_btn_[i]->setTextColor(color_ability1);
        teji_btn_[i]->setHaveBox(false);
        teji_btn_[i]->setVisible(false);
        teji_btn_[i]->setTexture("background", -1, -1, 34);
        teji_menu_->addChild(teji_btn_[i]);
        teji_value_[i] = std::make_shared<TextBox>();
        teji_value_[i]->setPosition(x1 + 100, y1);
        teji_value_[i]->setHaveBox(false);
        teji_value_[i]->setVisible(false);
        all_value_menu_->addChild(teji_value_[i]);
    }

    x = x_ + 20;
    y = y_ + 390;

    jhwg_title_ = std::make_shared<TextBox>();
    jhwg_title_->setText("激活的外功");
    jhwg_title_->setFontSize(25);
    jhwg_title_->setPosition(x - 10, y);
    jhwg_title_->setHaveBox(false);
    jhwg_title_->setVisible(false);
    jhwg_title_->setTextColor(color_name);
    addChild(jhwg_title_);
    jhwg_title2_ = std::make_shared<TextBox>();
    jhwg_title2_->setText("（最多十个）");
    jhwg_title2_->setFontSize(font_size);
    jhwg_title2_->setPosition(x + 125, y);
    jhwg_title2_->setHaveBox(false);
    jhwg_title2_->setVisible(false);
    jhwg_title2_->setTextColor(color_name);
    addChild(jhwg_title2_);


    for (int i = 0; i < ROLE_ACTIVE_MAGIC_COUNT; i++)
    {
            int x1 = x + i % 5 * 130;
            int y1 = y + 30 + i / 5 * 25;
            jh_waigong_[i] = std::make_shared<Button>();
            jh_waigong_[i]->setPosition(x1, y1);
            jh_waigong_[i]->setTextColor(color_ability1);
            jh_waigong_[i]->setHaveBox(false);
            jh_waigong_[i]->setVisible(false);
            all_value_menu_->addChild(jh_waigong_[i]);
    }

    x = x_ + 20;
    y = y_ + 480;
    wg_title_ = std::make_shared<TextBox>();
    wg_title_->setText("所学外功");
    wg_title_->setFontSize(25);
    wg_title_->setPosition(x - 10, y);
    wg_title_->setHaveBox(false);
    wg_title_->setVisible(false);
    wg_title_->setTextColor(color_name);
    addChild(wg_title_);

    waigong_menu_->setPosition(x, y);

    for (int i = 0; i < ROLE_MAGIC_COUNT; i++)
    {
        int x1 = x + i % 4 * 150;
        int y1 = y + 30 + i / 4 * 25;
        waigong_btn_[i] = std::make_shared<Button>();
        waigong_btn_[i]->setPosition(x1, y1);
        waigong_btn_[i]->setTextColor(color_ability1);
        waigong_btn_[i]->setHaveBox(false);
        waigong_btn_[i]->setVisible(false);
        waigong_btn_[i]->setTexture("background", -1, -1, 34);
        waigong_menu_->addChild(waigong_btn_[i]);
        waigong_value_[i] = std::make_shared<TextBox>();
        waigong_value_[i]->setPosition(x1 + 100, y1);
        waigong_value_[i]->setHaveBox(false);
        waigong_value_[i]->setVisible(false);
        all_value_menu_->addChild(waigong_value_[i]);
    }

}

void UIMagic::draw()
{
    if (role_ == nullptr)
    {
        //button_medicine_->setVisible(false);
        //button_detoxification_->setVisible(false);
        //button_leave_->setVisible(false);
        return;
    }

    TextureManager::getInstance()->renderTexture("head", role_->HeadID, x_ + 10, y_ + 20);

    auto font = Font::getInstance();

    auto select_color1 = [&](int v, int max_v) -> BP_Color
    {
        if (v >= max_v * 0.9)
        {
            return color_red;
        }
        else if (v >= max_v * 0.8)
        {
            return { 255, 165, 79, 255 };
        }
        else if (v >= max_v * 0.7)
        {
            return { 255, 255, 50, 255 };
        }
        else if (v < 0)
        {
            return color_purple;
        }
        return color_white;
    };

    auto select_color2 = [&](int v) -> BP_Color
    {
        if (v > 0)
        {
            return color_red;
        }
        if (v < 0)
        {
            return color_purple;
        }
        return color_white;
    };

    int font_size = 22;

    int x, y;

    x = x_ + 50;
    y = y_ + 20;

    font->draw("生命", font_size, x + 175, y + 50, color_ability1);
    font->draw(convert::formatString("%5d/", Event::getInstance()->getHp(role_)), font_size, x + 219, y + 50, color_white);
    font->draw(convert::formatString("%5d", Event::getInstance()->getMaxHp(role_)), font_size, x + 285, y + 50, color_white);
    font->draw("內力", font_size, x + 175, y + 75, color_ability1);

    BP_Color c = color_white;
    if (role_->MPType == 0)
    {
        c = color_purple;
    }
    else if (role_->MPType == 1)
    {
        c = color_magic;
    }

    font->draw(convert::formatString("%5d/", Event::getInstance()->getMaxMp(role_)), font_size, x + 219, y + 75, c);
    font->draw(convert::formatString("%5d", Event::getInstance()->getMaxMp(role_)), font_size, x + 285, y + 75, c);
    font->draw("體力", font_size, x + 175, y + 100, color_ability1);
    font->draw(convert::formatString("%5d/", role_->PhysicalPower), font_size, x + 219, y + 100, color_white);
    font->draw(convert::formatString("%5d", 100), font_size, x + 285, y + 100, color_white);

    x = x_ + 450;
    y = y_ + 20;

    font->draw("资质", font_size, x, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->IQ), font_size, x + 44, y + 50, select_color1(role_->IQ, Role::getMaxValue()->IQ));
    font->draw("富源", font_size, x, y + 75, color_ability1);
    font->draw(convert::formatString("%5d", role_->Fuyuan), font_size, x + 44, y + 75, select_color1(role_->Fuyuan, Role::getMaxValue()->Fuyuan));

    x = x_ + 20;
    y = y_ + 180;

    font->draw("攻击", font_size, x, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Attack), font_size, x + 44, y, select_color1(role_->Attack, Role::getMaxValue()->Attack));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddAttack(role_)), font_size, x + 104, y, color_seagreen);
    font->draw("防御", font_size, x + 200, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Defence), font_size, x + 244, y, select_color1(role_->Defence, Role::getMaxValue()->Defence));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddDefence(role_)), font_size, x + 304, y, color_seagreen);
    font->draw("轻功", font_size, x + 400, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Speed), font_size, x + 444, y, select_color1(role_->Speed, Role::getMaxValue()->Speed));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddSpeed(role_)), font_size, x + 504, y, color_seagreen);


    font->draw("醫療", font_size, x, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->Medicine), font_size, x + 44, y + 25, select_color1(role_->Medicine, Role::getMaxValue()->Medicine));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddMedicine(role_)), font_size, x + 104, y+25, color_seagreen);
    font->draw("抗毒", font_size, x + 200, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->AntiPoison), font_size, x + 244, y + 25, select_color1(role_->AntiPoison, Role::getMaxValue()->AntiPoison));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddAntiPoison(role_)), font_size, x + 304, y+25, color_seagreen);
    font->draw("用毒", font_size, x + 400, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->AttackWithPoison), font_size, x + 444, y + 25, select_color1(role_->AttackWithPoison, Role::getMaxValue()->AttackWithPoison));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddAWP(role_)), font_size, x + 504, y+25, color_seagreen);

    font->draw("拳掌", font_size, x, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->Fist), font_size, x + 34, y + 50, select_color1(role_->Fist, Role::getMaxValue()->Fist));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddFist(role_)), font_size, x + 60+34, y+50, color_seagreen);
    font->draw("御劍", font_size, x + 140, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->Sword), font_size, x + 140 + 34, y + 50, select_color1(role_->Sword, Role::getMaxValue()->Sword));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddSword(role_)), font_size, x + 140 + 60+34, y + 50, color_seagreen);
    font->draw("耍刀", font_size, x + 280, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->Knife), font_size, x + 280 + 34, y + 50, select_color1(role_->Knife, Role::getMaxValue()->Knife));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddKnife(role_)), font_size, x + 280 + 60 + 34, y + 50, color_seagreen);
    font->draw("特殊", font_size, x + 420, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->Unusual), font_size, x + 420 + 34, y + 50, select_color1(role_->Unusual, Role::getMaxValue()->Unusual));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddUnusual(role_)), font_size, x + 420 + 60 + 34, y + 50, color_seagreen);
    font->draw("暗器", font_size, x + 560, y + 50, color_ability1);
    font->draw(convert::formatString("%5d", role_->HiddenWeapon), font_size, x + 560 + 34, y + 50, select_color1(role_->HiddenWeapon, Role::getMaxValue()->HiddenWeapon));
    font->draw(convert::formatString("+%d", Event::getInstance()->getAddHiddenWeapon(role_)), font_size, x + 560 + 60+ 34, y + 50, color_seagreen);



    auto magic = Save::getInstance()->getRoleLearnedMagic(role_, role_->Gongti);
    if (magic) {
        jh_neigong_->setVisible(true);
        jh_neigong_->setText(convert::formatString("%s", magic->Name));
        jh_neigong_->setTextColor(color_red);
    }
    else {
        jh_neigong_->setVisible(true);
        jh_neigong_->setText("无");
        jh_neigong_->setTextColor(color_purple);
    }

    ng_title_->setVisible(true);
    tj_title_->setVisible(true);
    wg_title_->setVisible(true);
    jhng_title_->setVisible(true);
    jhtj_title_->setVisible(true);
    jhwg_title_->setVisible(true);
    jhwg_title2_->setVisible(true);

    all_value_menu_->setAllChildVisible(false);

    neigongs_.clear();
    tejis_.clear();
    waigongs_.clear();

    if (just_loaded_) {
        neigong_menu_->cleanOptions();
        teji_menu_->cleanOptions();
        waigong_menu_->cleanOptions();
    }

    int neigong_itr = 0;
    int teji_itr = 0;
    int waigong_itr = 0;
    int k = 0;

    for (auto i : role_->MagicID)
    {
        auto magic = Save::getInstance()->getMagic(i);
        std::string str = "__________";
        if (magic == nullptr) {
            if (neigong_itr < 10 && just_loaded_) {
                neigong_btn_[neigong_itr]->setVisible(false);
                neigong_menu_->setOptionActive(neigong_itr, -1);
                neigong_itr++;
            }else if(teji_itr<10 && just_loaded_){
                teji_btn_[teji_itr]->setVisible(false);
                teji_menu_->setOptionActive(teji_itr, -1);
                teji_itr++;
            }else if(just_loaded_){
                waigong_btn_[waigong_itr]->setVisible(false);
                waigong_menu_->setOptionActive(waigong_itr, -1);
                waigong_itr++;
            }
            continue;
        }
        if (magic->MagicType == 5)
        {
            if (role_->Gongti == k && just_loaded_) {
                neigong_menu_->setOptionActive(neigong_itr, 1);
            }
            else if (just_loaded_) {
                neigong_menu_->setOptionActive(neigong_itr, -1);
            }
            auto magic_r = std::make_shared<magic_record>();
            magic_r->magic = magic;
            magic_r->index = k;
            neigongs_.push_back(magic_r);
            str = convert::formatString("%s", magic->Name);
            neigong_btn_[neigong_itr]->setText(str);
            neigong_btn_[neigong_itr]->setVisible(true);
            str = convert::formatString("%3d", role_->getRoleShowLearnedMagicLevel(k));
            neigong_value_[neigong_itr]->setText(str);
            neigong_value_[neigong_itr]->setVisible(true);
            neigong_value_[neigong_itr]->setTextColor(role_->getRoleShowLearnedMagicLevel(k) > 2 ? color_red : color_purple);
            neigong_itr++;
        }
        else if(magic->MagicType == 6) {
            if (role_->zbtj == k && just_loaded_) {
                teji_menu_->setOptionActive(teji_itr, 1);
            }
            else if(just_loaded_){
                teji_menu_->setOptionActive(teji_itr, -1);
            }
            auto magic_r = std::make_shared<magic_record>();
            magic_r->magic = magic;
            magic_r->index = k;
            tejis_.push_back(magic_r);
            str = convert::formatString("%s", magic->Name);
            teji_btn_[teji_itr]->setText(str);
            teji_btn_[teji_itr]->setVisible(true);
            str = convert::formatString("%3d", role_->getRoleShowLearnedMagicLevel(k));
            teji_value_[teji_itr]->setText(str);
            teji_value_[teji_itr]->setVisible(true);
            teji_value_[teji_itr]->setTextColor(role_->getRoleShowLearnedMagicLevel(k) > 2 ? color_red : color_purple);
            teji_itr++;
        }
        else{
            if (role_->checkIsMagicActive(k) && just_loaded_) {
                waigong_menu_->setOptionActive(waigong_itr, 1);
            }
            else if (just_loaded_) {
                waigong_menu_->setOptionActive(waigong_itr, -1);
            }
            auto magic_r = std::make_shared<magic_record>();
            magic_r->magic = magic;
            magic_r->index = k;
            waigongs_.push_back(magic_r);
            str = convert::formatString("%s", magic->Name);
            waigong_btn_[waigong_itr]->setText(str);
            waigong_btn_[waigong_itr]->setVisible(true);
            str = convert::formatString("%3d", role_->getRoleShowLearnedMagicLevel(k));
            waigong_value_[waigong_itr]->setText(str);
            waigong_value_[waigong_itr]->setVisible(true);
            waigong_value_[waigong_itr]->setTextColor(role_->getRoleShowLearnedMagicLevel(k) > 9 ? color_red : color_purple);
            waigong_itr++;
        }
        k++;
    }

    neigong_menu_->setMagicRecords(neigongs_);
    teji_menu_->setMagicRecords(tejis_);
    waigong_menu_->setMagicRecords(waigongs_);
    neigong_menu_->setRole(role_);
    teji_menu_->setRole(role_);
    waigong_menu_->setRole(role_);

    if (neigong_menu_->getResult() == -2) {
        
    }
    else {
        int gongti = -1;
        for (int i = 0; i < neigong_menu_->active_nums_.size(); i++) {
            if (neigong_menu_->active_nums_[i]>0) {
                if(neigongs_[i])
                gongti = neigongs_[i]->index;
            }
            role_->Gongti = gongti;
        }
    }

    if (teji_menu_->getResult() == -2) {
    }
    else{
        int teji = -1;
        for (int i = 0; i < teji_menu_->active_nums_.size(); i++) {
            if (teji_menu_->active_nums_[i]>0) {
                if(tejis_[i])
                teji = tejis_[i]->index;
            }
            role_->zbtj = teji;
        }
    }

    if (waigong_menu_->getResult() == -2) {

    }
    else {
        int j = 0;
        for (int i = 0; i < waigong_menu_->active_nums_.size(); i++) {
            if (waigong_menu_->active_nums_[i]>0) {
                if(waigongs_[i])
                role_->JhMagic[j] = waigongs_[i]->index;
                j++;
            }
        }
        for (j; j < ROLE_ACTIVE_MAGIC_COUNT; j++) {
            role_->JhMagic[j] = -1;
        }
    }

    magic = Save::getInstance()->getRoleLearnedMagic(role_, role_->zbtj);
    if (magic) {
        jh_teji_->setVisible(true);
        jh_teji_->setText(convert::formatString("%s", magic->Name));
        jh_teji_->setTextColor(color_red); 
    }
    else {
        jh_teji_->setVisible(true);
        jh_teji_->setText("无");
        jh_teji_->setTextColor(color_purple);
    }

    waigong_itr = 0;
    for (auto i : role_->JhMagic)
    {
        auto magic = Save::getInstance()->getRoleLearnedMagic(role_, i);
        std::string str = "__________";
        if (magic)
        {
            str = convert::formatString("%s", magic->Name);
            jh_waigong_[waigong_itr]->setText(str);
            jh_waigong_[waigong_itr]->setVisible(true);
            waigong_itr++;
        }
        else {
            jh_waigong_[waigong_itr]->setVisible(false);
        }
    }
    
    just_loaded_ = false;
}

void UIMagic::onPressedOK()
{
    if (role_ == nullptr)
    {
        return;
    }

}

void UIMagic::setRoleName(std::string name)
{
    memset(role_->Name, '\0', sizeof(role_->Name));
    memcpy(role_->Name, name.c_str(), std::min(name.size(), sizeof(role_->Name)));
}

void UIMagic::setRole(Role* r) { 
    if (r != role_) {
        just_loaded_ = true;
    }
    role_ = r; 
}


MagicMenu::MagicMenu(RunNode* baseNode) {

    base_node_ = baseNode;
    magic_state_ = std::make_shared<MagicStateMenu>();
    magic_state_->setVisible(false);
    //base_node_->addChild(magic_state_);
}

void MagicMenu::draw() {
    int i = getActiveChildIndex();
    
    if (i >= 0 && magics_.size()>i) {
        if (magics_[i]) {
            int x, y;
            childs_[i]->getPosition(x, y);
            magic_state_->setPosition(x, y + 10);
            magic_state_->setRole(role_);
            magic_state_->setMagic(magics_[i]->magic);
            addIntoDrawTop(magic_state_);
        }
    }
    else {
        magic_state_->setVisible(false);
    }
}
