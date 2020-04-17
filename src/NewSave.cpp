#include "NewSave.h"
#include "PotConv.h"
#include "csv.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 基本
void NewSave::SaveToCSVBaseInfo(Save::BaseInfo* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_基本.csv");
	fout << "乘船";
	fout << ",";    fout << "场景";
	fout << ",";    fout << "人X";
	fout << ",";    fout << "人Y";
	fout << ",";    fout << "内场景坐标X";
	fout << ",";    fout << "内场景坐标Y";
	fout << ",";    fout << "人面对方向";
	fout << ",";    fout << "船X";
	fout << ",";    fout << "船Y";
	fout << ",";    fout << "计时";
	fout << ",";    fout << "定时事件";
	fout << ",";    fout << "随机事件";
	fout << ",";    fout << "内场景方向";
	fout << ",";    fout << "船面对方向";
	fout << ",";    fout << "队伍人数";
	fout << ",";    fout << "队友1";
	fout << ",";    fout << "队友2";
	fout << ",";    fout << "队友3";
	fout << ",";    fout << "队友4";
	fout << ",";    fout << "队友5";
	fout << ",";    fout << "队友6";
	fout << ",";    fout << "编码";
	fout << std::endl;
	for (int i = 0; i < length; i++) {
		fout << data[i].InShip;
		fout << ",";
		fout << data[i].InSubMap;
		fout << ",";
		fout << data[i].MainMapX;
		fout << ",";
		fout << data[i].MainMapY;
		fout << ",";
		fout << data[i].SubMapX;
		fout << ",";
		fout << data[i].SubMapY;
		fout << ",";
		fout << data[i].FaceTowards;
		fout << ",";
		fout << data[i].ShipX;
		fout << ",";
		fout << data[i].ShipY;
		fout << ",";
		fout << data[i].TimeCount;
		fout << ",";
		fout << data[i].TimeEvent;
		fout << ",";
		fout << data[i].RandomEvent;
		fout << ",";
		fout << data[i].SubmapTowards;
		fout << ",";
		fout << data[i].ShipTowards;
		fout << ",";
		fout << data[i].TeamCount;;
		fout << ",";
		for (int j = 0; j < 6; j++) {
			fout << data[i].Team[j];
			if (j != 6 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].Encode;
		fout << std::endl;
	}
}
// 背包
void NewSave::SaveToCSVItemList(ItemList* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_背包.csv");
	fout << "物品编号";
	fout << ",";    fout << "物品数量";
	fout << std::endl;
	for (int i = 0; i < length; i++) {
		fout << data[i].item_id;
		fout << ",";
		fout << data[i].count;
		fout << std::endl;
	}
}
// 人物
void NewSave::SaveToCSVRoleSave(const std::vector<Role>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_renwu.csv");
	fout << "编号";
	fout << ",";    fout << "头像/战斗代号";
	fout << ",";    fout << "生命增长";
	fout << ",";    fout << "福缘";
	fout << ",";    fout << "姓名";
	fout << ",";    fout << "外号";
	fout << ",";    fout << "性别";
	fout << ",";    fout << "等级";
	fout << ",";    fout << "经验值";
	fout << ",";    fout << "生命";
	fout << ",";    fout << "生命最大值";
	fout << ",";    fout << "受伤程度";
	fout << ",";    fout << "中毒程度";
	fout << ",";    fout << "体力";
	fout << ",";    fout << "战斗图编号";
	fout << ",";    fout << "装备";
	fout << ",";    fout << "装备1";
	fout << ",";    fout << "装备2";
	fout << ",";    fout << "装备3";
	fout << ",";    fout << "装备4";
	fout << ",";    fout << "功体";
	fout << ",";    fout << "队伍状态";
	fout << ",";    fout << "愤怒值";
	fout << ",";    fout << "查找标记";
	fout << ",";    fout << "行动能力";
	fout << ",";    fout << "技能点";
	fout << ",";    fout << "战略AI状态";
	fout << ",";    fout << "外观";
	fout << ",";    fout << "行动时间";
	fout << ",";    fout << "难度";
	fout << ",";    fout << "忠诚度";
	fout << ",";    fout << "药物";
	fout << ",";    fout << "内力性质";
	fout << ",";    fout << "内力";
	fout << ",";    fout << "内力最大值";
	fout << ",";    fout << "攻击力";
	fout << ",";    fout << "轻功";
	fout << ",";    fout << "防御力";
	fout << ",";    fout << "医疗";
	fout << ",";    fout << "暂缺";
	fout << ",";    fout << "技艺";
	fout << ",";    fout << "抗毒";
	fout << ",";    fout << "拳掌";
	fout << ",";    fout << "御剑";
	fout << ",";    fout << "耍刀";
	fout << ",";    fout << "特殊兵器";
	fout << ",";    fout << "暗器技巧";
	fout << ",";    fout << "武学常识";
	fout << ",";    fout << "品德";
	fout << ",";    fout << "毒术";
	fout << ",";    fout << "左右互搏";
	fout << ",";    fout << "声望";
	fout << ",";    fout << "资质";
	fout << ",";    fout << "修练物品";
	fout << ",";    fout << "修练点数";
	fout << ",";    fout << "相性";
	fout << ",";    fout << "交情";
	fout << ",";    fout << "人物类别";
	fout << ",";    fout << "声望倾向";
	fout << ",";    fout << "品德倾向";
	fout << ",";    fout << "相性倾向";
	fout << ",";    fout << "交情倾向";
	fout << ",";    fout << "所属门派";
	fout << ",";    fout << "师父";
	fout << ",";    fout << "师承序位";
	fout << ",";    fout << "拜师顺序";
	fout << ",";    fout << "仇视门派";
	fout << ",";    fout << "仇视门派1";
	fout << ",";    fout << "当前位置";
	fout << ",";    fout << "内部位置";
	fout << ",";    fout << "内部方向";
	fout << ",";    fout << "人物状态";
	fout << ",";    fout << "练武倾向";
	fout << ",";    fout << "冥思倾向";
	fout << ",";    fout << "劳动倾向";
	fout << ",";    fout << "其他倾向";
	fout << ",";    fout << "临时位置";
	fout << ",";    fout << "内部临时位置";
	fout << ",";    fout << "内部方向1";
	fout << ",";    fout << "场景X坐标";
	fout << ",";    fout << "场景Y坐标";
	fout << ",";    fout << "送书标记";
	fout << ",";    fout << "官府贡献";
	fout << ",";    fout << "夫妻";
	fout << ",";    fout << "年龄";
	fout << ",";    fout << "未用1";
	fout << ",";    fout << "未用2";
	fout << ",";    fout << "未用3";
	fout << ",";    fout << "战场ID";
	fout << ",";    fout << "所会武功";
	fout << ",";    fout << "所会武功1";
	fout << ",";    fout << "所会武功2";
	fout << ",";    fout << "所会武功3";
	fout << ",";    fout << "所会武功4";
	fout << ",";    fout << "所会武功5";
	fout << ",";    fout << "所会武功6";
	fout << ",";    fout << "所会武功7";
	fout << ",";    fout << "所会武功8";
	fout << ",";    fout << "所会武功9";
	fout << ",";    fout << "所会武功10";
	fout << ",";    fout << "所会武功11";
	fout << ",";    fout << "所会武功12";
	fout << ",";    fout << "所会武功13";
	fout << ",";    fout << "所会武功14";
	fout << ",";    fout << "所会武功15";
	fout << ",";    fout << "所会武功16";
	fout << ",";    fout << "所会武功17";
	fout << ",";    fout << "所会武功18";
	fout << ",";    fout << "所会武功19";
	fout << ",";    fout << "所会武功20";
	fout << ",";    fout << "所会武功21";
	fout << ",";    fout << "所会武功22";
	fout << ",";    fout << "所会武功23";
	fout << ",";    fout << "所会武功24";
	fout << ",";    fout << "所会武功25";
	fout << ",";    fout << "所会武功26";
	fout << ",";    fout << "所会武功27";
	fout << ",";    fout << "所会武功28";
	fout << ",";    fout << "所会武功29";
	fout << ",";    fout << "所会武功30";
	fout << ",";    fout << "所会武功31";
	fout << ",";    fout << "所会武功32";
	fout << ",";    fout << "所会武功33";
	fout << ",";    fout << "所会武功34";
	fout << ",";    fout << "所会武功35";
	fout << ",";    fout << "所会武功36";
	fout << ",";    fout << "所会武功37";
	fout << ",";    fout << "所会武功38";
	fout << ",";    fout << "所会武功39";
	fout << ",";    fout << "所会武功等级";
	fout << ",";    fout << "所会武功等级1";
	fout << ",";    fout << "所会武功等级2";
	fout << ",";    fout << "所会武功等级3";
	fout << ",";    fout << "所会武功等级4";
	fout << ",";    fout << "所会武功等级5";
	fout << ",";    fout << "所会武功等级6";
	fout << ",";    fout << "所会武功等级7";
	fout << ",";    fout << "所会武功等级8";
	fout << ",";    fout << "所会武功等级9";
	fout << ",";    fout << "所会武功等级10";
	fout << ",";    fout << "所会武功等级11";
	fout << ",";    fout << "所会武功等级12";
	fout << ",";    fout << "所会武功等级13";
	fout << ",";    fout << "所会武功等级14";
	fout << ",";    fout << "所会武功等级15";
	fout << ",";    fout << "所会武功等级16";
	fout << ",";    fout << "所会武功等级17";
	fout << ",";    fout << "所会武功等级18";
	fout << ",";    fout << "所会武功等级19";
	fout << ",";    fout << "所会武功等级20";
	fout << ",";    fout << "所会武功等级21";
	fout << ",";    fout << "所会武功等级22";
	fout << ",";    fout << "所会武功等级23";
	fout << ",";    fout << "所会武功等级24";
	fout << ",";    fout << "所会武功等级25";
	fout << ",";    fout << "所会武功等级26";
	fout << ",";    fout << "所会武功等级27";
	fout << ",";    fout << "所会武功等级28";
	fout << ",";    fout << "所会武功等级29";
	fout << ",";    fout << "所会武功等级30";
	fout << ",";    fout << "所会武功等级31";
	fout << ",";    fout << "所会武功等级32";
	fout << ",";    fout << "所会武功等级33";
	fout << ",";    fout << "所会武功等级34";
	fout << ",";    fout << "所会武功等级35";
	fout << ",";    fout << "所会武功等级36";
	fout << ",";    fout << "所会武功等级37";
	fout << ",";    fout << "所会武功等级38";
	fout << ",";    fout << "所会武功等级39";
	fout << ",";    fout << "携带物品";
	fout << ",";    fout << "携带物品1";
	fout << ",";    fout << "携带物品2";
	fout << ",";    fout << "携带物品3";
	fout << ",";    fout << "携带物品4";
	fout << ",";    fout << "携带物品5";
	fout << ",";    fout << "携带物品6";
	fout << ",";    fout << "携带物品7";
	fout << ",";    fout << "携带物品8";
	fout << ",";    fout << "携带物品数量";
	fout << ",";    fout << "携带物品数量1";
	fout << ",";    fout << "携带物品数量2";
	fout << ",";    fout << "携带物品数量3";
	fout << ",";    fout << "携带物品数量4";
	fout << ",";    fout << "携带物品数量5";
	fout << ",";    fout << "携带物品数量6";
	fout << ",";    fout << "携带物品数量7";
	fout << ",";    fout << "携带物品数量8";
	fout << ",";    fout << "激活武功";
	fout << ",";    fout << "激活武功1";
	fout << ",";    fout << "激活武功2";
	fout << ",";    fout << "激活武功3";
	fout << ",";    fout << "激活武功4";
	fout << ",";    fout << "激活武功5";
	fout << ",";    fout << "激活武功6";
	fout << ",";    fout << "激活武功7";
	fout << ",";    fout << "激活武功8";
	fout << ",";    fout << "激活武功9";
	fout << ",";    fout << "所会招式";
	fout << ",";    fout << "所会招式1";
	fout << ",";    fout << "所会招式2";
	fout << ",";    fout << "所会招式3";
	fout << ",";    fout << "所会招式4";
	fout << ",";    fout << "所会招式5";
	fout << ",";    fout << "所会招式6";
	fout << ",";    fout << "所会招式7";
	fout << ",";    fout << "所会招式8";
	fout << ",";    fout << "所会招式9";
	fout << ",";    fout << "所会招式10";
	fout << ",";    fout << "所会招式11";
	fout << ",";    fout << "所会招式12";
	fout << ",";    fout << "所会招式13";
	fout << ",";    fout << "所会招式14";
	fout << ",";    fout << "所会招式15";
	fout << ",";    fout << "所会招式16";
	fout << ",";    fout << "所会招式17";
	fout << ",";    fout << "所会招式18";
	fout << ",";    fout << "所会招式19";
	fout << ",";    fout << "所会招式20";
	fout << ",";    fout << "所会招式21";
	fout << ",";    fout << "所会招式22";
	fout << ",";    fout << "所会招式23";
	fout << ",";    fout << "所会招式24";
	fout << ",";    fout << "所会招式25";
	fout << ",";    fout << "所会招式26";
	fout << ",";    fout << "所会招式27";
	fout << ",";    fout << "所会招式28";
	fout << ",";    fout << "所会招式29";
	fout << ",";    fout << "所会招式30";
	fout << ",";    fout << "所会招式31";
	fout << ",";    fout << "所会招式32";
	fout << ",";    fout << "所会招式33";
	fout << ",";    fout << "所会招式34";
	fout << ",";    fout << "所会招式35";
	fout << ",";    fout << "所会招式36";
	fout << ",";    fout << "所会招式37";
	fout << ",";    fout << "所会招式38";
	fout << ",";    fout << "所会招式39";
	fout << ",";    fout << "对话菜单开关";
	fout << ",";    fout << "对话事件";
	fout << ",";    fout << "状态事件";
	fout << ",";    fout << "入队事件";
	fout << ",";    fout << "切磋事件";
	fout << ",";    fout << "学习事件";
	fout << ",";    fout << "事件池1";
	fout << ",";    fout << "事件池2";
	fout << ",";    fout << "事件池3";
	fout << ",";    fout << "离队期限";
	fout << ",";    fout << "离队事件";
	fout << ",";    fout << "随机值";
	fout << ",";    fout << "随机值1";
	fout << ",";    fout << "暗箭";
	fout << ",";    fout << "医师";
	fout << ",";    fout << "装备特技";
	fout << ",";    fout << "回血";
	fout << ",";    fout << "回内";
	fout << ",";    fout << "回体";
	fout << ",";    fout << "暴躁";
	fout << ",";    fout << "配合";
	fout << ",";    fout << "武学";
	fout << ",";    fout << "突破";
	fout << ",";    fout << "冷静";
	fout << ",";    fout << "百变";
	fout << ",";    fout << "破气";
	fout << ",";    fout << "罩门";
	fout << ",";    fout << "变幻";
	fout << ",";    fout << "反攻";
	fout << ",";    fout << "气功";
	fout << ",";    fout << "硬功";
	fout << ",";    fout << "灵活";
	fout << ",";    fout << "行气";
	fout << ",";    fout << "身法";
	fout << ",";    fout << "攻击潜力";
	fout << ",";    fout << "防御潜力";
	fout << ",";    fout << "轻功潜力";
	fout << ",";    fout << "拳掌潜力";
	fout << ",";    fout << "御剑潜力";
	fout << ",";    fout << "耍刀潜力";
	fout << ",";    fout << "奇门潜力";
	fout << ",";    fout << "暗器潜力";
	fout << ",";    fout << "固守";
	fout << ",";    fout << "天命";
	fout << ",";    fout << "星宿";
	fout << ",";    fout << "专长";
	fout << ",";    fout << "专长1";
	fout << ",";    fout << "专长2";
	fout << ",";    fout << "专长3";
	fout << ",";    fout << "专长4";
	fout << ",";    fout << "特性";
	fout << ",";    fout << "特性1";
	fout << ",";    fout << "特性2";
	fout << ",";    fout << "特性3";
	fout << ",";    fout << "特性4";
	fout << ",";    fout << "特性5";
	fout << ",";    fout << "特性6";
	fout << ",";    fout << "特性7";
	fout << ",";    fout << "特性8";
	fout << ",";    fout << "特性9";
	fout << ",";    fout << "门派贡献";
	fout << ",";    fout << "未使用";
	fout << ",";    fout << "未使用1";
	fout << ",";    fout << "未使用2";
	fout << ",";    fout << "未使用3";
	fout << ",";    fout << "未使用4";
	fout << ",";    fout << "未使用5";
	fout << ",";    fout << "未使用6";
	fout << ",";    fout << "未使用7";
	fout << ",";    fout << "未使用8";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << data[i].HeadID;
		fout << ",";
		fout << data[i].IncLife;
		fout << ",";
		fout << data[i].Fuyuan;
		fout << ",";
		fout << data[i].Name;
		fout << ",";
		fout << data[i].Nick;
		fout << ",";
		//fout << '"' << data[i].Name << '"';
		//fout << ",";
		//fout << '"' << data[i].Nick << '"';
		//fout << ",";
		fout << data[i].Sexual;
		fout << ",";
		fout << data[i].Level;
		fout << ",";
		fout << data[i].Exp;
		fout << ",";
		fout << data[i].HP;
		fout << ",";
		fout << data[i].MaxHP;
		fout << ",";
		fout << data[i].Hurt;
		fout << ",";
		fout << data[i].Poison;
		fout << ",";
		fout << data[i].PhysicalPower;
		fout << ",";
		fout << data[i].FightNum;
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].Equip[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].Gongti;
		fout << ",";
		fout << data[i].TeamState;
		fout << ",";
		fout << data[i].Angry;
		fout << ",";
		fout << data[i].isRandomed;
		fout << ",";
		fout << data[i].Moveable;
		fout << ",";
		fout << data[i].skillPoint;
		fout << ",";
		fout << data[i].ZhanLueAI;
		fout << ",";
		fout << data[i].Impression;
		fout << ",";
		fout << data[i].dtime;
		fout << ",";
		fout << data[i].difficulty;
		fout << ",";
		fout << data[i].Zhongcheng;
		fout << ",";
		fout << data[i].reHurt;
		fout << ",";
		fout << data[i].MPType;
		fout << ",";
		fout << data[i].MP;
		fout << ",";
		fout << data[i].MaxMP;
		fout << ",";
		fout << data[i].Attack;
		fout << ",";
		fout << data[i].Speed;
		fout << ",";
		fout << data[i].Defence;
		fout << ",";
		fout << data[i].Medicine;
		fout << ",";
		fout << data[i].Weiyong;
		fout << ",";
		fout << data[i].Art;
		fout << ",";
		fout << data[i].AntiPoison;
		fout << ",";
		fout << data[i].Fist;
		fout << ",";
		fout << data[i].Sword;
		fout << ",";
		fout << data[i].Knife;
		fout << ",";
		fout << data[i].Unusual;
		fout << ",";
		fout << data[i].HiddenWeapon;
		fout << ",";
		fout << data[i].Knowledge;
		fout << ",";
		fout << data[i].Morality;
		fout << ",";
		fout << data[i].AttackWithPoison;
		fout << ",";
		fout << data[i].AttackTwice;
		fout << ",";
		fout << data[i].Fame;
		fout << ",";
		fout << data[i].IQ;
		fout << ",";
		fout << data[i].PracticeItem;
		fout << ",";
		fout << data[i].ExpForItem;
		fout << ",";
		fout << data[i].xiangxing;
		fout << ",";
		fout << data[i].jiaoqing;
		fout << ",";
		fout << data[i].Rtype;
		fout << ",";
		fout << data[i].swq;
		fout << ",";
		fout << data[i].pdq;
		fout << ",";
		fout << data[i].xxq;
		fout << ",";
		fout << data[i].jqq;
		fout << ",";
		fout << data[i].MenPai;
		fout << ",";
		fout << data[i].shifu;
		fout << ",";
		fout << data[i].scsx;
		fout << ",";
		fout << data[i].bssx;
		fout << ",";
		for (int j = 0; j < 2; j++) {
			fout << data[i].Choushi[j];
			if (j != 2 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].weizhi;
		fout << ",";
		fout << data[i].nweizhi;
		fout << ",";
		fout << data[i].nfangxiang;
		fout << ",";
		fout << data[i].OnStatus;
		fout << ",";
		fout << data[i].lwq;
		fout << ",";
		fout << data[i].msq;
		fout << ",";
		fout << data[i].ldq;
		fout << ",";
		fout << data[i].qtq;
		fout << ",";
		fout << data[i].lsweizhi;
		fout << ",";
		fout << data[i].lsnweizhi;
		fout << ",";
		fout << data[i].lsfangxiang;
		fout << ",";
		fout << data[i].Sx;
		fout << ",";
		fout << data[i].Sy;
		fout << ",";
		fout << data[i].songshu;
		fout << ",";
		fout << data[i].gongxian;
		fout << ",";
		fout << data[i].fuqi;
		fout << ",";
		fout << data[i].age;
		fout << ",";
		fout << data[i].weiyong1;
		fout << ",";
		fout << data[i].weiyong2;
		fout << ",";
		fout << data[i].weiyong3;
		fout << ",";
		fout << data[i].btnum;
		fout << ",";
		for (int j = 0; j < 40; j++) {
			fout << data[i].MagicID[j];
			if (j != 40 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 40; j++) {
			fout << data[i].MagicLevel[j];
			if (j != 40 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 9; j++) {
			fout << data[i].TakingItem[j];
			if (j != 9 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 9; j++) {
			fout << data[i].TakingItemCount[j];
			if (j != 9 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].JhMagic[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 40; j++) {
			fout << data[i].LZhaoshi[j];
			if (j != 40 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].IsEvent;
		fout << ",";
		fout << data[i].TalkEvent;
		fout << ",";
		fout << data[i].StateEvent;
		fout << ",";
		fout << data[i].JoinEvent;
		fout << ",";
		fout << data[i].TestEvent;
		fout << ",";
		fout << data[i].LearnEvent;
		fout << ",";
		fout << data[i].unusedEvent1;
		fout << ",";
		fout << data[i].unusedEvent2;
		fout << ",";
		fout << data[i].unusedEvent3;
		fout << ",";
		fout << data[i].LeaveTime;
		fout << ",";
		fout << data[i].LeaveEvent;
		fout << ",";
		fout << data[i].RandomNum1;
		fout << ",";
		fout << data[i].RandomNum2;
		fout << ",";
		fout << data[i].anjian;
		fout << ",";
		fout << data[i].yishi;
		fout << ",";
		fout << data[i].zbtj;
		fout << ",";
		fout << data[i].huixue;
		fout << ",";
		fout << data[i].huinei;
		fout << ",";
		fout << data[i].huiti;
		fout << ",";
		fout << data[i].baozhao;
		fout << ",";
		fout << data[i].peihe;
		fout << ",";
		fout << data[i].wuxue;
		fout << ",";
		fout << data[i].tupo;
		fout << ",";
		fout << data[i].lengjing;
		fout << ",";
		fout << data[i].baibian;
		fout << ",";
		fout << data[i].poqi;
		fout << ",";
		fout << data[i].zhaomen;
		fout << ",";
		fout << data[i].bianhuan;
		fout << ",";
		fout << data[i].fangong;
		fout << ",";
		fout << data[i].qigong;
		fout << ",";
		fout << data[i].yinggong;
		fout << ",";
		fout << data[i].linghuo;
		fout << ",";
		fout << data[i].xingqi;
		fout << ",";
		fout << data[i].shenfa;
		fout << ",";
		fout << data[i].gjql;
		fout << ",";
		fout << data[i].fyql;
		fout << ",";
		fout << data[i].qgql;
		fout << ",";
		fout << data[i].qzql;
		fout << ",";
		fout << data[i].yjql;
		fout << ",";
		fout << data[i].sdql;
		fout << ",";
		fout << data[i].qmql;
		fout << ",";
		fout << data[i].aqql;
		fout << ",";
		fout << data[i].gushou;
		fout << ",";
		fout << data[i].tianmin;
		fout << ",";
		fout << data[i].xingxiu;
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].zhuanchang[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].texing[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].menpaiContribution;
		fout << ",";
		for (int j = 0; j < 9; j++) {
			fout << data[i].Unused[j];
			if (j != 9 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 物品
void NewSave::SaveToCSVItemSave(const std::vector<Item>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_物品.csv");
	fout << "编号";
	fout << ",";    fout << "物品名";
	fout << ",";    fout << "物品武功经验";
	fout << ",";    fout << "套装号";
	fout << ",";    fout << "战斗特效";
	fout << ",";    fout << "增加标签";
	fout << ",";    fout << "要求性别";
	fout << ",";    fout << "恢复伤势";
	fout << ",";    fout << "需品德";
	fout << ",";    fout << "需声望";
	fout << ",";    fout << "增加潜力值";
	fout << ",";    fout << "战场号";
	fout << ",";    fout << "物品说明";
	fout << ",";    fout << "练出武功";
	fout << ",";    fout << "暗器动画编号";
	fout << ",";    fout << "使用人";
	fout << ",";    fout << "装备类型";
	fout << ",";    fout << "显示物品说明";
	fout << ",";    fout << "类型";
	fout << ",";    fout << "商店库存";
	fout << ",";    fout << "售价";
	fout << ",";    fout << "调用事件";
	fout << ",";    fout << "加生命";
	fout << ",";    fout << "加生命最大值";
	fout << ",";    fout << "加中毒解毒";
	fout << ",";    fout << "加体力";
	fout << ",";    fout << "改变内力性质";
	fout << ",";    fout << "加内力";
	fout << ",";    fout << "加内力最大值";
	fout << ",";    fout << "加攻击力";
	fout << ",";    fout << "加轻功";
	fout << ",";    fout << "加防御力";
	fout << ",";    fout << "加医疗";
	fout << ",";    fout << "加使毒";
	fout << ",";    fout << "加技艺";
	fout << ",";    fout << "加抗毒";
	fout << ",";    fout << "加拳掌";
	fout << ",";    fout << "加御剑";
	fout << ",";    fout << "加耍刀";
	fout << ",";    fout << "加特殊兵器";
	fout << ",";    fout << "加暗器技巧";
	fout << ",";    fout << "加武学常识";
	fout << ",";    fout << "加品德";
	fout << ",";    fout << "需生命";
	fout << ",";    fout << "加攻击带毒";
	fout << ",";    fout << "仅修炼人物";
	fout << ",";    fout << "需内力性质";
	fout << ",";    fout << "需内力";
	fout << ",";    fout << "需攻击力";
	fout << ",";    fout << "需轻功";
	fout << ",";    fout << "需毒术";
	fout << ",";    fout << "需医疗";
	fout << ",";    fout << "需技艺";
	fout << ",";    fout << "需拳掌";
	fout << ",";    fout << "需御剑";
	fout << ",";    fout << "需耍刀";
	fout << ",";    fout << "需特殊兵器";
	fout << ",";    fout << "需暗器";
	fout << ",";    fout << "需资质";
	fout << ",";    fout << "需经验";
	fout << ",";    fout << "数量";
	fout << ",";    fout << "稀有度";
	fout << ",";    fout << "所需物品";
	fout << ",";    fout << "所需物品1";
	fout << ",";    fout << "所需物品2";
	fout << ",";    fout << "所需物品3";
	fout << ",";    fout << "所需物品4";
	fout << ",";    fout << "需要物品数量";
	fout << ",";    fout << "需要物品数量1";
	fout << ",";    fout << "需要物品数量2";
	fout << ",";    fout << "需要物品数量3";
	fout << ",";    fout << "需要物品数量4";
	fout << ",";    fout << "加资质";
	fout << ",";    fout << "加富源";
	fout << ",";    fout << "未使用";
	fout << ",";    fout << "未使用1";
	fout << ",";    fout << "未使用2";
	fout << ",";    fout << "未使用3";
	fout << ",";    fout << "未使用4";
	fout << ",";    fout << "未使用5";
	fout << ",";    fout << "未使用6";
	fout << ",";    fout << "未使用7";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].ExpofMagic;
		fout << ",";
		fout << data[i].SetNum;
		fout << ",";
		fout << data[i].BattleEffect;
		fout << ",";
		fout << data[i].AddSign;
		fout << ",";
		fout << data[i].needSex;
		fout << ",";
		fout << data[i].rehurt;
		fout << ",";
		fout << data[i].NeedEthics;
		fout << ",";
		fout << data[i].NeedRepute;
		fout << ",";
		fout << data[i].AddQianli;
		fout << ",";
		fout << data[i].BattleNum;
		fout << ",";
		fout << '"' << data[i].Introduction << '"';
		fout << ",";
		fout << data[i].MagicID;
		fout << ",";
		fout << data[i].HiddenWeaponEffectID;
		fout << ",";
		fout << data[i].User;
		fout << ",";
		fout << data[i].EquipType;
		fout << ",";
		fout << data[i].ShowIntroduction;
		fout << ",";
		fout << data[i].ItemType;
		fout << ",";
		fout << data[i].Inventory;
		fout << ",";
		fout << data[i].Price;
		fout << ",";
		fout << data[i].EventNum;
		fout << ",";
		fout << data[i].AddHP;
		fout << ",";
		fout << data[i].AddMaxHP;
		fout << ",";
		fout << data[i].AddPoison;
		fout << ",";
		fout << data[i].AddPhysicalPower;
		fout << ",";
		fout << data[i].ChangeMPType;
		fout << ",";
		fout << data[i].AddMP;
		fout << ",";
		fout << data[i].AddMaxMP;
		fout << ",";
		fout << data[i].AddAttack;
		fout << ",";
		fout << data[i].AddSpeed;
		fout << ",";
		fout << data[i].AddDefence;
		fout << ",";
		fout << data[i].AddMedicine;
		fout << ",";
		fout << data[i].AddUsePoison;
		fout << ",";
		fout << data[i].AddArt;
		fout << ",";
		fout << data[i].AddAntiPoison;
		fout << ",";
		fout << data[i].AddFist;
		fout << ",";
		fout << data[i].AddSword;
		fout << ",";
		fout << data[i].AddKnife;
		fout << ",";
		fout << data[i].AddUnusual;
		fout << ",";
		fout << data[i].AddHiddenWeapon;
		fout << ",";
		fout << data[i].AddKnowledge;
		fout << ",";
		fout << data[i].AddMorality;
		fout << ",";
		fout << data[i].NeedHP;
		fout << ",";
		fout << data[i].AddAttackWithPoison;
		fout << ",";
		fout << data[i].OnlySuitableRole;
		fout << ",";
		fout << data[i].NeedMPType;
		fout << ",";
		fout << data[i].NeedMP;
		fout << ",";
		fout << data[i].NeedAttack;
		fout << ",";
		fout << data[i].NeedSpeed;
		fout << ",";
		fout << data[i].NeedUsePoison;
		fout << ",";
		fout << data[i].NeedMedicine;
		fout << ",";
		fout << data[i].NeedArt;
		fout << ",";
		fout << data[i].NeedFist;
		fout << ",";
		fout << data[i].NeedSword;
		fout << ",";
		fout << data[i].NeedKnife;
		fout << ",";
		fout << data[i].NeedUnusual;
		fout << ",";
		fout << data[i].NeedHiddenWeapon;
		fout << ",";
		fout << data[i].NeedIQ;
		fout << ",";
		fout << data[i].NeedExp;
		fout << ",";
		fout << data[i].Count;
		fout << ",";
		fout << data[i].Rarity;
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].NeedItem[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].NeedItemCount[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].AddIQ;
		fout << ",";
		fout << data[i].AddFuyuan;
		fout << ",";
		for (int j = 0; j < 8; j++) {
			fout << data[i].Unused[j];
			if (j != 8 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 场景
void NewSave::SaveToCSVSubMapInfoSave(const std::vector<SubMapInfo>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_场景.csv");
	fout << "编号";
	fout << ",";    fout << "名称";
	fout << ",";    fout << "出门音乐";
	fout << ",";    fout << "进门音乐";
	fout << ",";    fout << "场景调色板";
	fout << ",";    fout << "进入条件";
	fout << ",";    fout << "外景入口X1";
	fout << ",";    fout << "外景入口Y1";
	fout << ",";    fout << "外景入口X2";
	fout << ",";    fout << "外景入口Y2";
	fout << ",";    fout << "入口X";
	fout << ",";    fout << "入口Y";
	fout << ",";    fout << "出口X1";
	fout << ",";    fout << "出口X2";
	fout << ",";    fout << "出口X3";
	fout << ",";    fout << "出口Y1";
	fout << ",";    fout << "出口Y2";
	fout << ",";    fout << "出口Y3";
	fout << ",";    fout << "环境";
	fout << ",";    fout << "未用";
	fout << ",";    fout << "所属门派";
	fout << ",";    fout << "战斗中";
	fout << ",";    fout << "总练武场数";
	fout << ",";    fout << "练武场数";
	fout << ",";    fout << "总藏经阁数";
	fout << ",";    fout << "藏经阁数";
	fout << ",";    fout << "练武场X";
	fout << ",";    fout << "练武场X1";
	fout << ",";    fout << "练武场X2";
	fout << ",";    fout << "练武场X3";
	fout << ",";    fout << "练武场X4";
	fout << ",";    fout << "练武场Y";
	fout << ",";    fout << "练武场Y1";
	fout << ",";    fout << "练武场Y2";
	fout << ",";    fout << "练武场Y3";
	fout << ",";    fout << "练武场Y4";
	fout << ",";    fout << "藏经阁X";
	fout << ",";    fout << "藏经阁X1";
	fout << ",";    fout << "藏经阁X2";
	fout << ",";    fout << "藏经阁X3";
	fout << ",";    fout << "藏经阁X4";
	fout << ",";    fout << "藏经阁Y";
	fout << ",";    fout << "藏经阁Y1";
	fout << ",";    fout << "藏经阁Y2";
	fout << ",";    fout << "藏经阁Y3";
	fout << ",";    fout << "藏经阁Y4";
	fout << ",";    fout << "闭关室开关";
	fout << ",";    fout << "闭关室X";
	fout << ",";    fout << "闭关室Y";
	fout << ",";    fout << "炼丹炉开关";
	fout << ",";    fout << "炼丹炉X";
	fout << ",";    fout << "炼丹炉Y";
	fout << ",";    fout << "兵器场开关";
	fout << ",";    fout << "兵器场X";
	fout << ",";    fout << "兵器场Y";
	fout << ",";    fout << "旗帜X";
	fout << ",";    fout << "旗帜Y";
	fout << ",";    fout << "炼丹进度";
	fout << ",";    fout << "锻造进度";
	fout << ",";    fout << "防御加成";
	fout << ",";    fout << "防御设施";
	fout << ",";    fout << "铁矿";
	fout << ",";    fout << "石料";
	fout << ",";    fout << "木材";
	fout << ",";    fout << "食物";
	fout << ",";    fout << "焦炭";
	fout << ",";    fout << "草药";
	fout << ",";    fout << "乌木";
	fout << ",";    fout << "异草";
	fout << ",";    fout << "稀金";
	fout << ",";    fout << "玄铁";
	fout << ",";    fout << "连接";
	fout << ",";    fout << "连接1";
	fout << ",";    fout << "连接2";
	fout << ",";    fout << "连接3";
	fout << ",";    fout << "连接4";
	fout << ",";    fout << "连接5";
	fout << ",";    fout << "连接6";
	fout << ",";    fout << "连接7";
	fout << ",";    fout << "连接8";
	fout << ",";    fout << "连接9";
	fout << ",";    fout << "未使用";
	fout << ",";    fout << "未使用1";
	fout << ",";    fout << "未使用2";
	fout << ",";    fout << "未使用3";
	fout << ",";    fout << "未使用4";
	fout << ",";    fout << "未使用5";
	fout << ",";    fout << "未使用6";
	fout << ",";    fout << "未使用7";
	fout << ",";    fout << "未使用8";
	fout << ",";    fout << "未使用9";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].ExitMusic;
		fout << ",";
		fout << data[i].EntranceMusic;
		fout << ",";
		fout << data[i].SubMapColor;
		fout << ",";
		fout << data[i].EntranceCondition;
		fout << ",";
		fout << data[i].MainEntranceX1;
		fout << ",";
		fout << data[i].MainEntranceY1;
		fout << ",";
		fout << data[i].MainEntranceX2;
		fout << ",";
		fout << data[i].MainEntranceY2;
		fout << ",";
		fout << data[i].EntranceX;
		fout << ",";
		fout << data[i].EntranceY;
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].ExitX[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].ExitY[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].Environment;
		fout << ",";
		fout << data[i].Weiyong;
		fout << ",";
		fout << data[i].menpai;
		fout << ",";
		fout << data[i].inbattle;
		fout << ",";
		fout << data[i].zlwc;
		fout << ",";
		fout << data[i].lwc;
		fout << ",";
		fout << data[i].zcjg;
		fout << ",";
		fout << data[i].cjg;
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].lwcx[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].lwcY[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].cjgx[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].cjgY[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].bgskg;
		fout << ",";
		fout << data[i].bgsx;
		fout << ",";
		fout << data[i].bgsy;
		fout << ",";
		fout << data[i].ldlkg;
		fout << ",";
		fout << data[i].ldlx;
		fout << ",";
		fout << data[i].ldly;
		fout << ",";
		fout << data[i].bqckg;
		fout << ",";
		fout << data[i].bqcx;
		fout << ",";
		fout << data[i].bqcy;
		fout << ",";
		fout << data[i].qizhix;
		fout << ",";
		fout << data[i].qizhiy;
		fout << ",";
		fout << data[i].ldjd;
		fout << ",";
		fout << data[i].dzjd;
		fout << ",";
		fout << data[i].fyjc;
		fout << ",";
		fout << data[i].fyss;
		fout << ",";
		fout << data[i].addtk;
		fout << ",";
		fout << data[i].addsl;
		fout << ",";
		fout << data[i].addmc;
		fout << ",";
		fout << data[i].addsw;
		fout << ",";
		fout << data[i].addjt;
		fout << ",";
		fout << data[i].addcy;
		fout << ",";
		fout << data[i].addwm;
		fout << ",";
		fout << data[i].addyc;
		fout << ",";
		fout << data[i].addxj;
		fout << ",";
		fout << data[i].addxt;
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].lianjie[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].Unused[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 武功
void NewSave::SaveToCSVMagicSave(const std::vector<Magic>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_wugong.csv");
	fout << "编号";
	fout << ",";    fout << "名称";
	fout << ",";    fout << "无用";
	fout << ",";    fout << "秘籍";
	fout << ",";    fout << "需要生命";
	fout << ",";    fout << "最小距离";
	fout << ",";    fout << "是否单图特效";
	fout << ",";    fout << "事件";
	fout << ",";    fout << "出招音效";
	fout << ",";    fout << "武功类型";
	fout << ",";    fout << "武功动画&音效";
	fout << ",";    fout << "内力类型";
	fout << ",";    fout << "攻击范围";
	fout << ",";    fout << "消耗内力";
	fout << ",";    fout << "敌人中毒点数";
	fout << ",";    fout << "最小攻击力";
	fout << ",";    fout << "最大攻击力";
	fout << ",";    fout << "威力系数";
	fout << ",";    fout << "攻击力比重";
	fout << ",";    fout << "内力比重";
	fout << ",";    fout << "轻功比重";
	fout << ",";    fout << "兵器值比重";
	fout << ",";    fout << "是否秘传";
	fout << ",";    fout << "加内力比例";
	fout << ",";    fout << "加生命比例";
	fout << ",";    fout << "移动范围";
	fout << ",";    fout << "移动范围1";
	fout << ",";    fout << "移动范围2";
	fout << ",";    fout << "移动范围3";
	fout << ",";    fout << "移动范围4";
	fout << ",";    fout << "移动范围5";
	fout << ",";    fout << "移动范围6";
	fout << ",";    fout << "移动范围7";
	fout << ",";    fout << "移动范围8";
	fout << ",";    fout << "移动范围9";
	fout << ",";    fout << "杀伤范围";
	fout << ",";    fout << "杀伤范围1";
	fout << ",";    fout << "杀伤范围2";
	fout << ",";    fout << "杀伤范围3";
	fout << ",";    fout << "杀伤范围4";
	fout << ",";    fout << "杀伤范围5";
	fout << ",";    fout << "杀伤范围6";
	fout << ",";    fout << "杀伤范围7";
	fout << ",";    fout << "杀伤范围8";
	fout << ",";    fout << "杀伤范围9";
	fout << ",";    fout << "加生命";
	fout << ",";    fout << "加生命1";
	fout << ",";    fout << "加生命2";
	fout << ",";    fout << "加内力";
	fout << ",";    fout << "加内力1";
	fout << ",";    fout << "加内力2";
	fout << ",";    fout << "加攻击";
	fout << ",";    fout << "加攻击1";
	fout << ",";    fout << "加攻击2";
	fout << ",";    fout << "加防御";
	fout << ",";    fout << "加防御1";
	fout << ",";    fout << "加防御2";
	fout << ",";    fout << "加轻功";
	fout << ",";    fout << "加轻功1";
	fout << ",";    fout << "加轻功2";
	fout << ",";    fout << "最小封穴几率";
	fout << ",";    fout << "最大封穴几率";
	fout << ",";    fout << "最小内伤几率";
	fout << ",";    fout << "最大内伤几率";
	fout << ",";    fout << "增加医疗";
	fout << ",";    fout << "增加毒术";
	fout << ",";    fout << "增加技艺";
	fout << ",";    fout << "增加抗毒";
	fout << ",";    fout << "增加拳掌";
	fout << ",";    fout << "增加御剑";
	fout << ",";    fout << "增加耍刀";
	fout << ",";    fout << "增加特殊";
	fout << ",";    fout << "增加暗器";
	fout << ",";    fout << "状态";
	fout << ",";    fout << "需经验1";
	fout << ",";    fout << "需经验2";
	fout << ",";    fout << "需经验3";
	fout << ",";    fout << "最高等级";
	fout << ",";    fout << "说明";
	fout << ",";    fout << "招式";
	fout << ",";    fout << "招式1";
	fout << ",";    fout << "招式2";
	fout << ",";    fout << "招式3";
	fout << ",";    fout << "招式4";
	fout << ",";    fout << "特殊";
	fout << ",";    fout << "特殊1";
	fout << ",";    fout << "特殊2";
	fout << ",";    fout << "特殊3";
	fout << ",";    fout << "特殊4";
	fout << ",";    fout << "特殊5";
	fout << ",";    fout << "特殊6";
	fout << ",";    fout << "特殊7";
	fout << ",";    fout << "特殊8";
	fout << ",";    fout << "特殊9";
	fout << ",";    fout << "特殊类型";
	fout << ",";    fout << "特殊类型1";
	fout << ",";    fout << "特殊类型2";
	fout << ",";    fout << "特殊类型3";
	fout << ",";    fout << "特殊类型4";
	fout << ",";    fout << "特殊类型5";
	fout << ",";    fout << "特殊类型6";
	fout << ",";    fout << "特殊类型7";
	fout << ",";    fout << "特殊类型8";
	fout << ",";    fout << "特殊类型9";
	fout << ",";    fout << "未使用";
	fout << ",";    fout << "未使用1";
	fout << ",";    fout << "未使用2";
	fout << ",";    fout << "未使用3";
	fout << ",";    fout << "未使用4";
	fout << ",";    fout << "未使用5";
	fout << ",";    fout << "未使用6";
	fout << ",";    fout << "未使用7";
	fout << ",";    fout << "未使用8";
	fout << ",";    fout << "未使用9";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].Wuyong;
		fout << ",";
		fout << data[i].miji;
		fout << ",";
		fout << data[i].NeedHP;
		fout << ",";
		fout << data[i].MinDistance;
		fout << ",";
		fout << data[i].bigami;
		fout << ",";
		fout << data[i].EventNum;
		fout << ",";
		fout << data[i].SoundID;
		fout << ",";
		fout << data[i].MagicType;
		fout << ",";
		fout << data[i].EffectID;
		fout << ",";
		fout << data[i].HurtType;
		fout << ",";
		fout << data[i].AttackAreaType;
		fout << ",";
		fout << data[i].NeedMP;
		fout << ",";
		fout << data[i].WithPoison;
		fout << ",";
		fout << data[i].MinHurt;
		fout << ",";
		fout << data[i].MaxHurt;
		fout << ",";
		fout << data[i].HurtModulus;
		fout << ",";
		fout << data[i].AttackModulus;
		fout << ",";
		fout << data[i].MPModulus;
		fout << ",";
		fout << data[i].SpeedModulus;
		fout << ",";
		fout << data[i].WeaponModulus;
		fout << ",";
		fout << data[i].Ismichuan;
		fout << ",";
		fout << data[i].AddMpScale;
		fout << ",";
		fout << data[i].AddHpScale;
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].SelectDistance[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].AttackDistance[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].AddHP[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].AddMP[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].AddAttack[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].AddDefence[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].AddSpeed[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].MinPeg;
		fout << ",";
		fout << data[i].MaxPeg;
		fout << ",";
		fout << data[i].MinInjury;
		fout << ",";
		fout << data[i].MaxInjury;
		fout << ",";
		fout << data[i].AddMedcine;
		fout << ",";
		fout << data[i].AddUsePoi;
		fout << ",";
		fout << data[i].AddArt;
		fout << ",";
		fout << data[i].AddDefPoi;
		fout << ",";
		fout << data[i].AddFist;
		fout << ",";
		fout << data[i].AddSword;
		fout << ",";
		fout << data[i].AddKnife;
		fout << ",";
		fout << data[i].AddUnusual;
		fout << ",";
		fout << data[i].AddHidWeapon;
		fout << ",";
		fout << data[i].BattleState;;
		fout << ",";
		for (int j = 0; j < 3; j++) {
			fout << data[i].NeedExp[j];
			if (j != 3 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].MaxLevel;
		fout << ",";
		fout << '"' << data[i].Introduction << '"';
		fout << ",";
		for (int j = 0; j < 5; j++) {
			fout << data[i].Zhaoshi[j];
			if (j != 5 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].Teshu[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].Teshumod[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].unused[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 商店
void NewSave::SaveToCSVShopSave(const std::vector<Shop>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_商店.csv");
	fout << "物品编号";
	fout << ",";    fout << "物品编号1";
	fout << ",";    fout << "物品编号2";
	fout << ",";    fout << "物品编号3";
	fout << ",";    fout << "物品编号4";
	fout << ",";    fout << "物品编号5";
	fout << ",";    fout << "物品编号6";
	fout << ",";    fout << "物品编号7";
	fout << ",";    fout << "物品编号8";
	fout << ",";    fout << "物品编号9";
	fout << ",";    fout << "物品编号10";
	fout << ",";    fout << "物品编号11";
	fout << ",";    fout << "物品编号12";
	fout << ",";    fout << "物品编号13";
	fout << ",";    fout << "物品编号14";
	fout << ",";    fout << "物品编号15";
	fout << ",";    fout << "物品编号16";
	fout << ",";    fout << "物品编号17";
	fout << ",";    fout << "物品编号18";
	fout << ",";    fout << "物品编号19";
	fout << ",";    fout << "物品编号20";
	fout << ",";    fout << "物品编号21";
	fout << ",";    fout << "物品编号22";
	fout << ",";    fout << "物品编号23";
	fout << ",";    fout << "物品编号24";
	fout << ",";    fout << "物品编号25";
	fout << ",";    fout << "物品编号26";
	fout << ",";    fout << "物品编号27";
	fout << ",";    fout << "物品编号28";
	fout << ",";    fout << "物品编号29";
	fout << ",";    fout << "物品编号30";
	fout << ",";    fout << "物品编号31";
	fout << ",";    fout << "物品编号32";
	fout << ",";    fout << "物品编号33";
	fout << ",";    fout << "物品编号34";
	fout << ",";    fout << "物品总量";
	fout << ",";    fout << "物品总量1";
	fout << ",";    fout << "物品总量2";
	fout << ",";    fout << "物品总量3";
	fout << ",";    fout << "物品总量4";
	fout << ",";    fout << "物品总量5";
	fout << ",";    fout << "物品总量6";
	fout << ",";    fout << "物品总量7";
	fout << ",";    fout << "物品总量8";
	fout << ",";    fout << "物品总量9";
	fout << ",";    fout << "物品总量10";
	fout << ",";    fout << "物品总量11";
	fout << ",";    fout << "物品总量12";
	fout << ",";    fout << "物品总量13";
	fout << ",";    fout << "物品总量14";
	fout << ",";    fout << "物品总量15";
	fout << ",";    fout << "物品总量16";
	fout << ",";    fout << "物品总量17";
	fout << ",";    fout << "物品总量18";
	fout << ",";    fout << "物品总量19";
	fout << ",";    fout << "物品总量20";
	fout << ",";    fout << "物品总量21";
	fout << ",";    fout << "物品总量22";
	fout << ",";    fout << "物品总量23";
	fout << ",";    fout << "物品总量24";
	fout << ",";    fout << "物品总量25";
	fout << ",";    fout << "物品总量26";
	fout << ",";    fout << "物品总量27";
	fout << ",";    fout << "物品总量28";
	fout << ",";    fout << "物品总量29";
	fout << ",";    fout << "物品总量30";
	fout << ",";    fout << "物品总量31";
	fout << ",";    fout << "物品总量32";
	fout << ",";    fout << "物品总量33";
	fout << ",";    fout << "物品总量34";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 35; j++) {
			fout << data[i].ItemID[j];
			if (j != 35 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 35; j++) {
			fout << data[i].Total[j];
			if (j != 35 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 时间
void NewSave::SaveToCSVTimeSave(TimeSave* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_日期.csv");
	fout << "甲子";
	fout << ",";    fout << "年";
	fout << ",";    fout << "月";
	fout << ",";    fout << "日";
	fout << ",";    fout << "時";
	fout << std::endl;
	for (int i = 0; i < length; i++) {
		fout << data[i].Jiazi;
		fout << ",";
		fout << data[i].Year;
		fout << ",";
		fout << data[i].Month;
		fout << ",";
		fout << data[i].Day;
		fout << ",";
		fout << data[i].Hour;
		fout << std::endl;
	}
}
// 招式
// 招式
void NewSave::SaveToCSVZhaoshiSave(const std::vector<Zhaoshi>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_zhaoshi.csv");
	fout << "编号";
	fout << ",";    fout << "从属";
	fout << ",";    fout << "顺位";
	fout << ",";    fout << "名称";
	fout << ",";    fout << "是否攻击";
	fout << ",";    fout << "攻击加成";
	fout << ",";    fout << "是否防御";
	fout << ",";    fout << "防御加成";
	fout << ",";    fout << "说明";
	fout << ",";    fout << "特效类型";
	fout << ",";    fout << "特效类型1";
	fout << ",";    fout << "特效类型2";
	fout << ",";    fout << "特效类型3";
	fout << ",";    fout << "特效类型4";
	fout << ",";    fout << "特效类型5";
	fout << ",";    fout << "特效类型6";
	fout << ",";    fout << "特效类型7";
	fout << ",";    fout << "特效类型8";
	fout << ",";    fout << "特效类型9";
	fout << ",";    fout << "特效类型10";
	fout << ",";    fout << "特效类型11";
	fout << ",";    fout << "特效类型12";
	fout << ",";    fout << "特效类型13";
	fout << ",";    fout << "特效类型14";
	fout << ",";    fout << "特效类型15";
	fout << ",";    fout << "特效类型16";
	fout << ",";    fout << "特效类型17";
	fout << ",";    fout << "特效类型18";
	fout << ",";    fout << "特效类型19";
	fout << ",";    fout << "特效类型20";
	fout << ",";    fout << "特效类型21";
	fout << ",";    fout << "特效类型22";
	fout << ",";    fout << "特效类型23";
	fout << ",";    fout << "特效数据";
	fout << ",";    fout << "特效数据1";
	fout << ",";    fout << "特效数据2";
	fout << ",";    fout << "特效数据3";
	fout << ",";    fout << "特效数据4";
	fout << ",";    fout << "特效数据5";
	fout << ",";    fout << "特效数据6";
	fout << ",";    fout << "特效数据7";
	fout << ",";    fout << "特效数据8";
	fout << ",";    fout << "特效数据9";
	fout << ",";    fout << "特效数据10";
	fout << ",";    fout << "特效数据11";
	fout << ",";    fout << "特效数据12";
	fout << ",";    fout << "特效数据13";
	fout << ",";    fout << "特效数据14";
	fout << ",";    fout << "特效数据15";
	fout << ",";    fout << "特效数据16";
	fout << ",";    fout << "特效数据17";
	fout << ",";    fout << "特效数据18";
	fout << ",";    fout << "特效数据19";
	fout << ",";    fout << "特效数据20";
	fout << ",";    fout << "特效数据21";
	fout << ",";    fout << "特效数据22";
	fout << ",";    fout << "特效数据23";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << data[i].congshu;
		fout << ",";
		fout << data[i].shunwei;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].ygongji;
		fout << ",";
		fout << data[i].gongji;
		fout << ",";
		fout << data[i].yfangyu;
		fout << ",";
		fout << data[i].fangyu;
		fout << ",";
		fout << '"' << data[i].Introduction << '"';
		fout << ",";
		for (int j = 0; j < 24; j++) {
			fout << data[i].texiao[j].Type;
			if (j != 24 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 24; j++) {
			fout << data[i].texiao[j].Value;
			if (j != 24 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 门派
void NewSave::SaveToCSVMenpaiSave(const std::vector<Menpai>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_门派.csv");
	fout << "编号";
	fout << ",";    fout << "名称";
	fout << ",";    fout << "据点个数";
	fout << ",";    fout << "总舵";
	fout << ",";    fout << "掌门人";
	fout << ",";    fout << "弟子个数";
	fout << ",";    fout << "门派声望";
	fout << ",";    fout << "门派善恶";
	fout << ",";    fout << "铁矿";
	fout << ",";    fout << "石料";
	fout << ",";    fout << "木材";
	fout << ",";    fout << "食物";
	fout << ",";    fout << "焦炭";
	fout << ",";    fout << "草药";
	fout << ",";    fout << "乌木";
	fout << ",";    fout << "异草";
	fout << ",";    fout << "稀金";
	fout << ",";    fout << "玄铁";
	fout << ",";    fout << "铁矿+";
	fout << ",";    fout << "石料+";
	fout << ",";    fout << "木材+";
	fout << ",";    fout << "食物+";
	fout << ",";    fout << "焦炭+";
	fout << ",";    fout << "草药+";
	fout << ",";    fout << "乌木+";
	fout << ",";    fout << "异草+";
	fout << ",";    fout << "稀金+";
	fout << ",";    fout << "玄铁+";
	fout << ",";    fout << "门派内功";
	fout << ",";    fout << "门派内功1";
	fout << ",";    fout << "门派内功2";
	fout << ",";    fout << "门派内功3";
	fout << ",";    fout << "门派内功4";
	fout << ",";    fout << "门派内功5";
	fout << ",";    fout << "门派内功6";
	fout << ",";    fout << "门派内功7";
	fout << ",";    fout << "门派内功8";
	fout << ",";    fout << "门派内功9";
	fout << ",";    fout << "门派内功10";
	fout << ",";    fout << "门派内功11";
	fout << ",";    fout << "门派内功12";
	fout << ",";    fout << "门派内功13";
	fout << ",";    fout << "门派内功14";
	fout << ",";    fout << "门派内功15";
	fout << ",";    fout << "门派内功16";
	fout << ",";    fout << "门派内功17";
	fout << ",";    fout << "门派内功18";
	fout << ",";    fout << "门派内功19";
	fout << ",";    fout << "门派关系";
	fout << ",";    fout << "门派关系1";
	fout << ",";    fout << "门派关系2";
	fout << ",";    fout << "门派关系3";
	fout << ",";    fout << "门派关系4";
	fout << ",";    fout << "门派关系5";
	fout << ",";    fout << "门派关系6";
	fout << ",";    fout << "门派关系7";
	fout << ",";    fout << "门派关系8";
	fout << ",";    fout << "门派关系9";
	fout << ",";    fout << "门派关系10";
	fout << ",";    fout << "门派关系11";
	fout << ",";    fout << "门派关系12";
	fout << ",";    fout << "门派关系13";
	fout << ",";    fout << "门派关系14";
	fout << ",";    fout << "门派关系15";
	fout << ",";    fout << "门派关系16";
	fout << ",";    fout << "门派关系17";
	fout << ",";    fout << "门派关系18";
	fout << ",";    fout << "门派关系19";
	fout << ",";    fout << "门派关系20";
	fout << ",";    fout << "门派关系21";
	fout << ",";    fout << "门派关系22";
	fout << ",";    fout << "门派关系23";
	fout << ",";    fout << "门派关系24";
	fout << ",";    fout << "门派关系25";
	fout << ",";    fout << "门派关系26";
	fout << ",";    fout << "门派关系27";
	fout << ",";    fout << "门派关系28";
	fout << ",";    fout << "门派关系29";
	fout << ",";    fout << "门派关系30";
	fout << ",";    fout << "门派关系31";
	fout << ",";    fout << "门派关系32";
	fout << ",";    fout << "门派关系33";
	fout << ",";    fout << "门派关系34";
	fout << ",";    fout << "门派关系35";
	fout << ",";    fout << "门派关系36";
	fout << ",";    fout << "门派关系37";
	fout << ",";    fout << "门派关系38";
	fout << ",";    fout << "门派关系39";
	fout << ",";    fout << "门派职务";
	fout << ",";    fout << "门派职务1";
	fout << ",";    fout << "门派职务2";
	fout << ",";    fout << "门派职务3";
	fout << ",";    fout << "门派职务4";
	fout << ",";    fout << "门派职务5";
	fout << ",";    fout << "门派职务6";
	fout << ",";    fout << "门派职务7";
	fout << ",";    fout << "门派职务8";
	fout << ",";    fout << "门派职务9";
	fout << ",";    fout << "扩张倾向";
	fout << ",";    fout << "招弟子倾向";
	fout << ",";    fout << "弟子成长速度";
	fout << ",";    fout << "旗帜";
	fout << ",";    fout << "男弟子起图";
	fout << ",";    fout << "男弟子头像";
	fout << ",";    fout << "女弟子起图";
	fout << ",";    fout << "女弟子头像";
	fout << ",";    fout << "弟子性别";
	fout << ",";    fout << "弟子身份";
	fout << ",";    fout << "灭门事件";
	fout << ",";    fout << "同盟";
	fout << ",";    fout << "查找标记";
	fout << ",";    fout << "未定义2";
	fout << ",";    fout << "未定义3";
	fout << ",";    fout << "未定义4";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].jvdian;
		fout << ",";
		fout << data[i].zongduo;
		fout << ",";
		fout << data[i].zmr;
		fout << ",";
		fout << data[i].dizi;
		fout << ",";
		fout << data[i].shengwang;
		fout << ",";
		fout << data[i].shane;
		fout << ",";
		fout << data[i].tiekuang;
		fout << ",";
		fout << data[i].shiliao;
		fout << ",";
		fout << data[i].muchai;
		fout << ",";
		fout << data[i].shiwu;
		fout << ",";
		fout << data[i].jiaotan;
		fout << ",";
		fout << data[i].caoyao;
		fout << ",";
		fout << data[i].wumu;
		fout << ",";
		fout << data[i].yicao;
		fout << ",";
		fout << data[i].xijin;
		fout << ",";
		fout << data[i].xuantie;
		fout << ",";
		fout << data[i].addtiekuang;
		fout << ",";
		fout << data[i].addshiliao;
		fout << ",";
		fout << data[i].addmuchai;
		fout << ",";
		fout << data[i].addshiwu;
		fout << ",";
		fout << data[i].addjiaotan;
		fout << ",";
		fout << data[i].addcaoyao;
		fout << ",";
		fout << data[i].addwumu;
		fout << ",";
		fout << data[i].addyicao;
		fout << ",";
		fout << data[i].addxijin;
		fout << ",";
		fout << data[i].addxuantie;
		fout << ",";
		for (int j = 0; j < 20; j++) {
			fout << data[i].neigong[j];
			if (j != 20 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 40; j++) {
			fout << data[i].guanxi[j];
			if (j != 40 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 10; j++) {
			fout << data[i].zhiwu[j];
			if (j != 10 - 1) fout << ",";
		}
		fout << ",";
		fout << data[i].kzq;
		fout << ",";
		fout << data[i].dzq;
		fout << ",";
		fout << data[i].czsd;
		fout << ",";
		fout << data[i].qizhi;
		fout << ",";
		fout << data[i].mdizigrp;
		fout << ",";
		fout << data[i].mdizipic;
		fout << ",";
		fout << data[i].fdizigrp;
		fout << ",";
		fout << data[i].fdizipic;
		fout << ",";
		fout << data[i].sexy;
		fout << ",";
		fout << data[i].identity;
		fout << ",";
		fout << data[i].endevent;
		fout << ",";
		fout << data[i].tongmeng;
		fout << ",";
		fout << data[i].israndomed;
		fout << ",";
		fout << data[i].unuse2;
		fout << ",";
		fout << data[i].unuse3;
		fout << ",";
		fout << data[i].unuse4;
		fout << std::endl;
	}
}
// 标签
void NewSave::SaveToCSVRSignSave(const std::vector<RSign>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_biaoqian.csv");
	fout << "编号";
	fout << ",";    fout << "名称";
	fout << ",";    fout << "效果";
	fout << ",";    fout << "类别";
	fout << ",";    fout << "说明";
	fout << ",";    fout << "备用";
	fout << ",";    fout << "是否隐藏";
	fout << ",";    fout << "特效类型";
	fout << ",";    fout << "特效类型1";
	fout << ",";    fout << "特效类型2";
	fout << ",";    fout << "特效类型3";
	fout << ",";    fout << "特效类型4";
	fout << ",";    fout << "特效类型5";
	fout << ",";    fout << "特效类型6";
	fout << ",";    fout << "特效类型7";
	fout << ",";    fout << "特效类型8";
	fout << ",";    fout << "特效类型9";
	fout << ",";    fout << "特效类型10";
	fout << ",";    fout << "特效类型11";
	fout << ",";    fout << "特效类型12";
	fout << ",";    fout << "特效类型13";
	fout << ",";    fout << "特效类型14";
	fout << ",";    fout << "特效类型15";
	fout << ",";    fout << "特效类型16";
	fout << ",";    fout << "特效类型17";
	fout << ",";    fout << "特效类型18";
	fout << ",";    fout << "特效类型19";
	fout << ",";    fout << "特效类型20";
	fout << ",";    fout << "特效类型21";
	fout << ",";    fout << "特效类型22";
	fout << ",";    fout << "特效类型23";
	fout << ",";    fout << "特效数据";
	fout << ",";    fout << "特效数据1";
	fout << ",";    fout << "特效数据2";
	fout << ",";    fout << "特效数据3";
	fout << ",";    fout << "特效数据4";
	fout << ",";    fout << "特效数据5";
	fout << ",";    fout << "特效数据6";
	fout << ",";    fout << "特效数据7";
	fout << ",";    fout << "特效数据8";
	fout << ",";    fout << "特效数据9";
	fout << ",";    fout << "特效数据10";
	fout << ",";    fout << "特效数据11";
	fout << ",";    fout << "特效数据12";
	fout << ",";    fout << "特效数据13";
	fout << ",";    fout << "特效数据14";
	fout << ",";    fout << "特效数据15";
	fout << ",";    fout << "特效数据16";
	fout << ",";    fout << "特效数据17";
	fout << ",";    fout << "特效数据18";
	fout << ",";    fout << "特效数据19";
	fout << ",";    fout << "特效数据20";
	fout << ",";    fout << "特效数据21";
	fout << ",";    fout << "特效数据22";
	fout << ",";    fout << "特效数据23";
	fout << std::endl;
	int length = data.size();
	for (int i = 0; i < length; i++) {
		fout << data[i].ID;
		fout << ",";
		fout << '"' << data[i].Name << '"';
		fout << ",";
		fout << data[i].effert;
		fout << ",";
		fout << data[i].TypeNum;
		fout << ",";
		fout << '"' << data[i].Introduction << '"';
		fout << ",";
		fout << data[i].beiyong;
		fout << ",";
		fout << data[i].isshow;
		fout << ",";
		for (int j = 0; j < 24; j++) {
			fout << data[i].texiao[j].Type;
			if (j != 24 - 1) fout << ",";
		}
		fout << ",";
		for (int j = 0; j < 24; j++) {
			fout << data[i].texiao[j].Value;
			if (j != 24 - 1) fout << ",";
		}
		fout << std::endl;
	}
}
// 基本
void NewSave::LoadFromCSVBaseInfo(Save::BaseInfo* data, int length, int record) {
	io::CSVReader<22, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_jiben.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"乘船",
		"场景",
		"人X",
		"人Y",
		"内场景坐标X",
		"内场景坐标Y",
		"人面对方向",
		"船X",
		"船Y",
		"计时",
		"定时事件",
		"随机事件",
		"内场景方向",
		"船面对方向",
		"队伍人数",
		"队友",
		"队友1",
		"队友2",
		"队友3",
		"队友4",
		"队友5",
		"编码"
		);
	auto getDefault = []() {
		Save::BaseInfo nextLineData;
		nextLineData.InShip = 0;
		nextLineData.InSubMap = 0;
		nextLineData.MainMapX = 0;
		nextLineData.MainMapY = 0;
		nextLineData.SubMapX = 0;
		nextLineData.SubMapY = 0;
		nextLineData.FaceTowards = 0;
		nextLineData.ShipX = 0;
		nextLineData.ShipY = 0;
		nextLineData.TimeCount = 0;
		nextLineData.TimeEvent = 0;
		nextLineData.RandomEvent = 0;
		nextLineData.SubmapTowards = 0;
		nextLineData.ShipTowards = 0;
		nextLineData.TeamCount = 0;
		for (int j = 0; j < 6; j++) {
			nextLineData.Team[j] = -1;
		}
		nextLineData.Encode = 0;
		return nextLineData;
	};
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.InShip,
		nextLineData.InSubMap,
		nextLineData.MainMapX,
		nextLineData.MainMapY,
		nextLineData.SubMapX,
		nextLineData.SubMapY,
		nextLineData.FaceTowards,
		nextLineData.ShipX,
		nextLineData.ShipY,
		nextLineData.TimeCount,
		nextLineData.TimeEvent,
		nextLineData.RandomEvent,
		nextLineData.SubmapTowards,
		nextLineData.ShipTowards,
		nextLineData.TeamCount,
		nextLineData.Team[0],
		nextLineData.Team[1],
		nextLineData.Team[2],
		nextLineData.Team[3],
		nextLineData.Team[4],
		nextLineData.Team[5],
		nextLineData.Encode
		)) {
		data[lines] = nextLineData;
		if (lines + 1 == length) break;
		lines++;
		nextLineData = getDefault();
	}
}
// 背包
void NewSave::LoadFromCSVItemList(ItemList* data, int length, int record) {
	io::CSVReader<2, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_背包.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"物品编号",
		"物品数量"
		);
	auto getDefault = []() {
		ItemList nextLineData;
		nextLineData.item_id = -1;
		nextLineData.count = 0;
		return nextLineData;
	};
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.item_id,
		nextLineData.count
		)) {
		data[lines] = nextLineData;
		if (lines + 1 == length) break;
		lines++;
		nextLineData = getDefault();
	}
}
// 人物
void NewSave::LoadFromCSVRoleSave(std::vector<Role>& data, int record) {
	data.clear();
	data.shrink_to_fit();
	io::CSVReader<307, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_renwu.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"头像/战斗代号",
		"生命增长",
		"福缘",
		"姓名",
		"外号",
		"性别",
		"等级",
		"经验值",
		"生命",
		"生命最大值",
		"受伤程度",
		"中毒程度",
		"体力",
		"战斗图编号",
		"装备",
		"装备1",
		"装备2",
		"装备3",
		"装备4",
		"功体",
		"队伍状态",
		"愤怒值",
		"查找标记",
		"行动能力",
		"技能点",
		"战略AI状态",
		"外观",
		"行动时间",
		"难度",
		"忠诚度",
		"药物",
		"内力性质",
		"内力",
		"内力最大值",
		"攻击力",
		"轻功",
		"防御力",
		"医疗",
		"暂缺",
		"技艺",
		"抗毒",
		"拳掌",
		"御剑",
		"耍刀",
		"特殊兵器",
		"暗器技巧",
		"武学常识",
		"品德",
		"毒术",
		"左右互搏",
		"声望",
		"资质",
		"修练物品",
		"修练点数",
		"相性",
		"交情",
		"人物类别",
		"声望倾向",
		"品德倾向",
		"相性倾向",
		"交情倾向",
		"所属门派",
		"师父",
		"师承序位",
		"拜师顺序",
		"仇视门派",
		"仇视门派1",
		"当前位置",
		"内部位置",
		"内部方向",
		"人物状态",
		"练武倾向",
		"冥思倾向",
		"劳动倾向",
		"其他倾向",
		"临时位置",
		"内部临时位置",
		"内部方向1",
		"场景X坐标",
		"场景Y坐标",
		"送书标记",
		"官府贡献",
		"夫妻",
		"年龄",
		"未用1",
		"未用2",
		"未用3",
		"战场ID",
		"所会武功",
		"所会武功1",
		"所会武功2",
		"所会武功3",
		"所会武功4",
		"所会武功5",
		"所会武功6",
		"所会武功7",
		"所会武功8",
		"所会武功9",
		"所会武功10",
		"所会武功11",
		"所会武功12",
		"所会武功13",
		"所会武功14",
		"所会武功15",
		"所会武功16",
		"所会武功17",
		"所会武功18",
		"所会武功19",
		"所会武功20",
		"所会武功21",
		"所会武功22",
		"所会武功23",
		"所会武功24",
		"所会武功25",
		"所会武功26",
		"所会武功27",
		"所会武功28",
		"所会武功29",
		"所会武功30",
		"所会武功31",
		"所会武功32",
		"所会武功33",
		"所会武功34",
		"所会武功35",
		"所会武功36",
		"所会武功37",
		"所会武功38",
		"所会武功39",
		"所会武功等级",
		"所会武功等级1",
		"所会武功等级2",
		"所会武功等级3",
		"所会武功等级4",
		"所会武功等级5",
		"所会武功等级6",
		"所会武功等级7",
		"所会武功等级8",
		"所会武功等级9",
		"所会武功等级10",
		"所会武功等级11",
		"所会武功等级12",
		"所会武功等级13",
		"所会武功等级14",
		"所会武功等级15",
		"所会武功等级16",
		"所会武功等级17",
		"所会武功等级18",
		"所会武功等级19",
		"所会武功等级20",
		"所会武功等级21",
		"所会武功等级22",
		"所会武功等级23",
		"所会武功等级24",
		"所会武功等级25",
		"所会武功等级26",
		"所会武功等级27",
		"所会武功等级28",
		"所会武功等级29",
		"所会武功等级30",
		"所会武功等级31",
		"所会武功等级32",
		"所会武功等级33",
		"所会武功等级34",
		"所会武功等级35",
		"所会武功等级36",
		"所会武功等级37",
		"所会武功等级38",
		"所会武功等级39",
		"携带物品",
		"携带物品1",
		"携带物品2",
		"携带物品3",
		"携带物品4",
		"携带物品5",
		"携带物品6",
		"携带物品7",
		"携带物品8",
		"携带物品数量",
		"携带物品数量1",
		"携带物品数量2",
		"携带物品数量3",
		"携带物品数量4",
		"携带物品数量5",
		"携带物品数量6",
		"携带物品数量7",
		"携带物品数量8",
		"激活武功",
		"激活武功1",
		"激活武功2",
		"激活武功3",
		"激活武功4",
		"激活武功5",
		"激活武功6",
		"激活武功7",
		"激活武功8",
		"激活武功9",
		"所会招式",
		"所会招式1",
		"所会招式2",
		"所会招式3",
		"所会招式4",
		"所会招式5",
		"所会招式6",
		"所会招式7",
		"所会招式8",
		"所会招式9",
		"所会招式10",
		"所会招式11",
		"所会招式12",
		"所会招式13",
		"所会招式14",
		"所会招式15",
		"所会招式16",
		"所会招式17",
		"所会招式18",
		"所会招式19",
		"所会招式20",
		"所会招式21",
		"所会招式22",
		"所会招式23",
		"所会招式24",
		"所会招式25",
		"所会招式26",
		"所会招式27",
		"所会招式28",
		"所会招式29",
		"所会招式30",
		"所会招式31",
		"所会招式32",
		"所会招式33",
		"所会招式34",
		"所会招式35",
		"所会招式36",
		"所会招式37",
		"所会招式38",
		"所会招式39",
		"对话菜单开关",
		"对话事件",
		"状态事件",
		"入队事件",
		"切磋事件",
		"学习事件",
		"事件池1",
		"事件池2",
		"事件池3",
		"离队期限",
		"离队事件",
		"随机值",
		"随机值1",
		"暗箭",
		"医师",
		"装备特技",
		"回血",
		"回内",
		"回体",
		"暴躁",
		"配合",
		"武学",
		"突破",
		"冷静",
		"百变",
		"破气",
		"罩门",
		"变幻",
		"反攻",
		"气功",
		"硬功",
		"灵活",
		"行气",
		"身法",
		"攻击潜力",
		"防御潜力",
		"轻功潜力",
		"拳掌潜力",
		"御剑潜力",
		"耍刀潜力",
		"奇门潜力",
		"暗器潜力",
		"固守",
		"天命",
		"星宿",
		"专长",
		"专长1",
		"专长2",
		"专长3",
		"专长4",
		"特性",
		"特性1",
		"特性2",
		"特性3",
		"特性4",
		"特性5",
		"特性6",
		"特性7",
		"特性8",
		"特性9",
		"门派贡献",
		"未使用",
		"未使用1",
		"未使用2",
		"未使用3",
		"未使用4",
		"未使用5",
		"未使用6",
		"未使用7",
		"未使用8"
		);
	auto getDefault = []() {
		auto nextLineDataHeap = std::make_unique<Role>();
		auto& nextLineData = *nextLineDataHeap;
		nextLineData.ID = 0;
		nextLineData.HeadID = 0;
		nextLineData.IncLife = 0;
		nextLineData.Fuyuan = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		memset(nextLineData.Nick, '\0', sizeof(nextLineData.Nick));
		nextLineData.Sexual = 0;
		nextLineData.Level = 0;
		nextLineData.Exp = 0;
		nextLineData.HP = 0;
		nextLineData.MaxHP = 0;
		nextLineData.Hurt = 0;
		nextLineData.Poison = 0;
		nextLineData.PhysicalPower = 0;
		nextLineData.FightNum = 0;
		for (int j = 0; j < 5; j++) {
			nextLineData.Equip[j] = -1;
		}
		nextLineData.Gongti = 0;
		nextLineData.TeamState = 0;
		nextLineData.Angry = 0;
		nextLineData.isRandomed = 0;
		nextLineData.Moveable = 0;
		nextLineData.skillPoint = 0;
		nextLineData.ZhanLueAI = 0;
		nextLineData.Impression = 0;
		nextLineData.dtime = 0;
		nextLineData.difficulty = 0;
		nextLineData.Zhongcheng = 0;
		nextLineData.reHurt = 0;
		nextLineData.MPType = 0;
		nextLineData.MP = 0;
		nextLineData.MaxMP = 0;
		nextLineData.Attack = 0;
		nextLineData.Speed = 0;
		nextLineData.Defence = 0;
		nextLineData.Medicine = 0;
		nextLineData.Weiyong = 0;
		nextLineData.Art = 0;
		nextLineData.AntiPoison = 0;
		nextLineData.Fist = 0;
		nextLineData.Sword = 0;
		nextLineData.Knife = 0;
		nextLineData.Unusual = 0;
		nextLineData.HiddenWeapon = 0;
		nextLineData.Knowledge = 0;
		nextLineData.Morality = 0;
		nextLineData.AttackWithPoison = 0;
		nextLineData.AttackTwice = 0;
		nextLineData.Fame = 0;
		nextLineData.IQ = 0;
		nextLineData.PracticeItem = -1;
		nextLineData.ExpForItem = 0;
		nextLineData.xiangxing = 0;
		nextLineData.jiaoqing = 0;
		nextLineData.Rtype = 0;
		nextLineData.swq = 0;
		nextLineData.pdq = 0;
		nextLineData.xxq = 0;
		nextLineData.jqq = 0;
		nextLineData.MenPai = 0;
		nextLineData.shifu = 0;
		nextLineData.scsx = 0;
		nextLineData.bssx = 0;
		for (int j = 0; j < 2; j++) {
			nextLineData.Choushi[j] = -1;
		}
		nextLineData.weizhi = 0;
		nextLineData.nweizhi = 0;
		nextLineData.nfangxiang = 0;
		nextLineData.OnStatus = 0;
		nextLineData.lwq = 0;
		nextLineData.msq = 0;
		nextLineData.ldq = 0;
		nextLineData.qtq = 0;
		nextLineData.lsweizhi = 0;
		nextLineData.lsnweizhi = 0;
		nextLineData.lsfangxiang = 0;
		nextLineData.Sx = 0;
		nextLineData.Sy = 0;
		nextLineData.songshu = 0;
		nextLineData.gongxian = 0;
		nextLineData.fuqi = 0;
		nextLineData.age = 0;
		nextLineData.weiyong1 = 0;
		nextLineData.weiyong2 = 0;
		nextLineData.weiyong3 = 0;
		nextLineData.btnum = 0;
		for (int j = 0; j < 40; j++) {
			nextLineData.MagicID[j] = 0;
		}
		for (int j = 0; j < 40; j++) {
			nextLineData.MagicLevel[j] = 0;
		}
		for (int j = 0; j < 9; j++) {
			nextLineData.TakingItem[j] = -1;
		}
		for (int j = 0; j < 9; j++) {
			nextLineData.TakingItemCount[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.JhMagic[j] = 0;
		}
		for (int j = 0; j < 40; j++) {
			nextLineData.LZhaoshi[j] = 0;
		}
		nextLineData.IsEvent = 0;
		nextLineData.TalkEvent = 0;
		nextLineData.StateEvent = 0;
		nextLineData.JoinEvent = 0;
		nextLineData.TestEvent = 0;
		nextLineData.LearnEvent = 0;
		nextLineData.unusedEvent1 = 0;
		nextLineData.unusedEvent2 = 0;
		nextLineData.unusedEvent3 = 0;
		nextLineData.LeaveTime = 0;
		nextLineData.LeaveEvent = 0;
		nextLineData.RandomNum1 = 0;
		nextLineData.RandomNum2 = 0;
		nextLineData.anjian = 0;
		nextLineData.yishi = 0;
		nextLineData.zbtj = 0;
		nextLineData.huixue = 0;
		nextLineData.huinei = 0;
		nextLineData.huiti = 0;
		nextLineData.baozhao = 0;
		nextLineData.peihe = 0;
		nextLineData.wuxue = 0;
		nextLineData.tupo = 0;
		nextLineData.lengjing = 0;
		nextLineData.baibian = 0;
		nextLineData.poqi = 0;
		nextLineData.zhaomen = 0;
		nextLineData.bianhuan = 0;
		nextLineData.fangong = 0;
		nextLineData.qigong = 0;
		nextLineData.yinggong = 0;
		nextLineData.linghuo = 0;
		nextLineData.xingqi = 0;
		nextLineData.shenfa = 0;
		nextLineData.gjql = 0;
		nextLineData.fyql = 0;
		nextLineData.qgql = 0;
		nextLineData.qzql = 0;
		nextLineData.yjql = 0;
		nextLineData.sdql = 0;
		nextLineData.qmql = 0;
		nextLineData.aqql = 0;
		nextLineData.gushou = 0;
		nextLineData.tianmin = 0;
		nextLineData.xingxiu = 0;
		for (int j = 0; j < 5; j++) {
			nextLineData.zhuanchang[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.texing[j] = 0;
		}
		nextLineData.menpaiContribution = 0;
		for (int j = 0; j < 9; j++) {
			nextLineData.Unused[j] = 0;
		}
		return nextLineDataHeap;
	};
	std::string Name__;
	std::string Nick__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData->ID,
		nextLineData->HeadID,
		nextLineData->IncLife,
		nextLineData->Fuyuan,
		Name__,
		Nick__,
		nextLineData->Sexual,
		nextLineData->Level,
		nextLineData->Exp,
		nextLineData->HP,
		nextLineData->MaxHP,
		nextLineData->Hurt,
		nextLineData->Poison,
		nextLineData->PhysicalPower,
		nextLineData->FightNum,
		nextLineData->Equip[0],
		nextLineData->Equip[1],
		nextLineData->Equip[2],
		nextLineData->Equip[3],
		nextLineData->Equip[4],
		nextLineData->Gongti,
		nextLineData->TeamState,
		nextLineData->Angry,
		nextLineData->isRandomed,
		nextLineData->Moveable,
		nextLineData->skillPoint,
		nextLineData->ZhanLueAI,
		nextLineData->Impression,
		nextLineData->dtime,
		nextLineData->difficulty,
		nextLineData->Zhongcheng,
		nextLineData->reHurt,
		nextLineData->MPType,
		nextLineData->MP,
		nextLineData->MaxMP,
		nextLineData->Attack,
		nextLineData->Speed,
		nextLineData->Defence,
		nextLineData->Medicine,
		nextLineData->Weiyong,
		nextLineData->Art,
		nextLineData->AntiPoison,
		nextLineData->Fist,
		nextLineData->Sword,
		nextLineData->Knife,
		nextLineData->Unusual,
		nextLineData->HiddenWeapon,
		nextLineData->Knowledge,
		nextLineData->Morality,
		nextLineData->AttackWithPoison,
		nextLineData->AttackTwice,
		nextLineData->Fame,
		nextLineData->IQ,
		nextLineData->PracticeItem,
		nextLineData->ExpForItem,
		nextLineData->xiangxing,
		nextLineData->jiaoqing,
		nextLineData->Rtype,
		nextLineData->swq,
		nextLineData->pdq,
		nextLineData->xxq,
		nextLineData->jqq,
		nextLineData->MenPai,
		nextLineData->shifu,
		nextLineData->scsx,
		nextLineData->bssx,
		nextLineData->Choushi[0],
		nextLineData->Choushi[1],
		nextLineData->weizhi,
		nextLineData->nweizhi,
		nextLineData->nfangxiang,
		nextLineData->OnStatus,
		nextLineData->lwq,
		nextLineData->msq,
		nextLineData->ldq,
		nextLineData->qtq,
		nextLineData->lsweizhi,
		nextLineData->lsnweizhi,
		nextLineData->lsfangxiang,
		nextLineData->Sx,
		nextLineData->Sy,
		nextLineData->songshu,
		nextLineData->gongxian,
		nextLineData->fuqi,
		nextLineData->age,
		nextLineData->weiyong1,
		nextLineData->weiyong2,
		nextLineData->weiyong3,
		nextLineData->btnum,
		nextLineData->MagicID[0],
		nextLineData->MagicID[1],
		nextLineData->MagicID[2],
		nextLineData->MagicID[3],
		nextLineData->MagicID[4],
		nextLineData->MagicID[5],
		nextLineData->MagicID[6],
		nextLineData->MagicID[7],
		nextLineData->MagicID[8],
		nextLineData->MagicID[9],
		nextLineData->MagicID[10],
		nextLineData->MagicID[11],
		nextLineData->MagicID[12],
		nextLineData->MagicID[13],
		nextLineData->MagicID[14],
		nextLineData->MagicID[15],
		nextLineData->MagicID[16],
		nextLineData->MagicID[17],
		nextLineData->MagicID[18],
		nextLineData->MagicID[19],
		nextLineData->MagicID[20],
		nextLineData->MagicID[21],
		nextLineData->MagicID[22],
		nextLineData->MagicID[23],
		nextLineData->MagicID[24],
		nextLineData->MagicID[25],
		nextLineData->MagicID[26],
		nextLineData->MagicID[27],
		nextLineData->MagicID[28],
		nextLineData->MagicID[29],
		nextLineData->MagicID[30],
		nextLineData->MagicID[31],
		nextLineData->MagicID[32],
		nextLineData->MagicID[33],
		nextLineData->MagicID[34],
		nextLineData->MagicID[35],
		nextLineData->MagicID[36],
		nextLineData->MagicID[37],
		nextLineData->MagicID[38],
		nextLineData->MagicID[39],
		nextLineData->MagicLevel[0],
		nextLineData->MagicLevel[1],
		nextLineData->MagicLevel[2],
		nextLineData->MagicLevel[3],
		nextLineData->MagicLevel[4],
		nextLineData->MagicLevel[5],
		nextLineData->MagicLevel[6],
		nextLineData->MagicLevel[7],
		nextLineData->MagicLevel[8],
		nextLineData->MagicLevel[9],
		nextLineData->MagicLevel[10],
		nextLineData->MagicLevel[11],
		nextLineData->MagicLevel[12],
		nextLineData->MagicLevel[13],
		nextLineData->MagicLevel[14],
		nextLineData->MagicLevel[15],
		nextLineData->MagicLevel[16],
		nextLineData->MagicLevel[17],
		nextLineData->MagicLevel[18],
		nextLineData->MagicLevel[19],
		nextLineData->MagicLevel[20],
		nextLineData->MagicLevel[21],
		nextLineData->MagicLevel[22],
		nextLineData->MagicLevel[23],
		nextLineData->MagicLevel[24],
		nextLineData->MagicLevel[25],
		nextLineData->MagicLevel[26],
		nextLineData->MagicLevel[27],
		nextLineData->MagicLevel[28],
		nextLineData->MagicLevel[29],
		nextLineData->MagicLevel[30],
		nextLineData->MagicLevel[31],
		nextLineData->MagicLevel[32],
		nextLineData->MagicLevel[33],
		nextLineData->MagicLevel[34],
		nextLineData->MagicLevel[35],
		nextLineData->MagicLevel[36],
		nextLineData->MagicLevel[37],
		nextLineData->MagicLevel[38],
		nextLineData->MagicLevel[39],
		nextLineData->TakingItem[0],
		nextLineData->TakingItem[1],
		nextLineData->TakingItem[2],
		nextLineData->TakingItem[3],
		nextLineData->TakingItem[4],
		nextLineData->TakingItem[5],
		nextLineData->TakingItem[6],
		nextLineData->TakingItem[7],
		nextLineData->TakingItem[8],
		nextLineData->TakingItemCount[0],
		nextLineData->TakingItemCount[1],
		nextLineData->TakingItemCount[2],
		nextLineData->TakingItemCount[3],
		nextLineData->TakingItemCount[4],
		nextLineData->TakingItemCount[5],
		nextLineData->TakingItemCount[6],
		nextLineData->TakingItemCount[7],
		nextLineData->TakingItemCount[8],
		nextLineData->JhMagic[0],
		nextLineData->JhMagic[1],
		nextLineData->JhMagic[2],
		nextLineData->JhMagic[3],
		nextLineData->JhMagic[4],
		nextLineData->JhMagic[5],
		nextLineData->JhMagic[6],
		nextLineData->JhMagic[7],
		nextLineData->JhMagic[8],
		nextLineData->JhMagic[9],
		nextLineData->LZhaoshi[0],
		nextLineData->LZhaoshi[1],
		nextLineData->LZhaoshi[2],
		nextLineData->LZhaoshi[3],
		nextLineData->LZhaoshi[4],
		nextLineData->LZhaoshi[5],
		nextLineData->LZhaoshi[6],
		nextLineData->LZhaoshi[7],
		nextLineData->LZhaoshi[8],
		nextLineData->LZhaoshi[9],
		nextLineData->LZhaoshi[10],
		nextLineData->LZhaoshi[11],
		nextLineData->LZhaoshi[12],
		nextLineData->LZhaoshi[13],
		nextLineData->LZhaoshi[14],
		nextLineData->LZhaoshi[15],
		nextLineData->LZhaoshi[16],
		nextLineData->LZhaoshi[17],
		nextLineData->LZhaoshi[18],
		nextLineData->LZhaoshi[19],
		nextLineData->LZhaoshi[20],
		nextLineData->LZhaoshi[21],
		nextLineData->LZhaoshi[22],
		nextLineData->LZhaoshi[23],
		nextLineData->LZhaoshi[24],
		nextLineData->LZhaoshi[25],
		nextLineData->LZhaoshi[26],
		nextLineData->LZhaoshi[27],
		nextLineData->LZhaoshi[28],
		nextLineData->LZhaoshi[29],
		nextLineData->LZhaoshi[30],
		nextLineData->LZhaoshi[31],
		nextLineData->LZhaoshi[32],
		nextLineData->LZhaoshi[33],
		nextLineData->LZhaoshi[34],
		nextLineData->LZhaoshi[35],
		nextLineData->LZhaoshi[36],
		nextLineData->LZhaoshi[37],
		nextLineData->LZhaoshi[38],
		nextLineData->LZhaoshi[39],
		nextLineData->IsEvent,
		nextLineData->TalkEvent,
		nextLineData->StateEvent,
		nextLineData->JoinEvent,
		nextLineData->TestEvent,
		nextLineData->LearnEvent,
		nextLineData->unusedEvent1,
		nextLineData->unusedEvent2,
		nextLineData->unusedEvent3,
		nextLineData->LeaveTime,
		nextLineData->LeaveEvent,
		nextLineData->RandomNum1,
		nextLineData->RandomNum2,
		nextLineData->anjian,
		nextLineData->yishi,
		nextLineData->zbtj,
		nextLineData->huixue,
		nextLineData->huinei,
		nextLineData->huiti,
		nextLineData->baozhao,
		nextLineData->peihe,
		nextLineData->wuxue,
		nextLineData->tupo,
		nextLineData->lengjing,
		nextLineData->baibian,
		nextLineData->poqi,
		nextLineData->zhaomen,
		nextLineData->bianhuan,
		nextLineData->fangong,
		nextLineData->qigong,
		nextLineData->yinggong,
		nextLineData->linghuo,
		nextLineData->xingqi,
		nextLineData->shenfa,
		nextLineData->gjql,
		nextLineData->fyql,
		nextLineData->qgql,
		nextLineData->qzql,
		nextLineData->yjql,
		nextLineData->sdql,
		nextLineData->qmql,
		nextLineData->aqql,
		nextLineData->gushou,
		nextLineData->tianmin,
		nextLineData->xingxiu,
		nextLineData->zhuanchang[0],
		nextLineData->zhuanchang[1],
		nextLineData->zhuanchang[2],
		nextLineData->zhuanchang[3],
		nextLineData->zhuanchang[4],
		nextLineData->texing[0],
		nextLineData->texing[1],
		nextLineData->texing[2],
		nextLineData->texing[3],
		nextLineData->texing[4],
		nextLineData->texing[5],
		nextLineData->texing[6],
		nextLineData->texing[7],
		nextLineData->texing[8],
		nextLineData->texing[9],
		nextLineData->menpaiContribution,
		nextLineData->Unused[0],
		nextLineData->Unused[1],
		nextLineData->Unused[2],
		nextLineData->Unused[3],
		nextLineData->Unused[4],
		nextLineData->Unused[5],
		nextLineData->Unused[6],
		nextLineData->Unused[7],
		nextLineData->Unused[8]
		)) {
		memcpy(nextLineData->Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData->Name) - 1));
		memcpy(nextLineData->Nick, Nick__.data(), std::min(Nick__.size(), sizeof(nextLineData->Nick) - 1));
		data.push_back(*nextLineData);
		lines++;
		nextLineData = getDefault();
		Name__.clear();
		Nick__.clear();
	}
}
// 物品
void NewSave::LoadFromCSVItemSave(std::vector<Item>& data, int record) {
	data.clear();
	io::CSVReader<82, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_物品.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"物品名",
		"物品武功经验",
		"套装号",
		"战斗特效",
		"增加标签",
		"要求性别",
		"恢复伤势",
		"需品德",
		"需声望",
		"增加潜力值",
		"战场号",
		"物品说明",
		"练出武功",
		"暗器动画编号",
		"使用人",
		"装备类型",
		"显示物品说明",
		"类型",
		"商店库存",
		"售价",
		"调用事件",
		"加生命",
		"加生命最大值",
		"加中毒解毒",
		"加体力",
		"改变内力性质",
		"加内力",
		"加内力最大值",
		"加攻击力",
		"加轻功",
		"加防御力",
		"加医疗",
		"加使毒",
		"加技艺",
		"加抗毒",
		"加拳掌",
		"加御剑",
		"加耍刀",
		"加特殊兵器",
		"加暗器技巧",
		"加武学常识",
		"加品德",
		"需生命",
		"加攻击带毒",
		"仅修炼人物",
		"需内力性质",
		"需内力",
		"需攻击力",
		"需轻功",
		"需毒术",
		"需医疗",
		"需技艺",
		"需拳掌",
		"需御剑",
		"需耍刀",
		"需特殊兵器",
		"需暗器",
		"需资质",
		"需经验",
		"数量",
		"稀有度",
		"所需物品",
		"所需物品1",
		"所需物品2",
		"所需物品3",
		"所需物品4",
		"需要物品数量",
		"需要物品数量1",
		"需要物品数量2",
		"需要物品数量3",
		"需要物品数量4",
		"加资质",
		"加富源",
		"未使用",
		"未使用1",
		"未使用2",
		"未使用3",
		"未使用4",
		"未使用5",
		"未使用6",
		"未使用7"
		);
	auto getDefault = []() {
		Item nextLineData;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.ExpofMagic = 0;
		nextLineData.SetNum = 0;
		nextLineData.BattleEffect = 0;
		nextLineData.AddSign = 0;
		nextLineData.needSex = 0;
		nextLineData.rehurt = 0;
		nextLineData.NeedEthics = 0;
		nextLineData.NeedRepute = 0;
		nextLineData.AddQianli = 0;
		nextLineData.BattleNum = 0;
		memset(nextLineData.Introduction, '\0', sizeof(nextLineData.Introduction));
		nextLineData.MagicID = -1;
		nextLineData.HiddenWeaponEffectID = -1;
		nextLineData.User = -1;
		nextLineData.EquipType = -1;
		nextLineData.ShowIntroduction = 0;
		nextLineData.ItemType = 0;
		nextLineData.Inventory = 0;
		nextLineData.Price = 0;
		nextLineData.EventNum = 0;
		nextLineData.AddHP = 0;
		nextLineData.AddMaxHP = 0;
		nextLineData.AddPoison = 0;
		nextLineData.AddPhysicalPower = 0;
		nextLineData.ChangeMPType = -1;
		nextLineData.AddMP = 0;
		nextLineData.AddMaxMP = 0;
		nextLineData.AddAttack = 0;
		nextLineData.AddSpeed = 0;
		nextLineData.AddDefence = 0;
		nextLineData.AddMedicine = 0;
		nextLineData.AddUsePoison = 0;
		nextLineData.AddArt = 0;
		nextLineData.AddAntiPoison = 0;
		nextLineData.AddFist = 0;
		nextLineData.AddSword = 0;
		nextLineData.AddKnife = 0;
		nextLineData.AddUnusual = 0;
		nextLineData.AddHiddenWeapon = 0;
		nextLineData.AddKnowledge = 0;
		nextLineData.AddMorality = 0;
		nextLineData.NeedHP = 0;
		nextLineData.AddAttackWithPoison = 0;
		nextLineData.OnlySuitableRole = -1;
		nextLineData.NeedMPType = 0;
		nextLineData.NeedMP = 0;
		nextLineData.NeedAttack = 0;
		nextLineData.NeedSpeed = 0;
		nextLineData.NeedUsePoison = 0;
		nextLineData.NeedMedicine = 0;
		nextLineData.NeedArt = 0;
		nextLineData.NeedFist = 0;
		nextLineData.NeedSword = 0;
		nextLineData.NeedKnife = 0;
		nextLineData.NeedUnusual = 0;
		nextLineData.NeedHiddenWeapon = 0;
		nextLineData.NeedIQ = 0;
		nextLineData.NeedExp = 0;
		nextLineData.Count = 0;
		nextLineData.Rarity = -1;
		for (int j = 0; j < 5; j++) {
			nextLineData.NeedItem[j] = -1;
		}
		for (int j = 0; j < 5; j++) {
			nextLineData.NeedItemCount[j] = 0;
		}
		nextLineData.AddIQ = 0;
		nextLineData.AddFuyuan = 0;
		for (int j = 0; j < 8; j++) {
			nextLineData.Unused[j] = 0;
		}
		return nextLineData;
	};
	std::string Name__;
	std::string Introduction__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.ExpofMagic,
		nextLineData.SetNum,
		nextLineData.BattleEffect,
		nextLineData.AddSign,
		nextLineData.needSex,
		nextLineData.rehurt,
		nextLineData.NeedEthics,
		nextLineData.NeedRepute,
		nextLineData.AddQianli,
		nextLineData.BattleNum,
		Introduction__,
		nextLineData.MagicID,
		nextLineData.HiddenWeaponEffectID,
		nextLineData.User,
		nextLineData.EquipType,
		nextLineData.ShowIntroduction,
		nextLineData.ItemType,
		nextLineData.Inventory,
		nextLineData.Price,
		nextLineData.EventNum,
		nextLineData.AddHP,
		nextLineData.AddMaxHP,
		nextLineData.AddPoison,
		nextLineData.AddPhysicalPower,
		nextLineData.ChangeMPType,
		nextLineData.AddMP,
		nextLineData.AddMaxMP,
		nextLineData.AddAttack,
		nextLineData.AddSpeed,
		nextLineData.AddDefence,
		nextLineData.AddMedicine,
		nextLineData.AddUsePoison,
		nextLineData.AddArt,
		nextLineData.AddAntiPoison,
		nextLineData.AddFist,
		nextLineData.AddSword,
		nextLineData.AddKnife,
		nextLineData.AddUnusual,
		nextLineData.AddHiddenWeapon,
		nextLineData.AddKnowledge,
		nextLineData.AddMorality,
		nextLineData.NeedHP,
		nextLineData.AddAttackWithPoison,
		nextLineData.OnlySuitableRole,
		nextLineData.NeedMPType,
		nextLineData.NeedMP,
		nextLineData.NeedAttack,
		nextLineData.NeedSpeed,
		nextLineData.NeedUsePoison,
		nextLineData.NeedMedicine,
		nextLineData.NeedArt,
		nextLineData.NeedFist,
		nextLineData.NeedSword,
		nextLineData.NeedKnife,
		nextLineData.NeedUnusual,
		nextLineData.NeedHiddenWeapon,
		nextLineData.NeedIQ,
		nextLineData.NeedExp,
		nextLineData.Count,
		nextLineData.Rarity,
		nextLineData.NeedItem[0],
		nextLineData.NeedItem[1],
		nextLineData.NeedItem[2],
		nextLineData.NeedItem[3],
		nextLineData.NeedItem[4],
		nextLineData.NeedItemCount[0],
		nextLineData.NeedItemCount[1],
		nextLineData.NeedItemCount[2],
		nextLineData.NeedItemCount[3],
		nextLineData.NeedItemCount[4],
		nextLineData.AddIQ,
		nextLineData.AddFuyuan,
		nextLineData.Unused[0],
		nextLineData.Unused[1],
		nextLineData.Unused[2],
		nextLineData.Unused[3],
		nextLineData.Unused[4],
		nextLineData.Unused[5],
		nextLineData.Unused[6],
		nextLineData.Unused[7]
		)) {
		memcpy(nextLineData.Introduction, Introduction__.data(), sizeof(nextLineData.Introduction) - 1);
		memcpy(nextLineData.Name, Name__.data(), sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
		Introduction__.clear();
		Name__.clear();
	}
}
// 场景
void NewSave::LoadFromCSVSubMapInfoSave(std::vector<SubMapInfo>& data, int record) {
	data.clear();
	io::CSVReader<91, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_场景.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"名称",
		"出门音乐",
		"进门音乐",
		"场景调色板",
		"进入条件",
		"外景入口X1",
		"外景入口Y1",
		"外景入口X2",
		"外景入口Y2",
		"入口X",
		"入口Y",
		"出口X1",
		"出口X2",
		"出口X3",
		"出口Y1",
		"出口Y2",
		"出口Y3",
		"环境",
		"未用",
		"所属门派",
		"战斗中",
		"总练武场数",
		"练武场数",
		"总藏经阁数",
		"藏经阁数",
		"练武场X",
		"练武场X1",
		"练武场X2",
		"练武场X3",
		"练武场X4",
		"练武场Y",
		"练武场Y1",
		"练武场Y2",
		"练武场Y3",
		"练武场Y4",
		"藏经阁X",
		"藏经阁X1",
		"藏经阁X2",
		"藏经阁X3",
		"藏经阁X4",
		"藏经阁Y",
		"藏经阁Y1",
		"藏经阁Y2",
		"藏经阁Y3",
		"藏经阁Y4",
		"闭关室开关",
		"闭关室X",
		"闭关室Y",
		"炼丹炉开关",
		"炼丹炉X",
		"炼丹炉Y",
		"兵器场开关",
		"兵器场X",
		"兵器场Y",
		"旗帜X",
		"旗帜Y",
		"炼丹进度",
		"锻造进度",
		"防御加成",
		"防御设施",
		"铁矿",
		"石料",
		"木材",
		"食物",
		"焦炭",
		"草药",
		"乌木",
		"异草",
		"稀金",
		"玄铁",
		"连接",
		"连接1",
		"连接2",
		"连接3",
		"连接4",
		"连接5",
		"连接6",
		"连接7",
		"连接8",
		"连接9",
		"未使用",
		"未使用1",
		"未使用2",
		"未使用3",
		"未使用4",
		"未使用5",
		"未使用6",
		"未使用7",
		"未使用8",
		"未使用9"
		);
	auto getDefault = []() {
		auto nextLineDataHeap = std::make_unique<SubMapInfo>();
		auto& nextLineData = *nextLineDataHeap;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.ExitMusic = 0;
		nextLineData.EntranceMusic = -1;
		nextLineData.SubMapColor = -1;
		nextLineData.EntranceCondition = 0;
		nextLineData.MainEntranceX1 = 0;
		nextLineData.MainEntranceY1 = 0;
		nextLineData.MainEntranceX2 = 0;
		nextLineData.MainEntranceY2 = 0;
		nextLineData.EntranceX = 0;
		nextLineData.EntranceY = 0;
		for (int j = 0; j < 3; j++) {
			nextLineData.ExitX[j] = -1;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.ExitY[j] = -1;
		}
		nextLineData.Environment = 0;
		nextLineData.Weiyong = 0;
		nextLineData.menpai = 0;
		nextLineData.inbattle = 0;
		nextLineData.zlwc = 0;
		nextLineData.lwc = 0;
		nextLineData.zcjg = 0;
		nextLineData.cjg = 0;
		for (int j = 0; j < 5; j++) {
			nextLineData.lwcx[j] = -1;
		}
		for (int j = 0; j < 5; j++) {
			nextLineData.lwcY[j] = -1;
		}
		for (int j = 0; j < 5; j++) {
			nextLineData.cjgx[j] = -1;
		}
		for (int j = 0; j < 5; j++) {
			nextLineData.cjgY[j] = -1;
		}
		nextLineData.bgskg = 0;
		nextLineData.bgsx = 0;
		nextLineData.bgsy = 0;
		nextLineData.ldlkg = 0;
		nextLineData.ldlx = 0;
		nextLineData.ldly = 0;
		nextLineData.bqckg = 0;
		nextLineData.bqcx = 0;
		nextLineData.bqcy = 0;
		nextLineData.qizhix = 0;
		nextLineData.qizhiy = 0;
		nextLineData.ldjd = 0;
		nextLineData.dzjd = 0;
		nextLineData.fyjc = 0;
		nextLineData.fyss = 0;
		nextLineData.addtk = 0;
		nextLineData.addsl = 0;
		nextLineData.addmc = 0;
		nextLineData.addsw = 0;
		nextLineData.addjt = 0;
		nextLineData.addcy = 0;
		nextLineData.addwm = 0;
		nextLineData.addyc = 0;
		nextLineData.addxj = 0;
		nextLineData.addxt = 0;
		for (int j = 0; j < 10; j++) {
			nextLineData.lianjie[j] = -1;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.Unused[j] = -1;
		}
		return nextLineDataHeap;
	};
	std::string Name__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData->ID,
		Name__,
		nextLineData->ExitMusic,
		nextLineData->EntranceMusic,
		nextLineData->SubMapColor,
		nextLineData->EntranceCondition,
		nextLineData->MainEntranceX1,
		nextLineData->MainEntranceY1,
		nextLineData->MainEntranceX2,
		nextLineData->MainEntranceY2,
		nextLineData->EntranceX,
		nextLineData->EntranceY,
		nextLineData->ExitX[0],
		nextLineData->ExitX[1],
		nextLineData->ExitX[2],
		nextLineData->ExitY[0],
		nextLineData->ExitY[1],
		nextLineData->ExitY[2],
		nextLineData->Environment,
		nextLineData->Weiyong,
		nextLineData->menpai,
		nextLineData->inbattle,
		nextLineData->zlwc,
		nextLineData->lwc,
		nextLineData->zcjg,
		nextLineData->cjg,
		nextLineData->lwcx[0],
		nextLineData->lwcx[1],
		nextLineData->lwcx[2],
		nextLineData->lwcx[3],
		nextLineData->lwcx[4],
		nextLineData->lwcY[0],
		nextLineData->lwcY[1],
		nextLineData->lwcY[2],
		nextLineData->lwcY[3],
		nextLineData->lwcY[4],
		nextLineData->cjgx[0],
		nextLineData->cjgx[1],
		nextLineData->cjgx[2],
		nextLineData->cjgx[3],
		nextLineData->cjgx[4],
		nextLineData->cjgY[0],
		nextLineData->cjgY[1],
		nextLineData->cjgY[2],
		nextLineData->cjgY[3],
		nextLineData->cjgY[4],
		nextLineData->bgskg,
		nextLineData->bgsx,
		nextLineData->bgsy,
		nextLineData->ldlkg,
		nextLineData->ldlx,
		nextLineData->ldly,
		nextLineData->bqckg,
		nextLineData->bqcx,
		nextLineData->bqcy,
		nextLineData->qizhix,
		nextLineData->qizhiy,
		nextLineData->ldjd,
		nextLineData->dzjd,
		nextLineData->fyjc,
		nextLineData->fyss,
		nextLineData->addtk,
		nextLineData->addsl,
		nextLineData->addmc,
		nextLineData->addsw,
		nextLineData->addjt,
		nextLineData->addcy,
		nextLineData->addwm,
		nextLineData->addyc,
		nextLineData->addxj,
		nextLineData->addxt,
		nextLineData->lianjie[0],
		nextLineData->lianjie[1],
		nextLineData->lianjie[2],
		nextLineData->lianjie[3],
		nextLineData->lianjie[4],
		nextLineData->lianjie[5],
		nextLineData->lianjie[6],
		nextLineData->lianjie[7],
		nextLineData->lianjie[8],
		nextLineData->lianjie[9],
		nextLineData->Unused[0],
		nextLineData->Unused[1],
		nextLineData->Unused[2],
		nextLineData->Unused[3],
		nextLineData->Unused[4],
		nextLineData->Unused[5],
		nextLineData->Unused[6],
		nextLineData->Unused[7],
		nextLineData->Unused[8],
		nextLineData->Unused[9]
		)) {
		memcpy(nextLineData->Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData->Name) - 1));
		data.push_back(*nextLineData);
		lines++;
		nextLineData = getDefault();
		Name__.clear();
	}
}
// 武功
void NewSave::LoadFromCSVMagicSave(std::vector<Magic>& data, int record) {
	data.clear();
	io::CSVReader<114, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_wugong.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"名称",
		"无用",
		"秘籍",
		"需要生命",
		"最小距离",
		"是否单图特效",
		"事件",
		"出招音效",
		"武功类型",
		"武功动画&音效",
		"内力类型",
		"攻击范围",
		"消耗内力",
		"敌人中毒点数",
		"最小攻击力",
		"最大攻击力",
		"威力系数",
		"攻击力比重",
		"内力比重",
		"轻功比重",
		"兵器值比重",
		"是否秘传",
		"加内力比例",
		"加生命比例",
		"移动范围",
		"移动范围1",
		"移动范围2",
		"移动范围3",
		"移动范围4",
		"移动范围5",
		"移动范围6",
		"移动范围7",
		"移动范围8",
		"移动范围9",
		"杀伤范围",
		"杀伤范围1",
		"杀伤范围2",
		"杀伤范围3",
		"杀伤范围4",
		"杀伤范围5",
		"杀伤范围6",
		"杀伤范围7",
		"杀伤范围8",
		"杀伤范围9",
		"加生命",
		"加生命1",
		"加生命2",
		"加内力",
		"加内力1",
		"加内力2",
		"加攻击",
		"加攻击1",
		"加攻击2",
		"加防御",
		"加防御1",
		"加防御2",
		"加轻功",
		"加轻功1",
		"加轻功2",
		"最小封穴几率",
		"最大封穴几率",
		"最小内伤几率",
		"最大内伤几率",
		"增加医疗",
		"增加毒术",
		"增加技艺",
		"增加抗毒",
		"增加拳掌",
		"增加御剑",
		"增加耍刀",
		"增加特殊",
		"增加暗器",
		"状态",
		"需经验1",
		"需经验2",
		"需经验3",
		"最高等级",
		"说明",
		"招式",
		"招式1",
		"招式2",
		"招式3",
		"招式4",
		"特殊",
		"特殊1",
		"特殊2",
		"特殊3",
		"特殊4",
		"特殊5",
		"特殊6",
		"特殊7",
		"特殊8",
		"特殊9",
		"特殊类型",
		"特殊类型1",
		"特殊类型2",
		"特殊类型3",
		"特殊类型4",
		"特殊类型5",
		"特殊类型6",
		"特殊类型7",
		"特殊类型8",
		"特殊类型9",
		"未使用",
		"未使用1",
		"未使用2",
		"未使用3",
		"未使用4",
		"未使用5",
		"未使用6",
		"未使用7",
		"未使用8",
		"未使用9"
		);
	auto getDefault = []() {
		Magic nextLineData;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.Wuyong = 0;
		nextLineData.miji = 0;
		nextLineData.NeedHP = 0;
		nextLineData.MinDistance = 0;
		nextLineData.bigami = 0;
		nextLineData.EventNum = 0;
		nextLineData.SoundID = 0;
		nextLineData.MagicType = 0;
		nextLineData.EffectID = 0;
		nextLineData.HurtType = 0;
		nextLineData.AttackAreaType = 0;
		nextLineData.NeedMP = 0;
		nextLineData.WithPoison = 0;
		nextLineData.MinHurt = 0;
		nextLineData.MaxHurt = 0;
		nextLineData.HurtModulus = 0;
		nextLineData.AttackModulus = 0;
		nextLineData.MPModulus = 0;
		nextLineData.SpeedModulus = 0;
		nextLineData.WeaponModulus = 0;
		nextLineData.Ismichuan = 0;
		nextLineData.AddMpScale = 0;
		nextLineData.AddHpScale = 0;
		for (int j = 0; j < 10; j++) {
			nextLineData.SelectDistance[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.AttackDistance[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.AddHP[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.AddMP[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.AddAttack[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.AddDefence[j] = 0;
		}
		for (int j = 0; j < 3; j++) {
			nextLineData.AddSpeed[j] = 0;
		}
		nextLineData.MinPeg = 0;
		nextLineData.MaxPeg = 0;
		nextLineData.MinInjury = 0;
		nextLineData.MaxInjury = 0;
		nextLineData.AddMedcine = 0;
		nextLineData.AddUsePoi = 0;
		nextLineData.AddArt = 0;
		nextLineData.AddDefPoi = 0;
		nextLineData.AddFist = 0;
		nextLineData.AddSword = 0;
		nextLineData.AddKnife = 0;
		nextLineData.AddUnusual = 0;
		nextLineData.AddHidWeapon = 0;
		nextLineData.BattleState = 0;
		for (int j = 0; j < 3; j++) {
			nextLineData.NeedExp[j] = 0;
		}
		nextLineData.MaxLevel = 0;
		memset(nextLineData.Introduction, '\0', sizeof(nextLineData.Introduction));
		for (int j = 0; j < 5; j++) {
			nextLineData.Zhaoshi[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.Teshu[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.Teshumod[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.unused[j] = 0;
		}
		return nextLineData;
	};
	std::string Name__;
	std::string Introduction__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.Wuyong,
		nextLineData.miji,
		nextLineData.NeedHP,
		nextLineData.MinDistance,
		nextLineData.bigami,
		nextLineData.EventNum,
		nextLineData.SoundID,
		nextLineData.MagicType,
		nextLineData.EffectID,
		nextLineData.HurtType,
		nextLineData.AttackAreaType,
		nextLineData.NeedMP,
		nextLineData.WithPoison,
		nextLineData.MinHurt,
		nextLineData.MaxHurt,
		nextLineData.HurtModulus,
		nextLineData.AttackModulus,
		nextLineData.MPModulus,
		nextLineData.SpeedModulus,
		nextLineData.WeaponModulus,
		nextLineData.Ismichuan,
		nextLineData.AddMpScale,
		nextLineData.AddHpScale,
		nextLineData.SelectDistance[0],
		nextLineData.SelectDistance[1],
		nextLineData.SelectDistance[2],
		nextLineData.SelectDistance[3],
		nextLineData.SelectDistance[4],
		nextLineData.SelectDistance[5],
		nextLineData.SelectDistance[6],
		nextLineData.SelectDistance[7],
		nextLineData.SelectDistance[8],
		nextLineData.SelectDistance[9],
		nextLineData.AttackDistance[0],
		nextLineData.AttackDistance[1],
		nextLineData.AttackDistance[2],
		nextLineData.AttackDistance[3],
		nextLineData.AttackDistance[4],
		nextLineData.AttackDistance[5],
		nextLineData.AttackDistance[6],
		nextLineData.AttackDistance[7],
		nextLineData.AttackDistance[8],
		nextLineData.AttackDistance[9],
		nextLineData.AddHP[0],
		nextLineData.AddHP[1],
		nextLineData.AddHP[2],
		nextLineData.AddMP[0],
		nextLineData.AddMP[1],
		nextLineData.AddMP[2],
		nextLineData.AddAttack[0],
		nextLineData.AddAttack[1],
		nextLineData.AddAttack[2],
		nextLineData.AddDefence[0],
		nextLineData.AddDefence[1],
		nextLineData.AddDefence[2],
		nextLineData.AddSpeed[0],
		nextLineData.AddSpeed[1],
		nextLineData.AddSpeed[2],
		nextLineData.MinPeg,
		nextLineData.MaxPeg,
		nextLineData.MinInjury,
		nextLineData.MaxInjury,
		nextLineData.AddMedcine,
		nextLineData.AddUsePoi,
		nextLineData.AddArt,
		nextLineData.AddDefPoi,
		nextLineData.AddFist,
		nextLineData.AddSword,
		nextLineData.AddKnife,
		nextLineData.AddUnusual,
		nextLineData.AddHidWeapon,
		nextLineData.BattleState,
		nextLineData.NeedExp[0],
		nextLineData.NeedExp[1],
		nextLineData.NeedExp[2],
		nextLineData.MaxLevel,
		Introduction__,
		nextLineData.Zhaoshi[0],
		nextLineData.Zhaoshi[1],
		nextLineData.Zhaoshi[2],
		nextLineData.Zhaoshi[3],
		nextLineData.Zhaoshi[4],
		nextLineData.Teshu[0],
		nextLineData.Teshu[1],
		nextLineData.Teshu[2],
		nextLineData.Teshu[3],
		nextLineData.Teshu[4],
		nextLineData.Teshu[5],
		nextLineData.Teshu[6],
		nextLineData.Teshu[7],
		nextLineData.Teshu[8],
		nextLineData.Teshu[9],
		nextLineData.Teshumod[0],
		nextLineData.Teshumod[1],
		nextLineData.Teshumod[2],
		nextLineData.Teshumod[3],
		nextLineData.Teshumod[4],
		nextLineData.Teshumod[5],
		nextLineData.Teshumod[6],
		nextLineData.Teshumod[7],
		nextLineData.Teshumod[8],
		nextLineData.Teshumod[9],
		nextLineData.unused[0],
		nextLineData.unused[1],
		nextLineData.unused[2],
		nextLineData.unused[3],
		nextLineData.unused[4],
		nextLineData.unused[5],
		nextLineData.unused[6],
		nextLineData.unused[7],
		nextLineData.unused[8],
		nextLineData.unused[9]
		)) {
		memcpy(nextLineData.Introduction, Introduction__.data(), std::min(Introduction__.size(), sizeof(nextLineData.Introduction) - 1));
		memcpy(nextLineData.Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData.Name) - 1));
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// 商店
void NewSave::LoadFromCSVShopSave(std::vector<Shop>& data, int record) {
	data.clear();
	io::CSVReader<70, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_商店.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"物品编号",
		"物品编号1",
		"物品编号2",
		"物品编号3",
		"物品编号4",
		"物品编号5",
		"物品编号6",
		"物品编号7",
		"物品编号8",
		"物品编号9",
		"物品编号10",
		"物品编号11",
		"物品编号12",
		"物品编号13",
		"物品编号14",
		"物品编号15",
		"物品编号16",
		"物品编号17",
		"物品编号18",
		"物品编号19",
		"物品编号20",
		"物品编号21",
		"物品编号22",
		"物品编号23",
		"物品编号24",
		"物品编号25",
		"物品编号26",
		"物品编号27",
		"物品编号28",
		"物品编号29",
		"物品编号30",
		"物品编号31",
		"物品编号32",
		"物品编号33",
		"物品编号34",
		"物品总量",
		"物品总量1",
		"物品总量2",
		"物品总量3",
		"物品总量4",
		"物品总量5",
		"物品总量6",
		"物品总量7",
		"物品总量8",
		"物品总量9",
		"物品总量10",
		"物品总量11",
		"物品总量12",
		"物品总量13",
		"物品总量14",
		"物品总量15",
		"物品总量16",
		"物品总量17",
		"物品总量18",
		"物品总量19",
		"物品总量20",
		"物品总量21",
		"物品总量22",
		"物品总量23",
		"物品总量24",
		"物品总量25",
		"物品总量26",
		"物品总量27",
		"物品总量28",
		"物品总量29",
		"物品总量30",
		"物品总量31",
		"物品总量32",
		"物品总量33",
		"物品总量34"
		);
	auto getDefault = []() {
		Shop nextLineData;
		for (int j = 0; j < 35; j++) {
			nextLineData.ItemID[j] = -1;
		}
		for (int j = 0; j < 35; j++) {
			nextLineData.Total[j] = 0;
		}
		return nextLineData;
	};
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ItemID[0],
		nextLineData.ItemID[1],
		nextLineData.ItemID[2],
		nextLineData.ItemID[3],
		nextLineData.ItemID[4],
		nextLineData.ItemID[5],
		nextLineData.ItemID[6],
		nextLineData.ItemID[7],
		nextLineData.ItemID[8],
		nextLineData.ItemID[9],
		nextLineData.ItemID[10],
		nextLineData.ItemID[11],
		nextLineData.ItemID[12],
		nextLineData.ItemID[13],
		nextLineData.ItemID[14],
		nextLineData.ItemID[15],
		nextLineData.ItemID[16],
		nextLineData.ItemID[17],
		nextLineData.ItemID[18],
		nextLineData.ItemID[19],
		nextLineData.ItemID[20],
		nextLineData.ItemID[21],
		nextLineData.ItemID[22],
		nextLineData.ItemID[23],
		nextLineData.ItemID[24],
		nextLineData.ItemID[25],
		nextLineData.ItemID[26],
		nextLineData.ItemID[27],
		nextLineData.ItemID[28],
		nextLineData.ItemID[29],
		nextLineData.ItemID[30],
		nextLineData.ItemID[31],
		nextLineData.ItemID[32],
		nextLineData.ItemID[33],
		nextLineData.ItemID[34],
		nextLineData.Total[0],
		nextLineData.Total[1],
		nextLineData.Total[2],
		nextLineData.Total[3],
		nextLineData.Total[4],
		nextLineData.Total[5],
		nextLineData.Total[6],
		nextLineData.Total[7],
		nextLineData.Total[8],
		nextLineData.Total[9],
		nextLineData.Total[10],
		nextLineData.Total[11],
		nextLineData.Total[12],
		nextLineData.Total[13],
		nextLineData.Total[14],
		nextLineData.Total[15],
		nextLineData.Total[16],
		nextLineData.Total[17],
		nextLineData.Total[18],
		nextLineData.Total[19],
		nextLineData.Total[20],
		nextLineData.Total[21],
		nextLineData.Total[22],
		nextLineData.Total[23],
		nextLineData.Total[24],
		nextLineData.Total[25],
		nextLineData.Total[26],
		nextLineData.Total[27],
		nextLineData.Total[28],
		nextLineData.Total[29],
		nextLineData.Total[30],
		nextLineData.Total[31],
		nextLineData.Total[32],
		nextLineData.Total[33],
		nextLineData.Total[34]
		)) {
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// 时间
void NewSave::LoadFromCSVTimeSave(TimeSave* data, int length, int record) {
	io::CSVReader<5, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_日期.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"甲子",
		"年",
		"月",
		"日",
		"時"
		);
	auto getDefault = []() {
		TimeSave nextLineData;
		nextLineData.Jiazi = 0;
		nextLineData.Year = 0;
		nextLineData.Month = 0;
		nextLineData.Day = 0;
		nextLineData.Hour = 0;
		return nextLineData;
	};
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.Jiazi,
		nextLineData.Year,
		nextLineData.Month,
		nextLineData.Day,
		nextLineData.Hour
		)) {
		data[lines] = nextLineData;
		if (lines + 1 == length) break;
		lines++;
		nextLineData = getDefault();
	}
}
// 招式
void NewSave::LoadFromCSVZhaoshiSave(std::vector<Zhaoshi>& data, int record) {
	data.clear();
	io::CSVReader<57, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_zhaoshi.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"从属",
		"顺位",
		"名称",
		"是否攻击",
		"攻击加成",
		"是否防御",
		"防御加成",
		"说明",
		"特效类型",
		"特效类型1",
		"特效类型2",
		"特效类型3",
		"特效类型4",
		"特效类型5",
		"特效类型6",
		"特效类型7",
		"特效类型8",
		"特效类型9",
		"特效类型10",
		"特效类型11",
		"特效类型12",
		"特效类型13",
		"特效类型14",
		"特效类型15",
		"特效类型16",
		"特效类型17",
		"特效类型18",
		"特效类型19",
		"特效类型20",
		"特效类型21",
		"特效类型22",
		"特效类型23",
		"特效数据",
		"特效数据1",
		"特效数据2",
		"特效数据3",
		"特效数据4",
		"特效数据5",
		"特效数据6",
		"特效数据7",
		"特效数据8",
		"特效数据9",
		"特效数据10",
		"特效数据11",
		"特效数据12",
		"特效数据13",
		"特效数据14",
		"特效数据15",
		"特效数据16",
		"特效数据17",
		"特效数据18",
		"特效数据19",
		"特效数据20",
		"特效数据21",
		"特效数据22",
		"特效数据23"
		);
	auto getDefault = []() {
		Zhaoshi nextLineData;
		nextLineData.ID = 0;
		nextLineData.congshu = 0;
		nextLineData.shunwei = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.ygongji = 0;
		nextLineData.gongji = 0;
		nextLineData.yfangyu = 0;
		nextLineData.fangyu = 0;
		memset(nextLineData.Introduction, '\0', sizeof(nextLineData.Introduction));
		for (int j = 0; j < 24; j++) {
			nextLineData.texiao[j].Type = -1;
		}
		for (int j = 0; j < 24; j++) {
			nextLineData.texiao[j].Value = 0;
		}
		return nextLineData;
	};
	std::string Name__;
	std::string Introduction__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		nextLineData.congshu,
		nextLineData.shunwei,
		Name__,
		nextLineData.ygongji,
		nextLineData.gongji,
		nextLineData.yfangyu,
		nextLineData.fangyu,
		Introduction__,
		nextLineData.texiao[0].Type,
		nextLineData.texiao[1].Type,
		nextLineData.texiao[2].Type,
		nextLineData.texiao[3].Type,
		nextLineData.texiao[4].Type,
		nextLineData.texiao[5].Type,
		nextLineData.texiao[6].Type,
		nextLineData.texiao[7].Type,
		nextLineData.texiao[8].Type,
		nextLineData.texiao[9].Type,
		nextLineData.texiao[10].Type,
		nextLineData.texiao[11].Type,
		nextLineData.texiao[12].Type,
		nextLineData.texiao[13].Type,
		nextLineData.texiao[14].Type,
		nextLineData.texiao[15].Type,
		nextLineData.texiao[16].Type,
		nextLineData.texiao[17].Type,
		nextLineData.texiao[18].Type,
		nextLineData.texiao[19].Type,
		nextLineData.texiao[20].Type,
		nextLineData.texiao[21].Type,
		nextLineData.texiao[22].Type,
		nextLineData.texiao[23].Type,
		nextLineData.texiao[0].Value,
		nextLineData.texiao[1].Value,
		nextLineData.texiao[2].Value,
		nextLineData.texiao[3].Value,
		nextLineData.texiao[4].Value,
		nextLineData.texiao[5].Value,
		nextLineData.texiao[6].Value,
		nextLineData.texiao[7].Value,
		nextLineData.texiao[8].Value,
		nextLineData.texiao[9].Value,
		nextLineData.texiao[10].Value,
		nextLineData.texiao[11].Value,
		nextLineData.texiao[12].Value,
		nextLineData.texiao[13].Value,
		nextLineData.texiao[14].Value,
		nextLineData.texiao[15].Value,
		nextLineData.texiao[16].Value,
		nextLineData.texiao[17].Value,
		nextLineData.texiao[18].Value,
		nextLineData.texiao[19].Value,
		nextLineData.texiao[20].Value,
		nextLineData.texiao[21].Value,
		nextLineData.texiao[22].Value,
		nextLineData.texiao[23].Value
		)) {
		memcpy(nextLineData.Introduction, Introduction__.data(), std::min(Introduction__.size(), sizeof(nextLineData.Introduction) - 1));
		memcpy(nextLineData.Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData.Name) - 1));
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
		Introduction__.clear();
		Name__.clear();
	}
}
// 门派
void NewSave::LoadFromCSVMenpaiSave(std::vector<Menpai>& data, int record) {
	data.clear();
	io::CSVReader<114, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_门派.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"名称",
		"据点个数",
		"总舵",
		"掌门人",
		"弟子个数",
		"门派声望",
		"门派善恶",
		"铁矿",
		"石料",
		"木材",
		"食物",
		"焦炭",
		"草药",
		"乌木",
		"异草",
		"稀金",
		"玄铁",
		"铁矿+",
		"石料+",
		"木材+",
		"食物+",
		"焦炭+",
		"草药+",
		"乌木+",
		"异草+",
		"稀金+",
		"玄铁+",
		"门派内功",
		"门派内功1",
		"门派内功2",
		"门派内功3",
		"门派内功4",
		"门派内功5",
		"门派内功6",
		"门派内功7",
		"门派内功8",
		"门派内功9",
		"门派内功10",
		"门派内功11",
		"门派内功12",
		"门派内功13",
		"门派内功14",
		"门派内功15",
		"门派内功16",
		"门派内功17",
		"门派内功18",
		"门派内功19",
		"门派关系",
		"门派关系1",
		"门派关系2",
		"门派关系3",
		"门派关系4",
		"门派关系5",
		"门派关系6",
		"门派关系7",
		"门派关系8",
		"门派关系9",
		"门派关系10",
		"门派关系11",
		"门派关系12",
		"门派关系13",
		"门派关系14",
		"门派关系15",
		"门派关系16",
		"门派关系17",
		"门派关系18",
		"门派关系19",
		"门派关系20",
		"门派关系21",
		"门派关系22",
		"门派关系23",
		"门派关系24",
		"门派关系25",
		"门派关系26",
		"门派关系27",
		"门派关系28",
		"门派关系29",
		"门派关系30",
		"门派关系31",
		"门派关系32",
		"门派关系33",
		"门派关系34",
		"门派关系35",
		"门派关系36",
		"门派关系37",
		"门派关系38",
		"门派关系39",
		"门派职务",
		"门派职务1",
		"门派职务2",
		"门派职务3",
		"门派职务4",
		"门派职务5",
		"门派职务6",
		"门派职务7",
		"门派职务8",
		"门派职务9",
		"扩张倾向",
		"招弟子倾向",
		"弟子成长速度",
		"旗帜",
		"男弟子起图",
		"男弟子头像",
		"女弟子起图",
		"女弟子头像",
		"弟子性别",
		"弟子身份",
		"灭门事件",
		"同盟",
		"查找标记",
		"未定义2",
		"未定义3",
		"未定义4"
		);
	auto getDefault = []() {
		Menpai nextLineData;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.jvdian = 0;
		nextLineData.zongduo = 0;
		nextLineData.zmr = 0;
		nextLineData.dizi = 0;
		nextLineData.shengwang = 0;
		nextLineData.shane = 0;
		nextLineData.tiekuang = 0;
		nextLineData.shiliao = 0;
		nextLineData.muchai = 0;
		nextLineData.shiwu = 0;
		nextLineData.jiaotan = 0;
		nextLineData.caoyao = 0;
		nextLineData.wumu = 0;
		nextLineData.yicao = 0;
		nextLineData.xijin = 0;
		nextLineData.xuantie = 0;
		nextLineData.addtiekuang = 0;
		nextLineData.addshiliao = 0;
		nextLineData.addmuchai = 0;
		nextLineData.addshiwu = 0;
		nextLineData.addjiaotan = 0;
		nextLineData.addcaoyao = 0;
		nextLineData.addwumu = 0;
		nextLineData.addyicao = 0;
		nextLineData.addxijin = 0;
		nextLineData.addxuantie = 0;
		for (int j = 0; j < 20; j++) {
			nextLineData.neigong[j] = -1;
		}
		for (int j = 0; j < 40; j++) {
			nextLineData.guanxi[j] = 0;
		}
		for (int j = 0; j < 10; j++) {
			nextLineData.zhiwu[j] = 0;
		}
		nextLineData.kzq = 0;
		nextLineData.dzq = 0;
		nextLineData.czsd = 0;
		nextLineData.qizhi = 0;
		nextLineData.mdizigrp = 0;
		nextLineData.mdizipic = 0;
		nextLineData.fdizigrp = 0;
		nextLineData.fdizipic = 0;
		nextLineData.sexy = 0;
		nextLineData.identity = 0;
		nextLineData.endevent = 0;
		nextLineData.tongmeng = 0;
		nextLineData.israndomed = 0;
		nextLineData.unuse2 = 0;
		nextLineData.unuse3 = 0;
		nextLineData.unuse4 = 0;
		return nextLineData;
	};
	std::string Name__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.jvdian,
		nextLineData.zongduo,
		nextLineData.zmr,
		nextLineData.dizi,
		nextLineData.shengwang,
		nextLineData.shane,
		nextLineData.tiekuang,
		nextLineData.shiliao,
		nextLineData.muchai,
		nextLineData.shiwu,
		nextLineData.jiaotan,
		nextLineData.caoyao,
		nextLineData.wumu,
		nextLineData.yicao,
		nextLineData.xijin,
		nextLineData.xuantie,
		nextLineData.addtiekuang,
		nextLineData.addshiliao,
		nextLineData.addmuchai,
		nextLineData.addshiwu,
		nextLineData.addjiaotan,
		nextLineData.addcaoyao,
		nextLineData.addwumu,
		nextLineData.addyicao,
		nextLineData.addxijin,
		nextLineData.addxuantie,
		nextLineData.neigong[0],
		nextLineData.neigong[1],
		nextLineData.neigong[2],
		nextLineData.neigong[3],
		nextLineData.neigong[4],
		nextLineData.neigong[5],
		nextLineData.neigong[6],
		nextLineData.neigong[7],
		nextLineData.neigong[8],
		nextLineData.neigong[9],
		nextLineData.neigong[10],
		nextLineData.neigong[11],
		nextLineData.neigong[12],
		nextLineData.neigong[13],
		nextLineData.neigong[14],
		nextLineData.neigong[15],
		nextLineData.neigong[16],
		nextLineData.neigong[17],
		nextLineData.neigong[18],
		nextLineData.neigong[19],
		nextLineData.guanxi[0],
		nextLineData.guanxi[1],
		nextLineData.guanxi[2],
		nextLineData.guanxi[3],
		nextLineData.guanxi[4],
		nextLineData.guanxi[5],
		nextLineData.guanxi[6],
		nextLineData.guanxi[7],
		nextLineData.guanxi[8],
		nextLineData.guanxi[9],
		nextLineData.guanxi[10],
		nextLineData.guanxi[11],
		nextLineData.guanxi[12],
		nextLineData.guanxi[13],
		nextLineData.guanxi[14],
		nextLineData.guanxi[15],
		nextLineData.guanxi[16],
		nextLineData.guanxi[17],
		nextLineData.guanxi[18],
		nextLineData.guanxi[19],
		nextLineData.guanxi[20],
		nextLineData.guanxi[21],
		nextLineData.guanxi[22],
		nextLineData.guanxi[23],
		nextLineData.guanxi[24],
		nextLineData.guanxi[25],
		nextLineData.guanxi[26],
		nextLineData.guanxi[27],
		nextLineData.guanxi[28],
		nextLineData.guanxi[29],
		nextLineData.guanxi[30],
		nextLineData.guanxi[31],
		nextLineData.guanxi[32],
		nextLineData.guanxi[33],
		nextLineData.guanxi[34],
		nextLineData.guanxi[35],
		nextLineData.guanxi[36],
		nextLineData.guanxi[37],
		nextLineData.guanxi[38],
		nextLineData.guanxi[39],
		nextLineData.zhiwu[0],
		nextLineData.zhiwu[1],
		nextLineData.zhiwu[2],
		nextLineData.zhiwu[3],
		nextLineData.zhiwu[4],
		nextLineData.zhiwu[5],
		nextLineData.zhiwu[6],
		nextLineData.zhiwu[7],
		nextLineData.zhiwu[8],
		nextLineData.zhiwu[9],
		nextLineData.kzq,
		nextLineData.dzq,
		nextLineData.czsd,
		nextLineData.qizhi,
		nextLineData.mdizigrp,
		nextLineData.mdizipic,
		nextLineData.fdizigrp,
		nextLineData.fdizipic,
		nextLineData.sexy,
		nextLineData.identity,
		nextLineData.endevent,
		nextLineData.tongmeng,
		nextLineData.israndomed,
		nextLineData.unuse2,
		nextLineData.unuse3,
		nextLineData.unuse4
		)) {
		memcpy(nextLineData.Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData.Name) - 1));
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
		Name__.clear();
	}
}
// 标签
void NewSave::LoadFromCSVRSignSave(std::vector<RSign>& data, int record) {
	data.clear();
	io::CSVReader<55, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_biaoqian.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"编号",
		"名称",
		"效果",
		"类别",
		"说明",
		"备用",
		"是否隐藏",
		"特效类型",
		"特效类型1",
		"特效类型2",
		"特效类型3",
		"特效类型4",
		"特效类型5",
		"特效类型6",
		"特效类型7",
		"特效类型8",
		"特效类型9",
		"特效类型10",
		"特效类型11",
		"特效类型12",
		"特效类型13",
		"特效类型14",
		"特效类型15",
		"特效类型16",
		"特效类型17",
		"特效类型18",
		"特效类型19",
		"特效类型20",
		"特效类型21",
		"特效类型22",
		"特效类型23",
		"特效数据",
		"特效数据1",
		"特效数据2",
		"特效数据3",
		"特效数据4",
		"特效数据5",
		"特效数据6",
		"特效数据7",
		"特效数据8",
		"特效数据9",
		"特效数据10",
		"特效数据11",
		"特效数据12",
		"特效数据13",
		"特效数据14",
		"特效数据15",
		"特效数据16",
		"特效数据17",
		"特效数据18",
		"特效数据19",
		"特效数据20",
		"特效数据21",
		"特效数据22",
		"特效数据23"
		);
	auto getDefault = []() {
		RSign nextLineData;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.effert = 0;
		nextLineData.TypeNum = 0;
		memset(nextLineData.Introduction, '\0', sizeof(nextLineData.Introduction));
		nextLineData.beiyong = 0;
		nextLineData.isshow = 0;
		for (int j = 0; j < 24; j++) {
			nextLineData.texiao[j].Type = -1;
		}
		for (int j = 0; j < 24; j++) {
			nextLineData.texiao[j].Value = -1;
		}
		return nextLineData;
	};
	std::string Name__;
	std::string Introduction__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.effert,
		nextLineData.TypeNum,
		Introduction__,
		nextLineData.beiyong,
		nextLineData.isshow,
		nextLineData.texiao[0].Type,
		nextLineData.texiao[1].Type,
		nextLineData.texiao[2].Type,
		nextLineData.texiao[3].Type,
		nextLineData.texiao[4].Type,
		nextLineData.texiao[5].Type,
		nextLineData.texiao[6].Type,
		nextLineData.texiao[7].Type,
		nextLineData.texiao[8].Type,
		nextLineData.texiao[9].Type,
		nextLineData.texiao[10].Type,
		nextLineData.texiao[11].Type,
		nextLineData.texiao[12].Type,
		nextLineData.texiao[13].Type,
		nextLineData.texiao[14].Type,
		nextLineData.texiao[15].Type,
		nextLineData.texiao[16].Type,
		nextLineData.texiao[17].Type,
		nextLineData.texiao[18].Type,
		nextLineData.texiao[19].Type,
		nextLineData.texiao[20].Type,
		nextLineData.texiao[21].Type,
		nextLineData.texiao[22].Type,
		nextLineData.texiao[23].Type,
		nextLineData.texiao[0].Value,
		nextLineData.texiao[1].Value,
		nextLineData.texiao[2].Value,
		nextLineData.texiao[3].Value,
		nextLineData.texiao[4].Value,
		nextLineData.texiao[5].Value,
		nextLineData.texiao[6].Value,
		nextLineData.texiao[7].Value,
		nextLineData.texiao[8].Value,
		nextLineData.texiao[9].Value,
		nextLineData.texiao[10].Value,
		nextLineData.texiao[11].Value,
		nextLineData.texiao[12].Value,
		nextLineData.texiao[13].Value,
		nextLineData.texiao[14].Value,
		nextLineData.texiao[15].Value,
		nextLineData.texiao[16].Value,
		nextLineData.texiao[16].Value,
		nextLineData.texiao[18].Value,
		nextLineData.texiao[19].Value,
		nextLineData.texiao[20].Value,
		nextLineData.texiao[21].Value,
		nextLineData.texiao[22].Value,
		nextLineData.texiao[23].Value
		)) {
		memcpy(nextLineData.Introduction, Introduction__.data(), std::min(Introduction__.size(), sizeof(nextLineData.Introduction) - 1));
		memcpy(nextLineData.Name, Name__.data(), std::min(Name__.size(), sizeof(nextLineData.Name) - 1));
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
		Name__.clear();
		Introduction__.clear();
	}
}
void NewSave::InsertRoleAt(std::vector<Role>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();

	for (auto& p : Save::getInstance()->getItems()) {
		if (p->User >= idx) p->User += 1;
		if (p->OnlySuitableRole >= idx) p->OnlySuitableRole += 1;
	}
}
void NewSave::InsertItemAt(std::vector<Item>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
	for (auto& p : Save::getInstance()->Items) {
		if (p.item_id >= idx) p.item_id += 1;
	}
	for (auto& p : Save::getInstance()->getRoles()) {
		if (p->Equip[0] >= idx) p->Equip[0] += 1;
		if (p->Equip[1] >= idx) p->Equip[1] += 1;
		if (p->Equip[2] >= idx) p->Equip[2] += 1;
		if (p->Equip[3] >= idx) p->Equip[3] += 1;
		if (p->Equip[4] >= idx) p->Equip[4] += 1;
		if (p->PracticeItem >= idx) p->PracticeItem += 1;
		if (p->TakingItem[0] >= idx) p->TakingItem[0] += 1;
		if (p->TakingItem[1] >= idx) p->TakingItem[1] += 1;
		if (p->TakingItem[2] >= idx) p->TakingItem[2] += 1;
		if (p->TakingItem[3] >= idx) p->TakingItem[3] += 1;
		if (p->TakingItem[4] >= idx) p->TakingItem[4] += 1;
		if (p->TakingItem[5] >= idx) p->TakingItem[5] += 1;
		if (p->TakingItem[6] >= idx) p->TakingItem[6] += 1;
		if (p->TakingItem[7] >= idx) p->TakingItem[7] += 1;
		if (p->TakingItem[8] >= idx) p->TakingItem[8] += 1;
	}
	for (auto& p : Save::getInstance()->getItems()) {
		if (p->NeedItem[0] >= idx) p->NeedItem[0] += 1;
		if (p->NeedItem[1] >= idx) p->NeedItem[1] += 1;
		if (p->NeedItem[2] >= idx) p->NeedItem[2] += 1;
		if (p->NeedItem[3] >= idx) p->NeedItem[3] += 1;
		if (p->NeedItem[4] >= idx) p->NeedItem[4] += 1;
	}
	for (auto& p : Save::getInstance()->getShops()) {
		if (p->ItemID[0] >= idx) p->ItemID[0] += 1;
		if (p->ItemID[1] >= idx) p->ItemID[1] += 1;
		if (p->ItemID[2] >= idx) p->ItemID[2] += 1;
		if (p->ItemID[3] >= idx) p->ItemID[3] += 1;
		if (p->ItemID[4] >= idx) p->ItemID[4] += 1;
		if (p->ItemID[5] >= idx) p->ItemID[5] += 1;
		if (p->ItemID[6] >= idx) p->ItemID[6] += 1;
		if (p->ItemID[7] >= idx) p->ItemID[7] += 1;
		if (p->ItemID[8] >= idx) p->ItemID[8] += 1;
		if (p->ItemID[9] >= idx) p->ItemID[9] += 1;
		if (p->ItemID[10] >= idx) p->ItemID[10] += 1;
		if (p->ItemID[11] >= idx) p->ItemID[11] += 1;
		if (p->ItemID[12] >= idx) p->ItemID[12] += 1;
		if (p->ItemID[13] >= idx) p->ItemID[13] += 1;
		if (p->ItemID[14] >= idx) p->ItemID[14] += 1;
		if (p->ItemID[15] >= idx) p->ItemID[15] += 1;
		if (p->ItemID[16] >= idx) p->ItemID[16] += 1;
		if (p->ItemID[17] >= idx) p->ItemID[17] += 1;
		if (p->ItemID[18] >= idx) p->ItemID[18] += 1;
		if (p->ItemID[19] >= idx) p->ItemID[19] += 1;
		if (p->ItemID[20] >= idx) p->ItemID[20] += 1;
		if (p->ItemID[21] >= idx) p->ItemID[21] += 1;
		if (p->ItemID[22] >= idx) p->ItemID[22] += 1;
		if (p->ItemID[23] >= idx) p->ItemID[23] += 1;
		if (p->ItemID[24] >= idx) p->ItemID[24] += 1;
		if (p->ItemID[25] >= idx) p->ItemID[25] += 1;
		if (p->ItemID[26] >= idx) p->ItemID[26] += 1;
		if (p->ItemID[27] >= idx) p->ItemID[27] += 1;
		if (p->ItemID[28] >= idx) p->ItemID[28] += 1;
		if (p->ItemID[29] >= idx) p->ItemID[29] += 1;
		if (p->ItemID[30] >= idx) p->ItemID[30] += 1;
		if (p->ItemID[31] >= idx) p->ItemID[31] += 1;
		if (p->ItemID[32] >= idx) p->ItemID[32] += 1;
		if (p->ItemID[33] >= idx) p->ItemID[33] += 1;
		if (p->ItemID[34] >= idx) p->ItemID[34] += 1;
	}
	for (auto& p : Save::getInstance()->getZhaoshis()) {
		if (p->texiao[0].Type >= idx) p->texiao[0].Type += 1;
		if (p->texiao[1].Type >= idx) p->texiao[1].Type += 1;
		if (p->texiao[2].Type >= idx) p->texiao[2].Type += 1;
		if (p->texiao[3].Type >= idx) p->texiao[3].Type += 1;
		if (p->texiao[4].Type >= idx) p->texiao[4].Type += 1;
		if (p->texiao[5].Type >= idx) p->texiao[5].Type += 1;
		if (p->texiao[6].Type >= idx) p->texiao[6].Type += 1;
		if (p->texiao[7].Type >= idx) p->texiao[7].Type += 1;
		if (p->texiao[8].Type >= idx) p->texiao[8].Type += 1;
		if (p->texiao[9].Type >= idx) p->texiao[9].Type += 1;
		if (p->texiao[10].Type >= idx) p->texiao[10].Type += 1;
		if (p->texiao[11].Type >= idx) p->texiao[11].Type += 1;
		if (p->texiao[12].Type >= idx) p->texiao[12].Type += 1;
		if (p->texiao[13].Type >= idx) p->texiao[13].Type += 1;
		if (p->texiao[14].Type >= idx) p->texiao[14].Type += 1;
		if (p->texiao[15].Type >= idx) p->texiao[15].Type += 1;
		if (p->texiao[16].Type >= idx) p->texiao[16].Type += 1;
		if (p->texiao[17].Type >= idx) p->texiao[17].Type += 1;
		if (p->texiao[18].Type >= idx) p->texiao[18].Type += 1;
		if (p->texiao[19].Type >= idx) p->texiao[19].Type += 1;
		if (p->texiao[20].Type >= idx) p->texiao[20].Type += 1;
		if (p->texiao[21].Type >= idx) p->texiao[21].Type += 1;
		if (p->texiao[22].Type >= idx) p->texiao[22].Type += 1;
		if (p->texiao[23].Type >= idx) p->texiao[23].Type += 1;
	}
}
void NewSave::InsertSubMapInfoAt(std::vector<SubMapInfo>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
}
void NewSave::InsertMagicAt(std::vector<Magic>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
	for (auto& p : Save::getInstance()->getRoles()) {
		if (p->MagicID[0] >= idx) p->MagicID[0] += 1;
		if (p->MagicID[1] >= idx) p->MagicID[1] += 1;
		if (p->MagicID[2] >= idx) p->MagicID[2] += 1;
		if (p->MagicID[3] >= idx) p->MagicID[3] += 1;
		if (p->MagicID[4] >= idx) p->MagicID[4] += 1;
		if (p->MagicID[5] >= idx) p->MagicID[5] += 1;
		if (p->MagicID[6] >= idx) p->MagicID[6] += 1;
		if (p->MagicID[7] >= idx) p->MagicID[7] += 1;
		if (p->MagicID[8] >= idx) p->MagicID[8] += 1;
		if (p->MagicID[9] >= idx) p->MagicID[9] += 1;
		if (p->MagicID[10] >= idx) p->MagicID[10] += 1;
		if (p->MagicID[11] >= idx) p->MagicID[11] += 1;
		if (p->MagicID[12] >= idx) p->MagicID[12] += 1;
		if (p->MagicID[13] >= idx) p->MagicID[13] += 1;
		if (p->MagicID[14] >= idx) p->MagicID[14] += 1;
		if (p->MagicID[15] >= idx) p->MagicID[15] += 1;
		if (p->MagicID[16] >= idx) p->MagicID[16] += 1;
		if (p->MagicID[17] >= idx) p->MagicID[17] += 1;
		if (p->MagicID[18] >= idx) p->MagicID[18] += 1;
		if (p->MagicID[19] >= idx) p->MagicID[19] += 1;
		if (p->MagicID[20] >= idx) p->MagicID[20] += 1;
		if (p->MagicID[21] >= idx) p->MagicID[21] += 1;
		if (p->MagicID[22] >= idx) p->MagicID[22] += 1;
		if (p->MagicID[23] >= idx) p->MagicID[23] += 1;
		if (p->MagicID[24] >= idx) p->MagicID[24] += 1;
		if (p->MagicID[25] >= idx) p->MagicID[25] += 1;
		if (p->MagicID[26] >= idx) p->MagicID[26] += 1;
		if (p->MagicID[27] >= idx) p->MagicID[27] += 1;
		if (p->MagicID[28] >= idx) p->MagicID[28] += 1;
		if (p->MagicID[29] >= idx) p->MagicID[29] += 1;
		if (p->MagicID[30] >= idx) p->MagicID[30] += 1;
		if (p->MagicID[31] >= idx) p->MagicID[31] += 1;
		if (p->MagicID[32] >= idx) p->MagicID[32] += 1;
		if (p->MagicID[33] >= idx) p->MagicID[33] += 1;
		if (p->MagicID[34] >= idx) p->MagicID[34] += 1;
		if (p->MagicID[35] >= idx) p->MagicID[35] += 1;
		if (p->MagicID[36] >= idx) p->MagicID[36] += 1;
		if (p->MagicID[37] >= idx) p->MagicID[37] += 1;
		if (p->MagicID[38] >= idx) p->MagicID[38] += 1;
		if (p->MagicID[39] >= idx) p->MagicID[39] += 1;
		if (p->JhMagic[0] >= idx) p->JhMagic[0] += 1;
		if (p->JhMagic[1] >= idx) p->JhMagic[1] += 1;
		if (p->JhMagic[2] >= idx) p->JhMagic[2] += 1;
		if (p->JhMagic[3] >= idx) p->JhMagic[3] += 1;
		if (p->JhMagic[4] >= idx) p->JhMagic[4] += 1;
		if (p->JhMagic[5] >= idx) p->JhMagic[5] += 1;
		if (p->JhMagic[6] >= idx) p->JhMagic[6] += 1;
		if (p->JhMagic[7] >= idx) p->JhMagic[7] += 1;
		if (p->JhMagic[8] >= idx) p->JhMagic[8] += 1;
		if (p->JhMagic[9] >= idx) p->JhMagic[9] += 1;
		if (p->LZhaoshi[0] >= idx) p->LZhaoshi[0] += 1;
		if (p->LZhaoshi[1] >= idx) p->LZhaoshi[1] += 1;
		if (p->LZhaoshi[2] >= idx) p->LZhaoshi[2] += 1;
		if (p->LZhaoshi[3] >= idx) p->LZhaoshi[3] += 1;
		if (p->LZhaoshi[4] >= idx) p->LZhaoshi[4] += 1;
		if (p->LZhaoshi[5] >= idx) p->LZhaoshi[5] += 1;
		if (p->LZhaoshi[6] >= idx) p->LZhaoshi[6] += 1;
		if (p->LZhaoshi[7] >= idx) p->LZhaoshi[7] += 1;
		if (p->LZhaoshi[8] >= idx) p->LZhaoshi[8] += 1;
		if (p->LZhaoshi[9] >= idx) p->LZhaoshi[9] += 1;
		if (p->LZhaoshi[10] >= idx) p->LZhaoshi[10] += 1;
		if (p->LZhaoshi[11] >= idx) p->LZhaoshi[11] += 1;
		if (p->LZhaoshi[12] >= idx) p->LZhaoshi[12] += 1;
		if (p->LZhaoshi[13] >= idx) p->LZhaoshi[13] += 1;
		if (p->LZhaoshi[14] >= idx) p->LZhaoshi[14] += 1;
		if (p->LZhaoshi[15] >= idx) p->LZhaoshi[15] += 1;
		if (p->LZhaoshi[16] >= idx) p->LZhaoshi[16] += 1;
		if (p->LZhaoshi[17] >= idx) p->LZhaoshi[17] += 1;
		if (p->LZhaoshi[18] >= idx) p->LZhaoshi[18] += 1;
		if (p->LZhaoshi[19] >= idx) p->LZhaoshi[19] += 1;
		if (p->LZhaoshi[20] >= idx) p->LZhaoshi[20] += 1;
		if (p->LZhaoshi[21] >= idx) p->LZhaoshi[21] += 1;
		if (p->LZhaoshi[22] >= idx) p->LZhaoshi[22] += 1;
		if (p->LZhaoshi[23] >= idx) p->LZhaoshi[23] += 1;
		if (p->LZhaoshi[24] >= idx) p->LZhaoshi[24] += 1;
		if (p->LZhaoshi[25] >= idx) p->LZhaoshi[25] += 1;
		if (p->LZhaoshi[26] >= idx) p->LZhaoshi[26] += 1;
		if (p->LZhaoshi[27] >= idx) p->LZhaoshi[27] += 1;
		if (p->LZhaoshi[28] >= idx) p->LZhaoshi[28] += 1;
		if (p->LZhaoshi[29] >= idx) p->LZhaoshi[29] += 1;
		if (p->LZhaoshi[30] >= idx) p->LZhaoshi[30] += 1;
		if (p->LZhaoshi[31] >= idx) p->LZhaoshi[31] += 1;
		if (p->LZhaoshi[32] >= idx) p->LZhaoshi[32] += 1;
		if (p->LZhaoshi[33] >= idx) p->LZhaoshi[33] += 1;
		if (p->LZhaoshi[34] >= idx) p->LZhaoshi[34] += 1;
		if (p->LZhaoshi[35] >= idx) p->LZhaoshi[35] += 1;
		if (p->LZhaoshi[36] >= idx) p->LZhaoshi[36] += 1;
		if (p->LZhaoshi[37] >= idx) p->LZhaoshi[37] += 1;
		if (p->LZhaoshi[38] >= idx) p->LZhaoshi[38] += 1;
		if (p->LZhaoshi[39] >= idx) p->LZhaoshi[39] += 1;
	}
	for (auto& p : Save::getInstance()->getItems()) {
		if (p->MagicID >= idx) p->MagicID += 1;
	}
	for (auto& p : Save::getInstance()->getMenpais()) {
		if (p->neigong[0] >= idx) p->neigong[0] += 1;
		if (p->neigong[1] >= idx) p->neigong[1] += 1;
		if (p->neigong[2] >= idx) p->neigong[2] += 1;
		if (p->neigong[3] >= idx) p->neigong[3] += 1;
		if (p->neigong[4] >= idx) p->neigong[4] += 1;
		if (p->neigong[5] >= idx) p->neigong[5] += 1;
		if (p->neigong[6] >= idx) p->neigong[6] += 1;
		if (p->neigong[7] >= idx) p->neigong[7] += 1;
		if (p->neigong[8] >= idx) p->neigong[8] += 1;
		if (p->neigong[9] >= idx) p->neigong[9] += 1;
		if (p->neigong[10] >= idx) p->neigong[10] += 1;
		if (p->neigong[11] >= idx) p->neigong[11] += 1;
		if (p->neigong[12] >= idx) p->neigong[12] += 1;
		if (p->neigong[13] >= idx) p->neigong[13] += 1;
		if (p->neigong[14] >= idx) p->neigong[14] += 1;
		if (p->neigong[15] >= idx) p->neigong[15] += 1;
		if (p->neigong[16] >= idx) p->neigong[16] += 1;
		if (p->neigong[17] >= idx) p->neigong[17] += 1;
		if (p->neigong[18] >= idx) p->neigong[18] += 1;
		if (p->neigong[19] >= idx) p->neigong[19] += 1;
	}
}
void NewSave::InsertShopAt(std::vector<Shop>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		//data[i].ItemID[] = i;
	}
	Save::getInstance()->updateAllPtrVector();
}
void NewSave::InsertZhaoshiAt(std::vector<Zhaoshi>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
}
void NewSave::InsertMenpaiAt(std::vector<Menpai>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
	for (auto& p : Save::getInstance()->getRoles()) {
		if (p->Choushi[0] >= idx) p->Choushi[0] += 1;
		if (p->Choushi[1] >= idx) p->Choushi[1] += 1;
	}
}
void NewSave::InsertRSignAt(std::vector<RSign>& data, int idx) {
	auto newCopy = data[idx];
	data.insert(data.begin() + idx, newCopy);
	for (int i = 0; i < data.size(); i++) {
		data[i].ID = i;
	}
	Save::getInstance()->updateAllPtrVector();
}

