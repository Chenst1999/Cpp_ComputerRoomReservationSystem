#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalFile.h"
class OrderFile {
public:
	OrderFile();
	void updataOrder();
	int m_size;
	map<int, map<string, string>>m_orderData;
};