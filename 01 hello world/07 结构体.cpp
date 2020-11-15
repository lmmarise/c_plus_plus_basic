#include <iostream>
#include <string>

using namespace std;

struct student {
	string name;
	int age;
	int score;
} s3;

struct teacher
{
	string name;
	int age;
	student stus[5];
};

// 目的只是为了打印引用数据, const*可以避免引用数据被修改; 用指针接收参数可以避免参数副本的拷贝
void printStudent(const student* s) {
	cout << "名字:" << s->name << ", 年龄:" << s->age << ", 分数:" << s->score << endl;
};

struct hero
{
	string name;
	int age;
	string sex;
};

void printHero(const hero* h) {
	cout << "名字:" << h->name << ", 年龄:" << h->age << ", 性别:" << h->sex << endl;
};

void heroBubbleSort(hero* heroArr, int len) {
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len - i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age)
			{
				hero temp = heroArr[j];
				heroArr[j] = heroArr[j + 1];
				heroArr[j + 1] = temp;
			}
		}
	}
}

void main7() {
	// 结构体创建方式
	// 1.
	student s1;
	// 2.
	student s2 = { "cxk", 12, 100 };
	// 3. 定义时创建

	// 结构体数组
	student stuArr[3] = {
		{"c1", 12, 100},
		{"c2", 12, 100},
		{"c3", 12, 100}
	};

	// 访问结构体
	// 1. .访问

	// 2. ->访问
	student* ps = &s2;
	cout << "名字:" << ps->name << ", 年龄:" << ps->age << ", 分数:" << ps->score << endl;

	printStudent(ps);


	hero heroArr[5] = {
		{"貂", 19, "女"},
		{"刘", 20, "男"},
		{"关", 23, "男"},
		{"张", 29, "男"},
		{"赵", 21, "男"}
	};
	int len = sizeof(heroArr) / sizeof(heroArr[0]);
	heroBubbleSort(heroArr, len);
	for (size_t i = 0; i < len; i++)
	{
		printHero(&heroArr[i]);
	}
}