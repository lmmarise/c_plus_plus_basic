#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

// 对比函数
template<class T>
bool compare(T& a, T& b)
{
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
// 对上面的函数进行特殊的重载
template<> bool compare(Person& p1, Person& p2)
{
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main23() 
{
	int a = 10, b = 20;
	if (compare(a, b)) {
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}

	Person p1("Tom", 2), p2("Jack", 1);
	if (compare(p1, p2)) {
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}