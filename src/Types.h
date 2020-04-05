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
    //不会保留原始数据
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

//前置声明
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
    SUBMAP_EVENT_COUNT = 200,    //单场景最大事件数
    ITEM_IN_BAG_COUNT = 400,     //最大物品数
    TEAMMATE_COUNT = 6,          //最大队伍人员数
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

//成员函数若是开头大写，并且无下划线，则可以直接访问并修改

//存档中的角色数据
struct RoleSave
{
public:
	int ID; // 编号
	int HeadID; // 头像/战斗代号
	int IncLife; // 生命成长
	int Fuyuan; // 福缘
	char Name[20]; // 姓名
	char Nick[20]; // 外号
	int Sexual; // 性别
	int Level; // 等级
	int Exp; // 经验
	int HP; // 生命
	int MaxHP; // 生命最大值
	int Hurt; // 受伤程度
	int Poison; // 中毒程度
	int PhysicalPower; // 体力
	int FightNum; // 战斗图编号
	int Equip[5]; // 装备
	int Gongti; // 功体
	int TeamState; // 队伍状态
	int Angry; // 愤怒值
	int isRandomed; // 查找标记
	int Moveable; // 行动能力
	int skillPoint; // 技能点
	int ZhanLueAI; // 战略AI状态
	int Impression; // 外观
	int dtime; // 行动时间
	int difficulty; // 难度
	int Zhongcheng; // 忠诚度
	int reHurt; // 药物
	int MPType; // 内力性质
	int MP; // 内力
	int MaxMP; // 内力最大值
	int Attack; // 攻击力
	int Speed; // 轻功
	int Defence; // 防御力
	int Medicine; // 医疗
	int Weiyong; // 暂缺
	int Art; // 技艺
	int AntiPoison; // 抗毒
	int Fist; // 拳掌
	int Sword; // 御剑
	int Knife; // 耍刀
	int Unusual; // 特殊兵器
	int HiddenWeapon; // 暗器技巧
	int Knowledge; // 武学常识
	int Morality; // 品德
	int AttackWithPoison; // 毒术
	int AttackTwice; // 左右互搏
	int Fame; // 声望
	int IQ; // 资质
	int PracticeItem; // 修练物品
	int ExpForItem;	//练出点数 
	int xiangxing; // 相性
	int jiaoqing; // 交情
	int Rtype; // 人物类别
	int swq; // 声望倾向
	int pdq; // 品德倾向
	int xxq; // 相性倾向
	int jqq; // 交情倾向
	int MenPai; // 所属门派
	int shifu; // 师父
	int scsx; // 师承序位
	int bssx; // 拜师顺序
	int Choushi[2]; // 仇视门派
	int weizhi; // 当前位置
	int nweizhi; // 内部位置
	int nfangxiang; // 内部方向
	int OnStatus; // 人物状态
	int lwq; // 练武倾向
	int msq; // 冥思倾向
	int ldq; //劳动倾向
	int qtq; // 其他倾向
	int lsweizhi; // 临时位置
	int lsnweizhi; // 内部临时位置
	int lsfangxiang; // 内部方向
	int Sx; // 场景X坐标
	int Sy; // 场景Y坐标
	int songshu; // 送书标记
	int gongxian; // 官府贡献
	int fuqi; // 夫妻
	int age; // 年龄
	int weiyong1; // 未用1
	int weiyong2; // 未用2
	int weiyong3; // 未用3
	int btnum; // 战场ID
	int MagicID[40]; // 所会武功
	int MagicLevel[40]; // 所会武功等级
	int TakingItem[9]; // 携带物品
	int TakingItemCount[9]; // 携带物品数量
	int JhMagic[10]; // 激活武功
	int LZhaoshi[40]; // 所会招式
	int IsEvent; // 对话菜单开关
	int TalkEvent; // 对话事件
	int StateEvent; // 状态事件
	int JoinEvent; // 入队事件
	int TestEvent; // 切磋事件
	int LearnEvent; // 学习事件
	int unusedEvent1; // 事件池1
	int unusedEvent2; // 事件池2
	int unusedEvent3; // 事件池3
	int LeaveTime; // 离队期限
	int LeaveEvent; // 离队事件
	int RandomNum1; // 随机值1
	int RandomNum2; // 随机值2
	int anjian; // 暗箭
	int yishi; // 医师
	int zbtj; // 装备特技
	int huixue; // 回血
	int huinei; // 回内
	int huiti; // 回体
	int baozhao; // 暴躁
	int peihe; // 配合
	int wuxue; // 武学
	int tupo; // 突破
	int lengjing; // 冷静
	int baibian; // 百变
	int poqi; // 破气
	int zhaomen; // 罩门
	int bianhuan; // 变幻
	int fangong; // 反攻
	int qigong; // 气功
	int yinggong; // 硬功
	int linghuo; // 灵活
	int xingqi; // 行气
	int shenfa; // 身法
	int gjql; // 攻击潜力
	int fyql; // 防御潜力
	int qgql; // 轻功潜力
	int qzql; // 拳掌潜力
	int yjql; // 御剑潜力
	int sdql; // 耍刀潜力
	int qmql; // 奇门潜力
	int aqql; // 暗器潜力
	int gushou; // 固守
	int tianmin; // 天命
	int xingxiu; // 星宿
	int zhuanchang[5]; // 专长
	int texing[10]; // 特性
	int menpaiContribution; // 门派贡献
	int Unused[9]; // 未使用

};

