#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"orderFile.h"
#include<vector>
class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empid, string name, string pwd);
	virtual void operMenu();
	void showAllOrder();
	void vaildOrder();
	int m_empid;
};