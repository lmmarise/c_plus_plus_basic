#include <iostream>
#include <string>
#include <fstream>	// 1.头文件

using namespace std;

void main() {
	// 2.创建流对象
	ofstream ofs;
	// 3.打开文件
	ofs.open("test.txt", ios::out);
	// 4.写数据
	ofs << "写入的数据";
	// 5.关闭文件
	ofs.close();
}