#include "Integer_heap.h"
#include <iostream>
using namespace std;

Integer::Integer(): Integer(0) // delegation
{
	cout << "default constructor" << endl;
}

Integer::Integer(const Integer &obj) : Integer(*obj.m_int) // delegation
{
	cout << "copy constructor" << endl;
}

Integer::Integer(int value)
{
	cout << "Parameter constructor" << endl;
	this->m_int = new int{ value };
}



Integer::~Integer()
{
	cout << "destructor" << endl;
	delete this->m_int;
}

void Integer::set_value(int value)
{
	*(this->m_int) = value;
}

int Integer::get_value() const
{
	return *m_int;
}
