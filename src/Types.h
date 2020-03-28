#pragma once
#include "Engine.h"
#include <cstdint>
#include <string>

using MAP_INT = int16_t;

#ifdef _MSC_VER
#define printf printf_s
//#define fopen fopen_s
#endif

template <typename T>
struct MapSquare
{
    MapSquare() {}
    MapSquare(int size) : MapSquare() { resize(size); }
    ~MapSquare()
    {
        if (data_)
        {
            delete[] data_;
        }
    }
    //���ᱣ��ԭʼ����
    void resize(int x)
    {
        if (data_)
        {
            delete[] data_;
        }
        data_ = new T[x * x];
        line_ = x;
    }

    T& data(int x, int y) { return data_[x + line_ * y]; }
    T& data(int x) { return data_[x]; }
    int size() { return line_; }
    int squareSize() { return line_ * line_; }
    void setAll(T v)
    {
        for (int i = 0; i < squareSize(); i++)
        {
            data_[i] = v;
        }
    }
    void copyTo(MapSquare* ms)
    {
        for (int i = 0; i < squareSize(); i++)
        {
            ms->data_[i] = data_[i];
        }
    }
    void copyFrom(MapSquare* ms)
    {
        for (int i = 0; i < squareSize(); i++)
        {
            data_[i] = ms->data_[i];
        }
    }

private:
    T* data_ = nullptr;
    int line_ = 0;
};

using MapSquareInt = MapSquare<MAP_INT>;

//ǰ������
struct Role;
struct Item;
struct Magic;
struct SubMapInfo;
struct Shop;
class Save;

enum
{
    SUBMAP_COORD_COUNT = 64,
    SUBMAP_LAYER_COUNT = 6,
    MAINMAP_COORD_COUNT = 480,
    SUBMAP_EVENT_COUNT = 200,    //����������¼���
    ITEM_IN_BAG_COUNT = 400,     //�����Ʒ��
    TEAMMATE_COUNT = 6,          //��������Ա��
};

enum
{
    ROLE_MAGIC_COUNT = 40,
    ROLE_TAKING_ITEM_COUNT = 4,

    MAX_MAGIC_LEVEL = 999,
    MAX_MAGIC_LEVEL_INDEX = 9,
};

enum
{
    SHOP_ITEM_COUNT = 36,
};

//��Ա�������ǿ�ͷ��д���������»��ߣ������ֱ�ӷ��ʲ��޸�

