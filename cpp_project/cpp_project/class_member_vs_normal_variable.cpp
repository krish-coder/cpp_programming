#include <iostream>
using namespace std;

class Myclass
{
public:
	mutable int a{};
	void change_mutable(const Myclass& obj) const
	{
		this->a = 2;
		obj.a = 5;
	}
};
int main()
{
	Myclass obj1, obj2;
	cout << obj1.a << " " << obj2.a << endl;
	obj1.change_mutable(obj2);
	cout << obj1.a << " " << obj2.a << endl;
	return 0;
}