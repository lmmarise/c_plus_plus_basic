#pragma once	// 防止头文件重复
#include <iostream>	// 输入输出流

using namespace std;	// 标准命名空间

#include "21 Worker.h"

class WorkerManager {
public:
	WorkerManager();

	// 展示菜单
	void show_menu();
	// 退出系统
	void exit_system();
	// 添加员工
	void add_emp();

	// 保存为文件
	void save();
	// 判断文件是否为空
	bool is_file_null;
	// 统计文件中人数
	int get_emp_num();
	// 初始化员工
	void init_emp();

	// 清空文件
	void clean_file();

	~WorkerManager();

	// 职工人数
	int m_emp_num;
	// 职工数组指针
	Worker** m_emp_arr;
};