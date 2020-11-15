#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "动物构造" << endl;
	}

	// 将父类析构标记为虚析构以调用子类析构
	// 利用虚析构以解决父类指针释放子类示例无法释放干净问题
	virtual ~Animal() = 0;

	// 将函数变为虚函数--动态多态
	virtual void speak() {}
};

// 父类也需要实现纯虚析构函数--父类也有可能数据开辟到堆区
Animal::~Animal() {
	cout << "动物析构" << endl;
}

class Cat : public Animal{
public:
	string* name;

	Cat() {
		cout << "猫构造" << endl;
	}

	Cat(string* name) {
		this->name = name;
		cout << "猫构造" << endl;
	}

	// 父类指针在析构时不会调用子类析构,将导致内存泄露
	~Cat() {
		cout << "猫析构";
		if (name != NULL) {
			cout << "猫析构";
			delete name;
			name = NULL;
		}
		cout << endl;
	}

	virtual void speak() {
		cout << "猫说:" << endl;
	}

};

class Dog : public Animal {
public:
	virtual void speak() {
		cout << "狗说:" << endl;
	}
	~Dog() {
		cout << "狗析构" << endl;
	}
};

void speak(Animal& animal) {
	animal.speak();
}

class Calc {
public:
	int n1, n2;

	Calc(int num1, int num2) {
		n1 = num1;
		n2 = num2;
	}

	int getResult(string opr) {
		if (opr == "+") {
			return n1 + n2;
		}
		else if (opr == "-") {
			return n1 - n2;
		}
		else if (opr == "*") {
			return n1 * n2;
		}
		else if (opr == "/") {
			return n1 / n2;
		}
	}
};

// 开闭原则:对扩展进行开放, 对修改进行关闭
class AbstractCalc {
public:
	// 纯虚函数--当前类无法实例化
	// 子类必须实现该方法
	virtual int getResult() = 0;
};

class AddCalc : public AbstractCalc {
public:
	int n1, n2;

	AddCalc(int num1, int num2) {
		n1 = num1;
		n2 = num2;
	}

	virtual int getResult() {
		return n1 * n2;
	}
};

void main19() {
	Cat cat;
	Dog dog;
	// 父类引用指向子类对象
	speak(cat);
	speak(dog);

	// 计算器
	Calc c(1, 3);
	cout << c.n1 << "+" << c.n2 << c.getResult("+") << endl;

	// 多态实现计算器
	AbstractCalc* abc = new AddCalc(10, 20);
	cout << abc->getResult() << endl;
	delete abc;
}