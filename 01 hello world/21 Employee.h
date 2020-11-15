#pragma once
#include <iostream>
using namespace std;
#include "21 Worker.h"

// 普通员工
class Employee : public Worker {
public:
	// 构造
	Employee(int id, string name, int dept_id);

	// 显示所有信息
	virtual void show_info();
	// 岗位名称
	virtual string get_dept_name();
};