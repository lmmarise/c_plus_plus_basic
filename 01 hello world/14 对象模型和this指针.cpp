#include <iostream>
#include <string>

using namespace std;


class P {
public:
	int a;		// ˵�����������ڸ������
	static int b;	// û������, ˵����̬��Ա���������������
	mutable int c;	// �������, �ڳ�������Ҳ�ɱ��޸�

	// ÿһ���Ǿ�̬��Ա����ֻ�ᵮ��һ�ݳ�Ա����ʵ��, ���������ͬ�Ķ�����ͬһ�ݴ��� ---> ����thisָ��
	void func1() {}	// û������  ˵����������Ķ�����
	static void func2() {}	// û������ ˵����������Ķ�����

	P(int a) {
		this->a = a;	// thisָ�򱻵��õĳ�Ա�����Ķ���
	}

	P& add(int i) {
		this->a += i;
		return *this;
	}

	void show() {
		cout << "show() ---- " << endl;
	}

	void show_a() {
		if (this == NULL) {
			return;
		}
		cout << "show_a() ----> " << this->a << endl;
	}

	// ������   �����������޸ĳ�Ա����  ����mutable���ܱ��޸�
	void show_p() const {	// const����thisָ���ָ��,�����Ϊ����ָ��
		// this->a = 100;		// thisָ���ֵҲ���ܱ��޸�
		// thisָ����һ��ָ�볣��,���ɱ��޸�ָ���ָ��   P* const this
		// this = NULL;
	}

	void show_p2() const {
		this->c = 100;
	}

	void show_p3() {
		this->a = 100;
	}
};


void main14() {
	P p(1);	// ����ǿն���, ����Ϊ1
	cout << "�ն����ռ�ÿռ�:" << sizeof(p) << endl;


	// this�ĺô�
	// 1.���������ͻ
	// 2.���ض�����  *this
	cout << "p->a:" << p.a << endl;
	p.add(1).add(2).add(3);
	cout << "p->a:" << p.a << endl;


	cout << endl << "��ָ����ú���" << endl;
	P p1 = NULL;
	p1.show();
	p1.show_a();

	const P p2 = NULL;
	// p2.show_p3();	// ������ֻ�ܵ��ó�����  ��ͨ��Ա���������޸ĳ�Ա����
	p2.show_p();
	p2.show_p2();
}