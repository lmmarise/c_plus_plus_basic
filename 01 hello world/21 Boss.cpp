#include <iostream>
using namespace std;
#include <string>
#include "21 Boss.h"


Boss::Boss(int id, string name, int dept_id) {
	m_id = id;
	m_name = name;
	m_dept_id = dept_id;
}

void Boss::show_info() {
	cout << "职工编号:" << m_id
		<< "\t职工姓名:" << m_name
		<< "\t岗位:" << get_dept_name()
		<< "\t职责:" << "管理公司所有事物"
		<< endl;
}

string Boss::get_dept_name() {
	return string("老板");
}