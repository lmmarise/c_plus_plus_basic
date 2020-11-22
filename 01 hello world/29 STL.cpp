#include <iostream>
#include <string>

using namespace std;


// STL����: ��������㷺��һЩ���ݽṹʵ�ֳ�����
// ����ʽ����: ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ�á�
// ����ʽ����: �������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ��

// �㷨: ����֮�ⷨҲ
// ���޵Ĳ��裬����߼�����ѧ�ϵ����⣬��һ��ѧ�����ǽ����㷨(Algorithmsi�㷨��Ϊ:�ʱ��㷨�ͷ��ʱ��㷨��
// �ʱ��㷨 : ��ָ��������л���������ڵ�Ԫ�ص����ݡ����翽�����滻��ɾ���ȵ�
// ���ʱ��㷨 : ��ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ�Ҽ�ֵ�ȵ�


// ������:�������㷨֮��ճ�ϼ���
// �ṩһ�ַ�����ʹ֮�ܹ�����Ѱ��ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ��
// ÿ�����������Լ�ר���ĵ�����, ������ʹ�÷ǳ�������ָ�룬��ѧ�׶����ǿ�������������Ϊָ�롣


#include <vector>

class Person {
public:
	Person(string name, int age) {
		m_name = name;
		m_age = age;
	}

public:
	string m_name;
	int m_age;
};

class Student {
public:
	string m_Name;
	int m_Age;

	Student(string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	Student* operator+(Student& stu) {
		cout << "Student����" << endl;
		return &stu;
	}
};

void main29() {
	// ���ݴ�������
	vector<int> arr1;
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);

	// ������������������
	vector<int>::iterator it_begin = arr1.begin();	// ָ�������һ��Ԫ��
	vector<int>::iterator it_end = arr1.end();		// ָ���������һ��Ԫ�ص���һ��λ��

	// ������ʽ
	while (it_begin != it_end) {
		cout << *it_begin << endl;
		it_begin++;
	}


	// stl�����洢�Զ������
	vector<Person> ps;
	ps.push_back(Person("cxk1", 1));
	ps.push_back(Person("cxk2", 2));
	ps.push_back(Person("cxk3", 3));
	// ��������
	for (vector<Person>::iterator it = ps.begin(); it != ps.end(); it++) {
		cout << "����:" << (*it).m_name << ", ����:" << (*it).m_age << endl;
	}

	// �洢�Զ������ĵ�ַ
	vector<Student*> psx;
	Student* stu4;		// �ᵼ��"cxk4"�治����
	stu4 = &Student("cxk4", 4);	// �뿪������ʱname�ᱻ����
	psx.push_back(stu4);
	Student* const stu5 = &Student("cxk5", 5);
	// stu5 = &Student("cxk5", 5);	// �������ɱ��޸�
	stu5->m_Age = 5;
	stu5->m_Name = "5";
	psx.push_back(stu5);
	Student px6 = Student("cxk6", 6);
	psx.push_back(&px6);
	Student px7 = Student("cxk7", 7);
	psx.push_back(&px7);
	for (vector<Student*>::iterator itx = psx.begin(); itx != psx.end(); itx++) {
		cout << "����:" << (*itx)->m_Name << ", ����:" << (*itx)->m_Age << endl;
	}
}