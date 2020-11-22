#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>

using namespace std;

// ��ͨ����
void print01(int val)
{
	cout << val << " ";
}
// �º���
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

// ���õı���
void test311()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	// ִ�б���
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << endl;
	}
	// ��������
	for_each(v.begin(), v.end(), print01);	// ���뺯��
	cout << endl;
	for_each(v.begin(), v.end(), print02());	// �������
	cout << endl;
}

// ��������
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
	// ��
	transform(v.begin(), v.end(), tv.begin(), Transform());
	// ��ӡ
	for_each(tv.begin(), tv.end(), print02());
	cout << endl;
}

// ��������
void find313()
{
	vector<int> v;
	// �������в����Ƿ���Ԫ��5
	// �����ѯ��Ҫ����==
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

// ��������
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
	// �������ڵ��ظ�Ԫ��--���ؿ�ʼ�ĵ�����
	vector<int>::iterator it2 = adjacent_find(v.begin(), v.end());
	// ���ֲ���--�������洢����ֵ������һ�����������
	bool is_exist = binary_search(v.begin(), v.end(), 5);
	if (is_exist)
	{
		cout << "5����" << endl;
	}
	// ͳ��Ԫ�س��ֵĴ���
	int count1 = count(v.begin(), v.end(), 4);
	// ��������������˳��
	random_shuffle(v.begin(), v.end());
	// �������������--����˳��
	srand((unsigned int)time(NULL));
	// �����������е����ݺϲ�
	vector<int> v_target;
	v_target.resize(v.size() + v2.size());
	merge(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// �������ݷ�ת
	reverse(v.begin(), v.end());
	// �������ݿ���
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());
	// ���������滻
	replace_if(v.begin(), v.end(), greater_5(), 500);
	// �������ݽ���--��������
	swap(v, v2);
	// �������--���Ϊָ����ֵ
	fill(v.begin(), v.end(), 199);
	// �����Ľ���--���صĲ���v_target�Ľ�����,������Ч���ݵĽ�����--Ŀ�������Ŀ���ȡ�����������е�Сֵ
	v_target.resize(min(v.size(), v2.size()));
	vector<int>::iterator it_end = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// ����
	vector<int>::iterator it_end2 = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	// �--��������ΪĿ��ռ�
	set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v_target.begin());
	
}

void main31()
{
	// test311();
	test312();
}