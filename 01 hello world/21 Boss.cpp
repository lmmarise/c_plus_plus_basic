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
	cout << "ְ�����:" << m_id
		<< "\tְ������:" << m_name
		<< "\t��λ:" << get_dept_name()
		<< "\tְ��:" << "����˾��������"
		<< endl;
}

string Boss::get_dept_name() {
	return string("�ϰ�");
}