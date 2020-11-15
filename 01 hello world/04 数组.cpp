#include <iostream>

using namespace std;

void main4() {
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
}