#include "21 workManager.h"
#include "21 Employee.h"
#include "21 manager.h"
#include "21 Boss.h"
#include <fstream>
#include <string>

#define FILENAME "emp_file.txt"

WorkerManager::WorkerManager() {
	// 1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open) {
		// cout << "�ļ�������" << endl;
		this->m_emp_num = 0;
		this->m_emp_arr = NULL;
		// ��ʼ���ļ�״̬
		this->is_file_null = true;
		ifs.close();
		return;
	}
	// 2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_emp_num = 0;
		this->m_emp_arr = NULL;
		// ��ʼ���ļ�״̬
		this->is_file_null = true;
		ifs.close();
		return;
	}
	// 3.�ļ��������ݲ�Ϊ��
	int num = this->get_emp_num();
	this->m_emp_num = num;
	// �����������ݵ�����
	this->m_emp_arr = new Worker*[this->m_emp_num];
	// ��ʼ��
	this->init_emp();
}

// չʾ�˵�
void WorkerManager::show_menu() {
	cout << "********************************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ!**********" << endl;
	cout << "*************0.�˳��������*************" << endl;
	cout << "*************1.����ְ����Ϣ*************" << endl; 
	cout << "*************2.��ʾְ����Ϣ*************" << endl; 
	cout << "*************3.ɾ����ְְ��*************" << endl; 
	cout << "*************4.�޸�ְ����Ϣ*************" << endl;
	cout << "*************5.����ְ����Ϣ*************" << endl;
	cout << "*************6.���ձ������*************" << endl;
	cout << "*************7.��������ĵ�*************" << endl;
	cout << "********************************************" << endl; 
	cout << endl;
}

// �˳�ϵͳ
void WorkerManager::exit_system() {
	cout << "��ӭ�´ι�~~��~" << endl;
	system("pause");
	exit(0);
}

// ���Ա��
void WorkerManager::add_emp() {
	cout << "���������Ա��������:" << endl;
	int add_num = -1;
	cin >> add_num;
	if (add_num > 0) {
		// ���
		// ��������¿ռ�Ĵ�С
		int new_size = this->m_emp_num + add_num;
		// �����¿ռ�
		Worker** new_space = new Worker*[new_size];
		for (int i = 0; i < add_num; i++) {
			int id;
			string name;
			int dept_select;

			// �����û�����
			cout << "�������" << i + 1 << "����ְ���ı��:" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������:" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "����ְ���ĸ�λ���:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl; 
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

			// �浵
			new_space[this->m_emp_num + i] = worker;

			// �ͷ�ԭ�пռ�
			delete[] this->m_emp_arr;

			// ����ջ�ϵ�ָ��
			m_emp_arr = new_space;

			// ��������
			this->m_emp_num = new_size;
		}
		cout << "�ɹ����" << add_num << "��ְ��" << endl;
	}
	else {
		cout << "�������������" << endl;
	}
	// �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

// �����ļ�
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

// ͳ���ļ�������
int WorkerManager::get_emp_num() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dept_id;

	int num = 0;
	// ÿ�ζ�һ��, ÿ�е����Կո�ָ�
	while (ifs >> id && ifs >> name && ifs >> dept_id) {
		num++;
	}
	return num;
}

// ��ʼ��Ա��--���ļ��е�Ա�������ڴ�
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

// ����ļ�
void WorkerManager::clean_file() {
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		// ɾ����������
		for (int i = 0; i < this->get_emp_num; i++)
		{
			delete this->m_emp_arr[i];
			this->m_emp_arr[i] = NULL;
		}
		// ɾ��ָ�������ָ��
		delete[] this->m_emp_arr;
		this->m_emp_arr = NULL;
		this->m_emp_num = 0;
		this->is_file_null = true;

		// ��ʾ
		cout << "ɾ���ɹ�" << endl;
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