#include <iostream>
#include <string>

using namespace std;

// �������ں���ʵ�֡���������ʵ��ֻ����һ����Ĭ��ֵ��
int func(int a, int b, int c);

// չλ����
void func1(int a, int) {
	cout << "this is a function" << endl;
}

// �������ء�����ֵ������Ϊ����������
void func2(int a) {
	cout << "int -> " << a << endl;
}

void func2(double a) {
	cout << "double -> " << a << endl;
}

// ���ú�������
void func3(int& a) {
	cout << "int -> " << a << endl;
}

void func3(const int& a) {
	cout << "const int& -> " << a << endl;
}


void main10() {
	int r = func(1, 10, 20);
	cout << r << endl;

	func1(99, 99);

	func2(1.1);


	func3(1);	// ����const int&
	int a = 10;
	func3(a);	// ����int&
}

// Ĭ�ϲ��������ĳ��������������Ĭ��ֵ����ô�ڴ�֮��Ĳ�������Ҫ��Ĭ��ֵ��
int func(int a, int b = 20, int c = 30) {
	return a + b + c;
}