#include <iostream>
using namespace std;

class SmallClass {
public:
	SmallClass(int a, int b) : x(a), y(b) { cout << "parameterized constructor" << endl; }

	SmallClass(const SmallClass &other) {
		x = other.x;
		y = other.y;
		std::cout << "Copy Constructor called\n";
	}

	SmallClass(SmallClass &&other) noexcept {
		x = other.x;
		y = other.y;
		std::cout << "Move Constructor called\n";
	}

private:
	int x, y;  // Stack-allocated members
};

SmallClass createObject() {
	SmallClass obj(5, 10); // parameterized constructor for intialization
	return obj;  // move constructor invoked since newObj (lvalue) is intialized by obj (rvalue)
}

int main() {
	SmallClass newObj = createObject();
	SmallClass newObj2(newObj); // copy constructor since newObj2 (lvalue) is initialized by newObj (lvalue)
	return 0;
}