//实际的角色数据，基类之外的通常是战斗属性
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
    int ActTeam;    //选择行动阵营 0-我方，1-非我方，画效果层时有效

	int qf_, yg_, lh_, xq_, sf_, ff_, zy_, jz_, js_, sd_;

    int SelectedMagic;

    int Progress;

    struct ShowString
    {
        std::string Text;
        BP_Color Color;
        int Size;
    };
    //显示文字效果使用
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

    //带role的，表示后面的参数是人物武功栏
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

//存档中的物品数据
struct ItemSave
{
	int ID; // 编号
	char Name[40]; // 物品名
	int ExpofMagic; // 物品武功经验
	int SetNum; // 套装号
	int BattleBattleEffect; // 战斗特效
	int AddSign; // 增加标签
	int needSex; // 要求性别
	int rehurt; // 恢复伤势
	int NeedEthics; // 需品德
	int NeedRepute; // 需声望
	int AddQianli; // 增加潜力值
	int BattleNum; // 战场号
	char Introduction[60]; // 物品说明
	int MagicID; // 练出武功
	int HiddenWeaponEffectID; // 暗器动画编号
	int User; // 使用人
	int EquipType; // 装备类型
	int ShowIntroduction; // 显示物品说明
	int ItemType; // 类型
	int Inventory; // 商店库存
	int Price; // 售价
	int EventNum; // 调用事件
	int AddHP; // 加生命
	int AddMaxHP; // 加生命最大值
	int AddPoison; // 加中毒解毒
	int AddPhysicalPower; // 加体力
	int ChangeMPType; // 改变内力性质
	int AddMP; // 加内力
	int AddMaxMP; // 加内力最大值
	int AddAttack; // 加攻击力
	int AddSpeed; // 加轻功
	int AddDefence; // 加防御力
	int AddMedicine; // 加医疗
	int AddUsePoison; // 加使毒
	int AddArt; // 加技艺
	int AddAntiPoison; // 加抗毒
	int AddFist; // 加拳掌
	int AddSword; // 加御剑
	int AddKnife; // 加耍刀
	int AddUnusual; // 加特殊兵器
	int AddHiddenWeapon; // 加暗器技巧
	int AddKnowledge; // 加武学常识
	int AddMorality; // 加品德
	int NeedHP; // 需生命
	int AddAttackWithPoison; // 加攻击带毒
	int OnlySuitableRole; // 仅修炼人物
	int NeedMPType; // 需内力性质
	int NeedMP; // 需内力
	int NeedAttack; // 需攻击力
	int NeedSpeed; // 需轻功
	int NeedUsePoison; // 需毒术
	int NeedMedicine; // 需医疗
	int NeedArt; // 需技艺
	int NeedFist; // 需拳掌
	int NeedSword; // 需御剑
	int NeedKnife; // 需耍刀
	int NeedUnusual; // 需特殊兵器
	int NeedHiddenWeapon; // 需暗器
	int NeedIQ; // 需资质
	int NeedExp; // 需经验
	int Count; // 数量
	int Rarity; // 稀有度
	int NeedItem[5]; // 所需物品
	int NeedItemCount[5]; // 需要物品数量
	int AddIQ; // 加资质
	int AddFuyuan; // 加富源
	int Unused[8]; // 未使用
};

