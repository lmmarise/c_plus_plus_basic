#include <iostream>
#include <string>

using namespace std;

class Building1;
class goodGay
{
public:
	goodGay();
	void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
	void visit2();

private:
	Building1* building;
};


class Building1
{
	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void goodGay::visit();
public:
	Building1();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

Building1::Building1()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	building = new Building1;
}

void goodGay::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;

}

void test02()
{
	goodGay  gg;
	gg.visit();

}

int main16() {

	test02();

	system("pause");
	return 0;
}