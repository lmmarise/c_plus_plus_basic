#include <iostream>

using namespace std;

/*
* ջ�Ϸ���: ������ջ�Զ��ͷ�
*/
char* str(char ch[], int n) {
	char temp[80] = { 0 };
	for (int i = 0; i < n; i++)
		temp[i] = ch[i];
	return temp;
}

/*
* new���Ϸ���: ������ջ�����Զ��ͷ�
*/
char* arr(const char ch[], int n) {
	int i;
	char *t = new char[n + 1];
	for (i = 0; i < n; i++)
		t[i] = ch[i];
	while (i <= n)
		t[i++] = '\0';
	cout << &t << endl;
	return t;
}

void main04() {
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

	int height[10];
	cout << "����height[10]�ĵ�һ��Ԫ�ص�ַ:" << height << endl;	// ��Ԫ�ص�ַ
	cout << "����height[10]����ʼ��ַ+1:" << height + 1 << endl;	// ��Ԫ�ص�ַ+1 -> ָ��+1
	cout << "��������height[10]�ĵ�ַ:" << &height << endl;		// ��������ĵ�ַ
	cout << "��������height+1�ĵ�ַ:" << &height + 1 << endl;		// ��������ĵ�ַ+1 -> �����鿴������, Ҳ������Ԫ��ָ�� + 10*sizeof(int), x86��ֱ�ӣ�40
	cout << "����height��һ��Ԫ�صĵ�ַ:" << &height[0] << endl;	// ����������ȡ��һ����ַ


	// 1���̶������ں�����������------��ջ
	// 2���̶�����Ϊȫ�ֱ���-----����
	// 3) �̶���������������------����
	// 4����̬���� -------����
	char *arr99 = new char[3];
	// arr99 = arr("hello", 3);
	arr99 = str("hello", 3);
	cout << arr99 << endl;
}