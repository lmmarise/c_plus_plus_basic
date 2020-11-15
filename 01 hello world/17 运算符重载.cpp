#include <iostream>
#include <string>

using namespace std;

class P1 {
public:
	int age;
	// 1.��Ա��������+��
	P1 operator+(P1& p) {
		P1 temp;
		temp.age = this->age + p.age;
		return temp;
	}
};

class P2 {
public:
	int age;
};

// 2.ȫ�ֺ�������
P2 operator+(P2& p1, P2& p2) {
	P2 temp;
	temp.age = p1.age + p2.age;
	return temp;
}

class P3 {
	friend ostream& operator<<(ostream& cout, P3& p);
private:
	int age;
public:
	int& set_age() {
		return this->age;
	}

	void set_age(int age) {
		this->age = age;
	}
};

// �����������
ostream& operator<<(ostream& cout, P3& p) {
	cout << "p3.age=" << p.age;
	return cout;
}

// �Զ���������������
class Int {
	friend ostream& operator<<(ostream& cout, Int i);
public:
	int num = 0;
	// ����ǰ��++
	Int& operator++() {
		num++;
		return *this;
	}
	// ���غ���++
	Int operator++(int) {
		Int temp = *this;
		++temp;
		return temp;
	}
	// ����
	Int() {
	}
	Int(int i) {
		num = i;
	}
};

ostream& operator<<(ostream& cout, Int i) {
	return cout << i.num;
}

// �ȺŸ�ֵ���� ������������ظ��ͷ�
class P4 {
public:
	Int *age = NULL;
	P4() { };
	P4(int age) {
		this->age = new Int(age);
	}
	// �������������ͷŸɾ�
	~P4() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	// ����= ʵ�����+��ʽ=��ֵ
	P4& operator=(P4& p) {
		age = new Int(*p.age);
		return *this;
	}
	// ���ضԱȲ���
	bool operator==(P4& p) {
		return this->age->num == p.age->num;
	}
	// ���غ�������--�º���
	void operator()(string str) {
		cout << str << endl;
	}
	int operator()(int i, int j) {
		return i + j;
	}
};

void main17() {
	P1 p1, p2;
	p1.age = 10;
	p2.age = 20;
	cout << (p1 + p2).age << endl;

	P2 p3, p4;
	p3.age = 100;
	p4.age = 200;
	cout << (p3 + p4).age << endl;

	P3 p5;
	p5.set_age() = 999;
	cout << p5 << endl;

	Int a = 0;
	cout << ++(++a) << endl;
	cout << a++ << endl;

	P4 person1 = 18;
	P4 person2 = 19;
	P4 person3 = 20;
	person1 = person2 = person3;
	cout << "person1������Ϊ:" << *person1.age << endl;

	// ����ʹ�÷º���
	P4()("cxk");
	cout << P4()(1, 2) << endl;
}