#include<iostream>
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager) {//Identity*& manager���ڸ�ָ������һ����������������ָ��
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {//����˺�
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {//�鿴����
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {//���ԤԼ
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//����ѧ���Ӳ˵�
void studentMenu(Identity*& student) {
	while (true) {
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {//�鿴������ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {//ȡ��ԤԼ
			stu->cancelOrder();
		}
		else {//ע����¼
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�����ʦ�Ӳ˵�
void teacherMenu(Identity *&teacher){
	while (true) {
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->vaildOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����
void LoginIn(string fileName, int type) {
	Identity* person = NULL;//����ָ�룬����ָ���������
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;
	//�ж����
	if (type == 1) {//ѧ��
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {//��ʦ
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1) {//ѧ�������֤
		int fid;
		string fname;
		string fpwd;
		while (ifs>>fid&&ifs>>fname&&ifs>>fpwd) {
			//���û����������Ϣ���Ա�
			if (fid == id&&fname == name&&fpwd == pwd) {
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {//��ʦ�����֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			//���û����������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {//����Ա�����֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			//���û����������Ϣ���Ա�
			if (fname == name && fpwd == pwd) {
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select = 0;
	while (true) {
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select) {
		case 1://ѧ�����
			LoginIn(STUDENT_FILE,1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://����Աϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}