#include <iostream>
using namespace std;
#include <string>
#include "21 manager.h"


Manager::Manager(int id, string name, int dept_id) {
	m_id = id;
	m_name = name;
	m_dept_id = dept_id;
}

void Manager::show_info() {
	cout << "职工编号:" << m_id
		<< "\t职工姓名:" << m_name
		<< "\t岗位:" << get_dept_name()
		<< "\t职责:" << "完成老板发布的任务,给员工分配任务"
		<< endl;
}

string Manager::get_dept_name() {
	return string("经理");
}