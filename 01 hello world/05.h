#pragma once

// ֵ����
int add(int num1, int num2) {
	return num1 + num2;
}


// ��Ҫ�޸��������е�ֵ: ��ַ����, ��ֵ���ݵ�����: ��ַ���ݲ��ᴴ����������, ֵ���ݻᴴ����������
void swap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}