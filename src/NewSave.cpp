#include "NewSave.h"
#include "PotConv.h"
#include "csv.h"
#include <fstream>
#include <iostream>
// ����
void NewSave::SaveToCSVBaseInfo(Save::BaseInfo* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "�˴�";
	fout << ",";    fout << "����";
	fout << ",";    fout << "��X";
	fout << ",";    fout << "��Y";
	fout << ",";    fout << "�ڳ�������X";
	fout << ",";    fout << "�ڳ�������Y";
	fout << ",";    fout << "����Է���";
	fout << ",";    fout << "��X";
	fout << ",";    fout << "��Y";
	fout << ",";    fout << "��ʱ";
	fout << ",";    fout << "��ʱ�¼�";
	fout << ",";    fout << "����¼�";
	fout << ",";    fout << "�ڳ�������";
	fout << ",";    fout << "����Է���";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "����1";
	fout << ",";    fout << "����2";
	fout << ",";    fout << "����3";
	fout << ",";    fout << "����4";
	fout << ",";    fout << "����5";
	fout << ",";    fout << "����6";
	fout << ",";    fout << "����";
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
// ����
void NewSave::SaveToCSVItemList(ItemList* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "��Ʒ���";
	fout << ",";    fout << "��Ʒ����";
	fout << std::endl;
	for (int i = 0; i < length; i++) {
		fout << data[i].item_id;
		fout << ",";
		fout << data[i].count;
		fout << std::endl;
	}
}
// ����
void NewSave::SaveToCSVRoleSave(const std::vector<Role>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "���";
	fout << ",";    fout << "ͷ��/ս������";
	fout << ",";    fout << "�����ɳ�";
	fout << ",";    fout << "��Ե";
	fout << ",";    fout << "����";
	fout << ",";    fout << "���";
	fout << ",";    fout << "�Ա�";
	fout << ",";    fout << "�ȼ�";
	fout << ",";    fout << "����ֵ";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�������ֵ";
	fout << ",";    fout << "���˳̶�";
	fout << ",";    fout << "�ж��̶�";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ս��ͼ���";
	fout << ",";    fout << "װ��";
	fout << ",";    fout << "װ��1";
	fout << ",";    fout << "װ��2";
	fout << ",";    fout << "װ��3";
	fout << ",";    fout << "װ��4";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����״̬";
	fout << ",";    fout << "��ŭֵ";
	fout << ",";    fout << "���ұ��";
	fout << ",";    fout << "�ж�����";
	fout << ",";    fout << "���ܵ�";
	fout << ",";    fout << "ս��AI״̬";
	fout << ",";    fout << "���";
	fout << ",";    fout << "�ж�ʱ��";
	fout << ",";    fout << "�Ѷ�";
	fout << ",";    fout << "�ҳ϶�";
	fout << ",";    fout << "ҩ��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�������ֵ";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�Ṧ";
	fout << ",";    fout << "������";
	fout << ",";    fout << "ҽ��";
	fout << ",";    fout << "��ȱ";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ȭ��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ˣ��";
	fout << ",";    fout << "�������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��ѧ��ʶ";
	fout << ",";    fout << "Ʒ��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "���һ���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "������Ʒ";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "Ʒ������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "ʦ��";
	fout << ",";    fout << "ʦ����λ";
	fout << ",";    fout << "��ʦ˳��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��������1";
	fout << ",";    fout << "��ǰλ��";
	fout << ",";    fout << "�ڲ�λ��";
	fout << ",";    fout << "�ڲ�����";
	fout << ",";    fout << "����״̬";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "ڤ˼����";
	fout << ",";    fout << "�Ͷ�����";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��ʱλ��";
	fout << ",";    fout << "�ڲ���ʱλ��";
	fout << ",";    fout << "�ڲ�����1";
	fout << ",";    fout << "����X����";
	fout << ",";    fout << "����Y����";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�ٸ�����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "δ��1";
	fout << ",";    fout << "δ��2";
	fout << ",";    fout << "δ��3";
	fout << ",";    fout << "ս��ID";
	fout << ",";    fout << "�����书";
	fout << ",";    fout << "�����书1";
	fout << ",";    fout << "�����书2";
	fout << ",";    fout << "�����书3";
	fout << ",";    fout << "�����书4";
	fout << ",";    fout << "�����书5";
	fout << ",";    fout << "�����书6";
	fout << ",";    fout << "�����书7";
	fout << ",";    fout << "�����书8";
	fout << ",";    fout << "�����书9";
	fout << ",";    fout << "�����书10";
	fout << ",";    fout << "�����书11";
	fout << ",";    fout << "�����书12";
	fout << ",";    fout << "�����书13";
	fout << ",";    fout << "�����书14";
	fout << ",";    fout << "�����书15";
	fout << ",";    fout << "�����书16";
	fout << ",";    fout << "�����书17";
	fout << ",";    fout << "�����书18";
	fout << ",";    fout << "�����书19";
	fout << ",";    fout << "�����书20";
	fout << ",";    fout << "�����书21";
	fout << ",";    fout << "�����书22";
	fout << ",";    fout << "�����书23";
	fout << ",";    fout << "�����书24";
	fout << ",";    fout << "�����书25";
	fout << ",";    fout << "�����书26";
	fout << ",";    fout << "�����书27";
	fout << ",";    fout << "�����书28";
	fout << ",";    fout << "�����书29";
	fout << ",";    fout << "�����书30";
	fout << ",";    fout << "�����书31";
	fout << ",";    fout << "�����书32";
	fout << ",";    fout << "�����书33";
	fout << ",";    fout << "�����书34";
	fout << ",";    fout << "�����书35";
	fout << ",";    fout << "�����书36";
	fout << ",";    fout << "�����书37";
	fout << ",";    fout << "�����书38";
	fout << ",";    fout << "�����书39";
	fout << ",";    fout << "�����书�ȼ�";
	fout << ",";    fout << "�����书�ȼ�1";
	fout << ",";    fout << "�����书�ȼ�2";
	fout << ",";    fout << "�����书�ȼ�3";
	fout << ",";    fout << "�����书�ȼ�4";
	fout << ",";    fout << "�����书�ȼ�5";
	fout << ",";    fout << "�����书�ȼ�6";
	fout << ",";    fout << "�����书�ȼ�7";
	fout << ",";    fout << "�����书�ȼ�8";
	fout << ",";    fout << "�����书�ȼ�9";
	fout << ",";    fout << "�����书�ȼ�10";
	fout << ",";    fout << "�����书�ȼ�11";
	fout << ",";    fout << "�����书�ȼ�12";
	fout << ",";    fout << "�����书�ȼ�13";
	fout << ",";    fout << "�����书�ȼ�14";
	fout << ",";    fout << "�����书�ȼ�15";
	fout << ",";    fout << "�����书�ȼ�16";
	fout << ",";    fout << "�����书�ȼ�17";
	fout << ",";    fout << "�����书�ȼ�18";
	fout << ",";    fout << "�����书�ȼ�19";
	fout << ",";    fout << "�����书�ȼ�20";
	fout << ",";    fout << "�����书�ȼ�21";
	fout << ",";    fout << "�����书�ȼ�22";
	fout << ",";    fout << "�����书�ȼ�23";
	fout << ",";    fout << "�����书�ȼ�24";
	fout << ",";    fout << "�����书�ȼ�25";
	fout << ",";    fout << "�����书�ȼ�26";
	fout << ",";    fout << "�����书�ȼ�27";
	fout << ",";    fout << "�����书�ȼ�28";
	fout << ",";    fout << "�����书�ȼ�29";
	fout << ",";    fout << "�����书�ȼ�30";
	fout << ",";    fout << "�����书�ȼ�31";
	fout << ",";    fout << "�����书�ȼ�32";
	fout << ",";    fout << "�����书�ȼ�33";
	fout << ",";    fout << "�����书�ȼ�34";
	fout << ",";    fout << "�����书�ȼ�35";
	fout << ",";    fout << "�����书�ȼ�36";
	fout << ",";    fout << "�����书�ȼ�37";
	fout << ",";    fout << "�����书�ȼ�38";
	fout << ",";    fout << "�����书�ȼ�39";
	fout << ",";    fout << "Я����Ʒ";
	fout << ",";    fout << "Я����Ʒ1";
	fout << ",";    fout << "Я����Ʒ2";
	fout << ",";    fout << "Я����Ʒ3";
	fout << ",";    fout << "Я����Ʒ4";
	fout << ",";    fout << "Я����Ʒ5";
	fout << ",";    fout << "Я����Ʒ6";
	fout << ",";    fout << "Я����Ʒ7";
	fout << ",";    fout << "Я����Ʒ8";
	fout << ",";    fout << "Я����Ʒ����";
	fout << ",";    fout << "Я����Ʒ����1";
	fout << ",";    fout << "Я����Ʒ����2";
	fout << ",";    fout << "Я����Ʒ����3";
	fout << ",";    fout << "Я����Ʒ����4";
	fout << ",";    fout << "Я����Ʒ����5";
	fout << ",";    fout << "Я����Ʒ����6";
	fout << ",";    fout << "Я����Ʒ����7";
	fout << ",";    fout << "Я����Ʒ����8";
	fout << ",";    fout << "�����书";
	fout << ",";    fout << "�����书1";
	fout << ",";    fout << "�����书2";
	fout << ",";    fout << "�����书3";
	fout << ",";    fout << "�����书4";
	fout << ",";    fout << "�����书5";
	fout << ",";    fout << "�����书6";
	fout << ",";    fout << "�����书7";
	fout << ",";    fout << "�����书8";
	fout << ",";    fout << "�����书9";
	fout << ",";    fout << "������ʽ";
	fout << ",";    fout << "������ʽ1";
	fout << ",";    fout << "������ʽ2";
	fout << ",";    fout << "������ʽ3";
	fout << ",";    fout << "������ʽ4";
	fout << ",";    fout << "������ʽ5";
	fout << ",";    fout << "������ʽ6";
	fout << ",";    fout << "������ʽ7";
	fout << ",";    fout << "������ʽ8";
	fout << ",";    fout << "������ʽ9";
	fout << ",";    fout << "������ʽ10";
	fout << ",";    fout << "������ʽ11";
	fout << ",";    fout << "������ʽ12";
	fout << ",";    fout << "������ʽ13";
	fout << ",";    fout << "������ʽ14";
	fout << ",";    fout << "������ʽ15";
	fout << ",";    fout << "������ʽ16";
	fout << ",";    fout << "������ʽ17";
	fout << ",";    fout << "������ʽ18";
	fout << ",";    fout << "������ʽ19";
	fout << ",";    fout << "������ʽ20";
	fout << ",";    fout << "������ʽ21";
	fout << ",";    fout << "������ʽ22";
	fout << ",";    fout << "������ʽ23";
	fout << ",";    fout << "������ʽ24";
	fout << ",";    fout << "������ʽ25";
	fout << ",";    fout << "������ʽ26";
	fout << ",";    fout << "������ʽ27";
	fout << ",";    fout << "������ʽ28";
	fout << ",";    fout << "������ʽ29";
	fout << ",";    fout << "������ʽ30";
	fout << ",";    fout << "������ʽ31";
	fout << ",";    fout << "������ʽ32";
	fout << ",";    fout << "������ʽ33";
	fout << ",";    fout << "������ʽ34";
	fout << ",";    fout << "������ʽ35";
	fout << ",";    fout << "������ʽ36";
	fout << ",";    fout << "������ʽ37";
	fout << ",";    fout << "������ʽ38";
	fout << ",";    fout << "������ʽ39";
	fout << ",";    fout << "�Ի��˵�����";
	fout << ",";    fout << "�Ի��¼�";
	fout << ",";    fout << "״̬�¼�";
	fout << ",";    fout << "����¼�";
	fout << ",";    fout << "�д��¼�";
	fout << ",";    fout << "ѧϰ�¼�";
	fout << ",";    fout << "�¼���1";
	fout << ",";    fout << "�¼���2";
	fout << ",";    fout << "�¼���3";
	fout << ",";    fout << "�������";
	fout << ",";    fout << "����¼�";
	fout << ",";    fout << "���ֵ";
	fout << ",";    fout << "���ֵ1";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ҽʦ";
	fout << ",";    fout << "װ���ؼ�";
	fout << ",";    fout << "��Ѫ";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "���";
	fout << ",";    fout << "��ѧ";
	fout << ",";    fout << "ͻ��";
	fout << ",";    fout << "�侲";
	fout << ",";    fout << "�ٱ�";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "Ӳ��";
	fout << ",";    fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "��";
	fout << ",";    fout << "����Ǳ��";
	fout << ",";    fout << "����Ǳ��";
	fout << ",";    fout << "�ṦǱ��";
	fout << ",";    fout << "ȭ��Ǳ��";
	fout << ",";    fout << "����Ǳ��";
	fout << ",";    fout << "ˣ��Ǳ��";
	fout << ",";    fout << "����Ǳ��";
	fout << ",";    fout << "����Ǳ��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ר��";
	fout << ",";    fout << "ר��1";
	fout << ",";    fout << "ר��2";
	fout << ",";    fout << "ר��3";
	fout << ",";    fout << "ר��4";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����1";
	fout << ",";    fout << "����2";
	fout << ",";    fout << "����3";
	fout << ",";    fout << "����4";
	fout << ",";    fout << "����5";
	fout << ",";    fout << "����6";
	fout << ",";    fout << "����7";
	fout << ",";    fout << "����8";
	fout << ",";    fout << "����9";
	fout << ",";    fout << "���ɹ���";
	fout << ",";    fout << "δʹ��";
	fout << ",";    fout << "δʹ��1";
	fout << ",";    fout << "δʹ��2";
	fout << ",";    fout << "δʹ��3";
	fout << ",";    fout << "δʹ��4";
	fout << ",";    fout << "δʹ��5";
	fout << ",";    fout << "δʹ��6";
	fout << ",";    fout << "δʹ��7";
	fout << ",";    fout << "δʹ��8";
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
// ��Ʒ
void NewSave::SaveToCSVItemSave(const std::vector<Item>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_��Ʒ.csv");
	fout << "���";
	fout << ",";    fout << "��Ʒ��";
	fout << ",";    fout << "��Ʒ�书����";
	fout << ",";    fout << "��װ��";
	fout << ",";    fout << "ս����Ч";
	fout << ",";    fout << "���ӱ�ǩ";
	fout << ",";    fout << "Ҫ���Ա�";
	fout << ",";    fout << "�ָ�����";
	fout << ",";    fout << "��Ʒ��";
	fout << ",";    fout << "������";
	fout << ",";    fout << "����Ǳ��ֵ";
	fout << ",";    fout << "ս����";
	fout << ",";    fout << "��Ʒ˵��";
	fout << ",";    fout << "�����书";
	fout << ",";    fout << "�����������";
	fout << ",";    fout << "ʹ����";
	fout << ",";    fout << "װ������";
	fout << ",";    fout << "��ʾ��Ʒ˵��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�̵���";
	fout << ",";    fout << "�ۼ�";
	fout << ",";    fout << "�����¼�";
	fout << ",";    fout << "������";
	fout << ",";    fout << "���������ֵ";
	fout << ",";    fout << "���ж��ⶾ";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�ı���������";
	fout << ",";    fout << "������";
	fout << ",";    fout << "���������ֵ";
	fout << ",";    fout << "�ӹ�����";
	fout << ",";    fout << "���Ṧ";
	fout << ",";    fout << "�ӷ�����";
	fout << ",";    fout << "��ҽ��";
	fout << ",";    fout << "��ʹ��";
	fout << ",";    fout << "�Ӽ���";
	fout << ",";    fout << "�ӿ���";
	fout << ",";    fout << "��ȭ��";
	fout << ",";    fout << "������";
	fout << ",";    fout << "��ˣ��";
	fout << ",";    fout << "���������";
	fout << ",";    fout << "�Ӱ�������";
	fout << ",";    fout << "����ѧ��ʶ";
	fout << ",";    fout << "��Ʒ��";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�ӹ�������";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�蹥����";
	fout << ",";    fout << "���Ṧ";
	fout << ",";    fout << "�趾��";
	fout << ",";    fout << "��ҽ��";
	fout << ",";    fout << "�輼��";
	fout << ",";    fout << "��ȭ��";
	fout << ",";    fout << "������";
	fout << ",";    fout << "��ˣ��";
	fout << ",";    fout << "���������";
	fout << ",";    fout << "�谵��";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�辭��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ϡ�ж�";
	fout << ",";    fout << "������Ʒ";
	fout << ",";    fout << "������Ʒ1";
	fout << ",";    fout << "������Ʒ2";
	fout << ",";    fout << "������Ʒ3";
	fout << ",";    fout << "������Ʒ4";
	fout << ",";    fout << "��Ҫ��Ʒ����";
	fout << ",";    fout << "��Ҫ��Ʒ����1";
	fout << ",";    fout << "��Ҫ��Ʒ����2";
	fout << ",";    fout << "��Ҫ��Ʒ����3";
	fout << ",";    fout << "��Ҫ��Ʒ����4";
	fout << ",";    fout << "������";
	fout << ",";    fout << "�Ӹ�Դ";
	fout << ",";    fout << "δʹ��";
	fout << ",";    fout << "δʹ��1";
	fout << ",";    fout << "δʹ��2";
	fout << ",";    fout << "δʹ��3";
	fout << ",";    fout << "δʹ��4";
	fout << ",";    fout << "δʹ��5";
	fout << ",";    fout << "δʹ��6";
	fout << ",";    fout << "δʹ��7";
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
		fout << data[i].BattleBattleEffect;
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
// ����
void NewSave::SaveToCSVSubMapInfoSave(const std::vector<SubMapInfo>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "������ɫ��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�⾰���X1";
	fout << ",";    fout << "�⾰���Y1";
	fout << ",";    fout << "�⾰���X2";
	fout << ",";    fout << "�⾰���Y2";
	fout << ",";    fout << "���X";
	fout << ",";    fout << "���Y";
	fout << ",";    fout << "����X1";
	fout << ",";    fout << "����X2";
	fout << ",";    fout << "����X3";
	fout << ",";    fout << "����Y1";
	fout << ",";    fout << "����Y2";
	fout << ",";    fout << "����Y3";
	fout << ",";    fout << "����";
	fout << ",";    fout << "δ��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "ս����";
	fout << ",";    fout << "�����䳡��";
	fout << ",";    fout << "���䳡��";
	fout << ",";    fout << "�ܲؾ�����";
	fout << ",";    fout << "�ؾ�����";
	fout << ",";    fout << "���䳡X";
	fout << ",";    fout << "���䳡X1";
	fout << ",";    fout << "���䳡X2";
	fout << ",";    fout << "���䳡X3";
	fout << ",";    fout << "���䳡X4";
	fout << ",";    fout << "���䳡Y";
	fout << ",";    fout << "���䳡Y1";
	fout << ",";    fout << "���䳡Y2";
	fout << ",";    fout << "���䳡Y3";
	fout << ",";    fout << "���䳡Y4";
	fout << ",";    fout << "�ؾ���X";
	fout << ",";    fout << "�ؾ���X1";
	fout << ",";    fout << "�ؾ���X2";
	fout << ",";    fout << "�ؾ���X3";
	fout << ",";    fout << "�ؾ���X4";
	fout << ",";    fout << "�ؾ���Y";
	fout << ",";    fout << "�ؾ���Y1";
	fout << ",";    fout << "�ؾ���Y2";
	fout << ",";    fout << "�ؾ���Y3";
	fout << ",";    fout << "�ؾ���Y4";
	fout << ",";    fout << "�չ��ҿ���";
	fout << ",";    fout << "�չ���X";
	fout << ",";    fout << "�չ���Y";
	fout << ",";    fout << "����¯����";
	fout << ",";    fout << "����¯X";
	fout << ",";    fout << "����¯Y";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "������X";
	fout << ",";    fout << "������Y";
	fout << ",";    fout << "����X";
	fout << ",";    fout << "����Y";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�������";
	fout << ",";    fout << "�����ӳ�";
	fout << ",";    fout << "������ʩ";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ʯ��";
	fout << ",";    fout << "ľ��";
	fout << ",";    fout << "ʳ��";
	fout << ",";    fout << "��̿";
	fout << ",";    fout << "��ҩ";
	fout << ",";    fout << "��ľ";
	fout << ",";    fout << "���";
	fout << ",";    fout << "ϡ��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����1";
	fout << ",";    fout << "����2";
	fout << ",";    fout << "����3";
	fout << ",";    fout << "����4";
	fout << ",";    fout << "����5";
	fout << ",";    fout << "����6";
	fout << ",";    fout << "����7";
	fout << ",";    fout << "����8";
	fout << ",";    fout << "����9";
	fout << ",";    fout << "δʹ��";
	fout << ",";    fout << "δʹ��1";
	fout << ",";    fout << "δʹ��2";
	fout << ",";    fout << "δʹ��3";
	fout << ",";    fout << "δʹ��4";
	fout << ",";    fout << "δʹ��5";
	fout << ",";    fout << "δʹ��6";
	fout << ",";    fout << "δʹ��7";
	fout << ",";    fout << "δʹ��8";
	fout << ",";    fout << "δʹ��9";
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
// �书
void NewSave::SaveToCSVMagicSave(const std::vector<Magic>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_�书.csv");
	fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�ؼ�";
	fout << ",";    fout << "��Ҫ����";
	fout << ",";    fout << "��С����";
	fout << ",";    fout << "�Ƿ�ͼ��Ч";
	fout << ",";    fout << "�¼�";
	fout << ",";    fout << "������Ч";
	fout << ",";    fout << "�书����";
	fout << ",";    fout << "�书����&��Ч";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "������Χ";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�����ж�����";
	fout << ",";    fout << "��С������";
	fout << ",";    fout << "��󹥻���";
	fout << ",";    fout << "����ϵ��";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�Ṧ����";
	fout << ",";    fout << "����ֵ����";
	fout << ",";    fout << "�Ƿ��ش�";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "����������";
	fout << ",";    fout << "�ƶ���Χ";
	fout << ",";    fout << "�ƶ���Χ1";
	fout << ",";    fout << "�ƶ���Χ2";
	fout << ",";    fout << "�ƶ���Χ3";
	fout << ",";    fout << "�ƶ���Χ4";
	fout << ",";    fout << "�ƶ���Χ5";
	fout << ",";    fout << "�ƶ���Χ6";
	fout << ",";    fout << "�ƶ���Χ7";
	fout << ",";    fout << "�ƶ���Χ8";
	fout << ",";    fout << "�ƶ���Χ9";
	fout << ",";    fout << "ɱ�˷�Χ";
	fout << ",";    fout << "ɱ�˷�Χ1";
	fout << ",";    fout << "ɱ�˷�Χ2";
	fout << ",";    fout << "ɱ�˷�Χ3";
	fout << ",";    fout << "ɱ�˷�Χ4";
	fout << ",";    fout << "ɱ�˷�Χ5";
	fout << ",";    fout << "ɱ�˷�Χ6";
	fout << ",";    fout << "ɱ�˷�Χ7";
	fout << ",";    fout << "ɱ�˷�Χ8";
	fout << ",";    fout << "ɱ�˷�Χ9";
	fout << ",";    fout << "������";
	fout << ",";    fout << "������1";
	fout << ",";    fout << "������2";
	fout << ",";    fout << "������";
	fout << ",";    fout << "������1";
	fout << ",";    fout << "������2";
	fout << ",";    fout << "�ӹ���";
	fout << ",";    fout << "�ӹ���1";
	fout << ",";    fout << "�ӹ���2";
	fout << ",";    fout << "�ӷ���";
	fout << ",";    fout << "�ӷ���1";
	fout << ",";    fout << "�ӷ���2";
	fout << ",";    fout << "���Ṧ";
	fout << ",";    fout << "���Ṧ1";
	fout << ",";    fout << "���Ṧ2";
	fout << ",";    fout << "��С��Ѩ����";
	fout << ",";    fout << "����Ѩ����";
	fout << ",";    fout << "��С���˼���";
	fout << ",";    fout << "������˼���";
	fout << ",";    fout << "����ҽ��";
	fout << ",";    fout << "���Ӷ���";
	fout << ",";    fout << "���Ӽ���";
	fout << ",";    fout << "���ӿ���";
	fout << ",";    fout << "����ȭ��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "����ˣ��";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "���Ӱ���";
	fout << ",";    fout << "״̬";
	fout << ",";    fout << "�辭��1";
	fout << ",";    fout << "�辭��2";
	fout << ",";    fout << "�辭��3";
	fout << ",";    fout << "��ߵȼ�";
	fout << ",";    fout << "˵��";
	fout << ",";    fout << "��ʽ";
	fout << ",";    fout << "��ʽ1";
	fout << ",";    fout << "��ʽ2";
	fout << ",";    fout << "��ʽ3";
	fout << ",";    fout << "��ʽ4";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����1";
	fout << ",";    fout << "����2";
	fout << ",";    fout << "����3";
	fout << ",";    fout << "����4";
	fout << ",";    fout << "����5";
	fout << ",";    fout << "����6";
	fout << ",";    fout << "����7";
	fout << ",";    fout << "����8";
	fout << ",";    fout << "����9";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "��������1";
	fout << ",";    fout << "��������2";
	fout << ",";    fout << "��������3";
	fout << ",";    fout << "��������4";
	fout << ",";    fout << "��������5";
	fout << ",";    fout << "��������6";
	fout << ",";    fout << "��������7";
	fout << ",";    fout << "��������8";
	fout << ",";    fout << "��������9";
	fout << ",";    fout << "δʹ��";
	fout << ",";    fout << "δʹ��1";
	fout << ",";    fout << "δʹ��2";
	fout << ",";    fout << "δʹ��3";
	fout << ",";    fout << "δʹ��4";
	fout << ",";    fout << "δʹ��5";
	fout << ",";    fout << "δʹ��6";
	fout << ",";    fout << "δʹ��7";
	fout << ",";    fout << "δʹ��8";
	fout << ",";    fout << "δʹ��9";
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
// �̵�
void NewSave::SaveToCSVShopSave(const std::vector<Shop>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_�̵�.csv");
	fout << "��Ʒ���";
	fout << ",";    fout << "��Ʒ���1";
	fout << ",";    fout << "��Ʒ���2";
	fout << ",";    fout << "��Ʒ���3";
	fout << ",";    fout << "��Ʒ���4";
	fout << ",";    fout << "��Ʒ���5";
	fout << ",";    fout << "��Ʒ���6";
	fout << ",";    fout << "��Ʒ���7";
	fout << ",";    fout << "��Ʒ���8";
	fout << ",";    fout << "��Ʒ���9";
	fout << ",";    fout << "��Ʒ���10";
	fout << ",";    fout << "��Ʒ���11";
	fout << ",";    fout << "��Ʒ���12";
	fout << ",";    fout << "��Ʒ���13";
	fout << ",";    fout << "��Ʒ���14";
	fout << ",";    fout << "��Ʒ���15";
	fout << ",";    fout << "��Ʒ���16";
	fout << ",";    fout << "��Ʒ���17";
	fout << ",";    fout << "��Ʒ���18";
	fout << ",";    fout << "��Ʒ���19";
	fout << ",";    fout << "��Ʒ���20";
	fout << ",";    fout << "��Ʒ���21";
	fout << ",";    fout << "��Ʒ���22";
	fout << ",";    fout << "��Ʒ���23";
	fout << ",";    fout << "��Ʒ���24";
	fout << ",";    fout << "��Ʒ���25";
	fout << ",";    fout << "��Ʒ���26";
	fout << ",";    fout << "��Ʒ���27";
	fout << ",";    fout << "��Ʒ���28";
	fout << ",";    fout << "��Ʒ���29";
	fout << ",";    fout << "��Ʒ���30";
	fout << ",";    fout << "��Ʒ���31";
	fout << ",";    fout << "��Ʒ���32";
	fout << ",";    fout << "��Ʒ���33";
	fout << ",";    fout << "��Ʒ���34";
	fout << ",";    fout << "��Ʒ����";
	fout << ",";    fout << "��Ʒ����1";
	fout << ",";    fout << "��Ʒ����2";
	fout << ",";    fout << "��Ʒ����3";
	fout << ",";    fout << "��Ʒ����4";
	fout << ",";    fout << "��Ʒ����5";
	fout << ",";    fout << "��Ʒ����6";
	fout << ",";    fout << "��Ʒ����7";
	fout << ",";    fout << "��Ʒ����8";
	fout << ",";    fout << "��Ʒ����9";
	fout << ",";    fout << "��Ʒ����10";
	fout << ",";    fout << "��Ʒ����11";
	fout << ",";    fout << "��Ʒ����12";
	fout << ",";    fout << "��Ʒ����13";
	fout << ",";    fout << "��Ʒ����14";
	fout << ",";    fout << "��Ʒ����15";
	fout << ",";    fout << "��Ʒ����16";
	fout << ",";    fout << "��Ʒ����17";
	fout << ",";    fout << "��Ʒ����18";
	fout << ",";    fout << "��Ʒ����19";
	fout << ",";    fout << "��Ʒ����20";
	fout << ",";    fout << "��Ʒ����21";
	fout << ",";    fout << "��Ʒ����22";
	fout << ",";    fout << "��Ʒ����23";
	fout << ",";    fout << "��Ʒ����24";
	fout << ",";    fout << "��Ʒ����25";
	fout << ",";    fout << "��Ʒ����26";
	fout << ",";    fout << "��Ʒ����27";
	fout << ",";    fout << "��Ʒ����28";
	fout << ",";    fout << "��Ʒ����29";
	fout << ",";    fout << "��Ʒ����30";
	fout << ",";    fout << "��Ʒ����31";
	fout << ",";    fout << "��Ʒ����32";
	fout << ",";    fout << "��Ʒ����33";
	fout << ",";    fout << "��Ʒ����34";
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
// ʱ��
void NewSave::SaveToCSVTimeSave(TimeSave* data, int length, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "����";
	fout << ",";    fout << "��";
	fout << ",";    fout << "��";
	fout << ",";    fout << "��";
	fout << ",";    fout << "�r";
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
// ��ʽ
// ��ʽ
void NewSave::SaveToCSVZhaoshiSave(const std::vector<Zhaoshi>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_��ʽ.csv");
	fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "˳λ";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�Ƿ񹥻�";
	fout << ",";    fout << "�����ӳ�";
	fout << ",";    fout << "�Ƿ����";
	fout << ",";    fout << "�����ӳ�";
	fout << ",";    fout << "˵��";
	fout << ",";    fout << "��Ч����";
	fout << ",";    fout << "��Ч����1";
	fout << ",";    fout << "��Ч����2";
	fout << ",";    fout << "��Ч����3";
	fout << ",";    fout << "��Ч����4";
	fout << ",";    fout << "��Ч����5";
	fout << ",";    fout << "��Ч����6";
	fout << ",";    fout << "��Ч����7";
	fout << ",";    fout << "��Ч����8";
	fout << ",";    fout << "��Ч����9";
	fout << ",";    fout << "��Ч����10";
	fout << ",";    fout << "��Ч����11";
	fout << ",";    fout << "��Ч����12";
	fout << ",";    fout << "��Ч����13";
	fout << ",";    fout << "��Ч����14";
	fout << ",";    fout << "��Ч����15";
	fout << ",";    fout << "��Ч����16";
	fout << ",";    fout << "��Ч����17";
	fout << ",";    fout << "��Ч����18";
	fout << ",";    fout << "��Ч����19";
	fout << ",";    fout << "��Ч����20";
	fout << ",";    fout << "��Ч����21";
	fout << ",";    fout << "��Ч����22";
	fout << ",";    fout << "��Ч����23";
	fout << ",";    fout << "��Ч����";
	fout << ",";    fout << "��Ч����1";
	fout << ",";    fout << "��Ч����2";
	fout << ",";    fout << "��Ч����3";
	fout << ",";    fout << "��Ч����4";
	fout << ",";    fout << "��Ч����5";
	fout << ",";    fout << "��Ч����6";
	fout << ",";    fout << "��Ч����7";
	fout << ",";    fout << "��Ч����8";
	fout << ",";    fout << "��Ч����9";
	fout << ",";    fout << "��Ч����10";
	fout << ",";    fout << "��Ч����11";
	fout << ",";    fout << "��Ч����12";
	fout << ",";    fout << "��Ч����13";
	fout << ",";    fout << "��Ч����14";
	fout << ",";    fout << "��Ч����15";
	fout << ",";    fout << "��Ч����16";
	fout << ",";    fout << "��Ч����17";
	fout << ",";    fout << "��Ч����18";
	fout << ",";    fout << "��Ч����19";
	fout << ",";    fout << "��Ч����20";
	fout << ",";    fout << "��Ч����21";
	fout << ",";    fout << "��Ч����22";
	fout << ",";    fout << "��Ч����23";
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
// ����
void NewSave::SaveToCSVMenpaiSave(const std::vector<Menpai>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_����.csv");
	fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�ݵ����";
	fout << ",";    fout << "�ܶ�";
	fout << ",";    fout << "������";
	fout << ",";    fout << "���Ӹ���";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�����ƶ�";
	fout << ",";    fout << "����";
	fout << ",";    fout << "ʯ��";
	fout << ",";    fout << "ľ��";
	fout << ",";    fout << "ʳ��";
	fout << ",";    fout << "��̿";
	fout << ",";    fout << "��ҩ";
	fout << ",";    fout << "��ľ";
	fout << ",";    fout << "���";
	fout << ",";    fout << "ϡ��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "����+";
	fout << ",";    fout << "ʯ��+";
	fout << ",";    fout << "ľ��+";
	fout << ",";    fout << "ʳ��+";
	fout << ",";    fout << "��̿+";
	fout << ",";    fout << "��ҩ+";
	fout << ",";    fout << "��ľ+";
	fout << ",";    fout << "���+";
	fout << ",";    fout << "ϡ��+";
	fout << ",";    fout << "����+";
	fout << ",";    fout << "�����ڹ�";
	fout << ",";    fout << "�����ڹ�1";
	fout << ",";    fout << "�����ڹ�2";
	fout << ",";    fout << "�����ڹ�3";
	fout << ",";    fout << "�����ڹ�4";
	fout << ",";    fout << "�����ڹ�5";
	fout << ",";    fout << "�����ڹ�6";
	fout << ",";    fout << "�����ڹ�7";
	fout << ",";    fout << "�����ڹ�8";
	fout << ",";    fout << "�����ڹ�9";
	fout << ",";    fout << "�����ڹ�10";
	fout << ",";    fout << "�����ڹ�11";
	fout << ",";    fout << "�����ڹ�12";
	fout << ",";    fout << "�����ڹ�13";
	fout << ",";    fout << "�����ڹ�14";
	fout << ",";    fout << "�����ڹ�15";
	fout << ",";    fout << "�����ڹ�16";
	fout << ",";    fout << "�����ڹ�17";
	fout << ",";    fout << "�����ڹ�18";
	fout << ",";    fout << "�����ڹ�19";
	fout << ",";    fout << "���ɹ�ϵ";
	fout << ",";    fout << "���ɹ�ϵ1";
	fout << ",";    fout << "���ɹ�ϵ2";
	fout << ",";    fout << "���ɹ�ϵ3";
	fout << ",";    fout << "���ɹ�ϵ4";
	fout << ",";    fout << "���ɹ�ϵ5";
	fout << ",";    fout << "���ɹ�ϵ6";
	fout << ",";    fout << "���ɹ�ϵ7";
	fout << ",";    fout << "���ɹ�ϵ8";
	fout << ",";    fout << "���ɹ�ϵ9";
	fout << ",";    fout << "���ɹ�ϵ10";
	fout << ",";    fout << "���ɹ�ϵ11";
	fout << ",";    fout << "���ɹ�ϵ12";
	fout << ",";    fout << "���ɹ�ϵ13";
	fout << ",";    fout << "���ɹ�ϵ14";
	fout << ",";    fout << "���ɹ�ϵ15";
	fout << ",";    fout << "���ɹ�ϵ16";
	fout << ",";    fout << "���ɹ�ϵ17";
	fout << ",";    fout << "���ɹ�ϵ18";
	fout << ",";    fout << "���ɹ�ϵ19";
	fout << ",";    fout << "���ɹ�ϵ20";
	fout << ",";    fout << "���ɹ�ϵ21";
	fout << ",";    fout << "���ɹ�ϵ22";
	fout << ",";    fout << "���ɹ�ϵ23";
	fout << ",";    fout << "���ɹ�ϵ24";
	fout << ",";    fout << "���ɹ�ϵ25";
	fout << ",";    fout << "���ɹ�ϵ26";
	fout << ",";    fout << "���ɹ�ϵ27";
	fout << ",";    fout << "���ɹ�ϵ28";
	fout << ",";    fout << "���ɹ�ϵ29";
	fout << ",";    fout << "���ɹ�ϵ30";
	fout << ",";    fout << "���ɹ�ϵ31";
	fout << ",";    fout << "���ɹ�ϵ32";
	fout << ",";    fout << "���ɹ�ϵ33";
	fout << ",";    fout << "���ɹ�ϵ34";
	fout << ",";    fout << "���ɹ�ϵ35";
	fout << ",";    fout << "���ɹ�ϵ36";
	fout << ",";    fout << "���ɹ�ϵ37";
	fout << ",";    fout << "���ɹ�ϵ38";
	fout << ",";    fout << "���ɹ�ϵ39";
	fout << ",";    fout << "����ְ��";
	fout << ",";    fout << "����ְ��1";
	fout << ",";    fout << "����ְ��2";
	fout << ",";    fout << "����ְ��3";
	fout << ",";    fout << "����ְ��4";
	fout << ",";    fout << "����ְ��5";
	fout << ",";    fout << "����ְ��6";
	fout << ",";    fout << "����ְ��7";
	fout << ",";    fout << "����ְ��8";
	fout << ",";    fout << "����ְ��9";
	fout << ",";    fout << "��������";
	fout << ",";    fout << "�е�������";
	fout << ",";    fout << "���ӳɳ��ٶ�";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�е�����ͼ";
	fout << ",";    fout << "�е���ͷ��";
	fout << ",";    fout << "Ů������ͼ";
	fout << ",";    fout << "Ů����ͷ��";
	fout << ",";    fout << "�����Ա�";
	fout << ",";    fout << "�������";
	fout << ",";    fout << "�����¼�";
	fout << ",";    fout << "ͬ��";
	fout << ",";    fout << "���ұ��";
	fout << ",";    fout << "δ����2";
	fout << ",";    fout << "δ����3";
	fout << ",";    fout << "δ����4";
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
// ��ǩ
void NewSave::SaveToCSVRSignSave(const std::vector<RSign>& data, int record) {
	std::ofstream fout("../game/save/csv/" + std::to_string(record) + "_��ǩ.csv");
	fout << "���";
	fout << ",";    fout << "����";
	fout << ",";    fout << "Ч��";
	fout << ",";    fout << "���";
	fout << ",";    fout << "˵��";
	fout << ",";    fout << "����";
	fout << ",";    fout << "�Ƿ�����";
	fout << ",";    fout << "��Ч����";
	fout << ",";    fout << "��Ч����1";
	fout << ",";    fout << "��Ч����2";
	fout << ",";    fout << "��Ч����3";
	fout << ",";    fout << "��Ч����4";
	fout << ",";    fout << "��Ч����5";
	fout << ",";    fout << "��Ч����6";
	fout << ",";    fout << "��Ч����7";
	fout << ",";    fout << "��Ч����8";
	fout << ",";    fout << "��Ч����9";
	fout << ",";    fout << "��Ч����10";
	fout << ",";    fout << "��Ч����11";
	fout << ",";    fout << "��Ч����12";
	fout << ",";    fout << "��Ч����13";
	fout << ",";    fout << "��Ч����14";
	fout << ",";    fout << "��Ч����15";
	fout << ",";    fout << "��Ч����16";
	fout << ",";    fout << "��Ч����17";
	fout << ",";    fout << "��Ч����18";
	fout << ",";    fout << "��Ч����19";
	fout << ",";    fout << "��Ч����20";
	fout << ",";    fout << "��Ч����21";
	fout << ",";    fout << "��Ч����22";
	fout << ",";    fout << "��Ч����23";
	fout << ",";    fout << "��Ч����";
	fout << ",";    fout << "��Ч����1";
	fout << ",";    fout << "��Ч����2";
	fout << ",";    fout << "��Ч����3";
	fout << ",";    fout << "��Ч����4";
	fout << ",";    fout << "��Ч����5";
	fout << ",";    fout << "��Ч����6";
	fout << ",";    fout << "��Ч����7";
	fout << ",";    fout << "��Ч����8";
	fout << ",";    fout << "��Ч����9";
	fout << ",";    fout << "��Ч����10";
	fout << ",";    fout << "��Ч����11";
	fout << ",";    fout << "��Ч����12";
	fout << ",";    fout << "��Ч����13";
	fout << ",";    fout << "��Ч����14";
	fout << ",";    fout << "��Ч����15";
	fout << ",";    fout << "��Ч����16";
	fout << ",";    fout << "��Ч����17";
	fout << ",";    fout << "��Ч����18";
	fout << ",";    fout << "��Ч����19";
	fout << ",";    fout << "��Ч����20";
	fout << ",";    fout << "��Ч����21";
	fout << ",";    fout << "��Ч����22";
	fout << ",";    fout << "��Ч����23";
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
// ����
void NewSave::LoadFromCSVBaseInfo(Save::BaseInfo* data, int length, int record) {
	io::CSVReader<22, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"�˴�",
		"����",
		"��X",
		"��Y",
		"�ڳ�������X",
		"�ڳ�������Y",
		"����Է���",
		"��X",
		"��Y",
		"��ʱ",
		"��ʱ�¼�",
		"����¼�",
		"�ڳ�������",
		"����Է���",
		"��������",
		"����",
		"����1",
		"����2",
		"����3",
		"����4",
		"����5",
		"����"
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
// ����
void NewSave::LoadFromCSVItemList(ItemList* data, int length, int record) {
	io::CSVReader<2, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"��Ʒ���",
		"��Ʒ����"
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
// ����
void NewSave::LoadFromCSVRoleSave(std::vector<Role>& data, int record) {
	data.clear();
	io::CSVReader<307, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"ͷ��/ս������",
		"��������",
		"��Ե",
		"����",
		"���",
		"�Ա�",
		"�ȼ�",
		"����",
		"����",
		"�������ֵ",
		"���˳̶�",
		"�ж��̶�",
		"����",
		"ս��ͼ���",
		"װ��",
		"װ��1",
		"װ��2",
		"װ��3",
		"װ��4",
		"����",
		"����״̬",
		"��ŭֵ",
		"���ұ��",
		"�ж�����",
		"���ܵ�",
		"ս��AI״̬",
		"���",
		"�ж�ʱ��",
		"�Ѷ�",
		"�ҳ϶�",
		"ҩ��",
		"��������",
		"����",
		"�������ֵ",
		"������",
		"�Ṧ",
		"������",
		"ҽ��",
		"��ȱ",
		"����",
		"����",
		"ȭ��",
		"����",
		"ˣ��",
		"�������",
		"��������",
		"��ѧ��ʶ",
		"Ʒ��",
		"����",
		"���һ���",
		"����",
		"����",
		"������Ʒ",
		"��������",
		"����",
		"����",
		"�������",
		"��������",
		"Ʒ������",
		"��������",
		"��������",
		"��������",
		"ʦ��",
		"ʦ����λ",
		"��ʦ˳��",
		"��������1",
		"��������2",
		"��ǰλ��",
		"�ڲ�λ��",
		"�ڲ�����",
		"����״̬",
		"��������",
		"ڤ˼����",
		"�Ͷ�����",
		"��������",
		"��ʱλ��",
		"�ڲ���ʱλ��",
		"�ڲ�����1",
		"����X����",
		"����Y����",
		"������",
		"�ٸ�����",
		"����",
		"����",
		"δ��1",
		"δ��2",
		"δ��3",
		"ս��ID",
		"�����书",
		"�����书1",
		"�����书2",
		"�����书3",
		"�����书4",
		"�����书5",
		"�����书6",
		"�����书7",
		"�����书8",
		"�����书9",
		"�����书10",
		"�����书11",
		"�����书12",
		"�����书13",
		"�����书14",
		"�����书15",
		"�����书16",
		"�����书17",
		"�����书18",
		"�����书19",
		"�����书20",
		"�����书21",
		"�����书22",
		"�����书23",
		"�����书24",
		"�����书25",
		"�����书26",
		"�����书27",
		"�����书28",
		"�����书29",
		"�����书30",
		"�����书31",
		"�����书32",
		"�����书33",
		"�����书34",
		"�����书35",
		"�����书36",
		"�����书37",
		"�����书38",
		"�����书39",
		"�����书�ȼ�",
		"�����书�ȼ�1",
		"�����书�ȼ�2",
		"�����书�ȼ�3",
		"�����书�ȼ�4",
		"�����书�ȼ�5",
		"�����书�ȼ�6",
		"�����书�ȼ�7",
		"�����书�ȼ�8",
		"�����书�ȼ�9",
		"�����书�ȼ�10",
		"�����书�ȼ�11",
		"�����书�ȼ�12",
		"�����书�ȼ�13",
		"�����书�ȼ�14",
		"�����书�ȼ�15",
		"�����书�ȼ�16",
		"�����书�ȼ�17",
		"�����书�ȼ�18",
		"�����书�ȼ�19",
		"�����书�ȼ�20",
		"�����书�ȼ�21",
		"�����书�ȼ�22",
		"�����书�ȼ�23",
		"�����书�ȼ�24",
		"�����书�ȼ�25",
		"�����书�ȼ�26",
		"�����书�ȼ�27",
		"�����书�ȼ�28",
		"�����书�ȼ�29",
		"�����书�ȼ�30",
		"�����书�ȼ�31",
		"�����书�ȼ�32",
		"�����书�ȼ�33",
		"�����书�ȼ�34",
		"�����书�ȼ�35",
		"�����书�ȼ�36",
		"�����书�ȼ�37",
		"�����书�ȼ�38",
		"�����书�ȼ�39",
		"Я����Ʒ",
		"Я����Ʒ1",
		"Я����Ʒ2",
		"Я����Ʒ3",
		"Я����Ʒ4",
		"Я����Ʒ5",
		"Я����Ʒ6",
		"Я����Ʒ7",
		"Я����Ʒ8",
		"Я����Ʒ����",
		"Я����Ʒ����1",
		"Я����Ʒ����2",
		"Я����Ʒ����3",
		"Я����Ʒ����4",
		"Я����Ʒ����5",
		"Я����Ʒ����6",
		"Я����Ʒ����7",
		"Я����Ʒ����8",
		"�����书",
		"�����书1",
		"�����书2",
		"�����书3",
		"�����书4",
		"�����书5",
		"�����书6",
		"�����书7",
		"�����书8",
		"�����书9",
		"������ʽ",
		"������ʽ1",
		"������ʽ2",
		"������ʽ3",
		"������ʽ4",
		"������ʽ5",
		"������ʽ6",
		"������ʽ7",
		"������ʽ8",
		"������ʽ9",
		"������ʽ10",
		"������ʽ11",
		"������ʽ12",
		"������ʽ13",
		"������ʽ14",
		"������ʽ15",
		"������ʽ16",
		"������ʽ17",
		"������ʽ18",
		"������ʽ19",
		"������ʽ20",
		"������ʽ21",
		"������ʽ22",
		"������ʽ23",
		"������ʽ24",
		"������ʽ25",
		"������ʽ26",
		"������ʽ27",
		"������ʽ28",
		"������ʽ29",
		"������ʽ30",
		"������ʽ31",
		"������ʽ32",
		"������ʽ33",
		"������ʽ34",
		"������ʽ35",
		"������ʽ36",
		"������ʽ37",
		"������ʽ38",
		"������ʽ39",
		"�Ի��˵�����",
		"�Ի��¼�",
		"״̬�¼�",
		"����¼�",
		"�д��¼�",
		"ѧϰ�¼�",
		"�¼���1",
		"�¼���2",
		"�¼���3",
		"�������",
		"����¼�",
		"���ֵ",
		"���ֵ1",
		"����",
		"ҽʦ",
		"װ���ؼ�",
		"��Ѫ",
		"����",
		"����",
		"����",
		"���",
		"��ѧ",
		"ͻ��",
		"�侲",
		"�ٱ�",
		"����",
		"����",
		"���",
		"����",
		"����",
		"Ӳ��",
		"���",
		"����",
		"��",
		"����Ǳ��",
		"����Ǳ��",
		"�ṦǱ��",
		"ȭ��Ǳ��",
		"����Ǳ��",
		"ˣ��Ǳ��",
		"����Ǳ��",
		"����Ǳ��",
		"����",
		"����",
		"����",
		"ר��",
		"ר��1",
		"ר��2",
		"ר��3",
		"ר��4",
		"����",
		"����1",
		"����2",
		"����3",
		"����4",
		"����5",
		"����6",
		"����7",
		"����8",
		"����9",
		"���ɹ���",
		"δʹ��",
		"δʹ��1",
		"δʹ��2",
		"δʹ��3",
		"δʹ��4",
		"δʹ��5",
		"δʹ��6",
		"δʹ��7",
		"δʹ��8"

	);
	auto getDefault = []() {
		Role nextLineData;
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
		return nextLineData;
	};
	char * Name__;
	char * Nick__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		nextLineData.HeadID,
		nextLineData.IncLife,
		nextLineData.Fuyuan,
		Name__,
		Nick__,
		nextLineData.Sexual,
		nextLineData.Level,
		nextLineData.Exp,
		nextLineData.HP,
		nextLineData.MaxHP,
		nextLineData.Hurt,
		nextLineData.Poison,
		nextLineData.PhysicalPower,
		nextLineData.FightNum,
		nextLineData.Equip[0],
		nextLineData.Equip[1],
		nextLineData.Equip[2],
		nextLineData.Equip[3],
		nextLineData.Equip[4],
		nextLineData.Gongti,
		nextLineData.TeamState,
		nextLineData.Angry,
		nextLineData.isRandomed,
		nextLineData.Moveable,
		nextLineData.skillPoint,
		nextLineData.ZhanLueAI,
		nextLineData.Impression,
		nextLineData.dtime,
		nextLineData.difficulty,
		nextLineData.Zhongcheng,
		nextLineData.reHurt,
		nextLineData.MPType,
		nextLineData.MP,
		nextLineData.MaxMP,
		nextLineData.Attack,
		nextLineData.Speed,
		nextLineData.Defence,
		nextLineData.Medicine,
		nextLineData.Weiyong,
		nextLineData.Art,
		nextLineData.AntiPoison,
		nextLineData.Fist,
		nextLineData.Sword,
		nextLineData.Knife,
		nextLineData.Unusual,
		nextLineData.HiddenWeapon,
		nextLineData.Knowledge,
		nextLineData.Morality,
		nextLineData.AttackWithPoison,
		nextLineData.AttackTwice,
		nextLineData.Fame,
		nextLineData.IQ,
		nextLineData.PracticeItem,
		nextLineData.ExpForItem,
		nextLineData.xiangxing,
		nextLineData.jiaoqing,
		nextLineData.Rtype,
		nextLineData.swq,
		nextLineData.pdq,
		nextLineData.xxq,
		nextLineData.jqq,
		nextLineData.MenPai,
		nextLineData.shifu,
		nextLineData.scsx,
		nextLineData.bssx,
		nextLineData.Choushi[0],
		nextLineData.Choushi[1],
		nextLineData.weizhi,
		nextLineData.nweizhi,
		nextLineData.nfangxiang,
		nextLineData.OnStatus,
		nextLineData.lwq,
		nextLineData.msq,
		nextLineData.ldq,
		nextLineData.qtq,
		nextLineData.lsweizhi,
		nextLineData.lsnweizhi,
		nextLineData.lsfangxiang,
		nextLineData.Sx,
		nextLineData.Sy,
		nextLineData.songshu,
		nextLineData.gongxian,
		nextLineData.fuqi,
		nextLineData.age,
		nextLineData.weiyong1,
		nextLineData.weiyong2,
		nextLineData.weiyong3,
		nextLineData.btnum,
		nextLineData.MagicID[0],
		nextLineData.MagicID[1],
		nextLineData.MagicID[2],
		nextLineData.MagicID[3],
		nextLineData.MagicID[4],
		nextLineData.MagicID[5],
		nextLineData.MagicID[6],
		nextLineData.MagicID[7],
		nextLineData.MagicID[8],
		nextLineData.MagicID[9],
		nextLineData.MagicID[10],
		nextLineData.MagicID[11],
		nextLineData.MagicID[12],
		nextLineData.MagicID[13],
		nextLineData.MagicID[14],
		nextLineData.MagicID[15],
		nextLineData.MagicID[16],
		nextLineData.MagicID[17],
		nextLineData.MagicID[18],
		nextLineData.MagicID[19],
		nextLineData.MagicID[20],
		nextLineData.MagicID[21],
		nextLineData.MagicID[22],
		nextLineData.MagicID[23],
		nextLineData.MagicID[24],
		nextLineData.MagicID[25],
		nextLineData.MagicID[26],
		nextLineData.MagicID[27],
		nextLineData.MagicID[28],
		nextLineData.MagicID[29],
		nextLineData.MagicID[30],
		nextLineData.MagicID[31],
		nextLineData.MagicID[32],
		nextLineData.MagicID[33],
		nextLineData.MagicID[34],
		nextLineData.MagicID[35],
		nextLineData.MagicID[36],
		nextLineData.MagicID[37],
		nextLineData.MagicID[38],
		nextLineData.MagicID[39],
		nextLineData.MagicLevel[0],
		nextLineData.MagicLevel[1],
		nextLineData.MagicLevel[2],
		nextLineData.MagicLevel[3],
		nextLineData.MagicLevel[4],
		nextLineData.MagicLevel[5],
		nextLineData.MagicLevel[6],
		nextLineData.MagicLevel[7],
		nextLineData.MagicLevel[8],
		nextLineData.MagicLevel[9],
		nextLineData.MagicLevel[10],
		nextLineData.MagicLevel[11],
		nextLineData.MagicLevel[12],
		nextLineData.MagicLevel[13],
		nextLineData.MagicLevel[14],
		nextLineData.MagicLevel[15],
		nextLineData.MagicLevel[16],
		nextLineData.MagicLevel[17],
		nextLineData.MagicLevel[18],
		nextLineData.MagicLevel[19],
		nextLineData.MagicLevel[20],
		nextLineData.MagicLevel[21],
		nextLineData.MagicLevel[22],
		nextLineData.MagicLevel[23],
		nextLineData.MagicLevel[24],
		nextLineData.MagicLevel[25],
		nextLineData.MagicLevel[26],
		nextLineData.MagicLevel[27],
		nextLineData.MagicLevel[28],
		nextLineData.MagicLevel[29],
		nextLineData.MagicLevel[30],
		nextLineData.MagicLevel[31],
		nextLineData.MagicLevel[32],
		nextLineData.MagicLevel[33],
		nextLineData.MagicLevel[34],
		nextLineData.MagicLevel[35],
		nextLineData.MagicLevel[36],
		nextLineData.MagicLevel[37],
		nextLineData.MagicLevel[38],
		nextLineData.MagicLevel[39],
		nextLineData.TakingItem[0],
		nextLineData.TakingItem[1],
		nextLineData.TakingItem[2],
		nextLineData.TakingItem[3],
		nextLineData.TakingItem[4],
		nextLineData.TakingItem[5],
		nextLineData.TakingItem[6],
		nextLineData.TakingItem[7],
		nextLineData.TakingItem[8],
		nextLineData.TakingItemCount[0],
		nextLineData.TakingItemCount[1],
		nextLineData.TakingItemCount[2],
		nextLineData.TakingItemCount[3],
		nextLineData.TakingItemCount[4],
		nextLineData.TakingItemCount[5],
		nextLineData.TakingItemCount[6],
		nextLineData.TakingItemCount[7],
		nextLineData.TakingItemCount[8],
		nextLineData.JhMagic[0],
		nextLineData.JhMagic[1],
		nextLineData.JhMagic[2],
		nextLineData.JhMagic[3],
		nextLineData.JhMagic[4],
		nextLineData.JhMagic[5],
		nextLineData.JhMagic[6],
		nextLineData.JhMagic[7],
		nextLineData.JhMagic[8],
		nextLineData.JhMagic[9],
		nextLineData.LZhaoshi[0],
		nextLineData.LZhaoshi[1],
		nextLineData.LZhaoshi[2],
		nextLineData.LZhaoshi[3],
		nextLineData.LZhaoshi[4],
		nextLineData.LZhaoshi[5],
		nextLineData.LZhaoshi[6],
		nextLineData.LZhaoshi[7],
		nextLineData.LZhaoshi[8],
		nextLineData.LZhaoshi[9],
		nextLineData.LZhaoshi[10],
		nextLineData.LZhaoshi[11],
		nextLineData.LZhaoshi[12],
		nextLineData.LZhaoshi[13],
		nextLineData.LZhaoshi[14],
		nextLineData.LZhaoshi[15],
		nextLineData.LZhaoshi[16],
		nextLineData.LZhaoshi[17],
		nextLineData.LZhaoshi[18],
		nextLineData.LZhaoshi[19],
		nextLineData.LZhaoshi[20],
		nextLineData.LZhaoshi[21],
		nextLineData.LZhaoshi[22],
		nextLineData.LZhaoshi[23],
		nextLineData.LZhaoshi[24],
		nextLineData.LZhaoshi[25],
		nextLineData.LZhaoshi[26],
		nextLineData.LZhaoshi[27],
		nextLineData.LZhaoshi[28],
		nextLineData.LZhaoshi[29],
		nextLineData.LZhaoshi[30],
		nextLineData.LZhaoshi[31],
		nextLineData.LZhaoshi[32],
		nextLineData.LZhaoshi[33],
		nextLineData.LZhaoshi[34],
		nextLineData.LZhaoshi[35],
		nextLineData.LZhaoshi[36],
		nextLineData.LZhaoshi[37],
		nextLineData.LZhaoshi[38],
		nextLineData.LZhaoshi[39],
		nextLineData.IsEvent,
		nextLineData.TalkEvent,
		nextLineData.StateEvent,
		nextLineData.JoinEvent,
		nextLineData.TestEvent,
		nextLineData.LearnEvent,
		nextLineData.unusedEvent1,
		nextLineData.unusedEvent2,
		nextLineData.unusedEvent3,
		nextLineData.LeaveTime,
		nextLineData.LeaveEvent,
		nextLineData.RandomNum1,
		nextLineData.RandomNum2,
		nextLineData.anjian,
		nextLineData.yishi,
		nextLineData.zbtj,
		nextLineData.huixue,
		nextLineData.huinei,
		nextLineData.huiti,
		nextLineData.baozhao,
		nextLineData.peihe,
		nextLineData.wuxue,
		nextLineData.tupo,
		nextLineData.lengjing,
		nextLineData.baibian,
		nextLineData.poqi,
		nextLineData.zhaomen,
		nextLineData.bianhuan,
		nextLineData.fangong,
		nextLineData.qigong,
		nextLineData.yinggong,
		nextLineData.linghuo,
		nextLineData.xingqi,
		nextLineData.shenfa,
		nextLineData.gjql,
		nextLineData.fyql,
		nextLineData.qgql,
		nextLineData.qzql,
		nextLineData.yjql,
		nextLineData.sdql,
		nextLineData.qmql,
		nextLineData.aqql,
		nextLineData.gushou,
		nextLineData.tianmin,
		nextLineData.xingxiu,
		nextLineData.zhuanchang[0],
		nextLineData.zhuanchang[1],
		nextLineData.zhuanchang[2],
		nextLineData.zhuanchang[3],
		nextLineData.zhuanchang[4],
		nextLineData.texing[0],
		nextLineData.texing[1],
		nextLineData.texing[2],
		nextLineData.texing[3],
		nextLineData.texing[4],
		nextLineData.texing[5],
		nextLineData.texing[6],
		nextLineData.texing[7],
		nextLineData.texing[8],
		nextLineData.texing[9],
		nextLineData.menpaiContribution,
		nextLineData.Unused[0],
		nextLineData.Unused[1],
		nextLineData.Unused[2],
		nextLineData.Unused[3],
		nextLineData.Unused[4],
		nextLineData.Unused[5],
		nextLineData.Unused[6],
		nextLineData.Unused[7],
		nextLineData.Unused[8]
	)) {
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		strncpy(nextLineData.Nick, Nick__, sizeof(nextLineData.Nick) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// ��Ʒ
void NewSave::LoadFromCSVItemSave(std::vector<Item>& data, int record) {
	data.clear();
	io::CSVReader<82, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_��Ʒ.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"��Ʒ��",
		"��Ʒ�书����",
		"��װ��",
		"ս����Ч",
		"���ӱ�ǩ",
		"Ҫ���Ա�",
		"�ָ�����",
		"��Ʒ��",
		"������",
		"����Ǳ��ֵ",
		"ս����",
		"��Ʒ˵��",
		"�����书",
		"�����������",
		"ʹ����",
		"װ������",
		"��ʾ��Ʒ˵��",
		"����",
		"�̵���",
		"�ۼ�",
		"�����¼�",
		"������",
		"���������ֵ",
		"���ж��ⶾ",
		"������",
		"�ı���������",
		"������",
		"���������ֵ",
		"�ӹ�����",
		"���Ṧ",
		"�ӷ�����",
		"��ҽ��",
		"��ʹ��",
		"�Ӽ���",
		"�ӿ���",
		"��ȭ��",
		"������",
		"��ˣ��",
		"���������",
		"�Ӱ�������",
		"����ѧ��ʶ",
		"��Ʒ��",
		"������",
		"�ӹ�������",
		"����������",
		"����������",
		"������",
		"�蹥����",
		"���Ṧ",
		"�趾��",
		"��ҽ��",
		"�輼��",
		"��ȭ��",
		"������",
		"��ˣ��",
		"���������",
		"�谵��",
		"������",
		"�辭��",
		"����",
		"ϡ�ж�",
		"������Ʒ",
		"������Ʒ1",
		"������Ʒ2",
		"������Ʒ3",
		"������Ʒ4",
		"��Ҫ��Ʒ����",
		"��Ҫ��Ʒ����1",
		"��Ҫ��Ʒ����2",
		"��Ҫ��Ʒ����3",
		"��Ҫ��Ʒ����4",
		"������",
		"�Ӹ�Դ",
		"δʹ��",
		"δʹ��1",
		"δʹ��2",
		"δʹ��3",
		"δʹ��4",
		"δʹ��5",
		"δʹ��6",
		"δʹ��7"
	);
	auto getDefault = []() {
		Item nextLineData;
		nextLineData.ID = 0;
		memset(nextLineData.Name, '\0', sizeof(nextLineData.Name));
		nextLineData.ExpofMagic = 0;
		nextLineData.SetNum = 0;
		nextLineData.BattleBattleEffect = 0;
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
	char * Name__;
	char * Introduction__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.ExpofMagic,
		nextLineData.SetNum,
		nextLineData.BattleBattleEffect,
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
		strncpy(nextLineData.Introduction, Introduction__, sizeof(nextLineData.Introduction) - 1);
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// ����
void NewSave::LoadFromCSVSubMapInfoSave(std::vector<SubMapInfo>& data, int record) {
	data.clear();
	io::CSVReader<91, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"����",
		"��������",
		"��������",
		"������ɫ��",
		"��������",
		"�⾰���X1",
		"�⾰���Y1",
		"�⾰���X2",
		"�⾰���Y2",
		"���X",
		"���Y",
		"����X1",
		"����X2",
		"����X3",
		"����Y1",
		"����Y2",
		"����Y3",
		"����",
		"δ��",
		"��������",
		"ս����",
		"�����䳡��",
		"���䳡��",
		"�ܲؾ�����",
		"�ؾ�����",
		"���䳡X",
		"���䳡X1",
		"���䳡X2",
		"���䳡X3",
		"���䳡X4",
		"���䳡Y",
		"���䳡Y1",
		"���䳡Y2",
		"���䳡Y3",
		"���䳡Y4",
		"�ؾ���X",
		"�ؾ���X1",
		"�ؾ���X2",
		"�ؾ���X3",
		"�ؾ���X4",
		"�ؾ���Y",
		"�ؾ���Y1",
		"�ؾ���Y2",
		"�ؾ���Y3",
		"�ؾ���Y4",
		"�չ��ҿ���",
		"�չ���X",
		"�չ���Y",
		"����¯����",
		"����¯X",
		"����¯Y",
		"����������",
		"������X",
		"������Y",
		"����X",
		"����Y",
		"��������",
		"�������",
		"�����ӳ�",
		"������ʩ",
		"����",
		"ʯ��",
		"ľ��",
		"ʳ��",
		"��̿",
		"��ҩ",
		"��ľ",
		"���",
		"ϡ��",
		"����",
		"����",
		"����1",
		"����2",
		"����3",
		"����4",
		"����5",
		"����6",
		"����7",
		"����8",
		"����9",
		"δʹ��",
		"δʹ��1",
		"δʹ��2",
		"δʹ��3",
		"δʹ��4",
		"δʹ��5",
		"δʹ��6",
		"δʹ��7",
		"δʹ��8",
		"δʹ��9"
	);
	auto getDefault = []() {
		SubMapInfo nextLineData;
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
		return nextLineData;
	};
	char * Name__;
	int lines = 0;
	auto nextLineData = getDefault();
	while (in.read_row(
		nextLineData.ID,
		Name__,
		nextLineData.ExitMusic,
		nextLineData.EntranceMusic,
		nextLineData.SubMapColor,
		nextLineData.EntranceCondition,
		nextLineData.MainEntranceX1,
		nextLineData.MainEntranceY1,
		nextLineData.MainEntranceX2,
		nextLineData.MainEntranceY2,
		nextLineData.EntranceX,
		nextLineData.EntranceY,
		nextLineData.ExitX[0],
		nextLineData.ExitX[1],
		nextLineData.ExitX[2],
		nextLineData.ExitY[0],
		nextLineData.ExitY[1],
		nextLineData.ExitY[2],
		nextLineData.Environment,
		nextLineData.Weiyong,
		nextLineData.menpai,
		nextLineData.inbattle,
		nextLineData.zlwc,
		nextLineData.lwc,
		nextLineData.zcjg,
		nextLineData.cjg,
		nextLineData.lwcx[0],
		nextLineData.lwcx[1],
		nextLineData.lwcx[2],
		nextLineData.lwcx[3],
		nextLineData.lwcx[4],
		nextLineData.lwcY[0],
		nextLineData.lwcY[1],
		nextLineData.lwcY[2],
		nextLineData.lwcY[3],
		nextLineData.lwcY[4],
		nextLineData.cjgx[0],
		nextLineData.cjgx[1],
		nextLineData.cjgx[2],
		nextLineData.cjgx[3],
		nextLineData.cjgx[4],
		nextLineData.cjgY[0],
		nextLineData.cjgY[1],
		nextLineData.cjgY[2],
		nextLineData.cjgY[3],
		nextLineData.cjgY[4],
		nextLineData.bgskg,
		nextLineData.bgsx,
		nextLineData.bgsy,
		nextLineData.ldlkg,
		nextLineData.ldlx,
		nextLineData.ldly,
		nextLineData.bqckg,
		nextLineData.bqcx,
		nextLineData.bqcy,
		nextLineData.qizhix,
		nextLineData.qizhiy,
		nextLineData.ldjd,
		nextLineData.dzjd,
		nextLineData.fyjc,
		nextLineData.fyss,
		nextLineData.addtk,
		nextLineData.addsl,
		nextLineData.addmc,
		nextLineData.addsw,
		nextLineData.addjt,
		nextLineData.addcy,
		nextLineData.addwm,
		nextLineData.addyc,
		nextLineData.addxj,
		nextLineData.addxt,
		nextLineData.lianjie[0],
		nextLineData.lianjie[1],
		nextLineData.lianjie[2],
		nextLineData.lianjie[3],
		nextLineData.lianjie[4],
		nextLineData.lianjie[5],
		nextLineData.lianjie[6],
		nextLineData.lianjie[7],
		nextLineData.lianjie[8],
		nextLineData.lianjie[9],
		nextLineData.Unused[0],
		nextLineData.Unused[1],
		nextLineData.Unused[2],
		nextLineData.Unused[3],
		nextLineData.Unused[4],
		nextLineData.Unused[5],
		nextLineData.Unused[6],
		nextLineData.Unused[7],
		nextLineData.Unused[8],
		nextLineData.Unused[9]
	)) {
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// �书
void NewSave::LoadFromCSVMagicSave(std::vector<Magic>& data, int record) {
	data.clear();
	io::CSVReader<114, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_�书.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"����",
		"����",
		"�ؼ�",
		"��Ҫ����",
		"��С����",
		"�Ƿ�ͼ��Ч",
		"�¼�",
		"������Ч",
		"�书����",
		"�书����&��Ч",
		"��������",
		"������Χ",
		"��������",
		"�����ж�����",
		"��С������",
		"��󹥻���",
		"����ϵ��",
		"����������",
		"��������",
		"�Ṧ����",
		"����ֵ����",
		"�Ƿ��ش�",
		"����������",
		"����������",
		"�ƶ���Χ",
		"�ƶ���Χ1",
		"�ƶ���Χ2",
		"�ƶ���Χ3",
		"�ƶ���Χ4",
		"�ƶ���Χ5",
		"�ƶ���Χ6",
		"�ƶ���Χ7",
		"�ƶ���Χ8",
		"�ƶ���Χ9",
		"ɱ�˷�Χ",
		"ɱ�˷�Χ1",
		"ɱ�˷�Χ2",
		"ɱ�˷�Χ3",
		"ɱ�˷�Χ4",
		"ɱ�˷�Χ5",
		"ɱ�˷�Χ6",
		"ɱ�˷�Χ7",
		"ɱ�˷�Χ8",
		"ɱ�˷�Χ9",
		"������",
		"������1",
		"������2",
		"������",
		"������1",
		"������2",
		"�ӹ���",
		"�ӹ���1",
		"�ӹ���2",
		"�ӷ���",
		"�ӷ���1",
		"�ӷ���2",
		"���Ṧ",
		"���Ṧ1",
		"���Ṧ2",
		"��С��Ѩ����",
		"����Ѩ����",
		"��С���˼���",
		"������˼���",
		"����ҽ��",
		"���Ӷ���",
		"���Ӽ���",
		"���ӿ���",
		"����ȭ��",
		"��������",
		"����ˣ��",
		"��������",
		"���Ӱ���",
		"״̬",
		"�辭��1",
		"�辭��2",
		"�辭��3",
		"��ߵȼ�",
		"˵��",
		"��ʽ",
		"��ʽ1",
		"��ʽ2",
		"��ʽ3",
		"��ʽ4",
		"����",
		"����1",
		"����2",
		"����3",
		"����4",
		"����5",
		"����6",
		"����7",
		"����8",
		"����9",
		"��������",
		"��������1",
		"��������2",
		"��������3",
		"��������4",
		"��������5",
		"��������6",
		"��������7",
		"��������8",
		"��������9",
		"δʹ��",
		"δʹ��1",
		"δʹ��2",
		"δʹ��3",
		"δʹ��4",
		"δʹ��5",
		"δʹ��6",
		"δʹ��7",
		"δʹ��8",
		"δʹ��9"
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
	char * Name__;
	char * Introduction__;
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
		strncpy(nextLineData.Introduction, Introduction__, sizeof(nextLineData.Introduction) - 1);
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// �̵�
void NewSave::LoadFromCSVShopSave(std::vector<Shop>& data, int record) {
	data.clear();
	io::CSVReader<70, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_�̵�.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"��Ʒ���",
		"��Ʒ���1",
		"��Ʒ���2",
		"��Ʒ���3",
		"��Ʒ���4",
		"��Ʒ���5",
		"��Ʒ���6",
		"��Ʒ���7",
		"��Ʒ���8",
		"��Ʒ���9",
		"��Ʒ���10",
		"��Ʒ���11",
		"��Ʒ���12",
		"��Ʒ���13",
		"��Ʒ���14",
		"��Ʒ���15",
		"��Ʒ���16",
		"��Ʒ���17",
		"��Ʒ���18",
		"��Ʒ���19",
		"��Ʒ���20",
		"��Ʒ���21",
		"��Ʒ���22",
		"��Ʒ���23",
		"��Ʒ���24",
		"��Ʒ���25",
		"��Ʒ���26",
		"��Ʒ���27",
		"��Ʒ���28",
		"��Ʒ���29",
		"��Ʒ���30",
		"��Ʒ���31",
		"��Ʒ���32",
		"��Ʒ���33",
		"��Ʒ���34",
		"��Ʒ����",
		"��Ʒ����1",
		"��Ʒ����2",
		"��Ʒ����3",
		"��Ʒ����4",
		"��Ʒ����5",
		"��Ʒ����6",
		"��Ʒ����7",
		"��Ʒ����8",
		"��Ʒ����9",
		"��Ʒ����10",
		"��Ʒ����11",
		"��Ʒ����12",
		"��Ʒ����13",
		"��Ʒ����14",
		"��Ʒ����15",
		"��Ʒ����16",
		"��Ʒ����17",
		"��Ʒ����18",
		"��Ʒ����19",
		"��Ʒ����20",
		"��Ʒ����21",
		"��Ʒ����22",
		"��Ʒ����23",
		"��Ʒ����24",
		"��Ʒ����25",
		"��Ʒ����26",
		"��Ʒ����27",
		"��Ʒ����28",
		"��Ʒ����29",
		"��Ʒ����30",
		"��Ʒ����31",
		"��Ʒ����32",
		"��Ʒ����33",
		"��Ʒ����34"
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
// ʱ��
void NewSave::LoadFromCSVTimeSave(TimeSave* data, int length, int record) {
	io::CSVReader<5, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"����",
		"��",
		"��",
		"��",
		"�r"
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
// ��ʽ
void NewSave::LoadFromCSVZhaoshiSave(std::vector<Zhaoshi>& data, int record) {
	data.clear();
	io::CSVReader<57, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_��ʽ.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"����",
		"˳λ",
		"����",
		"�Ƿ񹥻�",
		"�����ӳ�",
		"�Ƿ����",
		"�����ӳ�",
		"˵��",
		"��Ч����",
		"��Ч����1",
		"��Ч����2",
		"��Ч����3",
		"��Ч����4",
		"��Ч����5",
		"��Ч����6",
		"��Ч����7",
		"��Ч����8",
		"��Ч����9",
		"��Ч����10",
		"��Ч����11",
		"��Ч����12",
		"��Ч����13",
		"��Ч����14",
		"��Ч����15",
		"��Ч����16",
		"��Ч����17",
		"��Ч����18",
		"��Ч����19",
		"��Ч����20",
		"��Ч����21",
		"��Ч����22",
		"��Ч����23",
		"��Ч����",
		"��Ч����1",
		"��Ч����2",
		"��Ч����3",
		"��Ч����4",
		"��Ч����5",
		"��Ч����6",
		"��Ч����7",
		"��Ч����8",
		"��Ч����9",
		"��Ч����10",
		"��Ч����11",
		"��Ч����12",
		"��Ч����13",
		"��Ч����14",
		"��Ч����15",
		"��Ч����16",
		"��Ч����17",
		"��Ч����18",
		"��Ч����19",
		"��Ч����20",
		"��Ч����21",
		"��Ч����22",
		"��Ч����23"
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
	char * Name__;
	char * Introduction__;
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
		strncpy(nextLineData.Introduction, Introduction__, sizeof(nextLineData.Introduction) - 1);
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// ����
void NewSave::LoadFromCSVMenpaiSave(std::vector<Menpai>& data, int record) {
	data.clear();
	io::CSVReader<114, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_����.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"����",
		"�ݵ����",
		"�ܶ�",
		"������",
		"���Ӹ���",
		"��������",
		"�����ƶ�",
		"����",
		"ʯ��",
		"ľ��",
		"ʳ��",
		"��̿",
		"��ҩ",
		"��ľ",
		"���",
		"ϡ��",
		"����",
		"����+",
		"ʯ��+",
		"ľ��+",
		"ʳ��+",
		"��̿+",
		"��ҩ+",
		"��ľ+",
		"���+",
		"ϡ��+",
		"����+",
		"�����ڹ�",
		"�����ڹ�1",
		"�����ڹ�2",
		"�����ڹ�3",
		"�����ڹ�4",
		"�����ڹ�5",
		"�����ڹ�6",
		"�����ڹ�7",
		"�����ڹ�8",
		"�����ڹ�9",
		"�����ڹ�10",
		"�����ڹ�11",
		"�����ڹ�12",
		"�����ڹ�13",
		"�����ڹ�14",
		"�����ڹ�15",
		"�����ڹ�16",
		"�����ڹ�17",
		"�����ڹ�18",
		"�����ڹ�19",
		"���ɹ�ϵ",
		"���ɹ�ϵ1",
		"���ɹ�ϵ2",
		"���ɹ�ϵ3",
		"���ɹ�ϵ4",
		"���ɹ�ϵ5",
		"���ɹ�ϵ6",
		"���ɹ�ϵ7",
		"���ɹ�ϵ8",
		"���ɹ�ϵ9",
		"���ɹ�ϵ10",
		"���ɹ�ϵ11",
		"���ɹ�ϵ12",
		"���ɹ�ϵ13",
		"���ɹ�ϵ14",
		"���ɹ�ϵ15",
		"���ɹ�ϵ16",
		"���ɹ�ϵ17",
		"���ɹ�ϵ18",
		"���ɹ�ϵ19",
		"���ɹ�ϵ20",
		"���ɹ�ϵ21",
		"���ɹ�ϵ22",
		"���ɹ�ϵ23",
		"���ɹ�ϵ24",
		"���ɹ�ϵ25",
		"���ɹ�ϵ26",
		"���ɹ�ϵ27",
		"���ɹ�ϵ28",
		"���ɹ�ϵ29",
		"���ɹ�ϵ30",
		"���ɹ�ϵ31",
		"���ɹ�ϵ32",
		"���ɹ�ϵ33",
		"���ɹ�ϵ34",
		"���ɹ�ϵ35",
		"���ɹ�ϵ36",
		"���ɹ�ϵ37",
		"���ɹ�ϵ38",
		"���ɹ�ϵ39",
		"����ְ��",
		"����ְ��1",
		"����ְ��2",
		"����ְ��3",
		"����ְ��4",
		"����ְ��5",
		"����ְ��6",
		"����ְ��7",
		"����ְ��8",
		"����ְ��9",
		"��������",
		"�е�������",
		"���ӳɳ��ٶ�",
		"����",
		"�е�����ͼ",
		"�е���ͷ��",
		"Ů������ͼ",
		"Ů����ͷ��",
		"�����Ա�",
		"�������",
		"�����¼�",
		"ͬ��",
		"���ұ��",
		"δ����2",
		"δ����3",
		"δ����4"
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
	char * Name__;
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
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
	}
}
// ��ǩ
void NewSave::LoadFromCSVRSignSave(std::vector<RSign>& data, int record) {
	data.clear();
	io::CSVReader<55, io::trim_chars<>, io::double_quote_escape<',', '\"'>> in("../game/save/csv/" + std::to_string(record) + "_��ǩ.csv");
	in.read_header(io::ignore_missing_column | io::ignore_extra_column,
		"���",
		"����",
		"Ч��",
		"���",
		"˵��",
		"����",
		"�Ƿ�����",
		"��Ч����",
		"��Ч����1",
		"��Ч����2",
		"��Ч����3",
		"��Ч����4",
		"��Ч����5",
		"��Ч����6",
		"��Ч����7",
		"��Ч����8",
		"��Ч����9",
		"��Ч����10",
		"��Ч����11",
		"��Ч����12",
		"��Ч����13",
		"��Ч����14",
		"��Ч����15",
		"��Ч����16",
		"��Ч����17",
		"��Ч����18",
		"��Ч����19",
		"��Ч����20",
		"��Ч����21",
		"��Ч����22",
		"��Ч����23",
		"��Ч����",
		"��Ч����1",
		"��Ч����2",
		"��Ч����3",
		"��Ч����4",
		"��Ч����5",
		"��Ч����6",
		"��Ч����7",
		"��Ч����8",
		"��Ч����9",
		"��Ч����10",
		"��Ч����11",
		"��Ч����12",
		"��Ч����13",
		"��Ч����14",
		"��Ч����15",
		"��Ч����16",
		"��Ч����17",
		"��Ч����18",
		"��Ч����19",
		"��Ч����20",
		"��Ч����21",
		"��Ч����22",
		"��Ч����23"
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
	char * Name__;
	char * Introduction__;
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
		strncpy(nextLineData.Introduction, Introduction__, sizeof(nextLineData.Introduction) - 1);
		strncpy(nextLineData.Name, Name__, sizeof(nextLineData.Name) - 1);
		data.push_back(nextLineData);
		lines++;
		nextLineData = getDefault();
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
		if (p->texiao[13].Type >= idx) p->texiao[13].Type+= 1;
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
            BIND_FIELD_INT("�˴�", InShip),
            BIND_FIELD_INT("�ӳ�����", InSubMap),
            BIND_FIELD_INT("����ͼX", MainMapX),
            BIND_FIELD_INT("����ͼY", MainMapY),
            BIND_FIELD_INT("�ӳ���X", SubMapX),
            BIND_FIELD_INT("�ӳ���Y", SubMapY),
            BIND_FIELD_INT("�泯����", FaceTowards),
            BIND_FIELD_INT("��X", ShipX),
            BIND_FIELD_INT("��Y", ShipY),
			BIND_FIELD_INT("��X1",TimeCount),       
			BIND_FIELD_INT("��Y1", TimeEvent),
            BIND_FIELD_INT("�ڲ�����", RandomEvent),
            BIND_FIELD_INT("����1", Team[0]),
            BIND_FIELD_INT("����2", Team[1]),
            BIND_FIELD_INT("����3", Team[2]),
            BIND_FIELD_INT("����4", Team[3]),
            BIND_FIELD_INT("����5", Team[4]),
            BIND_FIELD_INT("����6", Team[5]),
        };
    }
    if (new_save_.item_list_.size() == 0)
    {
        ItemList a;
        new_save_.item_list_ =
        {
            BIND_FIELD_INT("��Ʒ���", item_id),
            BIND_FIELD_INT("��Ʒ����", count),
        };
    }
    if (new_save_.role_.size() == 0)
    {
        Role a;
        new_save_.role_ =
        {
            BIND_FIELD_INT("���", ID),
            BIND_FIELD_INT("ͷ��", HeadID),
            BIND_FIELD_INT("��������", IncLife),
            BIND_FIELD_INT("��Դ", Fuyuan),
            BIND_FIELD_TEXT("����", Name),
            BIND_FIELD_TEXT("���", Nick),
            BIND_FIELD_INT("�Ա�", Sexual),
            BIND_FIELD_INT("�ȼ�", Level),
            BIND_FIELD_INT("����", Exp),
            BIND_FIELD_INT("����", HP),
            BIND_FIELD_INT("�������ֵ", MaxHP),
            BIND_FIELD_INT("����", Hurt),
            BIND_FIELD_INT("�ж�", Poison),
            BIND_FIELD_INT("����", PhysicalPower),
            BIND_FIELD_INT("����", Equip[0]),
            BIND_FIELD_INT("����", Equip[1]),
			BIND_FIELD_INT("Ь��", Equip[3]),
			BIND_FIELD_INT("��Ʒ", Equip[3]),

            BIND_FIELD_INT("��������", MPType),
            BIND_FIELD_INT("����", MP),
            BIND_FIELD_INT("�������ֵ", MaxMP),
            BIND_FIELD_INT("������", Attack),
            BIND_FIELD_INT("�Ṧ", Speed),
            BIND_FIELD_INT("������", Defence),
            BIND_FIELD_INT("ҽ��", Medicine),

            BIND_FIELD_INT("����", AntiPoison),
            BIND_FIELD_INT("ȭ��", Fist),
            BIND_FIELD_INT("����", Sword),
            BIND_FIELD_INT("ˣ��", Knife),
            BIND_FIELD_INT("����", Unusual),
            BIND_FIELD_INT("����", HiddenWeapon),
            BIND_FIELD_INT("��ѧ��ʶ", Knowledge),
            BIND_FIELD_INT("Ʒ��", Morality),
            BIND_FIELD_INT("��������", AttackWithPoison),
            BIND_FIELD_INT("���һ���", AttackTwice),
            BIND_FIELD_INT("����", Fame),
            BIND_FIELD_INT("����", IQ),
            BIND_FIELD_INT("������Ʒ", PracticeItem),
            BIND_FIELD_INT("��������", ExpForItem),
            BIND_FIELD_INT("�����书1", MagicID[0]),
            BIND_FIELD_INT("�����书2", MagicID[1]),
            BIND_FIELD_INT("�����书3", MagicID[2]),
            BIND_FIELD_INT("�����书4", MagicID[3]),
            BIND_FIELD_INT("�����书5", MagicID[4]),
            BIND_FIELD_INT("�����书6", MagicID[5]),
            BIND_FIELD_INT("�����书7", MagicID[6]),
            BIND_FIELD_INT("�����书8", MagicID[7]),
            BIND_FIELD_INT("�����书9", MagicID[8]),
            BIND_FIELD_INT("�����书10", MagicID[9]),
            BIND_FIELD_INT("�书�ȼ�1", MagicLevel[0]),
            BIND_FIELD_INT("�书�ȼ�2", MagicLevel[1]),
            BIND_FIELD_INT("�书�ȼ�3", MagicLevel[2]),
            BIND_FIELD_INT("�书�ȼ�4", MagicLevel[3]),
            BIND_FIELD_INT("�书�ȼ�5", MagicLevel[4]),
            BIND_FIELD_INT("�书�ȼ�6", MagicLevel[5]),
            BIND_FIELD_INT("�书�ȼ�7", MagicLevel[6]),
            BIND_FIELD_INT("�书�ȼ�8", MagicLevel[7]),
            BIND_FIELD_INT("�书�ȼ�9", MagicLevel[8]),
            BIND_FIELD_INT("�书�ȼ�10", MagicLevel[9]),
            BIND_FIELD_INT("Я����Ʒ1", TakingItem[0]),
            BIND_FIELD_INT("Я����Ʒ2", TakingItem[1]),
            BIND_FIELD_INT("Я����Ʒ3", TakingItem[2]),
            BIND_FIELD_INT("Я����Ʒ4", TakingItem[3]),
            BIND_FIELD_INT("Я����Ʒ����1", TakingItemCount[0]),
            BIND_FIELD_INT("Я����Ʒ����2", TakingItemCount[1]),
            BIND_FIELD_INT("Я����Ʒ����3", TakingItemCount[2]),
            BIND_FIELD_INT("Я����Ʒ����4", TakingItemCount[3]),
        };
    }
    if (new_save_.item_.size() == 0)
    {
        Item a;
        new_save_.item_ =
        {
            BIND_FIELD_INT("���", ID),
            BIND_FIELD_TEXT("��Ʒ��", Name),


            BIND_FIELD_TEXT("��Ʒ˵��", Introduction),
            BIND_FIELD_INT("�����书", MagicID),
            BIND_FIELD_INT("�����������", HiddenWeaponEffectID),
            BIND_FIELD_INT("ʹ����", User),
            BIND_FIELD_INT("װ������", EquipType),
            BIND_FIELD_INT("��ʾ��Ʒ˵��", ShowIntroduction),
            BIND_FIELD_INT("��Ʒ����", ItemType),

			
			BIND_FIELD_INT("������", AddHP),
            BIND_FIELD_INT("���������ֵ", AddMaxHP),
            BIND_FIELD_INT("���ж��ⶾ", AddPoison),
            BIND_FIELD_INT("������", AddPhysicalPower),
            BIND_FIELD_INT("�ı���������", ChangeMPType),
            BIND_FIELD_INT("������", AddMP),
            BIND_FIELD_INT("���������ֵ", AddMaxMP),
            BIND_FIELD_INT("�ӹ�����", AddAttack),
            BIND_FIELD_INT("���Ṧ", AddSpeed),
            BIND_FIELD_INT("�ӷ�����", AddDefence),
            BIND_FIELD_INT("��ҽ��", AddMedicine),
            BIND_FIELD_INT("��ʹ��", AddUsePoison),
            //BIND_FIELD_INT("�ӽⶾ", AddDetoxification),
            BIND_FIELD_INT("�ӿ���", AddAntiPoison),
            BIND_FIELD_INT("��ȭ��", AddFist),
            BIND_FIELD_INT("������", AddSword),
            BIND_FIELD_INT("��ˣ��", AddKnife),
            BIND_FIELD_INT("���������", AddUnusual),
            BIND_FIELD_INT("�Ӱ�������", AddHiddenWeapon),
            BIND_FIELD_INT("����ѧ��ʶ", AddKnowledge),
            BIND_FIELD_INT("��Ʒ��", AddMorality),
            //BIND_FIELD_INT("�����һ���", AddAttackTwice),
            BIND_FIELD_INT("�ӹ�������", AddAttackWithPoison),
            BIND_FIELD_INT("����������", OnlySuitableRole),
            BIND_FIELD_INT("����������", NeedMPType),
            BIND_FIELD_INT("������", NeedMP),
            BIND_FIELD_INT("�蹥����", NeedAttack),
            BIND_FIELD_INT("���Ṧ", NeedSpeed),
            BIND_FIELD_INT("���ö�", NeedUsePoison),
            BIND_FIELD_INT("��ҽ��", NeedMedicine),
            //BIND_FIELD_INT("��ⶾ", NeedDetoxification),
            BIND_FIELD_INT("��ȭ��", NeedFist),
            BIND_FIELD_INT("������", NeedSword),
            BIND_FIELD_INT("��ˣ��", NeedKnife),
            BIND_FIELD_INT("���������", NeedUnusual),
            BIND_FIELD_INT("�谵��", NeedHiddenWeapon),
            BIND_FIELD_INT("������", NeedIQ),
            BIND_FIELD_INT("�辭��", NeedExp),
            //BIND_FIELD_INT("������Ʒ�辭��", NeedExpForMakeItem),
            //BIND_FIELD_INT("�����", NeedMaterial),
            //BIND_FIELD_INT("������Ʒ1", MakeItem[0]),
            //BIND_FIELD_INT("������Ʒ2", MakeItem[1]),
            //BIND_FIELD_INT("������Ʒ3", MakeItem[2]),
            //BIND_FIELD_INT("������Ʒ4", MakeItem[3]),
            //BIND_FIELD_INT("������Ʒ5", MakeItem[4]),
            //BIND_FIELD_INT("������Ʒ����1", MakeItemCount[0]),
            //BIND_FIELD_INT("������Ʒ����2", MakeItemCount[1]),
            //BIND_FIELD_INT("������Ʒ����3", MakeItemCount[2]),
            //BIND_FIELD_INT("������Ʒ����4", MakeItemCount[3]),
            //BIND_FIELD_INT("������Ʒ����5", MakeItemCount[4]),
        };
    }
    if (new_save_.submap_.size() == 0)
    {
        SubMapInfo a;
        new_save_.submap_ =
        {
            BIND_FIELD_INT("���", ID),
            BIND_FIELD_TEXT("����", Name),
            BIND_FIELD_INT("��������", ExitMusic),
            BIND_FIELD_INT("��������", EntranceMusic),
            //BIND_FIELD_INT("��ת����", JumpSubMap),
            BIND_FIELD_INT("��������", EntranceCondition),
            BIND_FIELD_INT("�⾰���X1", MainEntranceX1),
            BIND_FIELD_INT("�⾰���Y1", MainEntranceY1),
            BIND_FIELD_INT("�⾰���X2", MainEntranceX2),
            BIND_FIELD_INT("�⾰���Y2", MainEntranceY2),
            BIND_FIELD_INT("���X", EntranceX),
            BIND_FIELD_INT("���Y", EntranceY),
            BIND_FIELD_INT("����X1", ExitX[0]),
            BIND_FIELD_INT("����X2", ExitX[1]),
            BIND_FIELD_INT("����X3", ExitX[2]),
            BIND_FIELD_INT("����Y1", ExitY[0]),
            BIND_FIELD_INT("����Y2", ExitY[1]),
            BIND_FIELD_INT("����Y3", ExitY[2]),

        };
    }
    if (new_save_.magic_.size() == 0)
    {
        Magic a;
        new_save_.magic_ =
        {
            BIND_FIELD_INT("���", ID),
            BIND_FIELD_TEXT("����", Name),

            BIND_FIELD_INT("������Ч", SoundID),
            BIND_FIELD_INT("�书����", MagicType),
            BIND_FIELD_INT("�书����", EffectID),
            BIND_FIELD_INT("�˺�����", HurtType),
            BIND_FIELD_INT("������Χ����", AttackAreaType),
            BIND_FIELD_INT("��������", NeedMP),
            BIND_FIELD_INT("�����ж�", WithPoison),

            BIND_FIELD_INT("�ƶ���Χ1", SelectDistance[0]),
            BIND_FIELD_INT("�ƶ���Χ2", SelectDistance[1]),
            BIND_FIELD_INT("�ƶ���Χ3", SelectDistance[2]),
            BIND_FIELD_INT("�ƶ���Χ4", SelectDistance[3]),
            BIND_FIELD_INT("�ƶ���Χ5", SelectDistance[4]),
            BIND_FIELD_INT("�ƶ���Χ6", SelectDistance[5]),
            BIND_FIELD_INT("�ƶ���Χ7", SelectDistance[6]),
            BIND_FIELD_INT("�ƶ���Χ8", SelectDistance[7]),
            BIND_FIELD_INT("�ƶ���Χ9", SelectDistance[8]),
            BIND_FIELD_INT("�ƶ���Χ10", SelectDistance[9]),
            BIND_FIELD_INT("ɱ�˷�Χ1", AttackDistance[0]),
            BIND_FIELD_INT("ɱ�˷�Χ2", AttackDistance[1]),
            BIND_FIELD_INT("ɱ�˷�Χ3", AttackDistance[2]),
            BIND_FIELD_INT("ɱ�˷�Χ4", AttackDistance[3]),
            BIND_FIELD_INT("ɱ�˷�Χ5", AttackDistance[4]),
            BIND_FIELD_INT("ɱ�˷�Χ6", AttackDistance[5]),
            BIND_FIELD_INT("ɱ�˷�Χ7", AttackDistance[6]),
            BIND_FIELD_INT("ɱ�˷�Χ8", AttackDistance[7]),
            BIND_FIELD_INT("ɱ�˷�Χ9", AttackDistance[8]),
            BIND_FIELD_INT("ɱ�˷�Χ10", AttackDistance[9]),
            BIND_FIELD_INT("������1", AddMP[0]),
            BIND_FIELD_INT("������2", AddMP[1]),
            BIND_FIELD_INT("������3", AddMP[2]),
            BIND_FIELD_INT("������4", AddMP[3]),
            BIND_FIELD_INT("������5", AddMP[4]),
            BIND_FIELD_INT("������6", AddMP[5]),
            BIND_FIELD_INT("������7", AddMP[6]),
            BIND_FIELD_INT("������8", AddMP[7]),
            BIND_FIELD_INT("������9", AddMP[8]),
            BIND_FIELD_INT("������10", AddMP[9]),

        };
    }
    if (new_save_.shop_.size() == 0)
    {
        Shop a;
        new_save_.shop_ =
        {
            BIND_FIELD_INT("��Ʒ���1", ItemID[0]),
            BIND_FIELD_INT("��Ʒ���2", ItemID[1]),
            BIND_FIELD_INT("��Ʒ���3", ItemID[2]),
            BIND_FIELD_INT("��Ʒ���4", ItemID[3]),
            BIND_FIELD_INT("��Ʒ���5", ItemID[4]),

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
