#pragma once
#include "Head.h"
#include "Menu.h"
#include "UIItem.h"

class BattleScene;

class ZhaoshiStateMenu;

//注意，AI选择行动的行为也在这里面
class BattleActionMenu : public MenuText
{
public:
    BattleActionMenu(BattleScene* b);
    virtual ~BattleActionMenu();

    //virtual void onEntrance() override;

    std::shared_ptr<Button> button_medicine_, button_detoxification_, button_leave_;
    std::shared_ptr<Menu> state_menu_;

    Role* role_ = nullptr;
    void setRole(Role* r);
    int runAsRole(Role* r)
    {
        setRole(r);
        return run();
    }

    void dealEvent(BP_Event& e) override;

    BattleScene* battle_scene_ = nullptr;

    int autoSelect(Role* role);

    MapSquareInt distance_layer_;

    void calDistanceLayer(int x, int y, int max_step = 64);

    struct AIAction
    {
        int Action;
        double point = 0;
        int MoveX, MoveY;
        int ActionX, ActionY;
        Magic* magic = nullptr;
        Zhaoshi* zhaoshi = nullptr;
        Item* item = nullptr;
    };

    void setAIActionToRole(AIAction& aa, Role* role)
    {
        role->AI_Action = aa.Action;
        role->AI_MoveX = aa.MoveX;
        role->AI_MoveY = aa.MoveY;
        role->AI_ActionX = aa.ActionX;
        role->AI_ActionY = aa.ActionY;
        role->AI_Magic = aa.magic;
        role->AI_Item = aa.item;
        role->AI_Zhaoshi = aa.zhaoshi;
    }

    void getFarthestToAll(Role* role, std::vector<Role*> roles, int& x, int& y);
    void getNearestPosition(int x0, int y0, int& x, int& y);
    Role* getNearestRole(Role* role, std::vector<Role*> roles);
    void calAIActionNearest(Role* r2, AIAction& aa, Role* r_temp = nullptr);
    int calNeedActionDistance(AIAction& aa);
};

class BattleMagicMenu : public MenuText
{
public:
    BattleMagicMenu() {}
    virtual ~BattleMagicMenu() {}

    //virtual void onEntrance() override;

    Role* role_ = nullptr;
    Magic* magic_ = nullptr;
    void setRole(Role* r);
    int runAsRole(Role* r)
    {
        setRole(r);
        return run();
    }

    Magic* getMagic() { return magic_; }
    void onEntrance() override;

    virtual void onPressedOK() override;
    virtual void onPressedCancel() override
    {
        magic_ = nullptr;
        exitWithResult(-1);
    }
};

class BattleZhaoshiMenu : public MenuText
{
public:
    BattleZhaoshiMenu() {}
    virtual ~BattleZhaoshiMenu() {}

    //virtual void onEntrance() override;

    Role* role_ = nullptr;
    Magic* magic_ = nullptr;
    Zhaoshi* zhaoshi_ = nullptr;

    std::vector<Zhaoshi*> zhaoshis_;

    int current_ac_id = -1;

    std::shared_ptr<ZhaoshiStateMenu> zhaoshi_state_ = nullptr;

    void setRole(Role* r);
    int runAsRole(Role* r)
    {
        setRole(r);
        return run();
    }

    //void setZhaoshis(std::vector<Zhaoshi> zhaoshis, std::vector<std::string> items);

    void setMagic(Magic* magic) { magic_ = magic; }

    Zhaoshi* getZhaoshi() { return zhaoshi_; }
    void onEntrance() override;
    void draw() override;

    virtual void onPressedOK() override;
    virtual void onPressedCancel() override
    {
        zhaoshi_ = nullptr;
        exitWithResult(-1);
    }
};

class BattleItemMenu : public UIItem
{
public:
    BattleItemMenu();
    virtual ~BattleItemMenu() {}

private:
    Role* role_ = nullptr;

public:
    void setRole(Role* r) { role_ = r; }
    Role* getRole() { return role_; }

    void addItem(Item* item, int count);

    void onEntrance() override;

    std::vector<Item*> getAvaliableItems();
    static std::vector<Item*> getAvaliableItems(Role* role, int type);
};

class BattleStateMenu : public Menu
{
public:
    BattleStateMenu();
    virtual ~BattleStateMenu() {}

private:
    
    std::shared_ptr<TextBox> txt_name_, zz_name_, txt_qf_, txt_yg_, txt_lh_, txt_xq_, txt_sf_,
        txt_ff_, txt_zy_, txt_jz_, txt_js_, txt_sd_;
    std::shared_ptr<TextBox> txt_qf_value_, txt_yg_value_, txt_lh_value_, txt_xq_value_, txt_sf_value_, 
        txt_ff_value_, txt_zy_value_, txt_jz_value_, txt_js_value_, txt_sd_value_;
    std::shared_ptr<TextBox> zz_value_[5];
    std::shared_ptr<Menu> state_menu_;

    Role* role_ = nullptr;

public:

    virtual void draw() override;
    void setRole(Role* r);
    Role* getRole() { return role_; }

};


class ZhaoshiStateMenu : public Menu
{
public:
    ZhaoshiStateMenu();
    virtual ~ZhaoshiStateMenu() {}

private:


    std::shared_ptr<Menu> state_menu_;

    std::shared_ptr<TextBox> txt_name_;

    Role* role_ = nullptr;
    Magic* magic_ = nullptr;
    Zhaoshi* zhaoshi_ = nullptr;

public:

    void setRole(Role* r) { role_ = r; }
    void setMagic(Magic* magic) { magic_ = magic; }
    void setZhaoshi(Zhaoshi* zhaoshi);

    Role* getRole() { return role_; }

};

class MagicStateMenu : public Menu
{
public:
    MagicStateMenu();
    virtual ~MagicStateMenu() {}

private:


    std::shared_ptr<Menu> state_menu_;

    std::shared_ptr<TextBox> txt_name_;

    Role* role_ = nullptr;
    Magic* magic_ = nullptr;

public:

    void setRole(Role* r) { role_ = r; }
    void setMagic(Magic* magic);
    void setZhaoshi(Zhaoshi* zhaoshi);

    Role* getRole() { return role_; }

};