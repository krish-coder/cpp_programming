#include <iostream>
using namespace std;

/*class handles memory- good approach */
class Owner
{
	int* ptr{};
public:
	Owner()
	{
		ptr = new int{};
	}
	~Owner()
	{
		delete ptr;
	}
	void set_value(int value)
	{
		*ptr = value;
	}
	int get_value() const
	{
		return *ptr;
	}
};
/* user takes the ownership of memory*/
class Slave
{
	int *ptr{};
public:
	Slave(int* p):ptr(p)
	{ }
	void set_value(int value)
	{
		*ptr = value;
	}
	int get_value() const
	{
		return *ptr;
	}
};
int main()
{
	Owner obj;
	cout << "owner class: " << obj.get_value() << endl;
	obj.set_value(10);
	cout << "owner class: " << obj.get_value() << endl;

	int* user_ptr = new int{};
	Slave obj2(user_ptr);
	cout << "slave class: " << obj2.get_value() << endl;
	obj2.set_value(10);
	cout << "slave class: " << obj2.get_value() << endl;
	delete user_ptr;
	return 0;
}