NewSave NewSave::new_save_;

#define GET_OFFSET(field) (int((char*)(&(a.field)) - (char*)(&a)))
#define BIND_FIELD_INT(key, field) FieldInfo(key, 0, GET_OFFSET(field), sizeof(a.field))
#define BIND_FIELD_TEXT(key, field) FieldInfo(key, 1, GET_OFFSET(field), sizeof(a.field))

void NewSave::initDBFieldInfo()
{
	if (new_save_.base_.size() == 0)
	{
		Save::BaseInfo a;
		new_save_.base_ =
		{
			BIND_FIELD_INT("乘船", InShip),
			BIND_FIELD_INT("子场景内", InSubMap),
			BIND_FIELD_INT("主地图X", MainMapX),
			BIND_FIELD_INT("主地图Y", MainMapY),
			BIND_FIELD_INT("子场景X", SubMapX),
			BIND_FIELD_INT("子场景Y", SubMapY),
			BIND_FIELD_INT("面朝方向", FaceTowards),
			BIND_FIELD_INT("船X", ShipX),
			BIND_FIELD_INT("船Y", ShipY),
			BIND_FIELD_INT("船X1",TimeCount),
			BIND_FIELD_INT("船Y1", TimeEvent),
			BIND_FIELD_INT("内部编码", RandomEvent),
			BIND_FIELD_INT("队友1", Team[0]),
			BIND_FIELD_INT("队友2", Team[1]),
			BIND_FIELD_INT("队友3", Team[2]),
			BIND_FIELD_INT("队友4", Team[3]),
			BIND_FIELD_INT("队友5", Team[4]),
			BIND_FIELD_INT("队友6", Team[5]),
		};
	}
	if (new_save_.item_list_.size() == 0)
	{
		ItemList a;
		new_save_.item_list_ =
		{
			BIND_FIELD_INT("物品编号", item_id),
			BIND_FIELD_INT("物品数量", count),
		};
	}
	if (new_save_.role_.size() == 0)
	{
		Role a;
		new_save_.role_ =
		{
			BIND_FIELD_INT("编号", ID),
			BIND_FIELD_INT("头像", HeadID),
			BIND_FIELD_INT("生命增长", IncLife),
			BIND_FIELD_INT("富源", Fuyuan),
			BIND_FIELD_TEXT("名字", Name),
			BIND_FIELD_TEXT("外号", Nick),
			BIND_FIELD_INT("性别", Sexual),
			BIND_FIELD_INT("等级", Level),
			BIND_FIELD_INT("经验", Exp),
			BIND_FIELD_INT("生命", HP),
			BIND_FIELD_INT("生命最大值", MaxHP),
			BIND_FIELD_INT("内伤", Hurt),
			BIND_FIELD_INT("中毒", Poison),
			BIND_FIELD_INT("体力", PhysicalPower),
			BIND_FIELD_INT("武器", Equip[0]),
			BIND_FIELD_INT("防具", Equip[1]),
			BIND_FIELD_INT("鞋子", Equip[3]),
			BIND_FIELD_INT("饰品", Equip[3]),

			BIND_FIELD_INT("内力性质", MPType),
			BIND_FIELD_INT("内力", MP),
			BIND_FIELD_INT("内力最大值", MaxMP),
			BIND_FIELD_INT("攻击力", Attack),
			BIND_FIELD_INT("轻功", Speed),
			BIND_FIELD_INT("防御力", Defence),
			BIND_FIELD_INT("医疗", Medicine),

			BIND_FIELD_INT("抗毒", AntiPoison),
			BIND_FIELD_INT("拳掌", Fist),
			BIND_FIELD_INT("御剑", Sword),
			BIND_FIELD_INT("耍刀", Knife),
			BIND_FIELD_INT("特殊", Unusual),
			BIND_FIELD_INT("暗器", HiddenWeapon),
			BIND_FIELD_INT("武学常识", Knowledge),
			BIND_FIELD_INT("品德", Morality),
			BIND_FIELD_INT("攻击带毒", AttackWithPoison),
			BIND_FIELD_INT("左右互搏", AttackTwice),
			BIND_FIELD_INT("声望", Fame),
			BIND_FIELD_INT("资质", IQ),
			BIND_FIELD_INT("修炼物品", PracticeItem),
			BIND_FIELD_INT("修炼点数", ExpForItem),
			BIND_FIELD_INT("所会武功1", MagicID[0]),
			BIND_FIELD_INT("所会武功2", MagicID[1]),
			BIND_FIELD_INT("所会武功3", MagicID[2]),
			BIND_FIELD_INT("所会武功4", MagicID[3]),
			BIND_FIELD_INT("所会武功5", MagicID[4]),
			BIND_FIELD_INT("所会武功6", MagicID[5]),
			BIND_FIELD_INT("所会武功7", MagicID[6]),
			BIND_FIELD_INT("所会武功8", MagicID[7]),
			BIND_FIELD_INT("所会武功9", MagicID[8]),
			BIND_FIELD_INT("所会武功10", MagicID[9]),
			BIND_FIELD_INT("武功等级1", MagicLevel[0]),
			BIND_FIELD_INT("武功等级2", MagicLevel[1]),
			BIND_FIELD_INT("武功等级3", MagicLevel[2]),
			BIND_FIELD_INT("武功等级4", MagicLevel[3]),
			BIND_FIELD_INT("武功等级5", MagicLevel[4]),
			BIND_FIELD_INT("武功等级6", MagicLevel[5]),
			BIND_FIELD_INT("武功等级7", MagicLevel[6]),
			BIND_FIELD_INT("武功等级8", MagicLevel[7]),
			BIND_FIELD_INT("武功等级9", MagicLevel[8]),
			BIND_FIELD_INT("武功等级10", MagicLevel[9]),
			BIND_FIELD_INT("携带物品1", TakingItem[0]),
			BIND_FIELD_INT("携带物品2", TakingItem[1]),
			BIND_FIELD_INT("携带物品3", TakingItem[2]),
			BIND_FIELD_INT("携带物品4", TakingItem[3]),
			BIND_FIELD_INT("携带物品数量1", TakingItemCount[0]),
			BIND_FIELD_INT("携带物品数量2", TakingItemCount[1]),
			BIND_FIELD_INT("携带物品数量3", TakingItemCount[2]),
			BIND_FIELD_INT("携带物品数量4", TakingItemCount[3]),
		};
	}
	if (new_save_.item_.size() == 0)
	{
		Item a;
		new_save_.item_ =
		{
			BIND_FIELD_INT("编号", ID),
			BIND_FIELD_TEXT("物品名", Name),


			BIND_FIELD_TEXT("物品说明", Introduction),
			BIND_FIELD_INT("练出武功", MagicID),
			BIND_FIELD_INT("暗器动画编号", HiddenWeaponEffectID),
			BIND_FIELD_INT("使用人", User),
			BIND_FIELD_INT("装备类型", EquipType),
			BIND_FIELD_INT("显示物品说明", ShowIntroduction),
			BIND_FIELD_INT("物品类型", ItemType),


			BIND_FIELD_INT("加生命", AddHP),
			BIND_FIELD_INT("加生命最大值", AddMaxHP),
			BIND_FIELD_INT("加中毒解毒", AddPoison),
			BIND_FIELD_INT("加体力", AddPhysicalPower),
			BIND_FIELD_INT("改变内力性质", ChangeMPType),
			BIND_FIELD_INT("加内力", AddMP),
			BIND_FIELD_INT("加内力最大值", AddMaxMP),
			BIND_FIELD_INT("加攻击力", AddAttack),
			BIND_FIELD_INT("加轻功", AddSpeed),
			BIND_FIELD_INT("加防御力", AddDefence),
			BIND_FIELD_INT("加医疗", AddMedicine),
			BIND_FIELD_INT("加使毒", AddUsePoison),
			//BIND_FIELD_INT("加解毒", AddDetoxification),
			BIND_FIELD_INT("加抗毒", AddAntiPoison),
			BIND_FIELD_INT("加拳掌", AddFist),
			BIND_FIELD_INT("加御剑", AddSword),
			BIND_FIELD_INT("加耍刀", AddKnife),
			BIND_FIELD_INT("加特殊兵器", AddUnusual),
			BIND_FIELD_INT("加暗器技巧", AddHiddenWeapon),
			BIND_FIELD_INT("加武学常识", AddKnowledge),
			BIND_FIELD_INT("加品德", AddMorality),
			//BIND_FIELD_INT("加左右互搏", AddAttackTwice),
			BIND_FIELD_INT("加攻击带毒", AddAttackWithPoison),
			BIND_FIELD_INT("仅修炼人物", OnlySuitableRole),
			BIND_FIELD_INT("需内力性质", NeedMPType),
			BIND_FIELD_INT("需内力", NeedMP),
			BIND_FIELD_INT("需攻击力", NeedAttack),
			BIND_FIELD_INT("需轻功", NeedSpeed),
			BIND_FIELD_INT("需用毒", NeedUsePoison),
			BIND_FIELD_INT("需医疗", NeedMedicine),
			//BIND_FIELD_INT("需解毒", NeedDetoxification),
			BIND_FIELD_INT("需拳掌", NeedFist),
			BIND_FIELD_INT("需御剑", NeedSword),
			BIND_FIELD_INT("需耍刀", NeedKnife),
			BIND_FIELD_INT("需特殊兵器", NeedUnusual),
			BIND_FIELD_INT("需暗器", NeedHiddenWeapon),
			BIND_FIELD_INT("需资质", NeedIQ),
			BIND_FIELD_INT("需经验", NeedExp),
			//BIND_FIELD_INT("练出物品需经验", NeedExpForMakeItem),
			//BIND_FIELD_INT("需材料", NeedMaterial),
			//BIND_FIELD_INT("练出物品1", MakeItem[0]),
			//BIND_FIELD_INT("练出物品2", MakeItem[1]),
			//BIND_FIELD_INT("练出物品3", MakeItem[2]),
			//BIND_FIELD_INT("练出物品4", MakeItem[3]),
			//BIND_FIELD_INT("练出物品5", MakeItem[4]),
			//BIND_FIELD_INT("练出物品数量1", MakeItemCount[0]),
			//BIND_FIELD_INT("练出物品数量2", MakeItemCount[1]),
			//BIND_FIELD_INT("练出物品数量3", MakeItemCount[2]),
			//BIND_FIELD_INT("练出物品数量4", MakeItemCount[3]),
			//BIND_FIELD_INT("练出物品数量5", MakeItemCount[4]),
		};
	}
	if (new_save_.submap_.size() == 0)
	{
		SubMapInfo a;
		new_save_.submap_ =
		{
			BIND_FIELD_INT("编号", ID),
			BIND_FIELD_TEXT("名称", Name),
			BIND_FIELD_INT("出门音乐", ExitMusic),
			BIND_FIELD_INT("进门音乐", EntranceMusic),
			//BIND_FIELD_INT("跳转场景", JumpSubMap),
			BIND_FIELD_INT("进入条件", EntranceCondition),
			BIND_FIELD_INT("外景入口X1", MainEntranceX1),
			BIND_FIELD_INT("外景入口Y1", MainEntranceY1),
			BIND_FIELD_INT("外景入口X2", MainEntranceX2),
			BIND_FIELD_INT("外景入口Y2", MainEntranceY2),
			BIND_FIELD_INT("入口X", EntranceX),
			BIND_FIELD_INT("入口Y", EntranceY),
			BIND_FIELD_INT("出口X1", ExitX[0]),
			BIND_FIELD_INT("出口X2", ExitX[1]),
			BIND_FIELD_INT("出口X3", ExitX[2]),
			BIND_FIELD_INT("出口Y1", ExitY[0]),
			BIND_FIELD_INT("出口Y2", ExitY[1]),
			BIND_FIELD_INT("出口Y3", ExitY[2]),

		};
	}
	if (new_save_.magic_.size() == 0)
	{
		Magic a;
		new_save_.magic_ =
		{
			BIND_FIELD_INT("编号", ID),
			BIND_FIELD_TEXT("名称", Name),

			BIND_FIELD_INT("出招音效", SoundID),
			BIND_FIELD_INT("武功类型", MagicType),
			BIND_FIELD_INT("武功动画", EffectID),
			BIND_FIELD_INT("伤害类型", HurtType),
			BIND_FIELD_INT("攻击范围类型", AttackAreaType),
			BIND_FIELD_INT("消耗内力", NeedMP),
			BIND_FIELD_INT("敌人中毒", WithPoison),

			BIND_FIELD_INT("移动范围1", SelectDistance[0]),
			BIND_FIELD_INT("移动范围2", SelectDistance[1]),
			BIND_FIELD_INT("移动范围3", SelectDistance[2]),
			BIND_FIELD_INT("移动范围4", SelectDistance[3]),
			BIND_FIELD_INT("移动范围5", SelectDistance[4]),
			BIND_FIELD_INT("移动范围6", SelectDistance[5]),
			BIND_FIELD_INT("移动范围7", SelectDistance[6]),
			BIND_FIELD_INT("移动范围8", SelectDistance[7]),
			BIND_FIELD_INT("移动范围9", SelectDistance[8]),
			BIND_FIELD_INT("移动范围10", SelectDistance[9]),
			BIND_FIELD_INT("杀伤范围1", AttackDistance[0]),
			BIND_FIELD_INT("杀伤范围2", AttackDistance[1]),
			BIND_FIELD_INT("杀伤范围3", AttackDistance[2]),
			BIND_FIELD_INT("杀伤范围4", AttackDistance[3]),
			BIND_FIELD_INT("杀伤范围5", AttackDistance[4]),
			BIND_FIELD_INT("杀伤范围6", AttackDistance[5]),
			BIND_FIELD_INT("杀伤范围7", AttackDistance[6]),
			BIND_FIELD_INT("杀伤范围8", AttackDistance[7]),
			BIND_FIELD_INT("杀伤范围9", AttackDistance[8]),
			BIND_FIELD_INT("杀伤范围10", AttackDistance[9]),
			BIND_FIELD_INT("加内力1", AddMP[0]),
			BIND_FIELD_INT("加内力2", AddMP[1]),
			BIND_FIELD_INT("加内力3", AddMP[2]),
			BIND_FIELD_INT("加内力4", AddMP[3]),
			BIND_FIELD_INT("加内力5", AddMP[4]),
			BIND_FIELD_INT("加内力6", AddMP[5]),
			BIND_FIELD_INT("加内力7", AddMP[6]),
			BIND_FIELD_INT("加内力8", AddMP[7]),
			BIND_FIELD_INT("加内力9", AddMP[8]),
			BIND_FIELD_INT("加内力10", AddMP[9]),

		};
	}
	if (new_save_.shop_.size() == 0)
	{
		Shop a;
		new_save_.shop_ =
		{
			BIND_FIELD_INT("物品编号1", ItemID[0]),
			BIND_FIELD_INT("物品编号2", ItemID[1]),
			BIND_FIELD_INT("物品编号3", ItemID[2]),
			BIND_FIELD_INT("物品编号4", ItemID[3]),
			BIND_FIELD_INT("物品编号5", ItemID[4]),

		};
	}
}

