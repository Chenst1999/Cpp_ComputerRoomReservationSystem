#pragma once
#include"identity.h"
#include<iostream>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"
using namespace std;
class Manager :public Identity {
public:
	Manager();
	Manager(string name, string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();
	void initVector();
	bool cheakRepeat(int id, int type);
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;
};