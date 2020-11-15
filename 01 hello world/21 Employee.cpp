#include "21 Employee.h"

Employee::Employee(int id, string name, int dept_id) {
	m_id = id;
	m_name = name;
	m_dept_id = dept_id;
}

// 显示个人信息
void Employee::show_info() {
	cout << "职工编号:" << m_id
		<< "\t职工姓名:" << m_name
		<< "\t岗位" << get_dept_name() 
		<< endl;
}

// 岗位名称
string Employee::get_dept_name() {
	return string("员工");
}