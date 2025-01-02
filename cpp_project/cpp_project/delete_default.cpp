#include <iostream>
#include "Integer_heap.h"
using namespace std;
class Integer
{
	int m_value {};
	static int u = 9;
public:
	Integer() = default;
	Integer(int value)
	{
		m_value = value;
	}
	Integer(const Integer&) = delete;
};

int main()
{
	Integer i; 
	Integer i2;
	Integer i3(i);

	return 0;
}