#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>

using namespace std;

// 普通函数
void print01(int val)
{
	cout << val << " ";
}
// 仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

// 常用的遍历
void test311()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	// 执行遍历
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << endl;
	}
	// 遍历工具
	for_each(v.begin(), v.end(), print01);	// 传入函数
	cout << endl;
	for_each(v.begin(), v.end(), print02());	// 传入对象
	cout << endl;
}

// 搬运容器
class Transform
{
public:
	int operator()(int v)
	{
		return v;
	}
};
void test312()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	vector<int> tv;
	tv.resize(v.size());
	// 搬
	transform(v.begin(), v.end(), tv.begin(), Transform());
	// 打印
	for_each(tv.begin(), tv.end(), print02());
	cout << endl;
}

// 容器查找
void find313()
{
	vector<int> v;
	// 在容器中查找是否有元素5
	// 对象查询需要重载==
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}

// 条件查找
class greater_5
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


void find314()
{
	vector<int> v;
	vector<int> v2;
	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_5());
	// 查找相邻的重复元素--返回开始的迭代器
	vector<int>::iterator it2 = adjacent_find(v.begin(), v.end());
	// 二分查找--改容器存储的数值必须是一个有序的序列
	bool is_exist = binary_search(v.begin(), v.end(), 5);
	if (is_exist)
	{
		cout << "5存在" << endl;
	}
	// 统计元素出现的次数
	int count1 = count(v.begin(), v.end(), 4);
	// 打乱容器中数据顺序
	random_shuffle(v.begin(), v.end());
	// 加上随机数种子--打乱顺序
	srand((unsigned int)time(NULL));
	// 将两个容器中的数据合并
	vector<int> v_target;
	v_target.resize(v.size() + v2.size());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// 容器数据反转
	reverse(v.begin(), v.end());
	// 容器数据拷贝
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	// 按照条件替换
	replace_if(v.begin(), v.end(), greater_5(), 500);
	// 容器数据交换--传入容器
	swap(v, v2);
	// 数据填充--填充为指定的值
	fill(v.begin(), v.end(), 199);
	// 容器的交集--返回的不是v_target的结束点,而是有效数据的结束点--目标容器的开辟取两个容器的中的小值
	v_target.resize(min(v.size(), v2.size()));
	vector<int>::iterator it_end = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// 并集
	vector<int>::iterator it_end2 = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// 差集--用最大的最为目标空间
	set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	
}

void main31()
{
	// test311();
	test312();
}