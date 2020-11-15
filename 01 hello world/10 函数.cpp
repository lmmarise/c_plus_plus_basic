#include <iostream>
#include <string>

using namespace std;

// 声明，在后面实现。在声明和实现只能有一个有默认值。
int func(int a, int b, int c);

// 展位参数
void func1(int a, int) {
	cout << "this is a function" << endl;
}

// 函数重载。返回值不能作为重载条件。
void func2(int a) {
	cout << "int -> " << a << endl;
}

void func2(double a) {
	cout << "double -> " << a << endl;
}

// 引用函数重载
void func3(int& a) {
	cout << "int -> " << a << endl;
}

void func3(const int& a) {
	cout << "const int& -> " << a << endl;
}


void main10() {
	int r = func(1, 10, 20);
	cout << r << endl;

	func1(99, 99);

	func2(1.1);


	func3(1);	// 调用const int&
	int a = 10;
	func3(a);	// 调用int&
}

// 默认参数，如果某个函数参数有了默认值，那么在此之后的参数都需要有默认值。
int func(int a, int b = 20, int c = 30) {
	return a + b + c;
}