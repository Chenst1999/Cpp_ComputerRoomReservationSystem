#pragma once
#include<iostream>
using namespace std;

//��ݳ�����
class Identity {
public:
	//�����˵���ʹ�ô��麯������Ϊÿ������Ĳ˵�����һ��
	virtual void operMenu() = 0;
	string m_name;//�û���
	string m_pwd;//����
};