//�浵�еĽ�ɫ����
struct RoleSave
{
public:
	int ID; // ���
	int HeadID; // ͷ��/ս������
	int IncLife; // �����ɳ�
	int Fuyuan; // ��Ե
	char Name[20]; // ����
	char Nick[20]; // ���
	int Sexual; // �Ա�
	int Level; // �ȼ�
	int Exp; // ����
	int HP; // ����
	int MaxHP; // �������ֵ
	int Hurt; // ���˳̶�
	int Poison; // �ж��̶�
	int PhysicalPower; // ����
	int FightNum; // ս��ͼ���
	int Equip[5]; // װ��
	int Gongti; // ����
	int TeamState; // ����״̬
	int Angry; // ��ŭֵ
	int isRandomed; // ���ұ��
	int Moveable; // �ж�����
	int skillPoint; // ���ܵ�
	int ZhanLueAI; // ս��AI״̬
	int Impression; // ���
	int dtime; // �ж�ʱ��
	int difficulty; // �Ѷ�
	int Zhongcheng; // �ҳ϶�
	int reHurt; // ҩ��
	int MPType; // ��������
	int MP; // ����
	int MaxMP; // �������ֵ
	int Attack; // ������
	int Speed; // �Ṧ
	int Defence; // ������
	int Medicine; // ҽ��
	int Weiyong; // ��ȱ
	int Art; // ����
	int AntiPoison; // ����
	int Fist; // ȭ��
	int Sword; // ����
	int Knife; // ˣ��
	int Unusual; // �������
	int HiddenWeapon; // ��������
	int Knowledge; // ��ѧ��ʶ
	int Morality; // Ʒ��
	int AttackWithPoison; // ����
	int AttackTwice; // ���һ���
	int Fame; // ����
	int IQ; // ����
	int PracticeItem; // ������Ʒ
	int ExpForItem;	//�������� 
	int xiangxing; // ����
	int jiaoqing; // ����
	int Rtype; // �������
	int swq; // ��������
	int pdq; // Ʒ������
	int xxq; // ��������
	int jqq; // ��������
	int MenPai; // ��������
	int shifu; // ʦ��
	int scsx; // ʦ����λ
	int bssx; // ��ʦ˳��
	int Choushi[2]; // ��������
	int weizhi; // ��ǰλ��
	int nweizhi; // �ڲ�λ��
	int nfangxiang; // �ڲ�����
	int OnStatus; // ����״̬
	int lwq; // ��������
	int msq; // ڤ˼����
	int ldq; //�Ͷ�����
	int qtq; // ��������
	int lsweizhi; // ��ʱλ��
	int lsnweizhi; // �ڲ���ʱλ��
	int lsfangxiang; // �ڲ�����
	int Sx; // ����X����
	int Sy; // ����Y����
	int songshu; // ������
	int gongxian; // �ٸ�����
	int fuqi; // ����
	int age; // ����
	int weiyong1; // δ��1
	int weiyong2; // δ��2
	int weiyong3; // δ��3
	int btnum; // ս��ID
	int MagicID[40]; // �����书
	int MagicLevel[40]; // �����书�ȼ�
	int TakingItem[9]; // Я����Ʒ
	int TakingItemCount[9]; // Я����Ʒ����
	int JhMagic[10]; // �����书
	int LZhaoshi[40]; // ������ʽ
	int IsEvent; // �Ի��˵�����
	int TalkEvent; // �Ի��¼�
	int StateEvent; // ״̬�¼�
	int JoinEvent; // ����¼�
	int TestEvent; // �д��¼�
	int LearnEvent; // ѧϰ�¼�
	int unusedEvent1; // �¼���1
	int unusedEvent2; // �¼���2
	int unusedEvent3; // �¼���3
	int LeaveTime; // �������
	int LeaveEvent; // ����¼�
	int RandomNum1; // ���ֵ1
	int RandomNum2; // ���ֵ2
	int anjian; // ����
	int yishi; // ҽʦ
	int zbtj; // װ���ؼ�
	int huixue; // ��Ѫ
	int huinei; // ����
	int huiti; // ����
	int baozhao; // ����
	int peihe; // ���
	int wuxue; // ��ѧ
	int tupo; // ͻ��
	int lengjing; // �侲
	int baibian; // �ٱ�
	int poqi; // ����
	int zhaomen; // ����
	int bianhuan; // ���
	int fangong; // ����
	int qigong; // ����
	int yinggong; // Ӳ��
	int linghuo; // ���
	int xingqi; // ����
	int shenfa; // ��
	int gjql; // ����Ǳ��
	int fyql; // ����Ǳ��
	int qgql; // �ṦǱ��
	int qzql; // ȭ��Ǳ��
	int yjql; // ����Ǳ��
	int sdql; // ˣ��Ǳ��
	int qmql; // ����Ǳ��
	int aqql; // ����Ǳ��
	int gushou; // ����
	int tianmin; // ����
	int xingxiu; // ����
	int zhuanchang[5]; // ר��
	int texing[10]; // ����
	int menpaiContribution; // ���ɹ���
	int Unused[9]; // δʹ��

};

//ʵ�ʵĽ�ɫ���ݣ�����֮���ͨ����ս������
struct Role : public RoleSave
{
public:
    int Team;
    int FaceTowards, Dead, Step;
    int Pic, BattleSpeed;
    int ExpGot, Auto;
    int FightFrame[5] = { -1 };
    int FightingFrame;
    int Moved, Acted;
    int ActTeam;    //ѡ���ж���Ӫ 0-�ҷ���1-���ҷ�����Ч����ʱ��Ч

