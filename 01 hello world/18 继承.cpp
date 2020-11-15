#include <iostream>
#include <string>

using namespace std;

class Fa {
public:
	int a;
	static const int d = 888;
	Fa() {
		a = 100;
		cout << "Fa构造" << endl;
	}
	void func() {
		cout << "Fa func 调用" << endl;
	}
	void func(int a) {
		cout << "Fa func(int a) 调用" << endl;
	}
	static void func1() {
		cout << "Fa func1 调用" << endl;
	}
	static void func1(int a) {
		cout << "Fa func1(int a) 调用" << endl;
	}
	~Fa() {
		cout << "Fa析构" << endl;
	}
protected:
	int b;
private:
	int c;
};

// son继承fa

// 公共继承
class Son1 :public Fa {
public:
	int a = 288;
	static const int d = 999;
	// 子类不可访问父类private属性, 其它在子类不变
	Son1() {
		cout << "Son1构造" << endl;
	}
	void func() {
		cout << "Son1 func 调用" << endl;
	}
	static void func1() {
		cout << "Son1 func1 调用" << endl;
	}
	static void func1(int a) {
		cout << "Son1 func1(int a) 调用" << endl;
	}
	~Son1() {
		cout << "Son1析构" << endl;
	}
};

// 多继承
class Son2 : protected Fa, public Son1 {
	// 子类不可访问父类private属性, 其它变为子类的protected
};

class Son3 : virtual public Fa {
};

class Son4 : virtual public Fa {
};

// 菱形继承
// 虚继承解决菱形继承问题
// virtual使用指针,使其继承指针而非类
class Son5 : public Son3, public Son4 {
public:
	int a = 77;
};

void main18() {
	cout << "Fa大小:" << sizeof(Fa) << endl;
	// 子类会继承父类所有属性, 包括私有, 但是对子类隐藏
	// cl /d1 reportSingleClassLayout "18 继承.cpp"
	cout << "Son1大小:" << sizeof(Son1) << endl;
	cout << "Son2大小:" << sizeof(Son2) << endl;

	// 父类子类同名属性
	Son1 s1;
	cout << "Son1下的a=" << s1.a << endl;
	cout << "Fa下的a=" << s1.Fa::a << endl;
	// 父类子类同名方法
	s1.func();
	// s1.func(1);	// 子类和父类出现了同名的函数,子类同名成员会隐藏掉父类中所有同名成员函数
	s1.Fa::func();	
	s1.Fa::func(1);	// 加上作用域进行访问

	// 静态属性的访问1
	cout << "Son1下的静态d=" << s1.d << endl;
	cout << "Fa下的静态d=" << s1.Fa::d << endl;
	// 静态属性的访问2
	cout << "Son1下的静态d=" << Son1::d << endl;
	cout << "Fa下的静态d=" << Fa::d << endl;
	// 第一个::代表通过类名访问  第二个代表访问父类作用域下的
	cout << "Fa下的静态d=" << Son1::Fa::d << endl;

	// 静态方法
	Son1::func1();
	Fa::func1();
	Son1::Fa::func1(1);

	// 访问菱形继承的数据
	Son5 s5;
	s5.a = 18;
	s5.Son4::a = 28;
	cout << "s5.a=" << s5.a << endl;
	cout << "s5.a=" << s5.Son4::a << endl;
}