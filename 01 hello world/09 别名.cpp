#include <iostream>
#include <string>

using namespace std;


// 值传递
void func(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

// 地址传递
void func2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 引用传递
void func3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


// 引用作为返回值
int& func4() {
	static int a = 1000;
	return a;
}

// 打印 const防止被修改
void printInt(const int& val) {
	cout << val << endl;
}

void main9() {
	int a = 10;
	int &b = a;

	cout << &a << endl;
	cout << &b << endl;

	int c = 20;
	// 1.引用必须初始化
	// int &d;
	int &d = c;
	// 2. 引用初始化后不可被改变
	d = 30;

	int x = 100, y = 99;

	func(x, y);
	cout << x << " " << y << endl;

	func2(&x, &y);
	cout << x << " " << y << endl;

	func3(x, y);
	cout << x << " " << y << endl;

	// 将局部变量a的引用与xx变量建立链接，此时局部变量a将不会被回收
	int& xx = func4();
	cout << xx << endl;	// 1000
	cout << xx << endl;	// 1000
	// 别名返回值的函数将能被作为左值
	func4() = 9999;
	cout << xx << endl;	// 9999
}