    int SelectedMagic;

    int Progress;

    struct ShowString
    {
        std::string Text;
        BP_Color Color;
        int Size;
    };
    //��ʾ����Ч��ʹ��
    struct ActionShowInfo
    {
        std::vector<ShowString> ShowStrings;
        int BattleHurt;
        int ProgressChange;
        int Effect;
        ActionShowInfo()
        {
            clear();
        }
        void clear()
        {
            ShowStrings.clear();
            BattleHurt = 0;
            ProgressChange = 0;
            Effect = -1;
        }
    };
    ActionShowInfo Show;

private:
    int X_, Y_;
    int prevX_, prevY_;

public:
    MapSquare<Role*>* position_layer_ = nullptr;
    void setRolePositionLayer(MapSquare<Role*>* l) { position_layer_ = l; }
    void setPosition(int x, int y);
    void setPositionOnly(int x, int y)
    {
        X_ = x;
        Y_ = y;
    }
    void setPrevPosition(int x, int y)
    {
        prevX_ = x;
        prevY_ = y;
    }
    void resetPosition() { setPosition(prevX_, prevY_); }
    int X() { return X_; }
    int Y() { return Y_; }

    //��role�ģ���ʾ����Ĳ����������书��
    int getRoleShowLearnedMagicLevel(int i);
    int getRoleMagicLevelIndex(int i);

    int getLearnedMagicCount();
    int getMagicLevelIndex(Magic* magic);
    int getMagicLevelIndex(int magic_id);
    int getMagicOfRoleIndex(Magic* magic);

    void limit();

    int learnMagic(Magic* magic);
    int learnMagic(int magic_id);

    bool isAuto() { return Auto != 0 || Team != 0; }

    void addShowString(std::string text, BP_Color color = { 255, 255, 255, 255 }, int size = 28) { Show.ShowStrings.push_back({ text, color, size }); }
    void clearShowStrings() { Show.ShowStrings.clear(); }

public:
    int AI_Action = 0;
    int AI_MoveX, AI_MoveY;
    int AI_ActionX, AI_ActionY;
    Magic* AI_Magic = nullptr;
    Item* AI_Item = nullptr;

public:
    int Network_Action;
    int Network_MoveX;
    int Network_MoveY;
    int Network_ActionX;
    int Network_ActionY;
    Magic* Network_Magic = nullptr;
    Item* Network_Item = nullptr;

public:
    int RealID = -1;
    bool Networked = false;
    bool Competing = false;

public:
    static Role* getMaxValue() { return &max_role_value_; }

private:
    static Role max_role_value_;
};

