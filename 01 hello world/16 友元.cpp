#include <iostream>
#include <string>

using namespace std;

class Building1;
class goodGay
{
public:
	goodGay();
	void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
	void visit2();

private:
	Building1* building;
};


class Building1
{
	//���߱�����  goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend void goodGay::visit();
public:
	Building1();

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

Building1::Building1()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

goodGay::goodGay()
{
	building = new Building1;
}

void goodGay::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;

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