//实际的物品数据
struct Item : ItemSave
{
public:
    static int MoneyItemID;
    static int CompassItemID;

public:
    bool isCompass();
};

//存档中的武学数据（无适合对应翻译，而且武侠小说中的武学近于魔法，暂且如此）
struct MagicSave
{
	int ID; // 编号
	char Name[20]; // 名称
	int Wuyong; // 无用
	int miji; // 秘籍
	int NeedHP; // 需要生命
	int MinDistance; // 最小距离
	int bigami; // 是否单图特效
	int EventNum; // 事件
	int SoundID; // 出招音效
	int MagicType; // 武功类型
	int EffectID; // 武功动画&音效
	int HurtType; // 内力类型
	int AttackAreaType; // 攻击范围
	int NeedMP; // 消耗内力
	int WithPoison; // 敌人中毒点数
	int MinHurt; // 最小攻击力
	int MaxHurt; // 最大攻击力
	int HurtModulus; // 威力系数
	int AttackModulus; // 攻击力比重
	int MPModulus; // 内力比重
	int SpeedModulus; // 轻功比重
	int WeaponModulus; // 兵器值比重
	int Ismichuan; // 是否秘传
	int AddMpScale; // 加内力比例
	int AddHpScale; // 加生命比例
	int SelectDistance[10]; // 移动范围
	int AttackDistance[10]; // 杀伤范围
	int AddHP[3]; // 加生命
	int AddMP[3]; // 加内力
	int AddAttack[3]; // 加攻击
	int AddDefence[3]; // 加防御
	int AddSpeed[3]; // 加轻功
	int MinPeg; // 最小封穴几率
	int MaxPeg; // 最大封穴几率
	int MinInjury; // 最小内伤几率
	int MaxInjury; // 最大内伤几率
	int AddMedcine; // 增加医疗
	int AddUsePoi; // 增加毒术
	int AddArt; // 增加技艺
	int AddDefPoi; // 增加抗毒
	int AddFist; // 增加拳掌
	int AddSword; // 增加御剑
	int AddKnife; // 增加耍刀
	int AddUnusual; // 增加特殊
	int AddHidWeapon; // 增加暗器
	int BattleState;; // 状态
	int NeedExp[3]; // 需经验
	int MaxLevel; // 最高等级
	char Introduction[120]; // 说明
	int Zhaoshi[5]; // 招式
	int Teshu[10]; // 特殊
	int Teshumod[10]; // 特殊类型
	int unused[10]; // 未使用
};

struct Magic : MagicSave
{
    int calNeedMP(int level_index) { return NeedMP * ((level_index + 2) / 2); }
    int calMaxLevelIndexByMP(int mp, int max_level);
};

//存档中的子场景数据
//约定：Scene表示游戏中运行的某个Element实例，而Map表示存储的数据
struct SubMapInfoSave
{
	int ID; // 编号
	char Name[20]; // 名称
	int ExitMusic; // 出门音乐
	int EntranceMusic; // 进门音乐
	int SubMapColor; // 场景调色板
	int EntranceCondition; // 进入条件
	int MainEntranceX1; // 外景入口X1
	int MainEntranceY1; // 外景入口Y1
	int MainEntranceX2; // 外景入口X2
	int MainEntranceY2; // 外景入口Y2
	int EntranceX; // 入口X
	int EntranceY; // 入口Y
	int ExitX[3]; // 出口X
	int ExitY[3]; // 出口Y
	int Environment; // 环境
	int Weiyong; // 未用
	int menpai; // 所属门派
	int inbattle; // 战斗中
	int zlwc; // 总练武场数
	int lwc; // 练武场数
	int zcjg; // 总藏经阁数
	int cjg; // 藏经阁数
	int lwcx[5]; // 练武场X
	int lwcY[5]; // 练武场Y
	int cjgx[5]; // 藏经阁X
	int cjgY[5]; // 藏经阁Y
	int bgskg; // 闭关室开关
	int bgsx; // 闭关室X
	int bgsy; // 闭关室Y
	int ldlkg; // 炼丹炉开关
	int ldlx; // 炼丹炉X
	int ldly; // 炼丹炉Y
	int bqckg; // 兵器场开关
	int bqcx; // 兵器场X
	int bqcy; // 兵器场Y
	int qizhix; // 旗帜X
	int qizhiy; // 旗帜Y
	int ldjd; // 炼丹进度
	int dzjd; // 锻造进度
	int fyjc; // 防御加成
	int fyss; // 防御设施
	int addtk; // 铁矿
	int addsl; // 石料
	int addmc; // 木材
	int addsw; // 食物
	int addjt; // 焦炭
	int addcy; // 草药
	int addwm; // 乌木
	int addyc; // 异草
	int addxj; // 稀金
	int addxt; // 玄铁
	int lianjie[10]; // 连接
	int Unused[10]; // 未使用
};

