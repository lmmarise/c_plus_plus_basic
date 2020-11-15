#include <iostream>
#include <string>

using namespace std;

// 程序运行之前：
	// 代码区: 存放函数体的二进制代码，由操作系统进行管理的
			// 对于频繁访问的的被执行的程序, 内存中只需存放一份即可, 特点: 共享、只读
	// 全局区 : 存放全局变量和静态变量以及常量
// 程序运行之后：
	// 栈区 : 由编译器自动分配释放, 存放函数的参数值, 局部变量等
	// 堆区 : 由程序员分配和释放, 若程序员不释放, 程序结束时由操作系统回收



// 不要返回局部变量的地址[栈上分配]
int* func() {
	int a = 10;
	return &a;
}

// 堆上分配 特点：程序员分配和释放、new关键字来分配
// 程序员不释放，在软件关闭后有系统来进行释放
int* func2() {
	int* a = new int(10);
	return a;
}

// 堆上开辟数组
int* func3() {
	int* arr = new int[10];
	return arr;
}

void main8() {
	// 局部变量
	int a = 0;
	// 静态变量
	static int b = 1;
	// 常量
	const int c = 2;

	int* p = func();
	cout << *p << endl;	// 第一次正确打印，因为编译器做了保留
	cout << *p << endl;	// 第二次错误打印，因为a已经被回收

	int* p1 = func2();
	cout << *p1 << endl;
	cout << *p1 << endl;
	delete p1;
	// cout << *p1 << endl;	// 内存已被释放，再次访问将报错

	int* p2 = func3();
	for (size_t i = 0; i < sizeof(p2) / sizeof(p2[0]); i++)
	{
		// cout << p2[i] << endl;
		cout << *(p2 + i) << endl;
	}
	delete[] p2;
	// cout << p2[1] << endl;
}