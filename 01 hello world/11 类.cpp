#include <iostream>
#include <string>

using namespace std;

#define PI 3.1415926

// 继承、封装、多态
class cirecle {
// 公共权限：类外可访问，派生类也可访问
public:
	// 属性
	int m_r;		// 半径
	// 方法
	double caculate_area() {	// 计算面积
		return 2 * PI * m_r;
	}
// 保护权限：类外不可访问派生类可访问
protected:
// 私有权限：类外不可访问派生类也不可以访问
private:
};

// struct和class的唯一区别：访问权限不同。class默认访问权限为私有，struct默认访问权限是公共。
struct A {
	int id;	// 可被访问
};

class B {
	int id;	// 类外不可被访问
public:
	int age;
	// 构造函数
	// 默认情况下, 编译器至少给类提供了3个构造函数: 默认构造、析构、拷贝构造，属性进行值拷贝
	B() {		// 无参构造 默认构造  自己提供了,编译器就不再提供
		cout << "B的构造" << endl;
	}			// 有参构造
	B(int a) {
		cout << "B的构造, a=" << a << endl;
	}
	B(const B& b) {	// 拷贝构造 避免被修改; 自己提供了,编译器就不再提供
		cout << "B的拷贝构造" << endl;
	}
	// 析构函数
	~B() {
		cout << "B的析构" << endl;
	}
};


// 参数传递的值传递和地址传递
B func(B b) {
	return b;	// 在返回对象的时候也会调用对象的拷贝构造
}

// 避免对象值传递时的拷贝调用,节省性能
const B& func1(B& b) {	// 直接接收源对象,避免参数拷贝 返回对象为常量，不可改变
	return b;
}


// 类对象作为类成员
class Phone {
public:
	string m_name;

	Phone(string name) {
		cout << "Phone构造" << endl;
		m_name = name;
	}

	~Phone() { cout << "~Phone析构" << endl; }
};

class People {
	const static int id = 10;		// 静态方法只能访问静态成员
public:
	string m_name;
	Phone m_phone;

	People(string name, string phone_name): m_name(name), m_phone(phone_name) {
		cout << "People构造" << endl;
	}

	static void func() {
		cout << "People静态方法" << ", id=" << id << endl;
	}

	~People() { cout << "~People析构" << endl; }
};


void main11() {
	cirecle c1;
	c1.m_r = 9;
	cout << c1.caculate_area() << endl;

	B b;	// 默认构造
	// B b();	// 编译器将判定其为一个函数的声明,默认构造就上面那种方法即可。不会被认为在创建对象。
	B b1(1);

	// 显示构造
	B b2 = B(10);		// 匿名对象，再给他一个名字。不给名字，匿名对象将被立刻被回收。
	// B(b2);	// 编译器认为这行代码等价于：B b2；
	B(B(99));	// 等价于：B（99）；
	

	// 隐式转换法
	B b3 = 839;		// 调用int参数的构造
	B b4 = b3;		// 调用B类型的构造


	cout << "------参数传递测试------" << endl;
	B bx = 10086;
	bx.age = 10;
	cout << "调用函数func---->" << endl;
	B bx1 = func(bx);	// 参数传递会拷贝一份
	cout << "调用函数func1---->" << endl;
	B bx2 = func1(bx);	// 值传递会拷贝一份出来
	cout << (int)&bx << endl;	// 17825320
	cout << (int)&bx1 << endl;	// 17825308
	cout << (int)&bx2 << endl;	// 17825296
	cout << bx.age << endl;
	cout << bx1.age << endl;
	cout << bx2.age << endl;

	cout << endl;
	cout << "----类对象作为类成员----" << endl;
	People p1("张三", "Apple X");	// 首先构造类成员  析构的顺序相反

	cout << endl;
	cout << "----类的静态方法----" << endl;
	People::func();

	cout << endl;
	cout << "----程序结束----" << endl << endl;
}