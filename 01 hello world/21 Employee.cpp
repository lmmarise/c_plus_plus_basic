#include "21 Employee.h"

Employee::Employee(int id, string name, int dept_id) {
	m_id = id;
	m_name = name;
	m_dept_id = dept_id;
}

// ��ʾ������Ϣ
void Employee::show_info() {
	cout << "ְ�����:" << m_id
		<< "\tְ������:" << m_name
		<< "\t��λ" << get_dept_name() 
		<< endl;
}

// ��λ����
string Employee::get_dept_name() {
	return string("Ա��");
}