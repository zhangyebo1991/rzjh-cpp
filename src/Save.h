#pragma once
#include "sqlite3.h"
#include <map>
#include <vector>
#include "Types.h"



struct ItemList
{
    int item_id, count;
};

class Save
{
public:
    //此处为全局数据，载入和保存使用，必须放在类开头，按照顺序，否则自己看着办
	int InShip; // 乘船
	int InSubMap; // 场景
	int MainMapX; // 人X
	int MainMapY; // 人Y
	int SubMapX; // 内场景坐标X
	int SubMapY; // 内场景坐标Y
	int FaceTowards; // 人面对方向
	int ShipX; // 船X
	int ShipY; // 船Y
	int TimeCount; // 计时
	int TimeEvent; // 定时事件
	int RandomEvent; // 随机事件
	int SubmapTowards; // 内场景方向
	int ShipTowards; // 船面对方向
	int TeamCount;; // 队伍人数
	int Team[6]; // 队友
	int Encode; // 编码
    ItemList Items[ITEM_IN_BAG_COUNT];
	int Unuse[5];
	TimeSave time[1];

private:
    //缓冲区，无他用
    int buffer_[100];

    int sdata_length_ = sizeof(MAP_INT) * SUBMAP_LAYER_COUNT * SUBMAP_COORD_COUNT * SUBMAP_COORD_COUNT;
    int ddata_length_ = sizeof(SubMapEvent) * SUBMAP_EVENT_COUNT;

public:
    Save();
    ~Save();

    bool load(int num);
    void loadR(int num);
    void loadSD(int num);
    bool save(int num);
    void saveR(int num);
    void saveSD(int num);

    // 帮助网络交流
    void resetRData(const std::vector<RoleSave>& newData);

    static Save* getInstance()
    {
        static Save s;
        return &s;
    }

    static std::string getFilename(int i, char c);
    static bool checkSaveFileExist(int num);

private:
    //注意在读取之后，offset比length尾部会多一个元素，该值即总长度
    std::vector<int> offset_, length_;

    //这里实际保存所有数据
    std::vector<Role> roles_mem_;
    std::vector<Magic> magics_mem_;
    std::vector<Item> items_mem_;
    std::vector<SubMapInfo> submap_infos_mem_;
    std::vector<Shop> shops_mem_;
	std::vector<TimeSave> time_mem_;
	std::vector<Zhaoshi> zhaoshis_mem_;
	std::vector<Menpai> menpais_mem_;
	std::vector<RSign> rsigns_mem_;

    //下面保存的是指针，大部分时候使用
    std::vector<Role*> roles_;
    std::vector<Magic*> magics_;
    std::vector<Item*> items_;
    std::vector<SubMapInfo*> submap_infos_;
    std::vector<Shop*> shops_;
	std::vector<TimeSave*> time_;
	std::vector<Zhaoshi*> zhaoshis_;
	std::vector<Menpai*> menpais_;
	std::vector<RSign*> rsigns_;

    std::map<std::string, Role*> roles_by_name_;
    std::map<std::string, Item*> items_by_name_;
    std::map<std::string, Magic*> magics_by_name_;
    std::map<std::string, SubMapInfo*> submap_infos_by_name_;
	std::map<std::string, Zhaoshi*> zhaoshis_by_name_;
	std::map<std::string, Menpai*> menpais_by_name_;
	std::map<std::string, RSign*> rsigns_by_name_;

    template <class T>
    void setSavePointer(std::vector<T>& v, int size)
    {
        for (auto& i : v)
        {
            i.save_ = this;
        }
    }

    template <class T>
    void toPtrVector(std::vector<T>& v, std::vector<T*>& v_ptr)
    {
        v_ptr.clear();
        for (auto& i : v)
        {
            v_ptr.push_back(&i);
        }
    }

public:
    void updateAllPtrVector();

public:
    Role* getRole(int i)
    {
        if (i < 0 || i >= roles_.size())
        {
            return nullptr;
        }
        return roles_[i];
    }
    Magic* getMagic(int i)
    {
        if (i <= 0 || i >= magics_.size())
        {
            return nullptr;
        }
        return magics_[i];
    }    //0号武功无效
    Item* getItem(int i)
    {
        if (i < 0 || i >= items_.size())
        {
            return nullptr;
        }
        return items_[i];
    }
    SubMapInfo* getSubMapInfo(int i)
    {
        if (i < 0 || i >= submap_infos_.size())
        {
            return nullptr;
        }
        return submap_infos_[i];
    }
    Shop* getShop(int i)
    {
        if (i < 0 || i >= shops_.size())
        {
            return nullptr;
        }
        return shops_[i];
    }

