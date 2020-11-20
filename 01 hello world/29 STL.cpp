#include <iostream>
#include <string>

using namespace std;


// STL容器: 将运用最广泛的一些数据结构实现出来。
// 序列式容器: 强调值的排序，序列式容器中的每个元素均有固定的位置。
// 关联式容器: 二叉树结构，各元素之间没有严格的物理上的顺序关系。

// 算法: 问题之解法也
// 有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithmsi算法分为:质变算法和非质变算法。
// 质变算法 : 是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
// 非质变算法 : 是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等


// 迭代器:容器和算法之间粘合剂。
// 提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
// 每个容器都有自己专属的迭代器, 迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针。


#include <vector>

void main() {
	// 数据存入容器
	vector<int> arr1;
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);

	// 迭代器访问数组数据
	vector<int>::iterator it_begin = arr1.begin();	// 指向数组第一个元素
	vector<int>::iterator it_end = arr1.end();		// 指向数组最后一个元素的下一个位置

	// 遍历方式
	while (it_begin != it_end) {
		cout << *it_begin << endl;
		it_begin++;
	}
}