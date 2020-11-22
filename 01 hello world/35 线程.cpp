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

// �̵߳����к���
void* say_hello(void* args)
{
    cout << "Hello Runoob��" << endl;
    return 0;
}

HANDLE hMutex = NULL;   //������
//�̺߳���
DWORD WINAPI Fun(LPVOID lpParamter)
{
    for (int i = 0; i < 10; i++)
    {
        //����һ����������
        WaitForSingleObject(hMutex, INFINITE);
        cout << "A Thread Fun Display!" << endl;
        Sleep(100);
        //�ͷŻ�������
        ReleaseMutex(hMutex);
    }
    return 0L;//��ʾ���ص���long�͵�0
}



#if 0
HANDLE WINAPI CreateThread
( 
  __in_opt   LPSECURITY_ATTRIBUTES lpThreadAttributes, // ָ��SECURITY_ATTRIBUTES ��ָ�룬Ϊ���߳�ָ����ȫ���� 
  __in       SIZE_T dwStackSize, // ��ʼ���̶߳�ջ�ߴ� 
  __in       LPTHREAD_START_ROUTINE lpStartAddress, //�̺߳�����ָ��ĵ�ַ��ʼ����   
  __in_opt   LPVOID lpParameter, // ���̺߳������ݵĲ���   
  __in       DWORD dwCreationFlags, // �й��̵߳ı�־  
  __out_opt  LPDWORD lpThreadId //ϵͳ������̵߳�ID

 );
#endif

typedef struct MyData
{
    int val1;
    int val2;
    //char key[32];
}MYDATA; // ��typedef,MYDATA��MyData�ı���; ����MYDATA����һ������

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
    //���������ص������Ĳ������ö�λstatic����new��������
    WaitForMultipleObjects(MAX_THREADS, hThread, TRUE, INFINITE); 
    // Close all thread handles upon completion. 
    for (i = 0; i < MAX_THREADS; i++)
    {
        CloseHandle(hThread[i]);
    }
}

/*
WaitForSingleObject:
	�ȴ�һ��ָ���Ķ���(��Mutex����)��ֱ���ö����ڷ�ռ�õ�״̬(��Mutex�����ͷ�)�򳬳��趨��ʱ������
	����֮�⣬����һ���������Ƶĺ���WaitForMultipleObjects�����������ǵȴ�һ��������ָ���Ķ���
	ֱ�����еĶ����ڷ�ռ�õ�״̬���򳬳��趨��ʱ������
hHandle��
	Ҫ�ȴ���ָ������ľ����
dwMilliseconds��
	��ʱ�ļ�����Ժ���Ϊ��λ�����dwMillisecondsΪ��0����ȴ�ֱ��dwMillisecondsʱ�������������Ϊ��ռ�õ�״̬��
	���dwMillisecondsΪINFINITE���ʾ���޵ȴ���ֱ���ȴ��Ķ����ڷ�ռ�õ�״̬��
*/
void test35()
{
    //����һ�����߳�
    HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
    hMutex = CreateMutex(NULL, FALSE, "screen");
    //�ر��߳̾��--�����ͷ��߳���Դ��
    // �¿����̺߳������������������Ӧ�ùرվ�����ͷ�ϵͳ��Դ���ر��߳̾�����̵߳Ľ������û�й�ϵ��
    // ������߳�ֻ�봴���̣߳���������֮���ٲ�ѯ�����������ô��ʱ�رվ���Ǹ���ϰ�ߣ���õ�ʱû�أ��Ժ������ˣ�
    // ����й©��ϵͳ�ľ����Դ��ϵͳ������������޵ģ���
    CloseHandle(hThread);
    //���̵߳�ִ��·��
    for (int i = 0; i < 10; i++)
    {
        //������һ����������
        WaitForSingleObject(hMutex, INFINITE);
        cout << "Main Thread Display!" << endl;
        Sleep(100);
        //�ͷŻ�������
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

