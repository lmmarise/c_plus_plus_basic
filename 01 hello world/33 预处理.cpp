#include <iostream>
#include <string>
#include <functional>
#include <exception>

using namespace std;

// ָ���һ����ʽ: #define macro-name replacement-text
#define PI 3.14159
// �в����ĺ�
#define MIN(a,b) (a<b ? a : b)

// ��������
#ifdef NULL
#define NULL 0
#endif
#ifdef DEBUG
cerr << "Variable x = " << x << endl;
#endif

#if 0	// ʹ��if 0ע�͵�����
�����б���Ĵ���
#endif


// # �� ## �����			---- # �������� replacement-text ����ת��Ϊ���������������ַ���
#define MKSTR( x ) #x
// ## ���������������������
#define CONCAT( x, y )  x ## y


void main33()
{
	cout << "Value of PI :" << PI << endl; 
	int i, j;
	i = 100;
	j = 30;
	cout <<"��С��ֵΪ��" << MIN(i, j) << endl;

	cout << MKSTR(HELLO C++) << endl;

	int xy = 100;
	cout << CONCAT(x, y);	// �� x y����ת��Ϊ������xy
}