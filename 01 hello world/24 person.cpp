#include <iostream>
#include <string>

using namespace std;

#include "24 person.h"

template<class T1, class T2>
void printPerson(Person<T1, T2>& p) {
	p.showPerson();
	cout << "T1的类型:" << typeid(T1).name() << endl;
	cout << "T2的类型:" << typeid(T2).name() << endl;
}

template<class T>
class Base
{
public:
	T m;
};

template<class T1, class T2>
class Son : public Base<T2>	
{
public:
	Son()
	{
		cout << "T1的类型:" << typeid(T1).name() << endl;
		cout << "T2的类型:" << typeid(T2).name() << endl;
	}

	T1 obj;
};


// 构造函数类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

// 成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "T1的类型:" << typeid(T1).name() << endl;
	cout << "T2的类型:" << typeid(T2).name() << endl;
}
