#include <iostream>
#include <string>

using namespace std;

// ��������֮ǰ��
	// ������: ��ź�����Ķ����ƴ��룬�ɲ���ϵͳ���й����
			// ����Ƶ�����ʵĵı�ִ�еĳ���, �ڴ���ֻ����һ�ݼ���, �ص�: ����ֻ��
	// ȫ���� : ���ȫ�ֱ����;�̬�����Լ�����
// ��������֮��
	// ջ�� : �ɱ������Զ������ͷ�, ��ź����Ĳ���ֵ, �ֲ�������
	// ���� : �ɳ���Ա������ͷ�, ������Ա���ͷ�, �������ʱ�ɲ���ϵͳ����



// ��Ҫ���ؾֲ������ĵ�ַ[ջ�Ϸ���]
int* func() {
	int a = 10;
	return &a;
}

// ���Ϸ��� �ص㣺����Ա������ͷš�new�ؼ���������
// ����Ա���ͷţ�������رպ���ϵͳ�������ͷ�
int* func2() {
	int* a = new int(10);
	return a;
}

// ���Ͽ�������
int* func3() {
	int* arr = new int[10];
	return arr;
}

void main8() {
	// �ֲ�����
	int a = 0;
	// ��̬����
	static int b = 1;
	// ����
	const int c = 2;

	int* p = func();
	cout << *p << endl;	// ��һ����ȷ��ӡ����Ϊ���������˱���
	cout << *p << endl;	// �ڶ��δ����ӡ����Ϊa�Ѿ�������

	int* p1 = func2();
	cout << *p1 << endl;
	cout << *p1 << endl;
	delete p1;
	// cout << *p1 << endl;	// �ڴ��ѱ��ͷţ��ٴη��ʽ�����

	int* p2 = func3();
	for (size_t i = 0; i < sizeof(p2) / sizeof(p2[0]); i++)
	{
		// cout << p2[i] << endl;
		cout << *(p2 + i) << endl;
	}
	delete[] p2;
	// cout << p2[1] << endl;
}