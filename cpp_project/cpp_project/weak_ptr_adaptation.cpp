#include <iostream>
#include <memory>
using namespace std;

class MyClass
{

public:
	MyClass()
	{
		cout << "default constructor called" << endl;
	}
	~MyClass()
	{
		cout << "detructor called" << endl;
	}
};

int main()
{
	shared_ptr<MyClass> p1 = make_shared<MyClass>();
	shared_ptr<MyClass> p2 = p1; // referece count to 2
	cout << "reference count : " << p1.use_count() << endl;
	weak_ptr<MyClass> p3 = p1;
	cout << "reference count after weak pointer : " << p1.use_count() << endl;
	p1.reset();
	cout << "reference count after deleting p1 (no destructor call before this): " << p2.use_count() << endl;
	p2.reset();
	cout << "weak ptr still alive. destructor should be called before this for p2!!" << endl; // destructor gets called before this
	cout << "reference count post deletion of memory : "<< p3.use_count() << endl; // should be zero
	p3.reset();


	// weak pointer adaptation
	cout << "--------------------- weak ptr adaptation  -----------------------------" << endl;
	shared_ptr<MyClass> p4 = make_shared<MyClass>();
	weak_ptr<MyClass> p5 = p4;
	cout << "p4 reference count : " << p4.use_count() << endl; // should be 1
	cout << "has the memory expired : " << p5.expired() << endl; // should be false
	if (!p5.expired())
	{
		auto p6 = p5.lock(); // creates a adapted new pointer
		cout << "new reference for p4 memory due to weak pointer : " << p4.use_count() << endl;
		cout << "delete p4 now" << endl;
		p4.reset();
		cout << "new reference count for p4 memory after deletion (weak-shared ptr still alive) : " << p5.use_count() << endl; // should be 1

	}
	cout << "destructor must be called before this !!" << endl;
	cout << "weak-shared ptr out of scope. reference count post deletion of memory : " << p5.use_count() << endl; // should be zero

	return 0;
}