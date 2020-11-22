#include <csignal>
#include <iostream>
#include <string>
#include <functional>
#include <exception>
#include "windows.h"


using namespace std;

// 第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。
// void (*signal (int sig, void (*func)(int)))(int);

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序  
    exit(signum);
}

// sig 是要发送的信号的编号，这些信号包括：SIGINT、SIGABRT、SIGFPE、SIGILL、SIGSEGV、SIGTERM、SIGHUP
// int raise(signal sig);

void main34()
{
    int i = 3;
	// 注册信号 SIGINT 和信号处理程序
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