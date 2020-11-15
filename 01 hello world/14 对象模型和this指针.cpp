#include <iostream>
#include <string>

using namespace std;


class P {
public:
	int a;		// 说明该属性属于该类对象
	static int b;	// 没有增长, 说明静态成员变量不属于类对象
	mutable int c;	// 特殊变量, 在常函数中也可被修改

	// 每一个非静态成员函数只会诞生一份成员变量实例, 多个类型相同的对象公用同一份代码 ---> 引出this指针
	void func1() {}	// 没有增长  说明不属于类的对象上
	static void func2() {}	// 没有增长 说明不属于类的对象上

	P(int a) {
		this->a = a;	// this指向被调用的成员函数的对象
	}

	P& add(int i) {
		this->a += i;
		return *this;
	}

	void show() {
		cout << "show() ---- " << endl;
	}

	void show_a() {
		if (this == NULL) {
			return;
		}
		cout << "show_a() ----> " << this->a << endl;
	}

	// 常函数   常函数不能修改成员属性  加了mutable才能被修改
	void show_p() const {	// const修饰this指针的指向,将其变为常量指针
		// this->a = 100;		// this指向的值也不能被修改
		// this指针是一个指针常量,不可被修改指针的指向   P* const this
		// this = NULL;
	}

	void show_p2() const {
		this->c = 100;
	}

	void show_p3() {
		this->a = 100;
	}
};


void main14() {
	P p(1);	// 如果是空对象, 则结果为1
	cout << "空对象的占用空间:" << sizeof(p) << endl;


	// this的好处
	// 1.解决别名冲突
	// 2.返回对象本身  *this
	cout << "p->a:" << p.a << endl;
	p.add(1).add(2).add(3);
	cout << "p->a:" << p.a << endl;


	cout << endl << "空指针调用函数" << endl;
	P p1 = NULL;
	p1.show();
	p1.show_a();

	const P p2 = NULL;
	// p2.show_p3();	// 常对象只能调用常函数  普通成员函数可以修改成员变量
	p2.show_p();
	p2.show_p2();
}