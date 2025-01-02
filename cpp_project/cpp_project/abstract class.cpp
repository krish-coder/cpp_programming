#include <iostream>
using namespace std;

class Interface
{
public:
	virtual void method1() = 0 { cout << "base class method" << endl; };
	virtual void method2() = 0 { cout << "base class method" << endl; };
};

class Implementation : public Interface
{
public:
	using Interface::method1;
	virtual void method1() override
	{
		Interface::method1();
		cout << "derived class method" << endl;
	}
	virtual void method2() override
	{
		cout << "derived class method" << endl;
	}
};

int main()
{
	Implementation i;
	i.method1();
	return 0;
}