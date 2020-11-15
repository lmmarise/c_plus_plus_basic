#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "���ﹹ��" << endl;
	}

	// �������������Ϊ�������Ե�����������
	// �����������Խ������ָ���ͷ�����ʾ���޷��ͷŸɾ�����
	virtual ~Animal() = 0;

	// ��������Ϊ�麯��--��̬��̬
	virtual void speak() {}
};

// ����Ҳ��Ҫʵ�ִ�����������--����Ҳ�п������ݿ��ٵ�����
Animal::~Animal() {
	cout << "��������" << endl;
}

class Cat : public Animal{
public:
	string* name;

	Cat() {
		cout << "è����" << endl;
	}

	Cat(string* name) {
		this->name = name;
		cout << "è����" << endl;
	}

	// ����ָ��������ʱ���������������,�������ڴ�й¶
	~Cat() {
		cout << "è����";
		if (name != NULL) {
			cout << "è����";
			delete name;
			name = NULL;
		}
		cout << endl;
	}

	virtual void speak() {
		cout << "è˵:" << endl;
	}

};

class Dog : public Animal {
public:
	virtual void speak() {
		cout << "��˵:" << endl;
	}
	~Dog() {
		cout << "������" << endl;
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

// ����ԭ��:����չ���п���, ���޸Ľ��йر�
class AbstractCalc {
public:
	// ���麯��--��ǰ���޷�ʵ����
	// �������ʵ�ָ÷���
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
	// ��������ָ���������
	speak(cat);
	speak(dog);

	// ������
	Calc c(1, 3);
	cout << c.n1 << "+" << c.n2 << c.getResult("+") << endl;

	// ��̬ʵ�ּ�����
	AbstractCalc* abc = new AddCalc(10, 20);
	cout << abc->getResult() << endl;
	delete abc;
}