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
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exit_system();
			break;
		case 1: // ���ְ��
			wm.add_emp();
			break;
		case 2: // ��ʾְ��
			break;
		case 3: // ɾ��ְ��
			break;
		case 4: // �޸�ְ��
			break;
		case 5: // ����ְ��
			break;
		case 6: // ����ְ��
			break;
		case 7: // ����ļ�
			break;
		default:
			system("cls"); 
			break;
		}
	}

	system("pause");
}
