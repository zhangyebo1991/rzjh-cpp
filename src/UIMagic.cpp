#include "UIMagic.h"
#include "Font.h"
#include "Convert.h"
#include "Save.h"


void UIMagic::draw()
{
    if (role_ == nullptr || !show_button_)
    {
        //button_medicine_->setVisible(false);
        //button_detoxification_->setVisible(false);
        //button_leave_->setVisible(false);
    }

    if (role_)
    {

    }
    else
    {
        return;
    }
    TextureManager::getInstance()->renderTexture("head", role_->HeadID, x_ + 10, y_ + 20);

    auto font = Font::getInstance();
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

    x = x_ + 200;
    y = y_ + 50;

    font->draw("生命", font_size, x + 175, y + 50, color_ability1);
    font->draw(convert::formatString("%5d/", role_->HP), font_size, x + 219, y + 50, color_white);
    font->draw(convert::formatString("%5d", role_->MaxHP), font_size, x + 285, y + 50, color_white);
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

    font->draw(convert::formatString("%5d/", role_->MP), font_size, x + 219, y + 75, c);
    font->draw(convert::formatString("%5d", role_->MaxMP), font_size, x + 285, y + 75, c);
    font->draw("體力", font_size, x + 175, y + 100, color_ability1);
    font->draw(convert::formatString("%5d/", role_->PhysicalPower), font_size, x + 219, y + 100, color_white);
    font->draw(convert::formatString("%5d", 100), font_size, x + 285, y + 100, color_white);

    x = x_ + 20;
    y = y_ + 180;

    font->draw("资质", font_size, x, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->IQ), font_size, x + 44, y, select_color1(role_->Attack, Role::getMaxValue()->Attack));
    font->draw("富源", font_size, x + 100, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Fuyuan), font_size, x + 144, y, select_color1(role_->Defence, Role::getMaxValue()->Defence));

    x = x_ + 20;
    y = y_ + 190;

    //font->draw("攻擊", font_size, x, y, color_ability1);
    //font->draw(convert::formatString("%5d", role_->Attack), font_size, x + 44, y, select_color1(role_->Attack, Role::getMaxValue()->Attack));
    font->draw("防禦", font_size, x + 200, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Defence), font_size, x + 244, y, select_color1(role_->Defence, Role::getMaxValue()->Defence));
    font->draw("輕功", font_size, x + 400, y, color_ability1);
    font->draw(convert::formatString("%5d", role_->Speed), font_size, x + 444, y, select_color1(role_->Speed, Role::getMaxValue()->Speed));


    font->draw("醫療", font_size, x, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->Medicine), font_size, x + 44, y + 25, select_color1(role_->Medicine, Role::getMaxValue()->Medicine));
    font->draw("抗毒", font_size, x + 200, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->AntiPoison), font_size, x + 244, y + 25, select_color1(role_->AntiPoison, Role::getMaxValue()->AntiPoison));
    font->draw("用毒", font_size, x + 400, y + 25, color_ability1);
    font->draw(convert::formatString("%5d", role_->AttackWithPoison), font_size, x + 444, y + 25, select_color1(role_->AttackWithPoison, Role::getMaxValue()->AttackWithPoison));

    x = x_ + 20;
    y = y_ + 270;
    font->draw("技能", 25, x - 10, y, color_name);

    font->draw("拳掌", font_size, x, y + 30, color_ability1);
    font->draw(convert::formatString("%5d", role_->Fist), font_size, x + 44, y + 30, select_color1(role_->Fist, Role::getMaxValue()->Fist));
    font->draw("御劍", font_size, x, y + 55, color_ability1);
    font->draw(convert::formatString("%5d", role_->Sword), font_size, x + 44, y + 55, select_color1(role_->Sword, Role::getMaxValue()->Sword));
    font->draw("耍刀", font_size, x, y + 80, color_ability1);
    font->draw(convert::formatString("%5d", role_->Knife), font_size, x + 44, y + 80, select_color1(role_->Knife, Role::getMaxValue()->Knife));
    font->draw("特殊", font_size, x, y + 105, color_ability1);
    font->draw(convert::formatString("%5d", role_->Unusual), font_size, x + 44, y + 105, select_color1(role_->Unusual, Role::getMaxValue()->Unusual));
    font->draw("暗器", font_size, x, y + 130, color_ability1);
    font->draw(convert::formatString("%5d", role_->HiddenWeapon), font_size, x + 44, y + 130, select_color1(role_->HiddenWeapon, Role::getMaxValue()->HiddenWeapon));

    x = x_ + 220;
    y = y_ + 270;
    font->draw("激活武学", 25, x - 10, y, color_name);
    for (int i = 0; i < ROLE_ACTIVE_MAGIC_COUNT; i++)
    {
        auto magic = Save::getInstance()->getRoleActiveMagic(role_, i);
        std::string str = "__________";
        if (magic)
        {
            int x1 = x + i % 2 * 200;
            int y1 = y + 30 + i / 2 * 25;
            str = convert::formatString("%s", magic->Name);
            font->draw(str, font_size, x1, y1, color_ability1);
            str = convert::formatString("%3d", Save::getInstance()->getRoleActiveMagicLevel(role_, i));
            font->draw(str, font_size, x1 + 100, y1, Save::getInstance()->getRoleActiveMagicLevel(role_, i) ? color_red : color_purple);
        }
        else
        {
            int x1 = x + i % 2 * 200;
            int y1 = y + 30 + i / 2 * 25;
            font->draw("__________", font_size, x1, y1, color_ability1);
        }
    }

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