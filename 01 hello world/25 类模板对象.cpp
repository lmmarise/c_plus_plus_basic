#include "24 person.cpp"	// ����ģ��,��������Ҫ����ʵ�ֲ���

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
//	// ��ģ���Ա����������ʵ��
//	void showPerson();
//
//	T1 name;
//	T2 age;
//};

//template<class T1, class T2>
//void printPerson(Person<T1, T2>& p) {
//	p.showPerson();
//	cout << "T1������:" << typeid(T1).name() << endl;
//	cout << "T2������:" << typeid(T2).name() << endl;
//}
//
//// ��ģ����̳�
//// 1.�̳еĸ�������ģ��,��������ʱ��Ҫָ������ģ������
//// 2.�����ָ��,�������޷�Ϊ��������ڴ�
//// 3.������ָ������ģ�������,����Ҳ��Ҫ��Ϊģ��
//template<class T>
//class Base
//{
//public:
//	T m;
//};
//
//// class Son : public Base		// ����
//// class Son : public Base<int>	// ָ������ģ������
//template<class T1, class T2>
//class Son : public Base<T2>		// ���ָ������ģ������
//{
//public:
//	Son() 
//	{
//		cout << "T1������:" << typeid(T1).name() << endl;
//		cout << "T2������:" << typeid(T2).name() << endl;
//	}
//
//	T1 obj;
//};
//
//
//// ���캯������ʵ��
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->name = name;
//	this->age = age;
//}
//
//// ��Ա��������ʵ��
//template<class T1, class T2>
//void Person<T1, T2>::showPerson()
//{
//	cout << "T1������:" << typeid(T1).name() << endl;
//	cout << "T2������:" << typeid(T2).name() << endl;
//}


void main25() {
	Person<string, int> p1("cxk", 99);
	printPerson(p1);

	Son<int, char> s1;
}