	Menpai* getMenpai(int i)
	{
		if (i < 0 || i >= menpais_.size())
		{
			return menpais_[0];
		}
		return menpais_[i];
	}

	Zhaoshi* getZhaoshi(int i)
	{
		if (i < 0 || i >= zhaoshis_.size())
		{
			return zhaoshis_[0];
		}
		return zhaoshis_[i];
	}

	RSign* getRSign(int i)
	{
		if (i < 0 || i >= zhaoshis_.size())
		{
			return rsigns_[0];
		}
		return rsigns_[i];
	}

    Role* getTeamMate(int i);
    int getTeamMateID(int i) { return Team[i]; }

    Item* getItemByBagIndex(int i);
    int getItemCountByBagIndex(int i);
    int getItemCountInBag(Item* item);

    int getItemCountInBag(int item_id);
    int getMoneyCountInBag();

    void makeMaps();

    Role* getRoleByName(std::string name) { return roles_by_name_[name]; }
    Magic* getMagicByName(std::string name) { return magics_by_name_[name]; }
    Item* getItemByName(std::string name) { return items_by_name_[name]; }
    SubMapInfo* getSubMapRecordByName(std::string name) { return submap_infos_by_name_[name]; }

    Magic* getRoleLearnedMagic(Role* r, int i);
    int getRoleLearnedMagicLevelIndex(Role* r, Magic* m);

    Magic* getRoleActiveMagic(Role* r, int i);   //获取激活武功
    int getRoleActiveMagicLevel(Role* r, int i);   //获取激活武功
    int getActiveMagicIndex(Role* r, int j);    //获取激活武功栏位的具体编号

    Zhaoshi* getRoleLearnedZhaoshi(Role* r, Magic* magic, int i);

    const std::vector<Role*>& getRoles() { return roles_; }
    const std::vector<Magic*>& getMagics() { return magics_; }
    const std::vector<Item*>& getItems() { return items_; }
    const std::vector<SubMapInfo*>& getSubMapInfos() { return submap_infos_; }
    const std::vector<Shop*>& getShops() { return shops_; }
	const std::vector<Zhaoshi*>& getZhaoshis() { return zhaoshis_; }
	const std::vector<Menpai*>& getMenpais() { return menpais_; }
	const std::vector<RSign*>& getRSigns() { return rsigns_; }

public:
    int MaxLevel = 40;
    int MaxHP = 5000;
    int MaxMP = 10000;
    int MaxPhysicalPower = 100;

    int MaxPosion = 100;

    int MaxAttack = 200;
    int MaxDefence = 200;
    int MaxSpeed = 200;

    int MaxMedicine = 100;
    int MaxUsePoison = 100;
    int MaxDetoxification = 100;
    int MaxAntiPoison = 100;

    int MaxFist = 200;
    int MaxSword = 200;
    int MaxKnife = 200;
    int MaxUnusual = 200;
    int MaxHiddenWeapon = 200;

    int MaxKnowledge = 100;
    int MaxMorality = 100;
    int MaxAttackWithPoison = 100;
    int MaxFame = 999;
    int MaxIQ = 100;

    int MaxExp = 99999;

    void loadSaveValues() {}

public:
    struct BaseInfo
    {
        int InShip, InSubMap, MainMapX, MainMapY, SubMapX, SubMapY, FaceTowards, ShipX, ShipY, TimeCount, TimeEvent, RandomEvent, SubmapTowards, ShipTowards, TeamCount;
        int Team[TEAMMATE_COUNT];	
		int Encode;
    };

public:
    void saveRToCSV(int num);
    void loadRFromCSV(int num);
    bool insertAt(const std::string& type, int idx);

public:
    void saveRToDB(int num);
    void loadRFromDB(int num);
};
