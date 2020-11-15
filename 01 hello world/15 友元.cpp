#pragma once
#include <iostream>
#include <string>

using namespace std;

// 友元:声明特殊的函数或特殊的类
class Building {
	// 声明某个函数为当前类的友元函数:可以访问本类中私有的成员
	friend void goodGay(Building* building);
	// 友元类:可以访问了本类的私有成员
	friend class GoodGay;
	// 成员函数做友元
	// friend void B::visit();
private:
	string m_bedroom;;
public:
	string m_sitting_room;

	Building() {
		m_bedroom = "卧室";
		m_sitting_room = "客厅";
	}
};


// 全局函数
void goodGay(Building* building) {
	cout << "好基友正在访问" << building->m_sitting_room << endl;
	// 声明friend前无法访问私有变量
	cout << "好基友正在访问" << building->m_bedroom << endl;
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
	cout << "好基友正在访问" << buiding->m_bedroom << endl;
}


void main15() {
	Building b;
	goodGay(&b);
}