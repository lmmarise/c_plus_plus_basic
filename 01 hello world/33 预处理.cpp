#include <iostream>
#include <string>
#include <functional>
#include <exception>

using namespace std;

// 指令的一般形式: #define macro-name replacement-text
#define PI 3.14159
// 有参数的宏
#define MIN(a,b) (a<b ? a : b)

// 条件编译
#ifdef NULL
#define NULL 0
#endif
#ifdef DEBUG
cerr << "Variable x = " << x << endl;
#endif

#if 0	// 使用if 0注释掉代码
不进行编译的代码
#endif


// # 和 ## 运算符			---- # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串
#define MKSTR( x ) #x
// ## 运算符用于连接两个令牌
#define CONCAT( x, y )  x ## y


void main33()
{
	cout << "Value of PI :" << PI << endl; 
	int i, j;
	i = 100;
	j = 30;
	cout <<"较小的值为：" << MIN(i, j) << endl;

	cout << MKSTR(HELLO C++) << endl;

	int xy = 100;
	cout << CONCAT(x, y);	// 将 x y连接转换为变量名xy
}