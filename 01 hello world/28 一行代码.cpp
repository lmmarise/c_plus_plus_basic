#include <iostream>
#include <string>
#define unix 1 
using namespace std;

void printDot() {
	int a[6] = {
		1, 2, 3, 4, 5, 6
	};
	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf(",%d" + !i, a[i]);
	}
	cout << endl;
}

/**
* const char* str = &unix["\021%six\012\0"];	// ��ȷ:ȡ����ĵڶ���Ԫ�صĵ�ַ��ֵ
* const char* str = unix["\021%six\012\0"];		// ����:�޷���char i 37��Ϊָ��
*/
int main28() { 
	// printDot();

	printf("%c", unix["\021%six\012\0"]);
	printf("%c", 2["\021%six\012\0"]);
	printf("%c", 3["\021%six\012\0"]);

	cout << endl;

	printf(&unix["\021%six\012\0"], (unix)["have"] + "fun" - 0x60); 

	cout << 97 + "fun" - 96 << endl;

	/* unix���������ڶ�Ϊһ����
	* �൱��#define unix 1     */
	printf("unix=%d\n", unix); /* =1 */

	/* ��ӡ�ַ���"un"����Ϊ"fun"�Ǹ��ַ�����
	 * "fun"+1�൱���ַ�ָ�����ƣ�ָ��"un" */
	printf("%s\n", "fun" + 1);

	/* "have"�Ǹ��ַ����飬"have"[1]���ַ�a
	 * ���97�����ڶ����ַ�'a'��ASCIIֵ��*/
	printf("%d\n", "have"[1]);
	printf("%d\n", 'a');

	/* ��C�����У�x[1] = 1[x] */
	printf("%d\n", (1)["have"]);

	/* 97 - 96 = 0x61 - 0x60 = 1 */
	printf("%d\n", (1)["have"] - 0x60);

	/* ���� "fun"+((1)["have"]-0x60) �൱��"fun"+1�����"un" */
	printf("%s\n", "fun" + ((1)["have"] - 0x60));

	/* �����е�1��unix���� */
	printf("%s\n", (unix)["have"] + "fun" - 0x60);

	/* ����Ϊ��벿�� = "un" */

	/* �������������"bcde", ��Ϊָ�붼�Ǵ�'b'��ʼ */
	printf("%s\n", "abcde" + 1);
	printf("%s\n", &"abcde"[1]);

	/* &"abcde"[1] == &(1)["abcde"]  ���һ�� */
	printf("%s\n", &(1)["abcde"]);

	/* 1��unix���� */
	printf("%s\n", &unix["abcde"]);

	/* �������"%six" ������ */
	printf("%s", &"?%six\n"[1]);

	/* ע�⣺
	   \012 = 0x0a = \n,
	   ��һ���ַ� \021 ������
	   \0 �ǿ��ַ�  */

	   /* ͬ�����"%six" ������ */
	printf("%s", &"\021%six\012\0"[1]);

	/* �൱������ */
	printf("%s", &unix["\021%six\012\0"]);

	/* ���ַ���"%six\n"������ʽ�����"ABix" */
	printf(&unix["\021%six\012\0"], "AB");

	/* �൱������ */
	printf("%six\n", "AB");

	/* ��������Ŀ������"unix" */
	printf("%six\n", (unix)["have"] + "fun" - 0x60);

	/* ���ˣ����������������"unix" */
	printf(&unix["\021%six\012\0"], (unix)["have"] + "fun" - 0x60);

	return 0;
}