void NewSave::SaveDBBaseInfo(sqlite3* db, Save::BaseInfo* data, int length)
{
	sqlite3_exec(db, "delete from base", nullptr, nullptr, nullptr);
	std::string cmd = "insert into base values(";
	for (auto& info : new_save_.base_)
	{
		cmd += std::to_string(*(int*)((char*)data + info.offset)) + ",";
	}
	cmd.pop_back();
	cmd += ")";
	sqlite3_exec(db, cmd.c_str(), nullptr, nullptr, nullptr);
}

void NewSave::LoadDBBaseInfo(sqlite3* db, Save::BaseInfo* data, int length)
{
	std::vector<Save::BaseInfo> datas;
	readValues(db, "base", new_save_.base_, datas);
	*data = datas[0];
}

void NewSave::SaveDBItemList(sqlite3* db, ItemList* data, int length)
{
	std::vector<ItemList> itemlist(length);
	for (int i = 0; i < length; i++)
	{
		itemlist[i] = data[i];
	}
	writeValues(db, "bag", new_save_.item_list_, itemlist);
}

void NewSave::LoadDBItemList(sqlite3* db, ItemList* data, int length)
{
	std::vector<ItemList> itemlist;
	readValues(db, "bag", new_save_.item_list_, itemlist);
	for (int i = 0; i < length; i++)
	{
		data[i] = itemlist[i];
	}
}

