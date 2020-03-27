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
    //�˴�Ϊȫ�����ݣ�����ͱ���ʹ�ã���������࿪ͷ������˳�򣬷����Լ����Ű�
	int InShip; // �˴�
	int InSubMap; // ����
	int MainMapX; // ��X
	int MainMapY; // ��Y
	int SubMapX; // �ڳ�������X
	int SubMapY; // �ڳ�������Y
	int FaceTowards; // ����Է���
	int ShipX; // ��X
	int ShipY; // ��Y
	int TimeCount; // ��ʱ
	int TimeEvent; // ��ʱ�¼�
	int RandomEvent; // ����¼�
	int SubmapTowards; // �ڳ�������
	int ShipTowards; // ����Է���
	int TeamCount;; // ��������
	int Team[6]; // ����
	int Encode; // ����
    ItemList Items[ITEM_IN_BAG_COUNT];
	int Unuse[5];
	TimeSave time[1];

private:
    //��������������
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

    // �������罻��
    void resetRData(const std::vector<RoleSave>& newData);

    static Save* getInstance()
    {
        static Save s;
        return &s;
    }

    static std::string getFilename(int i, char c);
    static bool checkSaveFileExist(int num);

private:
    //ע���ڶ�ȡ֮��offset��lengthβ�����һ��Ԫ�أ���ֵ���ܳ���
    std::vector<int> offset_, length_;

    //����ʵ�ʱ�����������
    std::vector<Role> roles_mem_;
    std::vector<Magic> magics_mem_;
    std::vector<Item> items_mem_;
    std::vector<SubMapInfo> submap_infos_mem_;
    std::vector<Shop> shops_mem_;
	std::vector<TimeSave> time_mem_;
	std::vector<Zhaoshi> zhaoshis_mem_;
	std::vector<Menpai> menpais_mem_;
	std::vector<RSign> rsigns_mem_;

    //���汣�����ָ�룬�󲿷�ʱ��ʹ��
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
    }    //0���书��Ч
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

    const std::vector<Role*>& getRoles() { return roles_; }
    const std::vector<Magic*>& getMagics() { return magics_; }
    const std::vector<Item*>& getItems() { return items_; }
    const std::vector<SubMapInfo*>& getSubMapInfos() { return submap_infos_; }
    const std::vector<Shop*>& getShops() { return shops_; }
	const std::vector<Zhaoshi*>& getZhaoshis() { return zhaoshis_; }
	const std::vector<Menpai*>& getMenpais() { return menpais_; }
	const std::vector<RSign*>& getRSigns() { return rsigns_; }

public:
    int MaxLevel = 30;
    int MaxHP = 999;
    int MaxMP = 999;
    int MaxPhysicalPower = 100;

    int MaxPosion = 100;

    int MaxAttack = 100;
    int MaxDefence = 100;
    int MaxSpeed = 100;

    int MaxMedicine = 100;
    int MaxUsePoison = 100;
    int MaxDetoxification = 100;
    int MaxAntiPoison = 100;

    int MaxFist = 100;
    int MaxSword = 100;
    int MaxKnife = 100;
    int MaxUnusual = 100;
    int MaxHiddenWeapon = 100;

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
