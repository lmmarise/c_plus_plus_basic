#include <iostream>
#include <string>

using namespace std;


// ֵ����
void func(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

// ��ַ����
void func2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���ô���
void func3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


// ������Ϊ����ֵ
int& func4() {
	static int a = 1000;
	return a;
}

// ��ӡ const��ֹ���޸�
void printInt(const int& val) {
	cout << val << endl;
}

void main9() {
	int a = 10;
	int &b = a;

	cout << &a << endl;
	cout << &b << endl;

	int c = 20;
	// 1.���ñ����ʼ��
	// int &d;
	int &d = c;
	// 2. ���ó�ʼ���󲻿ɱ��ı�
	d = 30;

	int x = 100, y = 99;

	func(x, y);
	cout << x << " " << y << endl;

	func2(&x, &y);
	cout << x << " " << y << endl;

	func3(x, y);
	cout << x << " " << y << endl;

	// ���ֲ�����a��������xx�����������ӣ���ʱ�ֲ�����a�����ᱻ����
	int& xx = func4();
	cout << xx << endl;	// 1000
	cout << xx << endl;	// 1000
	// ��������ֵ�ĺ������ܱ���Ϊ��ֵ
	func4() = 9999;
	cout << xx << endl;	// 9999
}