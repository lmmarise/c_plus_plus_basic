#pragma once
#include <iostream>
#include <string>

using namespace std;

// ��Ԫ:��������ĺ������������
class Building {
	// ����ĳ������Ϊ��ǰ�����Ԫ����:���Է��ʱ�����˽�еĳ�Ա
	friend void goodGay(Building* building);
	// ��Ԫ��:���Է����˱����˽�г�Ա
	friend class GoodGay;
	// ��Ա��������Ԫ
	// friend void B::visit();
private:
	string m_bedroom;;
public:
	string m_sitting_room;

	Building() {
		m_bedroom = "����";
		m_sitting_room = "����";
	}
};


// ȫ�ֺ���
void goodGay(Building* building) {
	cout << "�û������ڷ���" << building->m_sitting_room << endl;
	// ����friendǰ�޷�����˽�б���
	cout << "�û������ڷ���" << building->m_bedroom << endl;
}


class GoodGay {
public:
	Building* buiding;

	GoodGay();
	void visit();
};

GoodGay::GoodGay() {
	buiding = new Building;
}

void GoodGay::visit() {
	cout << "�û������ڷ���" << buiding->m_bedroom << endl;
}


void main15() {
	Building b;
	goodGay(&b);
}