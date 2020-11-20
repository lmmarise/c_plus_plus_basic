#include <iostream>

using namespace std;

/*
* 栈上分配: 方法出栈自动释放
*/
char* str(char ch[], int n) {
	char temp[80] = { 0 };
	for (int i = 0; i < n; i++)
		temp[i] = ch[i];
	return temp;
}

/*
* new堆上分配: 方法出栈不会自动释放
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
	// 一维数组的用处: 统计整个数组在内存中的长度    可以获取数组在内存中的首地址
	// 1.
	int a1[5];
	a1[0] = 0;
	a1[1] = 2;
	// 2
	int a2[5] = { 1, 2,3,4,5 };
	cout << "数组占用内存空间" << sizeof(a2) << endl;
	cout << "数组每个元素占用内存空间" << sizeof(a2[0]) << endl;
	cout << "数组中元素个数" << sizeof(a2) / sizeof(a2[0]) << endl;
	cout << "数组首地址" << a2 << endl;
	cout << "数组首地址" << (int)a2 << endl;
	cout << "数组首地址" << &a2[0] << endl;
	cout << "数组首地址" << &a2 << endl;


	int arr1[2][3];		// 二维数组  2行3列
	int arr2[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	cout << "二维数组占用内存" << sizeof(arr2) << endl;
	cout << "二维数组第一行占用内存" << sizeof(arr2[0]) << endl;
	cout << "二维数组单个元素占用内存" << sizeof(arr2[0][0]) << endl;

	int height[10];
	cout << "数组height[10]的第一个元素地址:" << height << endl;	// 首元素地址
	cout << "数组height[10]的起始地址+1:" << height + 1 << endl;	// 首元素地址+1 -> 指针+1
	cout << "整个数组height[10]的地址:" << &height << endl;		// 整个数组的地址
	cout << "整个数组height+1的地址:" << &height + 1 << endl;		// 整个数组的地址+1 -> 将数组看作整体, 也就是首元素指针 + 10*sizeof(int), x86下直接＋40
	cout << "数组height第一个元素的地址:" << &height[0] << endl;	// 对整体数组取第一个地址


	// 1）固定数组在函数体内声明------》栈
	// 2）固定数组为全局变量-----》堆
	// 3) 固定数组在类中声明------》堆
	// 4）动态数组 -------》堆
	char *arr99 = new char[3];
	// arr99 = arr("hello", 3);
	arr99 = str("hello", 3);
	cout << arr99 << endl;
}