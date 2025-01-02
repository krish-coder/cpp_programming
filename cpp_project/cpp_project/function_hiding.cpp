#include <iostream>

class Base {
public:
	void display(int x) {
		std::cout << "Base class display with int: " << x << std::endl;
	}
	virtual void display(double y) {
		std::cout << "Base class display with double: " << y << std::endl;
	}
};

class Derived : public Base {
public:
	using Base::display;
	void display(double y) {
		std::cout << "Derived class display with double: " << y << std::endl;
	}
};

int main() {
	Derived derivedObj;

	// Calls the derived class version of display
	derivedObj.display(3.14); // Output: Derived class display with double: 3.14

	// The following line will cause a compilation error because the int version in Base is hidden by Derived
	derivedObj.display(5);

	Base* b = &derivedObj;
	Derived* d = static_cast<Derived*>(b);

	// To call the base class version, we need to explicitly use the base class name with scope resolution
	//derivedObj.Base::display(5); // Output: Base class display with int: 5

	return 0;
}