void NewSave::SaveDBRoleSave(sqlite3* db, const std::vector<Role>& data)
{
	writeValues(db, "role", new_save_.role_, data);
}

void NewSave::LoadDBRoleSave(sqlite3* db, std::vector<Role>& data)
{
	readValues(db, "role", new_save_.role_, data);
}

void NewSave::SaveDBItemSave(sqlite3* db, const std::vector<Item>& data)
{
	writeValues(db, "item", new_save_.item_, data);
}

void NewSave::LoadDBItemSave(sqlite3* db, std::vector<Item>& data)
{
	readValues(db, "item", new_save_.item_, data);
}

void NewSave::SaveDBSubMapInfoSave(sqlite3* db, const std::vector<SubMapInfo>& data)
{
	writeValues(db, "submap", new_save_.submap_, data);
}

void NewSave::LoadDBSubMapInfoSave(sqlite3* db, std::vector<SubMapInfo>& data)
{
	readValues(db, "submap", new_save_.submap_, data);
}

void NewSave::SaveDBMagicSave(sqlite3* db, const std::vector<Magic>& data)
{
	writeValues(db, "magic", new_save_.magic_, data);
}

void NewSave::LoadDBMagicSave(sqlite3* db, std::vector<Magic>& data)
{
	readValues(db, "magic", new_save_.magic_, data);
}

void NewSave::SaveDBShopSave(sqlite3* db, const std::vector<Shop>& data)
{
	writeValues(db, "shop", new_save_.shop_, data);
}

void NewSave::LoadDBShopSave(sqlite3* db, std::vector<Shop>& data)
{
	readValues(db, "shop", new_save_.shop_, data);
}