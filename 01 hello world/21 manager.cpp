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
	cout << "ְ�����:" << m_id
		<< "\tְ������:" << m_name
		<< "\t��λ:" << get_dept_name()
		<< "\tְ��:" << "����ϰ巢��������,��Ա����������"
		<< endl;
}

string Manager::get_dept_name() {
	return string("����");
}