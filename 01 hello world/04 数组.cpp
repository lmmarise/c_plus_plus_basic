#include <iostream>

using namespace std;

void main4() {
	// һά������ô�: ͳ�������������ڴ��еĳ���    ���Ի�ȡ�������ڴ��е��׵�ַ
	// 1.
	int a1[5];
	a1[0] = 0;
	a1[1] = 2;
	// 2
	int a2[5] = { 1, 2,3,4,5 };
	cout << "����ռ���ڴ�ռ�" << sizeof(a2) << endl;
	cout << "����ÿ��Ԫ��ռ���ڴ�ռ�" << sizeof(a2[0]) << endl;
	cout << "������Ԫ�ظ���" << sizeof(a2) / sizeof(a2[0]) << endl;
	cout << "�����׵�ַ" << a2 << endl;
	cout << "�����׵�ַ" << (int)a2 << endl;
	cout << "�����׵�ַ" << &a2[0] << endl;
	cout << "�����׵�ַ" << &a2 << endl;


	int arr1[2][3];		// ��ά����  2��3��
	int arr2[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	cout << "��ά����ռ���ڴ�" << sizeof(arr2) << endl;
	cout << "��ά�����һ��ռ���ڴ�" << sizeof(arr2[0]) << endl;
	cout << "��ά���鵥��Ԫ��ռ���ڴ�" << sizeof(arr2[0][0]) << endl;
}