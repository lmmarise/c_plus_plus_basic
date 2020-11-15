#pragma once

// 值传递
int add(int num1, int num2) {
	return num1 + num2;
}


// 需要修改主函数中的值: 地址传递, 与值传递的区别: 地址传递不会创建参数副本, 值传递会创建参数副本
void swap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}