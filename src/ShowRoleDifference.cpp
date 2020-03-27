#include "ShowRoleDifference.h"
#include "Font.h"
#include "Save.h"
#include "convert.h"

ShowRoleDifference::ShowRoleDifference()
{
    head1_ = std::make_shared<Head>();
    head2_ = std::make_shared<Head>();
    addChild(head1_);
    addChild(head2_, 400, 0);
    //setText("�����ɹ�");
    setPosition(250, 180);
    setTextPosition(0, -30);
}

ShowRoleDifference::~ShowRoleDifference()
{
}

void ShowRoleDifference::draw()
{
    if (role1_ == nullptr || role2_ == nullptr) { return; }

    //if (black_screen_)
    //{
    Engine::getInstance()->fillColor({ 0, 0, 0, 128 }, 0, 0, -1, -1);
    //}
    head1_->setRole(role1_);
    head2_->setRole(role2_);
    head1_->setState(Press);
    head2_->setState(Press);
    if (role1_ && role2_ && role1_->ID == role2_->ID)
    {
        head1_->setRole(role2_);
        head1_->setPosition(200, 50);
        head2_->setRole(nullptr);
    }

    head1_->setVisible(show_head_);
    head2_->setVisible(show_head_);

    auto font = Font::getInstance();
    BP_Color color = { 255, 255, 255, 255 };
    const int font_size = 25;
    int x = x_, y = y_;

    std::string str;

    //showOneDifference(role1_->Name, "���� %-7s  -> %-7s", 20, color, x, y);
    showOneDifference(role1_->Level, "�ȼ� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Exp, "��� %7d   -> %7d", 20, color, x, y);

    showOneDifference(role1_->PhysicalPower, "�w�� %7d   -> %7d", 20, color, x, y);

    if (role1_->HP != role2_->HP || role1_->MaxHP != role2_->MaxHP)
    {
        str = convert::formatString("���� %%3d/%3d   -> %%3d/%3d", role1_->MaxHP, role2_->MaxHP);
        showOneDifference(role1_->HP, str, 20, color, x, y, 1);
    }
    if (role1_->MP != role2_->MP || role1_->MaxMP != role2_->MaxMP)
    {
        str = convert::formatString("���� %%3d/%3d   -> %%3d/%3d", role1_->MaxMP, role2_->MaxMP);
        showOneDifference(role1_->MP, str, 20, color, x, y, 1);
    }

    showOneDifference(role1_->Attack, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Defence, "���R %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Speed, "�p�� %7d   -> %7d", 20, color, x, y);

    showOneDifference(role1_->Medicine, "�t�� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->AttackWithPoison, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Art, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->AntiPoison, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->AttackWithPoison, "���� %7d   -> %7d", 20, color, x, y);

    showOneDifference(role1_->Fist, "ȭ�� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Sword, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Knife, "ˣ�� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Unusual, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->HiddenWeapon, "���� %7d   -> %7d", 20, color, x, y);

    showOneDifference(role1_->Poison, "�ж� %7d   -> %7d", 20, color, x, y);

    showOneDifference(role1_->Morality, "���� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->Fame, "�� %7d   -> %7d", 20, color, x, y);
    showOneDifference(role1_->IQ, "�Y�| %7d   -> %7d", 20, color, x, y);

    str = "�������{��";
    if (role2_->MPType == 0) { str = "�����"; }
    if (role2_->MPType == 1) { str = "�����"; }
    showOneDifference(role1_->MPType, str, 20, color, x, y);
    showOneDifference(role1_->AttackTwice, "�p��", 20, color, x, y);

    for (int i = 0; i < ROLE_MAGIC_COUNT; i++)
    {
        if (role2_->MagicID[i] > 0
            && (role1_->MagicID[i] <= 0 || role1_->getRoleShowLearnedMagicLevel(i) != role2_->getRoleShowLearnedMagicLevel(i)))
        {
            str = convert::formatString("��W%sĿǰ�ޞ�%d",
                Save::getInstance()->getMagic(role2_->MagicID[i])->Name, role2_->getRoleShowLearnedMagicLevel(i));
            showOneDifference(role1_->MagicLevel[i], str, 20, color, x, y);
        }
    }

    if (y == y_)
    {
        Font::getInstance()->draw("�o����Ч��", 20, x, y, color);
    }
    //showOneDifference(role1_->Level, "���� %7d   -> %7d", 20, color, x, y);
    TextBox::draw();
}
