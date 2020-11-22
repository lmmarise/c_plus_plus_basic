#include <iostream>
#include <string>
// �ڽ���������
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class print {
public:
	// ν��: һԪν��,��Ԫν��(��������������)
	int operator()(int a, int b) {
		return a + b;
	}

	// �º���
	void operator()(string str) {
		cout << str << endl;
	}
};

// �����������ӵ���Լ���״̬
void do_print(print& p, string str) {
	p(str);
}

void test30_1() {
	negate<int> n;
	cout << n(10) << endl;
}

void test30_2() {
	plus<int> n;
	cout << n(10, 10) << endl;
}



// �����º���
// template<class T> T minus < T>
// template<class T> T multiplies < T>
// �˷��º���
// template<class T> T divides<T>
// �����º���
// template<class T> T modulus<T>
// ȡģ�º���
// template<class T> T negate<T>
// ȡ���º���

class my_compare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

// ��ϵ�º���
void test30_3()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(6);
	arr.push_back(4);
	arr.push_back(2);
	// sort(arr.begin(), arr.end(), my_compare());	// �Զ���
	sort(arr.begin(), arr.end(), greater<int>());	// �ڽ�
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// �߼��º���
void test30_4()
{
	vector<bool> arr;
	arr.push_back(true);
	arr.push_back(false);
	arr.push_back(true);
	arr.push_back(false);
	for (vector<bool>::iterator it; it != arr.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	// �������ڵ�����ȡ������
	vector<bool> v2;
	v2.resize(arr.size());
	transform(arr.begin(), arr.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void main30() {
	print p;
	cout << p(1, 2) << endl;
	do_print(p, "cxk");

	// �����ڽ�����
	test30_1();
	test30_2();
	test30_3();
	test30_4();
}