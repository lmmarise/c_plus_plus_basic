#include <iostream>
#include <string>

using namespace std;


class person {
public:
	string m_name;
	int m_age;
	int m_height;

	person(string name, int age, int height): m_name(name), m_age(age), m_height(height) {

	}
};

void main13() {
	person p("cxk", 10, 160);
}