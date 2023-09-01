#include"teacher.h"
Teacher::Teacher() {

}
Teacher::Teacher(int empid, string name, string pwd) {
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << "  ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "  ѧ�ţ� " << of.m_orderData[i]["stuID"];
		cout << "  ������ " << of.m_orderData[i]["stuName"];
		cout << "  �����ţ� " << of.m_orderData[i]["roomID"];
		//1.����� 2.��ԤԼ -1.ԤԼʧ�� 0.ȡ��ԤԼ
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "���ͨ��";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "��˲�ͨ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");

}
void Teacher::vaildOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	int index = 1;
	cout << "����˵�ԤԼ��¼���£�" << endl;
	for (int i = 0; i < of.m_size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << "  ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  ѧ��ѧ�ţ� " << of.m_orderData[i]["stuID"];
			cout << "  ѧ�������� " << of.m_orderData[i]["stuName"];
			cout << "  �����ţ� " << of.m_orderData[i]["roomID"];
			string status = "״̬������� ";
			cout << "  " << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int res = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˵Ľ��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> res;
				if (res == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else {
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updataOrder();//����ԤԼ��¼
				cout << "������" << endl;
				break;
			}
		}
		cout << "�����������������" << endl;
	}
	system("pause");
	system("cls");
}