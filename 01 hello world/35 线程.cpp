#include <csignal>
#include <iostream>
#include <string>
#include <functional>
#include <exception>
#include <thread>
#include <windows.h>   


using namespace std;

#define NUM_THREADS 5
#define MAX_THREADS 10

// 线程的运行函数
void* say_hello(void* args)
{
    cout << "Hello Runoob！" << endl;
    return 0;
}

HANDLE hMutex = NULL;   //互斥量
//线程函数
DWORD WINAPI Fun(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
    {
        //请求一个互斥量锁
        WaitForSingleObject(hMutex, INFINITE);
        cout << "A Thread Fun Display!" << endl;
        Sleep(100);
        //释放互斥量锁
        ReleaseMutex(hMutex);
    }
    return 0L;//表示返回的是long型的0
}



#if 0
HANDLE WINAPI CreateThread
( 
  __in_opt   LPSECURITY_ATTRIBUTES lpThreadAttributes, // 指向SECURITY_ATTRIBUTES 的指针，为新线程指定安全描述 
  __in       SIZE_T dwStackSize, // 初始化线程堆栈尺寸 
  __in       LPTHREAD_START_ROUTINE lpStartAddress, //线程函数所指向的地址起始函数   
  __in_opt   LPVOID lpParameter, // 给线程函数传递的参数   
  __in       DWORD dwCreationFlags, // 有关线程的标志  
  __out_opt  LPDWORD lpThreadId //系统分配给线程的ID

 );
#endif

typedef struct MyData
{
    int val1;
    int val2;
    //char key[32];
}MYDATA; // 用typedef,MYDATA是MyData的别名; 不用MYDATA就是一个变量

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
    MYDATA* pmd = (MYDATA*)lpParam;
    printf("%d\n", pmd->val1);
    printf("%d\n", pmd->val2);
    return 0;
}

DWORD(WINAPI* pThreadProc)(LPVOID lpParam);

void fun()
{
    pThreadProc = ThreadProc;
    MYDATA mydt[MAX_THREADS];

    HANDLE hThread[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++)
    {
        mydt[i].val1 = i;
        mydt[i].val2 = i + 1;
        hThread[i] = CreateThread(
            NULL,// default security attributes
            0,// use default stack size
            pThreadProc,// thread function
            &mydt[i],// argument to thread function
            0, // use default creation flags
            NULL);
        if (hThread[i] == NULL)
        {
            ExitProcess(i);
        }
    }
    // Wait until all threads have terminated.
    //这样传给回调函数的参数不用定位static或者new出来的了
    WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE); 
    // Close all thread handles upon completion. 
    for (i = 0; i < MAX_THREADS; i++)
    {
        CloseHandle(hThread[i]);
    }
}

/*
WaitForSingleObject:
	等待一个指定的对象(如Mutex对象)，直到该对象处于非占用的状态(如Mutex对象被释放)或超出设定的时间间隔。
	除此之外，还有一个与它类似的函数WaitForMultipleObjects，它的作用是等待一个或所有指定的对象，
	直到所有的对象处于非占用的状态，或超出设定的时间间隔。
hHandle：
	要等待的指定对象的句柄。
dwMilliseconds：
	超时的间隔，以毫秒为单位；如果dwMilliseconds为非0，则等待直到dwMilliseconds时间间隔用完或对象变为非占用的状态，
	如果dwMilliseconds为INFINITE则表示无限等待，直到等待的对象处于非占用的状态。
*/
void test35()
{
    //创建一个子线程
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    hMutex = CreateMutex(NULL, FALSE, "screen");
    //关闭线程句柄--用来释放线程资源的
    // 新开启线程后，如果不再利用其句柄，应该关闭句柄，释放系统资源。关闭线程句柄和线程的结束与否没有关系。
    // 如果主线程只想创建线程，而并不想之后再查询或操纵它，那么及时关闭句柄是个好习惯，免得当时没关，以后又忘了，
    // 于是泄漏了系统的句柄资源（系统句柄总数是有限的）。
    CloseHandle(hThread);
    //主线程的执行路径
    for (int i = 0; i < 10; i++)
    {
        //请求获得一个互斥量锁
        WaitForSingleObject(hMutex, INFINITE);
        cout << "Main Thread Display!" << endl;
        Sleep(100);
        //释放互斥量锁
        ReleaseMutex(hMutex);
    }
}

void test35_1()
{
    fun();
    getchar();
}

void main35()
{
	// test35();
	test35_1();
}

