#include "24 person.cpp"	// 对于模板,编译器需要看到实现才行

using namespace std;

//template<class T1, class T2>
//class Person 
//{
//public:
//	Person(T1 name, T2 age) {
//		this->name = name;
//		this->age = age;
//	}
//
//	/*void showPerson() {
//		cout << this->name << ", " << this->age << endl;
//	}*/
//
//	// 类模板成员函数的类外实现
//	void showPerson();
//
//	T1 name;
//	T2 age;
//};

//template<class T1, class T2>
//void printPerson(Person<T1, T2>& p) {
//	p.showPerson();
//	cout << "T1的类型:" << typeid(T1).name() << endl;
//	cout << "T2的类型:" << typeid(T2).name() << endl;
//}
//
//// 类模板与继承
//// 1.继承的父类是类模板,子类声明时需要指定父类模板类型
//// 2.如果不指定,编译器无法为子类分配内存
//// 3.如果灵活指定父类模板的类型,子类也需要变为模板
//template<class T>
//class Base
//{
//public:
//	T m;
//};
//
//// class Son : public Base		// 错误
//// class Son : public Base<int>	// 指定父类模板类型
//template<class T1, class T2>
//class Son : public Base<T2>		// 灵活指定父类模板类型
//{
//public:
//	Son() 
//	{
//		cout << "T1的类型:" << typeid(T1).name() << endl;
//		cout << "T2的类型:" << typeid(T2).name() << endl;
//	}
//
//	T1 obj;
//};
//
//
//// 构造函数类外实现
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->name = name;
//	this->age = age;
//}
//
//// 成员函数类外实现
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "T1的类型:" << typeid(T1).name() << endl;
//	cout << "T2的类型:" << typeid(T2).name() << endl;
//}


void main25() {
	Person<string, int> p1("cxk", 99);
	printPerson(p1);

	Son<int, char> s1;
}