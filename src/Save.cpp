#include "Save.h"
#include "File.h"
#include "GrpIdxFile.h"
#include "NewSave.h"
#include "PotConv.h"
#include "convert.h"

Save::Save()
{
}

Save::~Save()
{
}

std::string Save::getFilename(int i, char c)
{
    std::string filename;
    if (i > 0)
    {
        filename = convert::formatString("../game/save/%c%d.grp", c, i);
        if (c == 'r')
        {
            filename += "32";
        }
    }
    else
    {
        if (c == 'r')
        {
            filename = "../game/save/ranger.grp32";
        }
        else if (c == 's')
        {
            filename = "../game/save/allsin.grp";
        }
        else if (c == 'd')
        {
            filename = "../game/save/alldef.grp";
        }
    }
    return filename;
}

bool Save::checkSaveFileExist(int num)
{
    return File::fileExist(getFilename(num, 'r'))
        && File::fileExist(getFilename(num, 's'))
        && File::fileExist(getFilename(num, 'd'));
}

void Save::updateAllPtrVector()
{
    toPtrVector(roles_mem_, roles_);
    toPtrVector(items_mem_, items_);
    toPtrVector(submap_infos_mem_, submap_infos_);
    toPtrVector(magics_mem_, magics_);
    toPtrVector(shops_mem_, shops_);
	toPtrVector(zhaoshis_mem_, zhaoshis_);
	toPtrVector(menpais_mem_, menpais_);
	toPtrVector(rsigns_mem_, rsigns_);
}

bool Save::load(int num)
{
    if (!checkSaveFileExist(num))
    {
        return false;
    }

    //loadR(num);
    //loadRFromDB(num);
	loadRFromCSV(num);
	//Encode = 936; //CSV读取默认是cp936
    loadSD(num);
	

    //内部编码为cp936
    if (Encode != 936)
    {
        Encode = 936;
        for (auto i : roles_)
        {
            PotConv::fromCP950ToCP936(i->Name);
            PotConv::fromCP950ToCP936(i->Nick);
        }
        for (auto i : items_)
        {
            PotConv::fromCP950ToCP936(i->Name);
            PotConv::fromCP950ToCP936(i->Introduction);
        }
        for (auto i : magics_)
        {
            PotConv::fromCP950ToCP936(i->Name);
        }
        for (auto i : submap_infos_)
        {
            PotConv::fromCP950ToCP936(i->Name);
        }
    }

    makeMaps();

    return true;
}

void Save::loadR(int num)
{
    std::string filenamer = getFilename(num, 'r');
    std::string filename_idx = "../game/save/ranger.idx32";
    auto rgrp = GrpIdxFile::getIdxContent(filename_idx, filenamer, &offset_, &length_);
    memcpy((void*)this, rgrp.data() + offset_[0], length_[0]);
    File::readDataToVector(rgrp.data() + offset_[1], length_[1], roles_mem_, sizeof(RoleSave));
    File::readDataToVector(rgrp.data() + offset_[2], length_[2], items_mem_, sizeof(ItemSave));
    File::readDataToVector(rgrp.data() + offset_[3], length_[3], submap_infos_mem_, sizeof(SubMapInfoSave));
    File::readDataToVector(rgrp.data() + offset_[4], length_[4], magics_mem_, sizeof(MagicSave));
    File::readDataToVector(rgrp.data() + offset_[5], length_[5], shops_mem_, sizeof(ShopSave));

    updateAllPtrVector();
}

void Save::loadSD(int num)
{
    std::string filenames = getFilename(num, 's');
    std::string filenamed = getFilename(num, 'd');

    auto submap_count = submap_infos_.size();

    auto sdata = new char[submap_count * sdata_length_];
    auto ddata = new char[submap_count * ddata_length_];
    File::readFile(filenames, sdata, submap_count * sdata_length_);
    File::readFile(filenamed, ddata, submap_count * ddata_length_);
    for (int i = 0; i < submap_count; i++)
    {
        memcpy(&(submap_infos_mem_[i].LayerData(0, 0, 0)), sdata + sdata_length_ * i, sdata_length_);
        memcpy(submap_infos_mem_[i].Event(0), ddata + ddata_length_ * i, ddata_length_);
    }
    delete[] sdata;
    delete[] ddata;
}

