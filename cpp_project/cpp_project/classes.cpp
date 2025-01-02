#include <iostream>
using namespace std;
class Car
{
	int a;
	int b;
public:
	inline void print()
	{
		cout << a << " " << b << endl;
	}
	
};

int main()
{
	Car c;
	c.print();
	return 0;
}