#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker {
public:
	// ��ʾ������Ϣ
	virtual void show_info() = 0;
	// ��λ����
	virtual string get_dept_name() = 0;

	int m_id;
	string m_name;
	int m_dept_id;
};