//�浵�е���Ʒ����
struct ItemSave
{
	int ID; // ���
	char Name[40]; // ��Ʒ��
	int ExpofMagic; // ��Ʒ�书����
	int SetNum; // ��װ��
	int BattleBattleEffect; // ս����Ч
	int AddSign; // ���ӱ�ǩ
	int needSex; // Ҫ���Ա�
	int rehurt; // �ָ�����
	int NeedEthics; // ��Ʒ��
	int NeedRepute; // ������
	int AddQianli; // ����Ǳ��ֵ
	int BattleNum; // ս����
	char Introduction[60]; // ��Ʒ˵��
	int MagicID; // �����书
	int HiddenWeaponEffectID; // �����������
	int User; // ʹ����
	int EquipType; // װ������
	int ShowIntroduction; // ��ʾ��Ʒ˵��
	int ItemType; // ����
	int Inventory; // �̵���
	int Price; // �ۼ�
	int EventNum; // �����¼�
	int AddHP; // ������
	int AddMaxHP; // ���������ֵ
	int AddPoison; // ���ж��ⶾ
	int AddPhysicalPower; // ������
	int ChangeMPType; // �ı���������
	int AddMP; // ������
	int AddMaxMP; // ���������ֵ
	int AddAttack; // �ӹ�����
	int AddSpeed; // ���Ṧ
	int AddDefence; // �ӷ�����
	int AddMedicine; // ��ҽ��
	int AddUsePoison; // ��ʹ��
	int AddArt; // �Ӽ���
	int AddAntiPoison; // �ӿ���
	int AddFist; // ��ȭ��
	int AddSword; // ������
	int AddKnife; // ��ˣ��
	int AddUnusual; // ���������
	int AddHiddenWeapon; // �Ӱ�������
	int AddKnowledge; // ����ѧ��ʶ
	int AddMorality; // ��Ʒ��
	int NeedHP; // ������
	int AddAttackWithPoison; // �ӹ�������
	int OnlySuitableRole; // ����������
	int NeedMPType; // ����������
	int NeedMP; // ������
	int NeedAttack; // �蹥����
	int NeedSpeed; // ���Ṧ
	int NeedUsePoison; // �趾��
	int NeedMedicine; // ��ҽ��
	int NeedArt; // �輼��
	int NeedFist; // ��ȭ��
	int NeedSword; // ������
	int NeedKnife; // ��ˣ��
	int NeedUnusual; // ���������
	int NeedHiddenWeapon; // �谵��
	int NeedIQ; // ������
	int NeedExp; // �辭��
	int Count; // ����
	int Rarity; // ϡ�ж�
	int NeedItem[5]; // ������Ʒ
	int NeedItemCount[5]; // ��Ҫ��Ʒ����
	int AddIQ; // ������
	int AddFuyuan; // �Ӹ�Դ
	int Unused[8]; // δʹ��
};

//ʵ�ʵ���Ʒ����
struct Item : ItemSave
{
public:
    static int MoneyItemID;
    static int CompassItemID;

public:
    bool isCompass();
};

//�浵�е���ѧ���ݣ����ʺ϶�Ӧ���룬��������С˵�е���ѧ����ħ����������ˣ�
struct MagicSave
{
	int ID; // ���
	char Name[20]; // ����
	int Wuyong; // ����
	int miji; // �ؼ�
	int NeedHP; // ��Ҫ����
	int MinDistance; // ��С����
	int bigami; // �Ƿ�ͼ��Ч
	int EventNum; // �¼�
	int SoundID; // ������Ч
	int MagicType; // �书����
	int EffectID; // �书����&��Ч
	int HurtType; // ��������
	int AttackAreaType; // ������Χ
	int NeedMP; // ��������
	int WithPoison; // �����ж�����
	int MinHurt; // ��С������
	int MaxHurt; // ��󹥻���
	int HurtModulus; // ����ϵ��
	int AttackModulus; // ����������
	int MPModulus; // ��������
	int SpeedModulus; // �Ṧ����
	int WeaponModulus; // ����ֵ����
	int Ismichuan; // �Ƿ��ش�
	int AddMpScale; // ����������
	int AddHpScale; // ����������
	int SelectDistance[10]; // �ƶ���Χ
	int AttackDistance[10]; // ɱ�˷�Χ
	int AddHP[3]; // ������
	int AddMP[3]; // ������
	int AddAttack[3]; // �ӹ���
	int AddDefence[3]; // �ӷ���
	int AddSpeed[3]; // ���Ṧ
	int MinPeg; // ��С��Ѩ����
	int MaxPeg; // ����Ѩ����
	int MinInjury; // ��С���˼���
	int MaxInjury; // ������˼���
	int AddMedcine; // ����ҽ��
	int AddUsePoi; // ���Ӷ���
	int AddArt; // ���Ӽ���
	int AddDefPoi; // ���ӿ���
	int AddFist; // ����ȭ��
	int AddSword; // ��������
	int AddKnife; // ����ˣ��
	int AddUnusual; // ��������
	int AddHidWeapon; // ���Ӱ���
	int BattleState;; // ״̬
	int NeedExp[3]; // �辭��
	int MaxLevel; // ��ߵȼ�
	char Introduction[120]; // ˵��
	int Zhaoshi[5]; // ��ʽ
	int Teshu[10]; // ����
	int Teshumod[10]; // ��������
	int unused[10]; // δʹ��
};

