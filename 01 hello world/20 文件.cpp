#include <iostream>
#include <string>
#include <fstream>	// 1.ͷ�ļ�

using namespace std;

void main() {
	// 2.����������
	ofstream ofs;
	// 3.���ļ�
	ofs.open("test.txt", ios::out);
	// 4.д����
	ofs << "д�������";
	// 5.�ر��ļ�
	ofs.close();
}