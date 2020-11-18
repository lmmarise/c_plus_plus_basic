#include <iostream>
#include <string>

using namespace std;

class Show
{
	public:
	virtual void show() = 0;
};

// 类模板和函数模板的区别:
// 1.没有自动类型推导
// 2.可以有默认参数
template<class name_type, class age_type = int>
class Person : Show
{
public:
	Person(name_type name, age_type age)
	{
		this->age = age;
		this->name = name;
	}

	virtual void show()
	{
		cout << "name=" << name << ", age=" << age << endl;
	}

	name_type name;
	age_type age;
};

class P1
{
public:
	void showP1()
	{
		cout << "P1 show" << endl;
	}
};

class P2
{
public:
	void showP2()
	{
		cout << "P2 show" << endl;
	}
};

template<class T>
class my_class
{
public:
	T obj;

	// 类模板中的函数在调用时才生成
	void func1()
	{
		obj.showP1();
	}

	void func2()
	{
		obj.showP2();
	}
};

void main24()
{
	Person<string, int> p("荷", 19);
	p.show();
	Person<string> p2("荷1", 19);
	p2.show();

	// 测试:类模板函数
	my_class<P1> p3;
	p3.func1();
	my_class<P2> p4;
	p4.func2();
}