struct Magic : MagicSave
{
    int calNeedMP(int level_index) { return NeedMP * ((level_index + 2) / 2); }
    int calMaxLevelIndexByMP(int mp, int max_level);
};

//�浵�е��ӳ�������
//Լ����Scene��ʾ��Ϸ�����е�ĳ��Elementʵ������Map��ʾ�洢������
struct SubMapInfoSave
{
	int ID; // ���
	char Name[20]; // ����
	int ExitMusic; // ��������
	int EntranceMusic; // ��������
	int SubMapColor; // ������ɫ��
	int EntranceCondition; // ��������
	int MainEntranceX1; // �⾰���X1
	int MainEntranceY1; // �⾰���Y1
	int MainEntranceX2; // �⾰���X2
	int MainEntranceY2; // �⾰���Y2
	int EntranceX; // ���X
	int EntranceY; // ���Y
	int ExitX[3]; // ����X
	int ExitY[3]; // ����Y
	int Environment; // ����
	int Weiyong; // δ��
	int menpai; // ��������
	int inbattle; // ս����
	int zlwc; // �����䳡��
	int lwc; // ���䳡��
	int zcjg; // �ܲؾ�����
	int cjg; // �ؾ�����
	int lwcx[5]; // ���䳡X
	int lwcY[5]; // ���䳡Y
	int cjgx[5]; // �ؾ���X
	int cjgY[5]; // �ؾ���Y
	int bgskg; // �չ��ҿ���
	int bgsx; // �չ���X
	int bgsy; // �չ���Y
	int ldlkg; // ����¯����
	int ldlx; // ����¯X
	int ldly; // ����¯Y
	int bqckg; // ����������
	int bqcx; // ������X
	int bqcy; // ������Y
	int qizhix; // ����X
	int qizhiy; // ����Y
	int ldjd; // ��������
	int dzjd; // �������
	int fyjc; // �����ӳ�
	int fyss; // ������ʩ
	int addtk; // ����
	int addsl; // ʯ��
	int addmc; // ľ��
	int addsw; // ʳ��
	int addjt; // ��̿
	int addcy; // ��ҩ
	int addwm; // ��ľ
	int addyc; // ���
	int addxj; // ϡ��
	int addxt; // ����
	int lianjie[10]; // ����
	int Unused[10]; // δʹ��
};

//�浵�е�ʱ������
struct TimeSave
{
	int Jiazi; // ����
	int Year; // ��
	int Month; // ��
	int Day; // ��
	int Hour; // �r
};

//��Ч����
struct Ttexiao
{
public:
	int Type;
	int Value;
};

//�浵�е���ʽ����
struct ZhaoshiSave
{
	int ID; // ���
	int congshu; // ����
	int shunwei; // ˳λ
	char Name[40]; // ����
	int ygongji; // �Ƿ񹥻�
	int gongji; // �����ӳ�
	int yfangyu; // �Ƿ����
	int fangyu; // �����ӳ�
	char Introduction[90]; // ˵��
	Ttexiao texiao[24]; //89
};



//�浵�е���������
struct MenpaiSave
{
	int ID; // ���
	char Name[40]; // ����
	int jvdian; // �ݵ����
	int zongduo; // �ܶ�
	int zmr; // ������
	int dizi; // ���Ӹ���
	int shengwang; // ��������
	int shane; // �����ƶ�
	int tiekuang; // ����
	int shiliao; // ʯ��
	int muchai; // ľ��
	int shiwu; // ʳ��
	int jiaotan; // ��̿
	int caoyao; // ��ҩ
	int wumu; // ��ľ
	int yicao; // ���
	int xijin; // ϡ��
	int xuantie; // ����
	int addtiekuang; // ����+
	int addshiliao; // ʯ��+
	int addmuchai; // ľ��+
	int addshiwu; // ʳ��+
	int addjiaotan; // ��̿+
	int addcaoyao; // ��ҩ+
	int addwumu; // ��ľ+
	int addyicao; // ���+
	int addxijin; // ϡ��+
	int addxuantie; // ����+
	int neigong[20]; // �����ڹ�
	int guanxi[40]; // ���ɹ�ϵ
	int zhiwu[10]; // ����ְ��
	int kzq; // ��������
	int dzq; // �е�������
	int czsd; // ���ӳɳ��ٶ�
	int qizhi; // ����
	int mdizigrp; // �е�����ͼ
	int mdizipic; // �е���ͷ��
	int fdizigrp; // Ů������ͼ
	int fdizipic; // Ů����ͷ��
	int sexy; // �����Ա�
	int identity; // �������
	int endevent; // �����¼�
	int tongmeng; // ͬ��
	int israndomed; // ���ұ��
	int unuse2; // δ����2
	int unuse3; // δ����3
	int unuse4; // δ����4
};

