#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <thread>
#include <vector>


using namespace std;

class WorkerThread
{
public:
    void operator()()     
    {
		std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
    }
};

void my_thread()
{
	
}

void test_join()
{
	std::thread foo;
	std::thread bar(my_thread);

	std::cout << "Joinable after construction:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';	// false
	std::cout << "bar: " << bar.joinable() << '\n';	// true

	if (foo.joinable()) foo.join();
	if (bar.joinable()) bar.join();

	std::cout << "Joinable after joining:\n" << std::boolalpha;
	std::cout << "foo: " << foo.joinable() << '\n';	// false
	std::cout << "bar: " << bar.joinable() << '\n';	// false
}

int main()
{
	vector<std::thread> threadList;
    for(int i = 0; i < 10; i++)
    {
        threadList.push_back( std::thread( WorkerThread() ) );
    }
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    cout << "wait for all the worker thread to finish" << std::endl;
    for_each(threadList.begin(), threadList.end(), std::mem_fn(&thread::join));
    cout << "Exiting from Main Thread" << std::endl;


	// �����ˣ��̵߳���Դ���߳���ֹ����ϵͳ���գ����������д����߻���(pthread_join())
    // join()����
    // ��ǰ�߳���ͣ, �ȴ�ָ�����߳�ִ�н�����, ��ǰ�߳��ټ���
	// detach()����
	// ����ǰ�߳������߳�threadObj���룬���߳�threadObj�����ػ��̹߳����뵱ǰ�߳��޹�
	// joinable()����
	// �������߳�threadObj�ܷ�join/detach--һ�����߳�join��֮��Ͳ�����detach��detach֮������join
	test_join();
	


    return 0;
}