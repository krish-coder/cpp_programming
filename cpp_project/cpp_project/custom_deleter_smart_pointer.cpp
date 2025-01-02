#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

struct Free
{
	void operator()(int* obj)
	{
		free(obj);
		cout << "freed object" << endl;
	}

};

int main()
{
	unique_ptr<int, Free> p = { (int*)malloc(sizeof(int)), Free() };
	shared_ptr<int> p2 = { (int*)malloc(sizeof(int)), Free() };
	*p = 100;
	*p2 = 42;
	cout << *p <<" " << *p2<< endl;
	return 0;
}