//�浵�еı�ǩ���
struct SignType
{
	int num;
	char name[40]; //10
	char Introduction[120]; //41
};

//�浵�еı�ǩ����
struct RSignSave
{
	int ID; // ���
	char Name[40]; // ����
	int effert; // Ч��
	int TypeNum; // ���
	char Introduction[90]; // ˵��
	int beiyong; // ����
	int isshow; // �Ƿ�����
	Ttexiao texiao[24]; //92
};



//�����¼�����
struct SubMapEvent
{
    //event1Ϊ����������event2Ϊ��Ʒ������event3Ϊ��������
    MAP_INT CannotWalk, Index, Event1, Event2, Event3, CurrentPic, EndPic, BeginPic, PicDelay;

private:
    MAP_INT X_, Y_;

public:
	MAP_INT BeginTime, DuringTime, RecurrentTime, ActiveTime, IsActive, OverdueTime, OvderdueEvent;

public:
    MAP_INT X() { return X_; }
    MAP_INT Y() { return Y_; }
    void setPosition(int x, int y, SubMapInfo* submap_record);
    void setPic(int pic)
    {
        BeginPic = pic;
        CurrentPic = pic;
        EndPic = pic;
    }
};

//ʵ�ʵĳ�������
struct SubMapInfo : public SubMapInfoSave
{
public:
    MAP_INT& LayerData(int layer, int x, int y)
    {
        return layer_data_[layer][x + y * SUBMAP_COORD_COUNT];
    }

    MAP_INT& Earth(int x, int y)
    {
        return LayerData(0, x, y);
    }

    MAP_INT& Building(int x, int y)
    {
        return LayerData(1, x, y);
    }

    MAP_INT& Decoration(int x, int y)
    {
        return LayerData(2, x, y);
    }

    MAP_INT& EventIndex(int x, int y)
    {
        return LayerData(3, x, y);
    }

    MAP_INT& BuildingHeight(int x, int y)
    {
        return LayerData(4, x, y);
    }

    MAP_INT& DecorationHeight(int x, int y)
    {
        return LayerData(5, x, y);
    }

    SubMapEvent* Event(int x, int y)
    {
        int i = EventIndex(x, y);
        return Event(i);
    }

    SubMapEvent* Event(int i)
    {
        if (i < 0 || i >= SUBMAP_EVENT_COUNT)
        {
            return nullptr;
        }
        return &events_[i];
    }

private:
    MAP_INT layer_data_[SUBMAP_LAYER_COUNT][SUBMAP_COORD_COUNT * SUBMAP_COORD_COUNT];
    SubMapEvent events_[SUBMAP_EVENT_COUNT];
};

//�浵�е��̵�����
struct ShopSave
{
    int ItemID[SHOP_ITEM_COUNT], Total[SHOP_ITEM_COUNT];
};

//ʵ���̵�����
struct Shop : ShopSave
{
};

//ʵ����ʽ����
struct Zhaoshi : ZhaoshiSave
{
};

//ʵ����������
struct Menpai : MenpaiSave
{
};

//ʵ�ʱ�ǩ����
struct RSign : RSignSave
{
};