bool Save::save(int num)
{
    //saveR(num);
	saveRToCSV(num);
    saveSD(num);
    //saveRToDB(num);
    return true;
}

void Save::saveR(int num)
{
    std::string filenamer = getFilename(num, 'r');

    char* rgrp = new char[offset_.back()];
    memcpy(rgrp + offset_[0], &InShip, length_[0]);
    File::writeVectorToData(rgrp + offset_[1], length_[1], roles_mem_, sizeof(RoleSave));
    File::writeVectorToData(rgrp + offset_[2], length_[2], items_mem_, sizeof(ItemSave));
    File::writeVectorToData(rgrp + offset_[3], length_[3], submap_infos_mem_, sizeof(SubMapInfoSave));
    File::writeVectorToData(rgrp + offset_[4], length_[4], magics_mem_, sizeof(MagicSave));
    File::writeVectorToData(rgrp + offset_[5], length_[5], shops_mem_, sizeof(ShopSave));

    File::writeFile(filenamer, rgrp, offset_.back());
    delete[] rgrp;
}

void Save::saveSD(int num)
{
    std::string filenames = getFilename(num, 's');
    std::string filenamed = getFilename(num, 'd');
    auto submap_count = submap_infos_mem_.size();

    auto sdata = new char[submap_count * sdata_length_];
    auto ddata = new char[submap_count * ddata_length_];
    for (int i = 0; i < submap_count; i++)
    {
        memcpy(sdata + sdata_length_ * i, &(submap_infos_mem_[i].LayerData(0, 0, 0)), sdata_length_);
        memcpy(ddata + ddata_length_ * i, submap_infos_mem_[i].Event(0), ddata_length_);
    }
    File::writeFile(filenames, sdata, submap_count * sdata_length_);
    File::writeFile(filenamed, ddata, submap_count * ddata_length_);
    delete[] sdata;
    delete[] ddata;
}

void Save::resetRData(const std::vector<RoleSave>& newData)
{
    roles_mem_.clear();
    for (int i = 0; i < newData.size(); i++)
    {
        roles_mem_.emplace_back();
        auto& r = roles_mem_.back();
        memcpy(&r, &newData[i], sizeof(RoleSave));
        r.RealID = r.ID;
        r.ID = i;
    }
    updateAllPtrVector();
}

Role* Save::getTeamMate(int i)
{
    if (i < 0 || i >= TEAMMATE_COUNT)
    {
        return nullptr;
    }
    int r = Team[i];
    if (r < 0 || r >= roles_mem_.size())
    {
        return nullptr;
    }
    return roles_[r];
}

Item* Save::getItemByBagIndex(int i)
{
    if (i < 0 || i >= ITEM_IN_BAG_COUNT)
    {
        return nullptr;
    }
    int r = Items[i].item_id;
    if (r < 0 || r >= items_mem_.size())
    {
        return nullptr;
    }
    return items_[r];
}

int Save::getItemCountByBagIndex(int i)
{
    return Items[i].count;
}

int Save::getItemCountInBag(Item* item)
{
    return getItemCountInBag(item->ID);
}

int Save::getItemCountInBag(int item_id)
{
    for (int i = 0; i < ITEM_IN_BAG_COUNT; i++)
    {
        auto id = Items[i].item_id;
        if (id < 0)
        {
            break;
        }
        if (id == item_id)
        {
            return Items[i].count;
        }
    }
    return 0;
}

int Save::getMoneyCountInBag()
{
    return getItemCountInBag(Item::MoneyItemID);
}

