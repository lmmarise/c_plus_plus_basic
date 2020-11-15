#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker {
public:
	// 显示所有信息
	virtual void show_info() = 0;
	// 岗位名称
	virtual string get_dept_name() = 0;

	int m_id;
	string m_name;
	int m_dept_id;
};