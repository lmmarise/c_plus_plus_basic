#include <iostream>
#include "05.h"

using namespace std;

void main5() {
	int a = 0, b = 2;
	cout << add(a, b) << endl;

	swap(&a, &b);
	cout << "a=" << a << ",b=" << b << endl;


	system("pause");
}