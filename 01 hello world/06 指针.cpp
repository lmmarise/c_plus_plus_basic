#include <iostream>

using namespace std;

void main6() {
	int a = 10;
	int *p = &a;		// ����int���͵�ָ��

	// *P	// ��ָ��

	cout << "a�ĵ�ַΪ" << &a << endl;
	cout << "a��ֵΪ" << a << endl;
	cout << "p�ĵ�ַΪ" << &p << endl;
	cout << "p��ֵΪ" << p << endl;
	cout << "p��ֵ��ֵΪ" << *p << endl;
	cout << "ָ���С" << sizeof(int*) << endl;

	// ��ָ��
	// 1.�Ա������г�ʼ��
	// 2.��ָ�����޷���ֱ�ӷ���
	int *p1 = NULL;

	// Ұָ��
	int *p2 = (int*) 0x32424256;
	// cout << *p2 << endl;	// Ȩ�޷����쳣

	// const ��ָ��
	const int* p3 = &a;		// ����ָ��-ָ��ָ���ֵ���ܱ��޸�
	// *p3 = 2;
	p3 = &a;
	int* const p4 = &a;		// ָ�볣��-ָ�벻�ܱ��޸�
	// p4 = &a;
	*p4 = 3;
	const int* const p5 = NULL;	// ָ���ָ���ֵ�����ܱ��޸�


	// ָ��������
	int ax[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int* pa = ax;
	for (size_t i = 0; i < sizeof(ax) / sizeof(int); i++) {
		cout << *(pa + i) << endl;
	}
}