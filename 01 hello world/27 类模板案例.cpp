#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
	const int unsigned default_capacity = 10;	// 数组默认初始化大小
	float unsigned load_factor = 0.75F;		// 达到该值进行扩容
public:
	// 默认容量构造
	MyArray() {
		// cout << "初始容量构造" << endl;
		this->m_capacity = default_capacity;
		this->m_size = 0;
		this->p_address = new T[this->m_capacity];
	}

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

	// 添加数据--尾插法
	void back_push(const T& val) {
		if (this->m_size >= (this->m_capacity * this->load_factor)) {
			// 达到指定容量后进行数组扩容, 每次扩容原来的1.5倍
			expansion();
		}
		this->p_address[this->m_size++] = val;
	}

	// 删除最后一个元素
	void back_pop() {
		if (this->m_size == 0) {
			return;
		}
		this->p_address[this->m_size--];
	}

	// 重载[]
	T& operator[](int index) {
		return this->p_address[index];
	}

	// 数组容量
	int get_capacity() {
		return this->m_capacity;
	}

	// 数组有效数据个数
	int get_size() {
		return this->m_size;
	}

	// 打印数组数据
	void print() {
		cout << "[";
		for (int i = 0; i < this->m_size - 1; i++) {
			cout << this->p_address[i] << ", ";
		}
		cout << this->p_address[this->m_size - 1] << "]" << endl;
	}

private:
	T* p_address;		// 指针指向堆区开辟的真实数组
	int m_capacity;		// 数组容量
	int m_size;			// 数组的大小

	// 扩容数组的长度
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

	// 缩小数组长度
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
	cout << "数组的大小为:" << arr->get_size() << endl;
	cout << "数组的容量为:" << arr->get_capacity() << endl;
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
	cout << "数组的大小为:" << arr->get_size() << endl;
	cout << "数组的容量为:" << arr->get_capacity() << endl;
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
	cout << "数组的大小为:" << arr->get_size() << endl;
	cout << "数组的容量为:" << arr->get_capacity() << endl;
}