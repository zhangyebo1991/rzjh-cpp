#pragma once
#include "PotConv.h"
#include "Save.h"
#include <algorithm>

class NewSave
{
public:
	// 基本
	static void SaveToCSVBaseInfo (Save::BaseInfo* data, int length, int record);
	static void LoadFromCSVBaseInfo (Save::BaseInfo* data, int length, int record);
	// 背包
	static void SaveToCSVItemList (ItemList* data, int length, int record);
	static void LoadFromCSVItemList (ItemList* data, int length, int record);
	// 人物
	static void SaveToCSVRoleSave (const std::vector<Role>& data, int record);
	static void LoadFromCSVRoleSave (std::vector<Role>& data, int record);
	static void InsertRoleAt(std::vector<Role>& data, int idx);
	// 物品
	static void SaveToCSVItemSave (const std::vector<Item>& data, int record);
	static void LoadFromCSVItemSave (std::vector<Item>& data, int record);
	static void InsertItemAt(std::vector<Item>& data, int idx);
	// 场景
	static void SaveToCSVSubMapInfoSave (const std::vector<SubMapInfo>& data, int record);
	static void LoadFromCSVSubMapInfoSave (std::vector<SubMapInfo>& data, int record);
	static void InsertSubMapInfoAt(std::vector<SubMapInfo>& data, int idx);
	// 武功
	static void SaveToCSVMagicSave (const std::vector<Magic>& data, int record);
	static void LoadFromCSVMagicSave (std::vector<Magic>& data, int record);
	static void InsertMagicAt(std::vector<Magic>& data, int idx);
	// 商店
	static void SaveToCSVShopSave (const std::vector<Shop>& data, int record);
	static void LoadFromCSVShopSave (std::vector<Shop>& data, int record);
	static void InsertShopAt(std::vector<Shop>& data, int idx);
	// 时间
	static void SaveToCSVTimeSave (TimeSave* data, int length, int record);
	static void LoadFromCSVTimeSave (TimeSave* data, int length, int record);
	// 招式
	static void SaveToCSVZhaoshiSave(const std::vector<Zhaoshi>& data, int record);
	static void LoadFromCSVZhaoshiSave(std::vector<Zhaoshi>& data, int record);
	static void InsertZhaoshiAt(std::vector<Zhaoshi>& data, int idx);
	// 门派
	static void SaveToCSVMenpaiSave(const std::vector<Menpai>& data, int record);
	static void LoadFromCSVMenpaiSave(std::vector<Menpai>& data, int record);
	static void InsertMenpaiAt(std::vector<Menpai>& data, int idx);
	// 标签
	static void SaveToCSVRSignSave(const std::vector<RSign>& data, int record);
	static void LoadFromCSVRSignSave(std::vector<RSign>& data, int record);
	static void InsertRSignAt(std::vector<RSign>& data, int idx);

private:
    struct FieldInfo
    {
        std::string name;
        int type;    //0-int, 1-char
        int offset;
        size_t length;
        int col = -1;
        FieldInfo() {}
        FieldInfo(const std::string& n, int t, int o, size_t l, int c = -1) : name(n), type(t), offset(o), length(l), col(c) {}
    };
    std::vector<FieldInfo> base_, item_list_, role_, item_, submap_, magic_, shop_, zhaoshi_, menpai_, RSign_;
    //std::map<std::string, FieldInfo> base_map_;
    static NewSave new_save_;

public:
    static void initDBFieldInfo();
    static void SaveDBBaseInfo(sqlite3* db, Save::BaseInfo* data, int length);
    static void LoadDBBaseInfo(sqlite3* db, Save::BaseInfo* data, int length);
    // 背包
    static void SaveDBItemList(sqlite3* db, ItemList* data, int length);
    static void LoadDBItemList(sqlite3* db, ItemList* data, int length);
    // 人物
    static void SaveDBRoleSave(sqlite3* db, const std::vector<Role>& data);
    static void LoadDBRoleSave(sqlite3* db, std::vector<Role>& data);
    // 物品
    static void SaveDBItemSave(sqlite3* db, const std::vector<Item>& data);
    static void LoadDBItemSave(sqlite3* db, std::vector<Item>& data);
    // 场景
    static void SaveDBSubMapInfoSave(sqlite3* db, const std::vector<SubMapInfo>& data);
    static void LoadDBSubMapInfoSave(sqlite3* db, std::vector<SubMapInfo>& data);
    // 武功
    static void SaveDBMagicSave(sqlite3* db, const std::vector<Magic>& data);
    static void LoadDBMagicSave(sqlite3* db, std::vector<Magic>& data);
    // 商店
    static void SaveDBShopSave(sqlite3* db, const std::vector<Shop>& data);
    static void LoadDBShopSave(sqlite3* db, std::vector<Shop>& data);

private:
    template <class T>
    static void writeValues(sqlite3* db, const std::string& table_name, std::vector<FieldInfo>& infos, const std::vector<T>& data)
    {
        sqlite3_exec(db, ("delete from " + table_name).c_str(), nullptr, nullptr, nullptr);
        for (auto& data1 : data)
        {
            std::string cmd = "insert into " + table_name + " values(";
            for (auto& info : infos)
            {
                if (info.type == 0)
                {
                    cmd += std::to_string(*(int*)((char*)&data1 + info.offset)) + ",";
                }
                else
                {
                    cmd += "'" + PotConv::cp936toutf8((char*)((char*)&data1 + info.offset)) + "',";
                }
            }
            cmd.pop_back();
            cmd += ")";
            sqlite3_exec(db, cmd.c_str(), nullptr, nullptr, nullptr);
        }
    }

    template <class T>
    static void readValues(sqlite3* db, const std::string& table_name, std::vector<FieldInfo>& infos, std::vector<T>& data)
    {
        sqlite3_stmt* statement;
        std::string strSql = "select * from " + table_name;
        sqlite3_prepare(db, strSql.c_str(), -1, &statement, NULL);

        //重整列序
        //在游戏最初必须运行一次读取
        if (infos[0].col == -1)
        {
            for (int i = 0; i < sqlite3_column_count(statement); i++)
            {
                auto name = PotConv::utf8tocp936(sqlite3_column_name(statement, i));
                for (auto& info : infos)
                {
                    if (name == info.name)
                    {
                        info.col = i;
                        break;
                    }
                }
            }
            //std::sort(infos.begin(), infos.end(), [](FieldInfo & f1, FieldInfo & f2) { return f1.col < f2.col; });
        }
        //读取
        data.clear();
        while (sqlite3_step(statement) == SQLITE_ROW)
        {
            T data1;
            for (auto& info : infos)
            {
                if (info.type == 0)
                {
                    auto p = (int*)((char*)&data1 + info.offset);
                    *p = sqlite3_column_int(statement, info.col);
                }
                else
                {
                    auto p = (char*)((char*)&data1 + info.offset);
                    std::string str((char*)sqlite3_column_text(statement, info.col));
                    str = PotConv::utf8tocp936(str);
                    memset(p, 0, info.length);
                    memcpy(p, str.data(), std::min(info.length, str.length()));
                }
            }
            data.push_back(data1);
        }
        sqlite3_finalize(statement);
    }
};
