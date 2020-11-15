#include <iostream>

using namespace std;

void main6() {
	int a = 10;
	int *p = &a;		// 定义int类型的指针

	// *P	// 解指针

	cout << "a的地址为" << &a << endl;
	cout << "a的值为" << a << endl;
	cout << "p的地址为" << &p << endl;
	cout << "p的值为" << p << endl;
	cout << "p的值的值为" << *p << endl;
	cout << "指针大小" << sizeof(int*) << endl;

	// 空指针
	// 1.对变量进行初始化
	// 2.空指针是无法被直接访问
	int *p1 = NULL;

	// 野指针
	int *p2 = (int*) 0x32424256;
	// cout << *p2 << endl;	// 权限访问异常

	// const 与指针
	const int* p3 = &a;		// 常量指针-指针指向的值不能被修改
	// *p3 = 2;
	p3 = &a;
	int* const p4 = &a;		// 指针常量-指针不能被修改
	// p4 = &a;
	*p4 = 3;
	const int* const p5 = NULL;	// 指针和指向的值都不能被修改


	// 指针与数组
	int ax[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int* pa = ax;
	for (size_t i = 0; i < sizeof(ax) / sizeof(int); i++) {
		cout << *(pa + i) << endl;
	}
}