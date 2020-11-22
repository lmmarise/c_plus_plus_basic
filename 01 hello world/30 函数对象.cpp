#include <iostream>
#include <string>
// 内建函数对象
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class print {
public:
	// 谓词: 一元谓词,二元谓词(重载有两个参数)
	int operator()(int a, int b) {
		return a + b;
	}

	// 仿函数
	void operator()(string str) {
		cout << str << endl;
	}
};

// 函数对象可以拥有自己的状态
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



// 减法仿函数
// template<class T> T minus < T>
// template<class T> T multiplies < T>
// 乘法仿函数
// template<class T> T divides<T>
// 除法仿函数
// template<class T> T modulus<T>
// 取模仿函数
// template<class T> T negate<T>
// 取反仿函数

class my_compare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

// 关系仿函数
void test30_3()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(6);
	arr.push_back(4);
	arr.push_back(2);
	// sort(arr.begin(), arr.end(), my_compare());	// 自定义
	sort(arr.begin(), arr.end(), greater<int>());	// 内建
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 逻辑仿函数
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
	// 将容器内的数据取反搬运
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

	// 调用内建函数
	test30_1();
	test30_2();
	test30_3();
	test30_4();
}