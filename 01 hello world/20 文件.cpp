#include <iostream>
#include <string>
#include <fstream>	// 1.头文件

using namespace std;

class Person {
public:
	string name;
	int age;
};

void main20() {
	// 2.创建流对象
	ofstream ofs;
	// 3.打开文件
	ofs.open("test.txt", ios::out);
	if (ofs.is_open()) {
		// 4.写数据
		ofs << "写入的数据";
		// 5.关闭文件
		ofs.close();
	}
	// 读取数据
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ofs.is_open()) {
		// 第一种
		char buf[1024] = { 0 };
		while (ifs >> buf) {
			cout << buf << endl;
		}
		// 第二种
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}
		// 第三种
		string strBuf;
		while (getline(ifs, strBuf)) {
			cout << strBuf << endl;
		}
		// 第四种
		char c;
		while ((c = ifs.get()) != EOF) {
			cout << c;
		}
		ifs.close();
	} else {
		cout << "打开文件失败" << endl;
	}

	// 二进制写文件
	ofstream ofs1("person.txt", ios::out | ios::binary);
	Person p = {
		"张三",
		19
	};
	if (ofs1.is_open()) {
		ofs1.write((const char*)&p, sizeof(Person));

	}
	// 二进制读文件
	ifstream ifs1;
	ifs1.open("person.txt", ios::in | ios::binary);
	Person p1;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名:" << p.name << ", 年龄:" << p.age << endl;
	ifs1.close();
}