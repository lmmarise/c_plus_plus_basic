#include <iostream>
#include <string>

using namespace std;

class P1 {
public:
	int age;
	// 1.成员函数重载+号
	P1 operator+(P1& p) {
		P1 temp;
		temp.age = this->age + p.age;
		return temp;
	}
};

class P2 {
public:
	int age;
};

// 2.全局函数重载
P2 operator+(P2& p1, P2& p2) {
	P2 temp;
	temp.age = p1.age + p2.age;
	return temp;
}

class P3 {
	friend ostream& operator<<(ostream& cout, P3& p);
private:
	int age;
public:
	int& set_age() {
		return this->age;
	}

	void set_age(int age) {
		this->age = age;
	}
};

// 重载输出符号
ostream& operator<<(ostream& cout, P3& p) {
	cout << "p3.age=" << p.age;
	return cout;
}

// 自定义整形数据类型
class Int {
	friend ostream& operator<<(ostream& cout, Int i);
public:
	int num = 0;
	// 重载前置++
	Int& operator++() {
		num++;
		return *this;
	}
	// 重载后置++
	Int operator++(int) {
		Int temp = *this;
		++temp;
		return temp;
	}
	// 构造
	Int() {
	}
	Int(int i) {
		num = i;
	}
};

ostream& operator<<(ostream& cout, Int i) {
	return cout << i.num;
}

// 等号赋值重载 避免堆区数据重复释放
class P4 {
public:
	Int *age = NULL;
	P4() { };
	P4(int age) {
		this->age = new Int(age);
	}
	// 将堆区的数据释放干净
	~P4() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	// 重载= 实现深拷贝+链式=赋值
	P4& operator=(P4& p) {
		age = new Int(*p.age);
		return *this;
	}
	// 重载对比操作
	bool operator==(P4& p) {
		return this->age->num == p.age->num;
	}
	// 重载函数调用--仿函数
	void operator()(string str) {
		cout << str << endl;
	}
	int operator()(int i, int j) {
		return i + j;
	}
};

void main17() {
	P1 p1, p2;
	p1.age = 10;
	p2.age = 20;
	cout << (p1 + p2).age << endl;

	P2 p3, p4;
	p3.age = 100;
	p4.age = 200;
	cout << (p3 + p4).age << endl;

	P3 p5;
	p5.set_age() = 999;
	cout << p5 << endl;

	Int a = 0;
	cout << ++(++a) << endl;
	cout << a++ << endl;

	P4 person1 = 18;
	P4 person2 = 19;
	P4 person3 = 20;
	person1 = person2 = person3;
	cout << "person1的年龄为:" << *person1.age << endl;

	// 匿名使用仿函数
	P4()("cxk");
	cout << P4()(1, 2) << endl;
}