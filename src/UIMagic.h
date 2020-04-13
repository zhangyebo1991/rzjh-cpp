#pragma once
#include "RunNode.h"
#include "Button.h"
#include "Menu.h"
#include "Types.h"

class UIMagic :	public RunNode
{
public:
    UIMagic();
protected:

    std::shared_ptr<MultiMenu> neigong_menu_, teji_menu_, waigong_menu_;     //可多选的菜单
    
    std::shared_ptr<Menu> all_value_menu_;
    std::shared_ptr<Button> neigong_btn_[10], teji_btn_[10], waigong_btn_[ROLE_MAGIC_COUNT];    
    std::shared_ptr<TextBox> neigong_value_[10], teji_value_[10], waigong_value_[ROLE_MAGIC_COUNT];
    std::shared_ptr<TextBox> jh_neigong_, jh_teji_;
    std::shared_ptr<TextBox>  ng_title_, tj_title_, wg_title_, jhng_title_, jhtj_title_, jhwg_title_, jhwg_title2_;
    std::shared_ptr<TextBox> jh_waigong_[ROLE_ACTIVE_MAGIC_COUNT];

    struct magic_record {
        Magic* magic;
        int index;
    };
    std::vector<std::shared_ptr<magic_record>> neigongs_, tejis_, waigongs_;
   
    bool just_loaded_ = true;
    bool show_button_ = true;
    Role* role_ = nullptr;

public:

    virtual void draw() override;
    virtual void onPressedOK() override;
    void setShowButton(bool b) { show_button_ = b; }

    void setRole(Role* r);
    void setRoleName(std::string name);
    Role* getRole() { return role_; }
};

