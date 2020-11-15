#include <iostream>
#include <string>

using namespace std;

class Fa {
public:
	int a;
	static const int d = 888;
	Fa() {
		a = 100;
		cout << "Fa����" << endl;
	}
	void func() {
		cout << "Fa func ����" << endl;
	}
	void func(int a) {
		cout << "Fa func(int a) ����" << endl;
	}
	static void func1() {
		cout << "Fa func1 ����" << endl;
	}
	static void func1(int a) {
		cout << "Fa func1(int a) ����" << endl;
	}
	~Fa() {
		cout << "Fa����" << endl;
	}
protected:
	int b;
private:
	int c;
};

// son�̳�fa

// �����̳�
class Son1 :public Fa {
public:
	int a = 288;
	static const int d = 999;
	// ���಻�ɷ��ʸ���private����, ���������಻��
	Son1() {
		cout << "Son1����" << endl;
	}
	void func() {
		cout << "Son1 func ����" << endl;
	}
	static void func1() {
		cout << "Son1 func1 ����" << endl;
	}
	static void func1(int a) {
		cout << "Son1 func1(int a) ����" << endl;
	}
	~Son1() {
		cout << "Son1����" << endl;
	}
};

// ��̳�
class Son2 : protected Fa, public Son1 {
	// ���಻�ɷ��ʸ���private����, ������Ϊ�����protected
};

class Son3 : virtual public Fa {
};

class Son4 : virtual public Fa {
};

// ���μ̳�
// ��̳н�����μ̳�����
// virtualʹ��ָ��,ʹ��̳�ָ�������
class Son5 : public Son3, public Son4 {
public:
	int a = 77;
};

void main18() {
	cout << "Fa��С:" << sizeof(Fa) << endl;
	// �����̳и�����������, ����˽��, ���Ƕ���������
	// cl /d1 reportSingleClassLayout "18 �̳�.cpp"
	cout << "Son1��С:" << sizeof(Son1) << endl;
	cout << "Son2��С:" << sizeof(Son2) << endl;

	// ��������ͬ������
	Son1 s1;
	cout << "Son1�µ�a=" << s1.a << endl;
	cout << "Fa�µ�a=" << s1.Fa::a << endl;
	// ��������ͬ������
	s1.func();
	// s1.func(1);	// ����͸��������ͬ���ĺ���,����ͬ����Ա�����ص�����������ͬ����Ա����
	s1.Fa::func();	
	s1.Fa::func(1);	// ������������з���

	// ��̬���Եķ���1
	cout << "Son1�µľ�̬d=" << s1.d << endl;
	cout << "Fa�µľ�̬d=" << s1.Fa::d << endl;
	// ��̬���Եķ���2
	cout << "Son1�µľ�̬d=" << Son1::d << endl;
	cout << "Fa�µľ�̬d=" << Fa::d << endl;
	// ��һ��::����ͨ����������  �ڶ���������ʸ����������µ�
	cout << "Fa�µľ�̬d=" << Son1::Fa::d << endl;

	// ��̬����
	Son1::func1();
	Fa::func1();
	Son1::Fa::func1(1);

	// �������μ̳е�����
	Son5 s5;
	s5.a = 18;
	s5.Son4::a = 28;
	cout << "s5.a=" << s5.a << endl;
	cout << "s5.a=" << s5.Son4::a << endl;
}