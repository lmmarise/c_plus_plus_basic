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


	// 分离了，线程的资源在线程终止后由系统回收，不分离则有创建者回收(pthread_join())
    // join()作用
    // 当前线程暂停, 等待指定的线程执行结束后, 当前线程再继续
	// detach()作用
	// 将当前线程与子线程threadObj分离，子线程threadObj交由守护线程管理，与当前线程无关
	// joinable()作用
	// 返回子线程threadObj能否join/detach--一个子线程join了之后就不能再detach，detach之后不能再join
	test_join();
	


    return 0;
}