#include <iostream>
#include <string>

using namespace std;


// STL����: ��������㷺��һЩ���ݽṹʵ�ֳ�����
// ����ʽ����: ǿ��ֵ����������ʽ�����е�ÿ��Ԫ�ؾ��й̶���λ�á�
// ����ʽ����: �������ṹ����Ԫ��֮��û���ϸ�������ϵ�˳���ϵ��

// �㷨: ����֮�ⷨҲ
// ���޵Ĳ��裬����߼�����ѧ�ϵ����⣬��һ��ѧ�����ǽ����㷨(Algorithmsi�㷨��Ϊ:�ʱ��㷨�ͷ��ʱ��㷨��
// �ʱ��㷨 : ��ָ��������л���������ڵ�Ԫ�ص����ݡ����翽�����滻��ɾ���ȵ�
// ���ʱ��㷨 : ��ָ��������в�����������ڵ�Ԫ�����ݣ�������ҡ�������������Ѱ�Ҽ�ֵ�ȵ�


// ������:�������㷨֮��ճ�ϼ���
// �ṩһ�ַ�����ʹ֮�ܹ�����Ѱ��ĳ�����������ĸ���Ԫ�أ��������豩¶���������ڲ���ʾ��ʽ��
// ÿ�����������Լ�ר���ĵ�����, ������ʹ�÷ǳ�������ָ�룬��ѧ�׶����ǿ��������������Ϊָ�롣


#include <vector>

void main() {
	// ���ݴ�������
	vector<int> arr1;
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);

	// ������������������
	vector<int>::iterator it_begin = arr1.begin();	// ָ�������һ��Ԫ��
	vector<int>::iterator it_end = arr1.end();		// ָ���������һ��Ԫ�ص���һ��λ��

	// ������ʽ
	while (it_begin != it_end) {
		cout << *it_begin << endl;
		it_begin++;
	}
}