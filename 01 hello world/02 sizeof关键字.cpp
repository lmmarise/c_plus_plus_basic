#include <iostream>

using namespace std;

void main2() {
	// sizeof(数据类型/变量)
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof('a') << endl;
	cout << sizeof("aaaaa") << endl;	// 对于字符串会计算后面的'/0'
	char aa[] = "aaaaa";
	char* aa1 = "aaaaa";	// 字符串是存储在内存静态区中  const char*变量，不可改变
	cout << sizeof(aa) << endl;
	cout << sizeof(aa1) << endl;
	string bb = "bb";
	cout << sizeof(bb) << endl;

	bool bl = true;
	cout << sizeof(bl) << endl;
}