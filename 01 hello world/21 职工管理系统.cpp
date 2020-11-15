#include <iostream>
#include <string>
#include <fstream>
#include "21 workManager.h"

using namespace std;


void main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.show_menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // 退出系统
			wm.exit_system();
			break;
		case 1: // 添加职工
			wm.add_emp();
			break;
		case 2: // 显示职工
			break;
		case 3: // 删除职工
			break;
		case 4: // 修改职工
			break;
		case 5: // 查找职工
			break;
		case 6: // 排序职工
			break;
		case 7: // 清空文件
			break;
		default:
			system("cls"); 
			break;
		}
	}

	system("pause");
}