//存档中的时间数据
struct TimeSave
{
	int Jiazi; // 甲子
	int Year; // 年
	int Month; // 月
	int Day; // 日
	int Hour; // 時
};

//特效数据
struct Ttexiao
{
public:
	int Type;
	int Value;
};

//存档中的招式数据
struct ZhaoshiSave
{
	int ID; // 编号
	int congshu; // 从属
	int shunwei; // 顺位
	char Name[40]; // 名称
	int ygongji; // 是否攻击
	int gongji; // 攻击加成
	int yfangyu; // 是否防御
	int fangyu; // 防御加成
	char Introduction[90]; // 说明
	Ttexiao texiao[24]; //89
};



//存档中的门派数据
struct MenpaiSave
{
	int ID; // 编号
	char Name[40]; // 名称
	int jvdian; // 据点个数
	int zongduo; // 总舵
	int zmr; // 掌门人
	int dizi; // 弟子个数
	int shengwang; // 门派声望
	int shane; // 门派善恶
	int tiekuang; // 铁矿
	int shiliao; // 石料
	int muchai; // 木材
	int shiwu; // 食物
	int jiaotan; // 焦炭
	int caoyao; // 草药
	int wumu; // 乌木
	int yicao; // 异草
	int xijin; // 稀金
	int xuantie; // 玄铁
	int addtiekuang; // 铁矿+
	int addshiliao; // 石料+
	int addmuchai; // 木材+
	int addshiwu; // 食物+
	int addjiaotan; // 焦炭+
	int addcaoyao; // 草药+
	int addwumu; // 乌木+
	int addyicao; // 异草+
	int addxijin; // 稀金+
	int addxuantie; // 玄铁+
	int neigong[20]; // 门派内功
	int guanxi[40]; // 门派关系
	int zhiwu[10]; // 门派职务
	int kzq; // 扩张倾向
	int dzq; // 招弟子倾向
	int czsd; // 弟子成长速度
	int qizhi; // 旗帜
	int mdizigrp; // 男弟子起图
	int mdizipic; // 男弟子头像
	int fdizigrp; // 女弟子起图
	int fdizipic; // 女弟子头像
	int sexy; // 弟子性别
	int identity; // 弟子身份
	int endevent; // 灭门事件
	int tongmeng; // 同盟
	int israndomed; // 查找标记
	int unuse2; // 未定义2
	int unuse3; // 未定义3
	int unuse4; // 未定义4
};

//存档中的标签类别
struct SignType
{
	int num;
	char name[40]; //10
	char Introduction[120]; //41
};

//存档中的标签数据
struct RSignSave
{
	int ID; // 编号
	char Name[40]; // 名称
	int effert; // 效果
	int TypeNum; // 类别
	char Introduction[90]; // 说明
	int beiyong; // 备用
	int isshow; // 是否隐藏
	Ttexiao texiao[24]; //92
};



//场景事件数据
struct SubMapEvent
{
    //event1为主动触发，event2为物品触发，event3为经过触发
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

//实际的场景数据
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

//存档中的商店数据
struct ShopSave
{
    int ItemID[SHOP_ITEM_COUNT], Total[SHOP_ITEM_COUNT];
};

//实际商店数据
struct Shop : ShopSave
{
};

//实际招式数据
struct Zhaoshi : ZhaoshiSave
{
};

//实际门派数据
struct Menpai : MenpaiSave
{
};

//实际标签数据
struct RSign : RSignSave
{
};