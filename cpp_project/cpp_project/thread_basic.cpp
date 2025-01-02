#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void slow_function()
{
	cout << "start executing slow function" << endl;
	for (int i = 0; i < 1000000000; i++);
	cout << "finished executing slow function" << endl;
}

int main()
{
	vector<int> a(5, 0);
	cout << a.size() << " " << a[4] << endl;
	cout << "start main thread" << endl;
	thread new_thread(slow_function); // undetached thread is joinable and can be synchronized
	//thread new_thread2(slow_function);
	//new_thread2.detach(); // detachable thread that works asynchronously
	//slow_function();
	cout << "end main thread" << endl;
	//if (new_thread.joinable())
		//new_thread.join();
	return 0;
}