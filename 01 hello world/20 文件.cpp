#include <iostream>
#include <string>
#include <fstream>	// 1.ͷ�ļ�

using namespace std;

class Person {
public:
	string name;
	int age;
};

void main20() {
	// 2.����������
	ofstream ofs;
	// 3.���ļ�
	ofs.open("test.txt", ios::out);
	if (ofs.is_open()) {
		// 4.д����
		ofs << "д�������";
		// 5.�ر��ļ�
		ofs.close();
	}
	// ��ȡ����
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ofs.is_open()) {
		// ��һ��
		char buf[1024] = { 0 };
		while (ifs >> buf) {
			cout << buf << endl;
		}
		// �ڶ���
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}
		// ������
		string strBuf;
		while (getline(ifs, strBuf)) {
			cout << strBuf << endl;
		}
		// ������
		char c;
		while ((c = ifs.get()) != EOF) {
			cout << c;
		}
		ifs.close();
	} else {
		cout << "���ļ�ʧ��" << endl;
	}

	// ������д�ļ�
	ofstream ofs1("person.txt", ios::out | ios::binary);
	Person p = {
		"����",
		19
	};
	if (ofs1.is_open()) {
		ofs1.write((const char*)&p, sizeof(Person));

	}
	// �����ƶ��ļ�
	ifstream ifs1;
	ifs1.open("person.txt", ios::in | ios::binary);
	Person p1;
	ifs.read((char*)&p, sizeof(Person));
	cout << "����:" << p.name << ", ����:" << p.age << endl;
	ifs1.close();
}