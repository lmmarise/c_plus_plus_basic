#pragma once	// ��ֹͷ�ļ��ظ�
#include <iostream>	// ���������

using namespace std;	// ��׼�����ռ�

#include "21 Worker.h"

class WorkerManager {
public:
	WorkerManager();

	// չʾ�˵�
	void show_menu();
	// �˳�ϵͳ
	void exit_system();
	// ���Ա��
	void add_emp();

	// ����Ϊ�ļ�
	void save();
	// �ж��ļ��Ƿ�Ϊ��
	bool is_file_null;
	// ͳ���ļ�������
	int get_emp_num();
	// ��ʼ��Ա��
	void init_emp();

	// ����ļ�
	void clean_file();

	~WorkerManager();

	// ְ������
	int m_emp_num;
	// ְ������ָ��
	Worker** m_emp_arr;
};