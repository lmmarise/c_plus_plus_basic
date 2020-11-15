#include "21 workManager.h"
#include "21 Employee.h"
#include "21 manager.h"
#include "21 Boss.h"
#include <fstream>
#include <string>

#define FILENAME "emp_file.txt"

WorkerManager::WorkerManager() {
	// 1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open) {
		// cout << "文件不存在" << endl;
		this->m_emp_num = 0;
		this->m_emp_arr = NULL;
		// 初始化文件状态
		this->is_file_null = true;
		ifs.close();
		return;
	}
	// 2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_emp_num = 0;
		this->m_emp_arr = NULL;
		// 初始化文件状态
		this->is_file_null = true;
		ifs.close();
		return;
	}
	// 3.文件存在数据不为空
	int num = this->get_emp_num();
	this->m_emp_num = num;
	// 创建保存数据的数组
	this->m_emp_arr = new Worker*[this->m_emp_num];
	// 初始化
	this->init_emp();
}

// 展示菜单
void WorkerManager::show_menu() {
	cout << "********************************************" << endl;
	cout << "*********欢迎使用职工管理系统!**********" << endl;
	cout << "*************0.退出管理程序*************" << endl;
	cout << "*************1.增加职工信息*************" << endl; 
	cout << "*************2.显示职工信息*************" << endl; 
	cout << "*************3.删除离职职工*************" << endl; 
	cout << "*************4.修改职工信息*************" << endl;
	cout << "*************5.查找职工信息*************" << endl;
	cout << "*************6.按照编号排序*************" << endl;
	cout << "*************7.清空所有文档*************" << endl;
	cout << "********************************************" << endl; 
	cout << endl;
}

// 退出系统
void WorkerManager::exit_system() {
	cout << "欢迎下次光~~临~" << endl;
	system("pause");
	exit(0);
}

// 添加员工
void WorkerManager::add_emp() {
	cout << "请输入添加员工的数量:" << endl;
	int add_num = -1;
	cin >> add_num;
	if (add_num > 0) {
		// 添加
		// 计算添加新空间的大小
		int new_size = this->m_emp_num + add_num;
		// 开辟新空间
		Worker** new_space = new Worker*[new_size];
		for (int i = 0; i < add_num; i++) {
			int id;
			string name;
			int dept_select;

			// 设置用户数据
			cout << "请输入第" << i + 1 << "个新职工的编号:" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工的姓名:" << endl;
			cin >> name;

			cout << "请选择第" << i + 1 << "个新职工的岗位编号:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl; 
			cin >> dept_select;
			
			Worker* worker = NULL;
			switch (dept_select) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Employee(id, name, 2);
				break;
			case 3:
				worker = new Employee(id, name, 3);
				break;
			default:
				break;
			}

			// 存档
			new_space[this->m_emp_num + i] = worker;

			// 释放原有空间
			delete[] this->m_emp_arr;

			// 更新栈上的指向
			m_emp_arr = new_space;

			// 更新人数
			this->m_emp_num = new_size;
		}
		cout << "成功添加" << add_num << "名职工" << endl;
	}
	else {
		cout << "输入的数据有误" << endl;
	}
	// 清屏回到上级目录
	system("pause");
	system("cls");
}

// 保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_emp_num; i++) {
		ofs << this->m_emp_arr[i]->m_id << " "
			<< this->m_emp_arr[i]->m_name << " "
			<< this->m_emp_arr[i]->m_dept_id << endl;
	}
	ofs.close();
}

// 统计文件中人数
int WorkerManager::get_emp_num() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dept_id;

	int num = 0;
	// 每次读一行, 每行的列以空格分割
	while (ifs >> id && ifs >> name && ifs >> dept_id) {
		num++;
	}
	return num;
}

// 初始化员工--将文件中的员工放入内存
void WorkerManager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dept_id)
	{
		Worker* worker = NULL;
		if (id == 1)
		{
			worker = new Employee(id, name, dept_id);
		}
		else if (id == 2)
		{
			worker = new Manager(id, name, dept_id);
		}
		else if (id == 3)
		{
			worker = new Boss(id, name, dept_id);
		}
		this->m_emp_arr[index] = worker;
		index++;
	}

	ifs.close();
}

// 清空文件
void WorkerManager::clean_file() {
	cout << "确定清空?" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		// 删除堆区数据
		for (int i = 0; i < this->get_emp_num; i++)
		{
			delete this->m_emp_arr[i];
			this->m_emp_arr[i] = NULL;
		}
		// 删除指向堆区的指针
		delete[] this->m_emp_arr;
		this->m_emp_arr = NULL;
		this->m_emp_num = 0;
		this->is_file_null = true;

		// 提示
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
	else if(select == 2)
	{
		system("cls");
	}
}

WorkerManager::~WorkerManager() {

}