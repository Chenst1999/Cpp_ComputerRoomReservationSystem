#include"manager.h"
Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_pwd = pwd;
	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;
}
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
void Manager::addPerson() {
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string filename;
	string tip;
	ofstream ofs;
	string errorTip;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//���ѧ��
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		//�����ʦ
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}
	ofs.open(filename, ios::out | ios::app);//����׷�ӷ�ʽд�ļ�
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool res = cheakRepeat(id, select);
		if (res) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}
void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_id << "\t\t������" << s.m_name << "\t\t���룺" << s.m_pwd << endl;
}
void printTeacher(Teacher& s) {
	cout << "ְ���ţ�" << s.m_empid << "\t\t������" << s.m_name << "\t\t���룺" << s.m_pwd << endl;
}
void Manager::showPerson() {
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer() {
	cout << "��������Ϣ����:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "������ţ�" << it->m_comid << "\t\t�������������" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector() {
	//��ȡ��Ϣ-ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE,ios::in);
	if(!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();
	//��ȡ��Ϣ-��ʦ
	ifstream ifs1;
	ifs1.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs1 >> t.m_empid && ifs1 >> t.m_name && ifs1 >> t.m_pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
	ifs1.close();
}
bool Manager::cheakRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_empid) {
				return true;
			}
		}
	}
	return false;
}