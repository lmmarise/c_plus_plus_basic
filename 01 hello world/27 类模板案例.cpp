#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
	const int unsigned default_capacity = 10;	// ����Ĭ�ϳ�ʼ����С
	float unsigned load_factor = 0.75F;		// �ﵽ��ֵ��������
public:
	// Ĭ����������
	MyArray() {
		// cout << "��ʼ��������" << endl;
		this->m_capacity = default_capacity;
		this->m_size = 0;
		this->p_address = new T[this->m_capacity];
	}

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

	// �������--β�巨
	void back_push(const T& val) {
		if (this->m_size >= (this->m_capacity * this->load_factor)) {
			// �ﵽָ�������������������, ÿ������ԭ����1.5��
			expansion();
		}
		this->p_address[this->m_size++] = val;
	}

	// ɾ�����һ��Ԫ��
	void back_pop() {
		if (this->m_size == 0) {
			return;
		}
		this->p_address[this->m_size--];
	}

	// ����[]
	T& operator[](int index) {
		return this->p_address[index];
	}

	// ��������
	int get_capacity() {
		return this->m_capacity;
	}

	// ������Ч���ݸ���
	int get_size() {
		return this->m_size;
	}

	// ��ӡ��������
	void print() {
		cout << "[";
		for (int i = 0; i < this->m_size - 1; i++) {
			cout << this->p_address[i] << ", ";
		}
		cout << this->p_address[this->m_size - 1] << "]" << endl;
	}

private:
	T* p_address;		// ָ��ָ��������ٵ���ʵ����
	int m_capacity;		// ��������
	int m_size;			// ����Ĵ�С

	// ��������ĳ���
	void expansion() {
		int new_m_capacity = this->m_capacity + (this->m_capacity >> 1);
		T* new_p_address = new T[new_m_capacity];
		for (int i = 0; i < this->m_capacity; i++) {
			new_p_address[i] = this->p_address[i];
		}
		delete[] this->p_address;
		this->m_capacity = new_m_capacity;
		this->p_address = new_p_address;
	}

	// ��С���鳤��
	void reduce() {
		int new_m_capacity = this->m_capacity >> 1;
		T* new_p_address = new T[new_m_capacity];
		for (int i = 0; i < this->m_capacity; i++) {
			new_p_address[i] = this->p_address[i];
		}
		delete[] this->p_address;
		this->m_capacity = new_m_capacity;
		this->p_address = new_p_address;
	}
};


void test04() {
	MyArray<int> arr1(5);
	MyArray<int> arr2(5);
	MyArray<int> arr3(arr2);
	arr2 = arr3;
}

void main27() {
	// test04();
	MyArray<int> arr[10];
	cout << "����Ĵ�СΪ:" << arr->get_size() << endl;
	cout << "���������Ϊ:" << arr->get_capacity() << endl;
	arr->back_push(1);
	arr->back_push(2);
	arr->back_push(3);
	arr->back_push(4);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(5);
	arr->back_push(6);
	arr->back_push(7);
	arr->back_push(8);
	arr->back_push(9);
	arr->back_push(10);
	arr->print();
	cout << "����Ĵ�СΪ:" << arr->get_size() << endl;
	cout << "���������Ϊ:" << arr->get_capacity() << endl;
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	arr->back_pop();
	cout << "����Ĵ�СΪ:" << arr->get_size() << endl;
	cout << "���������Ϊ:" << arr->get_capacity() << endl;
}