void Save::makeMaps()
{
    roles_by_name_.clear();
    magics_by_name_.clear();
    items_by_name_.clear();
    submap_infos_by_name_.clear();
	zhaoshis_by_name_.clear();
	menpais_by_name_.clear();
	rsigns_by_name_.clear();

    //有重名的，斟酌使用
    for (auto& i : roles_)
    {
        roles_by_name_[i->Name] = i;
    }
    for (auto& i : magics_)
    {
        magics_by_name_[i->Name] = i;
    }
    for (auto& i : items_)
    {
        items_by_name_[i->Name] = i;
    }
    for (auto& i : submap_infos_)
    {
        submap_infos_by_name_[i->Name] = i;
    }
	for (auto& i : menpais_)
	{
		menpais_by_name_[i->Name] = i;
	}
	for (auto& i : zhaoshis_)
	{
		zhaoshis_by_name_[i->Name] = i;
	}
	for (auto& i : rsigns_)
	{
		rsigns_by_name_[i->Name] = i;
	}
}

Magic* Save::getRoleLearnedMagic(Role* r, int i)
{
    if (i < 0 || i >= ROLE_MAGIC_COUNT)
    {
        return nullptr;
    }
    return getMagic(r->MagicID[i]);
}

Magic* Save::getRoleActiveMagic(Role* r, int i)
{
    if (i < 0 || i >= ROLE_ACTIVE_MAGIC_COUNT)
    {
        return nullptr;
    }
    return getRoleLearnedMagic(r, r->JhMagic[i]);
}

int Save::getRoleActiveMagicLevel(Role* r, int i)
{
    if (i < 0 || i >= ROLE_ACTIVE_MAGIC_COUNT)
    {
        return -1;
    }
    return r->getRoleShowLearnedMagicLevel(r->JhMagic[i]);
}

int Save::getActiveMagicIndex(Role* r, int j)
{
    return r->JhMagic[j];
}


Zhaoshi* Save::getRoleLearnedZhaoshi(Role* r, Magic* magic, int i)
{
    if (i < 0 || i >= 6)
    {
        return nullptr;
    }
    int zs_array[5];
    int zs_state = r->LZhaoshi[r->getMagicOfRoleIndex(magic)];
    if (((zs_state >> i) & 1) == 0) {
        return nullptr;
    }
    if (magic->Zhaoshi[i]<1) {
        return nullptr;
    }
    return getZhaoshi(magic->Zhaoshi[i]);
}

int Save::getRoleLearnedMagicLevelIndex(Role* r, Magic* m)
{
    for (int i = 0; i < ROLE_MAGIC_COUNT; i++)
    {
        if (r->MagicID[i] == m->ID)
        {
            return r->getRoleMagicLevelIndex(i);
        }
    }
    return -1;
}

void Save::saveRToCSV(int num)
{
    NewSave::SaveToCSVBaseInfo((BaseInfo*)this, 1, num);
    // 背包
    NewSave::SaveToCSVItemList(Items, ITEM_IN_BAG_COUNT, num);
    // 人物
    NewSave::SaveToCSVRoleSave(roles_mem_, num);
    // 物品
    NewSave::SaveToCSVItemSave(items_mem_, num);
    // 场景
    NewSave::SaveToCSVSubMapInfoSave(submap_infos_mem_, num);
    // 武功
    NewSave::SaveToCSVMagicSave(magics_mem_, num);
    // 商店
    NewSave::SaveToCSVShopSave(shops_mem_, num);
	// 时间
	NewSave::SaveToCSVTimeSave(time, 1, num);
	// 门派
	NewSave::SaveToCSVMenpaiSave(menpais_mem_, num);
	// 招式
	NewSave::SaveToCSVZhaoshiSave(zhaoshis_mem_, num);
	// 标签
	NewSave::SaveToCSVRSignSave(rsigns_mem_, num);
}

