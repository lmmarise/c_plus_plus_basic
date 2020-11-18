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

// ��ͨ������ģ�庯��������:
// 1.��ͨ�������͵�����ʿ����ת��
int myAdd1(int a, int b) {
	return a + b;
}
// 2.ģ�庯�����÷��������Ƶ�,�����Զ�����ת��
template<class T>
T myAdd2(T a, T b) {
	return a + b;
}
// 3.��ʾָ�����Ϳ��Է�������ת��

// ģ�庯������ͨ�����ĵ��ù���
// 1.���ȵ�����ͨ����
void myPrint(int a, int b);
//{
//	cout << "��ͨ����" << endl;
//}
// 2.��ģ������б�,ǿ�Ƶ��ú���ģ��
template<class T>
void myPrint(T a, T b) {
	cout << "ģ�庯��:c=" << a << ", b=" << b << endl;
}
// 3.����ģ����Է�����������
template<class T>
void myPrint(T a, T b, int c) {
	cout << "ģ�庯������" << endl;
}
// 4.�������ģ����Բ������õ��������ȵ���ģ�庯��

void main22() {
	int a = 10, b = 11;
	char c = 'f', d = 'g';

	// intSwap(a, b);
	mySwap(a, b);

	cout << "a=" << a << ", b=" << b << endl;

	// ����:��ͨ����������ʽ����ת��
	cout << myAdd1(a, c) << endl;
	// cout << myAdd2(a, c) << endl;	// ���ᷢ����ʽ����ת��
	// ��ʾ��Ϊģ�庯��ָ������
	cout << myAdd2<int>(a, b) << endl;	// �Զ�����ת��Ϊint


	// ����:ģ�庯������
	// myPrint(1, 2);	// ���ȵ�����ͨ����������
	myPrint<>(1, 2);	// ����ģ�庯��
	myPrint<>(a, b, 100);	// ģ�庯������
	myPrint(c, d);	// ���������ȵ���ģ�庯��,������ȥ����int������ʽת��
}