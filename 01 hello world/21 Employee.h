#pragma once
#include <iostream>
using namespace std;
#include "21 Worker.h"

// ��ͨԱ��
class Employee : public Worker {
public:
	// ����
	Employee(int id, string name, int dept_id);

	// ��ʾ������Ϣ
	virtual void show_info();
	// ��λ����
	virtual string get_dept_name();
};