#include <iostream>
#include <string>

using namespace std;

// ȫ�ֺ�������ʵ��--��Ҫ��ǰ��֪��������������Ĵ���
template<class T1, class T2>
class Person;
// ȫ�ֺ���
template<class T1, class T2>
void print_person2(Person<T1, T2>& p)	// ����ģ���ʵ��
{
	cout << p.name << ", " << p.age << endl;
}

template<class T1, class T2>
class Person
{
public:
	// ȫ�ֺ�������ʵ��
	friend void print_person(Person<T1, T2>& p)
	{
		cout << p.name << ", " << p.age << endl;
	}

	// ȫ�ֺ�������ʵ��
	// ����<>������ͨ�����ĺ�������,�Ӹ���ģ��Ĳ����б�,���Ϊ����ģ��
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

// ȫ�ֺ���������ʵ��
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