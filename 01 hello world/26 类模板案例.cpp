#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
public:
	// 指定数组初始化容量构造
	MyArray(int capacity) {
		// cout << "初始容量构造" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this->p_address = new T[this->m_capacity];
	}

	~MyArray() {
		// cout << "析构" << endl;
		if (this->p_address != NULL) {
			delete[] this->p_address;
			this->p_address = NULL;
		}
	}

	// 拷贝构造
	MyArray(const MyArray& arr) {
		// cout << "拷贝构造" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		// 创建空间
		this->p_address = new T[this->m_capacity];
		// 将源数据拷贝到新的空间
		for (int i = 0; i < this->m_size; i++) {
			this->p_address[i] = this->p_address[i];
		}
	}

	// 重载=防止浅拷贝
	MyArray& operator=(const MyArray& arr) {
		// cout << "对象赋值" << endl;
		// 释放原来堆区的数据
		if (this->p_address != NULL) {
			delete[] this->p_address;
			this->p_address = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		// 深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->p_address = new T[this->m_capacity];
		for (int i = 0; i < this->m_capacity; i++) {
			this->p_address[i] = arr.p_address[i];
		}
		return (*this);
	}

private:
	T* p_address;		// 指针指向堆区开辟的真实数组
	int m_capacity;		// 数组容量
	int m_size;			// 数组的大小
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