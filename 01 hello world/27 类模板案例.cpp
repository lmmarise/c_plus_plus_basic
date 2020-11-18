#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
public:
	// ָ�������ʼ����������
	MyArray(int capacity) {
		// cout << "��ʼ��������" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->p_address = new T[this->m_capacity];
	}

	~MyArray() {
		// cout << "����" << endl;
		if (this->p_address != NULL) {
			delete[] this->p_address;
			this->p_address = NULL;
		}
	}

	// ��������
	MyArray(const MyArray& arr) {
		// cout << "��������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		// �����ռ�
		this->p_address = new T[this->m_capacity];
		// ��Դ���ݿ������µĿռ�
		for (int i = 0; i < this->m_size; i++) {
			this->p_address[i] = this->p_address[i];
		}
	}

	// ����=��ֹǳ����
	MyArray& operator=(const MyArray& arr) {
		// cout << "����ֵ" << endl;
		// �ͷ�ԭ������������
		if (this->p_address != NULL) {
			delete[] this->p_address;
			this->p_address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		// ���
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->p_address = new T[this->m_capacity];
		for (int i = 0; i < this->m_capacity; i++) {
			this->p_address[i] = arr.p_address[i];
		}
		return (*this);
	}

private:
	T* p_address;		// ָ��ָ��������ٵ���ʵ����
	int m_capacity;		// ��������
	int m_size;			// ����Ĵ�С
};


void test04() {
	MyArray<int> arr1(5);
	MyArray<int> arr2(5);
	MyArray<int> arr3(arr2);
	arr2 = arr3;
}

void main() {
	test04();
}