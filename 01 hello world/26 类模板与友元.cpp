#include <iostream>
#include <string>

using namespace std;

// 全局函数类外实现--需要提前告知编译器这个函数的存在
template<class T1, class T2>
class Person;
// 全局函数
template<class T1, class T2>
void print_person2(Person<T1, T2>& p)	// 函数模板的实现
{
	cout << p.name << ", " << p.age << endl;
}

template<class T1, class T2>
class Person
{
public:
	// 全局函数类内实现
	friend void print_person(Person<T1, T2>& p)
	{
		cout << p.name << ", " << p.age << endl;
	}

	// 全局函数类外实现
	// 不加<>就是普通函数的函数声明,加个空模板的参数列表,标记为函数模板
	friend void print_person2<>(Person<T1, T2>& p);	

	Person<T1, T2> (T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};

// 全局函数在类内实现
void test03()
{
	Person<string, int> p("Tom", 22);

	print_person(p);
	print_person2<string, int>(p);
}


void main26()
{
	test03();
}