void Save::loadRFromCSV(int num)
{
    NewSave::LoadFromCSVBaseInfo((BaseInfo*)this, 1, num);
    NewSave::LoadFromCSVItemList(Items, ITEM_IN_BAG_COUNT, num);
    NewSave::LoadFromCSVRoleSave(roles_mem_, num);
    NewSave::LoadFromCSVItemSave(items_mem_, num);
    NewSave::LoadFromCSVSubMapInfoSave(submap_infos_mem_, num);
    NewSave::LoadFromCSVMagicSave(magics_mem_, num);
    NewSave::LoadFromCSVShopSave(shops_mem_, num);
	NewSave::LoadFromCSVTimeSave(time, 1, num);
	NewSave::LoadFromCSVMenpaiSave(menpais_mem_,num);
	NewSave::LoadFromCSVZhaoshiSave(zhaoshis_mem_,num);
	NewSave::LoadFromCSVRSignSave(rsigns_mem_,num);
    updateAllPtrVector();
    makeMaps();
}

bool Save::insertAt(const std::string& type, int idx)
{
    if (type == u8"Role")
    {
        NewSave::InsertRoleAt(roles_mem_, idx);
        return true;
    }
    else if (type == u8"Item")
    {
        NewSave::InsertItemAt(items_mem_, idx);
        return true;
    }
    else if (type == u8"Magic")
    {
        NewSave::InsertMagicAt(magics_mem_, idx);
        return true;
    }
    else if (type == u8"SubMapInfo")
    {
        NewSave::InsertSubMapInfoAt(submap_infos_mem_, idx);
        return true;
    }
    else if (type == u8"Shop")
    {
        NewSave::InsertShopAt(shops_mem_, idx);
        return true;
    }
    return false;
}

void Save::saveRToDB(int num)
{
    std::string filename0 = "../game/save/0.db";
    if (!File::fileExist(filename0))
    {
        return;
    }
    sqlite3* db;
    //此处最好复制一个，先搞搞再说
    std::string filename = "../game/save/" + std::to_string(num) + ".db";
    convert::writeStringToFile(convert::readStringFromFile(filename0), filename);
    sqlite3_open(filename.c_str(), &db);
    sqlite3_exec(db, "BEGIN;", nullptr, nullptr, nullptr);
    NewSave::SaveDBBaseInfo(db, (BaseInfo*)this, 1);
    NewSave::SaveDBItemList(db, Items, ITEM_IN_BAG_COUNT);
    NewSave::SaveDBRoleSave(db, roles_mem_);
    NewSave::SaveDBItemSave(db, items_mem_);
    NewSave::SaveDBSubMapInfoSave(db, submap_infos_mem_);
    NewSave::SaveDBMagicSave(db, magics_mem_);
    NewSave::SaveDBShopSave(db, shops_mem_);
    sqlite3_exec(db, "COMMIT;", nullptr, nullptr, nullptr);
    sqlite3_close(db);
}

void Save::loadRFromDB(int num)
{
    NewSave::initDBFieldInfo();
    auto filename = "../game/save/" + std::to_string(num) + ".db";
    if (!File::fileExist(filename))
    {
        return;
    }
    sqlite3* db;
    sqlite3_open(filename.c_str(), &db);
    NewSave::LoadDBBaseInfo(db, (BaseInfo*)this, 1);
    NewSave::LoadDBItemList(db, Items, ITEM_IN_BAG_COUNT);
    NewSave::LoadDBRoleSave(db, roles_mem_);
    NewSave::LoadDBItemSave(db, items_mem_);
    NewSave::LoadDBSubMapInfoSave(db, submap_infos_mem_);
    NewSave::LoadDBMagicSave(db, magics_mem_);
    NewSave::LoadDBShopSave(db, shops_mem_);
    sqlite3_close(db);
    updateAllPtrVector();
    makeMaps();
}
