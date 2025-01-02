#include <iostream>
#include <memory>

using namespace std;
class functor
{
	// equation y = x + 5
	int c{};
public:
	functor(int c) : c(c){	}
	int operator()(int x)
	{
		return x + c;
	}
};

int cstyle_functor(int c, int x)
{
	return x + c;
}

// functors or function objects can maintain an internal state and the object can be called like a function

int main()
{
	functor obj(5);
	cout << obj(10) << endl; // access object like a function
	int(*c_functor)(int, int) = &cstyle_functor;
	cout << (*c_functor)(5, 10) << endl;
	return 0;
}