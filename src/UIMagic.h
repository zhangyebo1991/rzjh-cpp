#pragma once
#include "RunNode.h"
#include "Button.h"
#include "Menu.h"
#include "Types.h"

class UIMagic :	public RunNode
{
protected:
    std::shared_ptr<Button> button_medicine_, button_detoxification_, button_leave_;
    std::shared_ptr<Menu> menu_;

    bool show_button_ = true;
    Role* role_ = nullptr;

public:

    virtual void draw() override;
    virtual void onPressedOK() override;
    void setShowButton(bool b) { show_button_ = b; }

    void setRole(Role* r) { role_ = r; }
    void setRoleName(std::string name);
    Role* getRole() { return role_; }
};

