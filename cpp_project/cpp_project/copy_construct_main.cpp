#include <iostream>
#include "copy_construct.h"
using namespace std;

int main()
{
	Integer i(5);

	// invoke default copy constructor since we have not provided one
	// scenario 1
	//Integer i2(i);
	// scenario 2 object is passed as object value
	// scenario 3 function returns an object by value
	// scenario 4 - no assignment operator implemented so compiler provided operator does shallow copy
	//i = i2;



	// deep copy vs shallow copy
	int *p1 = new int{ 5 };
	int *p2 = p1;
	int *p3 = new int{*p1};
	delete p1;
	delete p3;

	// define user defined copy constructor
	Integer i2(i);
	cout << i.getValue() << endl;
	return 0;
}