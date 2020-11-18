#include <iostream>
#include <string>

using namespace std;

// 声明模板,告诉编译器后面代码紧跟着的不要报错,T通用类型
template<typename T>
void mySwap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

// 声明的模板必须马上使用
template<class C>
void func() {
	cout << "func" << endl;
}

void func1() {
	// 显示指定模板类型
	func<int>();
}
 
// 整数交换
void intSwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// 普通函数与模板函数的区别:
// 1.普通函数类型调用隐士类型转换
int myAdd1(int a, int b) {
	return a + b;
}
// 2.模板函数调用发生类型推导,不会自动类型转换
template<class T>
T myAdd2(T a, T b) {
	return a + b;
}
// 3.显示指定类型可以发生类型转换

// 模板函数与普通函数的调用规则
// 1.优先调用普通函数
void myPrint(int a, int b);
//{
//	cout << "普通函数" << endl;
//}
// 2.空模板参数列表,强制调用函数模板
template<class T>
void myPrint(T a, T b) {
	cout << "模板函数:c=" << a << ", b=" << b << endl;
}
// 3.函数模板可以发生函数重载
template<class T>
void myPrint(T a, T b, int c) {
	cout << "模板函数重载" << endl;
}
// 4.如果函数模板可以产生更好的适配优先调用模板函数

void main22() {
	int a = 10, b = 11;
	char c = 'f', d = 'g';

	// intSwap(a, b);
	mySwap(a, b);

	cout << "a=" << a << ", b=" << b << endl;

	// 测试:普通函数调用隐式类型转换
	cout << myAdd1(a, c) << endl;
	// cout << myAdd2(a, c) << endl;	// 不会发生隐式类型转换
	// 显示的为模板函数指定类型
	cout << myAdd2<int>(a, b) << endl;	// 自动类型转换为int


	// 测试:模板函数调用
	// myPrint(1, 2);	// 优先调用普通函数的声明
	myPrint<>(1, 2);	// 调用模板函数
	myPrint<>(a, b, 100);	// 模板函数重载
	myPrint(c, d);	// 编译器优先调用模板函数,而不是去调用int进行隐式转换
}