#include <iostream>
#include "move_semantics_class.h"
using namespace std;

Integer add(Integer& a, Integer& b)
{
	Integer i; // default constructor
	i.setValue(a.getValue() + b.getValue());
	return i;  // move constructor rvalue based
}

int main()
{
	//Integer a{ 2 }, b{ 3 }; // parameterised constructor
	//Integer c{ add(a, b) };// destructor i
	//Integer d{ a }; // copy constructor lvalue based

	// pointer on stack
	int *ptr{};
	int a1 = 10;
	ptr = &a1;
	&ptr; // stack address of pointer
	ptr; &a1;
	a1; *ptr;

	int a2[]{ 4,5,6 };
	ptr = a2; ptr = &a2[0];
	&ptr;
	a2; &a2[0]; ptr;
	a2[0]; *a2; *ptr;

	// heap
	int *p1{};
	p1 = new int{}; // memory on heap
	&p1; // stack memory
	p1;
	*p1;
	delete p1;

	int *p2{};
	p2 = new int[3]{ 6,7,8 };
	&p2; // stack memory address
	p2; // heap memory of element 1
	*p2; // access the value of element 1
	delete[] p2;

	// pointer on heap
	int **ptr_ptr{};
	ptr_ptr = new int*{};
	*ptr_ptr = new int{ 9 };
	delete *ptr_ptr;
	delete ptr_ptr;

	int &ref = a2[0];
	cout << ref << endl;
	ref = 99;
	cout << a2[0] << endl;

	//d = b;
	//int **ptr = new int*;
	//int *ptr = new int{ 2 };
	//cout << **ptr << " " << *ptr << endl;
	//cout << "stack memory address of pointer to a pointer " << &ptr << endl;
	//cout << "heap memory address pointed to by pointer to a pointer " << ptr << endl;
	//cout << "value of heap memory address pointed to by pointer to a pointer " << *ptr << endl;
	//cout << "value of heap memory pointed by pointer on heap memory pointed by pointer to a pointer on stack " << **ptr << endl;
	//delete ptr;
	//delete *ptr;
	
	// destructor a
	// destructor b
	// destructor c

	return 0;
}