#include <iostream>

using namespace std;

void main2() {
	// sizeof(��������/����)
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof('a') << endl;
	cout << sizeof("aaaaa") << endl;	// �����ַ������������'/0'
	char aa[] = "aaaaa";
	char* aa1 = "aaaaa";	// �ַ����Ǵ洢���ڴ澲̬����  const char*���������ɸı�
	cout << sizeof(aa) << endl;
	cout << sizeof(aa1) << endl;
	string bb = "bb";
	cout << sizeof(bb) << endl;

	bool bl = true;
	cout << sizeof(bl) << endl;
}