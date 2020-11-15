#include <iostream>
#include <string>

using namespace std;


class person {
public:
	int m_age;
	int* m_height;

	person() {
		cout << "无参构造" << endl;
	}

	person(int age, int height) {
		cout << "有参构造" << endl;
		m_age = age;
		m_height = new int(height);
	}

	person(const person& p) {
		cout << "拷贝构造" << endl;
		m_age = p.m_age;
		m_height = new int(*p.m_height);	// 自定义拷贝, 避免编译器提供的浅拷贝带来的问题
	}

	~person() {
		cout << "析构" << endl;
		if (m_height != NULL) {
			delete m_height;
		}
	}
};


void test01() {
	person p1(18, 180);
	person p2(p1);
	cout << "p1年龄:" << p1.m_age << ", p1的身高" << *p1.m_height << endl;
	cout << "p2年龄:" << p2.m_age << ", p2的身高" << *p2.m_height << endl;
}

void main12() {
	test01();
	system("pause");
}