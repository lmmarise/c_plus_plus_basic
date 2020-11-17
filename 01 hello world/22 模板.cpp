#include <iostream>
#include <string>

using namespace std;

// ����ģ��,���߱����������������ŵĲ�Ҫ����,Tͨ������
template<typename T>
void mySwap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

// ������ģ���������ʹ��
template<class C>
void func() {
	cout << "func" << endl;
}

void func1() {
	// ��ʾָ��ģ������
	func<int>();
}
 
// ��������
void intSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void main22() {
	int a = 10, b = 11;
	// intSwap(a, b);
	mySwap(a, b);

	cout << "a=" << a << ", b=" << b << endl;
}