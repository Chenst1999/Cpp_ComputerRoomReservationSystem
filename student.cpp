#include"student.h"
//Ĭ�Ϲ���
Student::Student() {

}
//�вι���
Student::Student(int id, string name, string pwd) {
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum) {
		vCom.push_back(com);
	}
	ifs.close();
}
//�˵�����
void Student::operMenu() {
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������
	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�������" << endl;
	cout << vCom[0].m_comid << "�Ż�������Ϊ:" << vCom[0].m_maxnum << endl;
	cout << vCom[1].m_comid << "�Ż�������Ϊ:" << vCom[1].m_maxnum << endl;
	cout << vCom[2].m_comid << "�Ż�������Ϊ:" << vCom[2].m_maxnum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuID:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomID:" << room << " ";
	ofs << "status:" << 1 << " ";
	ofs.close();
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showMyOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		if (this->m_id == atoi(of.m_orderData[i]["stuID"].c_str())) {//�ҵ������ԤԼ
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << "  ʱ��Σ�   " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  �����ţ�   " << of.m_orderData[i]["roomID"];
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
	}
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showAllOrder() {
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
//ȡ��ԤԼ
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1;
	vector<int> v;//��Ŵ���������ȡ��ԤԼ���±���
	for (int i = 0; i < of.m_size; i++) {
		//���ж�����ѧ��
		if (this->m_id == atoi(of.m_orderData[i]["stuID"].c_str())) {
			//���ж����״̬
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << "  ʱ��Σ� " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "  �����ţ� " << of.m_orderData[i]["roomID"];
				//1.����� 2.��ԤԼ -1.ԤԼʧ�� 0.ȡ��ԤԼ
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "���ͨ��";
				}
				cout << "  " << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updataOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}