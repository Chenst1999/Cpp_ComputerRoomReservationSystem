#include"manager.h"
Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	//初始化管理员信息
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
	cout << "机房的数量为：" << vCom.size() << endl;
}
void Manager::operMenu() {
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
void Manager::addPerson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	string filename;
	string tip;
	ofstream ofs;
	string errorTip;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//添加学生
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else {
		//添加老师
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入";
	}
	ofs.open(filename, ios::out | ios::app);//利用追加方式写文件
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
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}
void printStudent(Student& s) {
	cout << "学号：" << s.m_id << "\t\t姓名：" << s.m_name << "\t\t密码：" << s.m_pwd << endl;
}
void printTeacher(Teacher& s) {
	cout << "职工号：" << s.m_empid << "\t\t姓名：" << s.m_name << "\t\t密码：" << s.m_pwd << endl;
}
void Manager::showPerson() {
	cout << "请选择查看的内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer() {
	cout << "机房的信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房编号：" << it->m_comid << "\t\t机房最大容量：" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector() {
	//读取信息-学生
	ifstream ifs;
	ifs.open(STUDENT_FILE,ios::in);
	if(!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd) {
		vStu.push_back(s);
	}
	cout << "当前学生的数量为：" << vStu.size() << endl;
	ifs.close();
	//读取信息-老师
	ifstream ifs1;
	ifs1.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs1 >> t.m_empid && ifs1 >> t.m_name && ifs1 >> t.m_pwd) {
		vTea.push_back(t);
	}
	cout << "当前老师的数量为：" << vTea.size() << endl;
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