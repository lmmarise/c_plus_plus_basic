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

void main22() {
	int a = 10, b = 11;
	// intSwap(a, b);
	mySwap(a, b);

	cout << "a=" << a << ", b=" << b << endl;
}