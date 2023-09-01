#include"student.h"
//默认构造
Student::Student() {

}
//有参构造
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
//菜单界面
void Student::operMenu() {
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//申请预约
void Student::applyOrder() {
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int data = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号
	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房：" << endl;
	cout << vCom[0].m_comid << "号机房容量为:" << vCom[0].m_maxnum << endl;
	cout << vCom[1].m_comid << "号机房容量为:" << vCom[1].m_maxnum << endl;
	cout << vCom[2].m_comid << "号机房容量为:" << vCom[2].m_maxnum << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;
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
//查看自身预约
void Student::showMyOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		if (this->m_id == atoi(of.m_orderData[i]["stuID"].c_str())) {//找到自身的预约
			cout << "预约日期：周" << of.m_orderData[i]["data"];
			cout << "  时间段：   " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  机房号：   " << of.m_orderData[i]["roomID"];
			//1.审核中 2.已预约 -1.预约失败 0.取消预约
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "审核通过";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "审核不通过";
			}
			else {
				status += "预约已取消";
			}
			cout << "  " << status << endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["data"];
		cout << "  时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  学号： " << of.m_orderData[i]["stuID"];
		cout << "  姓名： " << of.m_orderData[i]["stuName"];
		cout << "  机房号： " << of.m_orderData[i]["roomID"];
		//1.审核中 2.已预约 -1.预约失败 0.取消预约
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "审核通过";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "审核不通过";
		}
		else {
			status += "预约已取消";
		}
		cout << "  " << status << endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1;
	vector<int> v;//存放大容器可以取消预约的下标编号
	for (int i = 0; i < of.m_size; i++) {
		//先判断自身学号
		if (this->m_id == atoi(of.m_orderData[i]["stuID"].c_str())) {
			//在判断审核状态
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["data"];
				cout << "  时间段： " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "  机房号： " << of.m_orderData[i]["roomID"];
				//1.审核中 2.已预约 -1.预约失败 0.取消预约
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "审核通过";
				}
				cout << "  " << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
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
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}