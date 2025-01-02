#include <iostream>
#include <utility> // std::move

using namespace std;

class MyClass
{
	int* ptr{}; // this class takes the ownership of memory for this pointer
	int value;
public:
	// default constructor
	MyClass() : ptr(new int{}), value(0)
	{
		cout << "Default constructor" << endl;
	}
	// parameterized constructor
	MyClass(int ptr_val, int val) : ptr(new int{ ptr_val }), value(val)
	{
		cout << "Parameterized constructor" << endl;
	}
	// copy constructor
	MyClass(const MyClass& obj)
	{
		cout << "copy constructor" << endl;
		this->ptr = new int{ *(obj.ptr) };
		this->value = obj.value;
	}
	// move constructor
	MyClass(MyClass &&obj) noexcept
	{
		cout << "move constructor" << endl;
		this->ptr = obj.ptr;
		this->value = obj.value;
		obj.ptr = nullptr;
	}
	// copy assignment
	MyClass& operator=(const MyClass& obj)
	{
		cout << "copy assignment" << endl;
		if (&obj == this)
			return *this;
		delete this->ptr;
		this->ptr = new int{ *(obj.ptr) };
		this->value = obj.value;
		return *this;
	}
	// move assignment
	MyClass& operator=(MyClass &&obj) noexcept
	{
		cout << "move assignment" << endl;
		if (&obj == this)
			return *this;
		delete this->ptr;
		this->ptr = obj.ptr;
		this->value = obj.value;
		obj.ptr = nullptr;
		return *this;
	}
	// destructor
	~MyClass()
	{
		cout << "Destructor" << endl;
		delete ptr;
	}
	// display
	void display()
	{
		cout << "the pointer value is : " << *(this->ptr) << endl;
		cout << "the member values is : " << this->value << endl;
	}
};

MyClass create_obj(int d1, int d2)
{
	MyClass obj(d1, d2); // parameterisezd constructor
	return obj; // move constructor, destructor
}

int main()
{
	///// default constructor
	//MyClass obj1;
	//obj1.display();

	///// parameterised constructor
	//MyClass obj2(10, 20);
	//obj2.display();

	//// copy constructor
	//MyClass obj3 = obj2;
	//obj3.display();

	//// move constructor
	//MyClass obj4 = std::move(obj2);
	//obj4.display();
	//// dont use obj2 anymore

	//// copy assignment
	//MyClass obj5;
	//obj5 = obj3;
	//obj5.display();


	//// move assignment
	//MyClass obj6;
	//obj6 = std::move(obj3);
	//obj6.display();

	// revalue return by function
	// o1 = create_obj(10, 30); // 

	MyClass o2; // default constructor
	o2 = create_obj(20, 20); // assignment



	return 0;
}