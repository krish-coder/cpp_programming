#include <iostream>

using namespace std;

class MyClass
{
	int &ref_value;
public:
	MyClass(int value) : ref_value(value)
	{
	}
	void display() const
	{
		cout << ref_value << endl;
	}
};

int main()
{
	// MyClass obj(2); this is a problem since the reference shall bind to a temporary value
	int num = 10;
	MyClass obj(num);
	obj.display();
	return 0;
}