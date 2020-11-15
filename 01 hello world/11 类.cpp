#include <iostream>
#include <string>

using namespace std;

#define PI 3.1415926

// �̳С���װ����̬
class cirecle {
// ����Ȩ�ޣ�����ɷ��ʣ�������Ҳ�ɷ���
public:
	// ����
	int m_r;		// �뾶
	// ����
	double caculate_area() {	// �������
		return 2 * PI * m_r;
	}
// ����Ȩ�ޣ����ⲻ�ɷ���������ɷ���
protected:
// ˽��Ȩ�ޣ����ⲻ�ɷ���������Ҳ�����Է���
private:
};

// struct��class��Ψһ���𣺷���Ȩ�޲�ͬ��classĬ�Ϸ���Ȩ��Ϊ˽�У�structĬ�Ϸ���Ȩ���ǹ�����
struct A {
	int id;	// �ɱ�����
};

class B {
	int id;	// ���ⲻ�ɱ�����
public:
	int age;
	// ���캯��
	// Ĭ�������, ���������ٸ����ṩ��3�����캯��: Ĭ�Ϲ��졢�������������죬���Խ���ֵ����
	B() {		// �޲ι��� Ĭ�Ϲ���  �Լ��ṩ��,�������Ͳ����ṩ
		cout << "B�Ĺ���" << endl;
	}			// �вι���
	B(int a) {
		cout << "B�Ĺ���, a=" << a << endl;
	}
	B(const B& b) {	// �������� ���ⱻ�޸�; �Լ��ṩ��,�������Ͳ����ṩ
		cout << "B�Ŀ�������" << endl;
	}
	// ��������
	~B() {
		cout << "B������" << endl;
	}
};


// �������ݵ�ֵ���ݺ͵�ַ����
B func(B b) {
	return b;	// �ڷ��ض����ʱ��Ҳ����ö���Ŀ�������
}

// �������ֵ����ʱ�Ŀ�������,��ʡ����
const B& func1(B& b) {	// ֱ�ӽ���Դ����,����������� ���ض���Ϊ���������ɸı�
	return b;
}


// �������Ϊ���Ա
class Phone {
public:
	string m_name;

	Phone(string name) {
		cout << "Phone����" << endl;
		m_name = name;
	}

	~Phone() { cout << "~Phone����" << endl; }
};

class People {
	const static int id = 10;		// ��̬����ֻ�ܷ��ʾ�̬��Ա
public:
	string m_name;
	Phone m_phone;

	People(string name, string phone_name): m_name(name), m_phone(phone_name) {
		cout << "People����" << endl;
	}

	static void func() {
		cout << "People��̬����" << ", id=" << id << endl;
	}

	~People() { cout << "~People����" << endl; }
};


void main11() {
	cirecle c1;
	c1.m_r = 9;
	cout << c1.caculate_area() << endl;

	B b;	// Ĭ�Ϲ���
	// B b();	// ���������ж���Ϊһ������������,Ĭ�Ϲ�����������ַ������ɡ����ᱻ��Ϊ�ڴ�������
	B b1(1);

	// ��ʾ����
	B b2 = B(10);		// ���������ٸ���һ�����֡��������֣��������󽫱����̱����ա�
	// B(b2);	// ��������Ϊ���д���ȼ��ڣ�B b2��
	B(B(99));	// �ȼ��ڣ�B��99����
	

	// ��ʽת����
	B b3 = 839;		// ����int�����Ĺ���
	B b4 = b3;		// ����B���͵Ĺ���


	cout << "------�������ݲ���------" << endl;
	B bx = 10086;
	bx.age = 10;
	cout << "���ú���func---->" << endl;
	B bx1 = func(bx);	// �������ݻ´��һ��
	cout << "���ú���func1---->" << endl;
	B bx2 = func1(bx);	// ֵ���ݻ´��һ�ݳ���
	cout << (int)&bx << endl;	// 17825320
	cout << (int)&bx1 << endl;	// 17825308
	cout << (int)&bx2 << endl;	// 17825296
	cout << bx.age << endl;
	cout << bx1.age << endl;
	cout << bx2.age << endl;

	cout << endl;
	cout << "----�������Ϊ���Ա----" << endl;
	People p1("����", "Apple X");	// ���ȹ������Ա  ������˳���෴

	cout << endl;
	cout << "----��ľ�̬����----" << endl;
	People::func();

	cout << endl;
	cout << "----�������----" << endl << endl;
}