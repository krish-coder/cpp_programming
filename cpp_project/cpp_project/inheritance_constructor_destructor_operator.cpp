#include <iostream>

//class Base {
//public:
//	virtual void operator()() const {
//		std::cout << "Base operator() called" << std::endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	//void operator()() const override {
//	//	std::cout << "Derived operator() called" << std::endl;
//	//}
//};

class Base 
{
	int m_a;
public:
	Base(int a): m_a(a)
	{

	}
};

class Derived : public Base {
public:
	Derived(int a) : Base(a)
	{
	}
};

int main() {
	Derived d(1);

	return 0;
}