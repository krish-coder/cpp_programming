#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass(int v) : value(v) {
		std::cout << "Constructor called with value: " << value << "\n";
	}

	MyClass(const MyClass &other) {
		value = other.value;
		std::cout << "Copy Constructor called with value: " << value << "\n";
	}

	MyClass(MyClass &&other) noexcept {
		value = other.value;
		std::cout << "Move Constructor called with value: " << value << "\n";
	}

	MyClass& operator=(const MyClass &other) {
		if (this != &other) {
			value = other.value;
			std::cout << "Copy Assignment Operator called with value: " << value << "\n";
		}
		return *this;
	}

	MyClass& operator=(MyClass &&other) noexcept {
		if (this != &other) {
			value = other.value;
			std::cout << "Move Assignment Operator called with value: " << value << "\n";
		}
		return *this;
	}

private:
	int value;
};

MyClass createObject() {
	MyClass obj(10); //parameterized constructor
	return obj;  // move constructor, destructor
}

int main() {
	//MyClass obj1(20);  // parameterized Constructor called
	//obj1 = createObject();  // Move assignment

	MyClass obj2 = createObject(); // does not call move constructor again here since only one move constructor gets called (optimization)
	return 0;
}