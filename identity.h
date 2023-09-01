#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity {
public:
	//操作菜单，使用纯虚函数，因为每个子类的菜单都不一致
	virtual void operMenu() = 0;
	string m_name;//用户名
	string m_pwd;//密码
};