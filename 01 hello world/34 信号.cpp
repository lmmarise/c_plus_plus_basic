#include <csignal>
#include <iostream>
#include <string>
#include <functional>
#include <exception>
#include "windows.h"


using namespace std;

// ��һ��������һ���������������źŵı�ţ��ڶ���������һ��ָ���źŴ�������ָ�롣
// void (*signal (int sig, void (*func)(int)))(int);

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // �����ر�
    // ��ֹ����  
    exit(signum);
}

// sig ��Ҫ���͵��źŵı�ţ���Щ�źŰ�����SIGINT��SIGABRT��SIGFPE��SIGILL��SIGSEGV��SIGTERM��SIGHUP
// int raise(signal sig);

void main34()
{
    int i = 3;
	// ע���ź� SIGINT ���źŴ������
    signal(SIGINT, signalHandler);
    while (true) {
        cout << "Going to sleep...." << endl;
        if (i == 3)
        {
	        raise(SIGINT);
        }
        Sleep(1000);
    }
}