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

// Ŀ��ֻ��Ϊ�˴�ӡ��������, const*���Ա����������ݱ��޸�; ��ָ����ղ������Ա�����������Ŀ���
void printStudent(const student* s) {
	cout << "����:" << s->name << ", ����:" << s->age << ", ����:" << s->score << endl;
};

struct hero
{
	string name;
	int age;
	string sex;
};

void printHero(const hero* h) {
	cout << "����:" << h->name << ", ����:" << h->age << ", �Ա�:" << h->sex << endl;
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
	// �ṹ�崴����ʽ
	// 1.
	student s1;
	// 2.
	student s2 = { "cxk", 12, 100 };
	// 3. ����ʱ����

	// �ṹ������
	student stuArr[3] = {
		{"c1", 12, 100},
		{"c2", 12, 100},
		{"c3", 12, 100}
	};

	// ���ʽṹ��
	// 1. .����

	// 2. ->����
	student* ps = &s2;
	cout << "����:" << ps->name << ", ����:" << ps->age << ", ����:" << ps->score << endl;

	printStudent(ps);


	hero heroArr[5] = {
		{"��", 19, "Ů"},
		{"��", 20, "��"},
		{"��", 23, "��"},
		{"��", 29, "��"},
		{"��", 21, "��"}
	};
	int len = sizeof(heroArr) / sizeof(heroArr[0]);
	heroBubbleSort(heroArr, len);
	for (size_t i = 0; i < len; i++)
	{
		printHero(&heroArr[i]);
	}
}