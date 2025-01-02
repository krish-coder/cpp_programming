#include <iostream>
#include "Integer_heap.h"
using namespace std;


int main()
{
	Integer i;
	Integer i2(5);
	Integer i3(i2);
	cout << i.get_value() << endl;
	cout << i2.get_value() << endl;
	cout << i3.get_value() << endl;

	return 0;
}