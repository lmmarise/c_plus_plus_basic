#include <iostream>
#include <string>

using namespace std;


class person {
public:
	int m_age;
	int* m_height;

	person() {
		cout << "�޲ι���" << endl;
	}

	person(int age, int height) {
		cout << "�вι���" << endl;
		m_age = age;
		m_height = new int(height);
	}

	person(const person& p) {
		cout << "��������" << endl;
		m_age = p.m_age;
		m_height = new int(*p.m_height);	// �Զ��忽��, ����������ṩ��ǳ��������������
	}

	~person() {
		cout << "����" << endl;
		if (m_height != NULL) {
			delete m_height;
		}
	}
};


void test01() {
	person p1(18, 180);
	person p2(p1);
	cout << "p1����:" << p1.m_age << ", p1�����" << *p1.m_height << endl;
	cout << "p2����:" << p2.m_age << ", p2�����" << *p2.m_height << endl;
}

void main12() {
	test01();
	system("pause");
}