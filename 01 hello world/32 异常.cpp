#include <iostream>
#include <string>
#include <functional>
#include <exception>

using namespace std;

int test32()
{
	int a = 1, b = 0;
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (a / b);
}

void main32()
{

	try {
		test32();
		cout << "[3]This statement will not be executed." << endl;
	}
	catch (const char*& e) {
		cout << e << endl;
	}
}