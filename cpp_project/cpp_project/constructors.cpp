#include <iostream>
using namespace std;
class MemberClass {
public:
	MemberClass() {
		std::cout << "MemberClass default constructor called." << std::endl;
	}
};
class MyClass {
public:
	static int sv;
	int a;
	MemberClass member; // This member will be initialized using its default constructor
	//MyClass() {
	//	std::cout << "MyClass default constructor called." << std::endl;
	//}
	void print() const;
};
void MyClass::print() const {
	cout << "const member function" << endl;
}
class Base {
public:
	Base() {
		std::cout << "Base default constructor called." << std::endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		std::cout << "Derived default constructor called." << std::endl;
	}
};
int MyClass::sv;

int main() {
	MyClass obj; // Will output both constructor messages
	obj.print();

	cout << MyClass::sv << endl;
	//std::cout << obj.a << std::endl;
	//Derived d;
	Base b;
	return 0;
}