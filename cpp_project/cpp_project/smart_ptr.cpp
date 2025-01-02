#include <iostream>
#include <memory>

using namespace std;
class user
{
public:
	int a;
};

int main()
{
	unique_ptr<user> p1 = make_unique<user>(42);
	cout << p1 << endl;
	(*p1).a;
	p1->a;
	*p1;
	return 0;
}