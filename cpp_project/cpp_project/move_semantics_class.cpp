#include "move_semantics_class.h"
#include <iostream>
using namespace std;

Integer::Integer()
{
	cout << "default constructor" << endl;
	this->pint = new int{ 0 };
}

Integer::Integer(int value)
{
	cout << "parameterised constructor" << endl;
	this->pint = new int{ value };
}

Integer::Integer(const Integer& obj)
{
	cout << "copy constructor" << endl;
	this->pint = new int{ *(obj.pint) };
}

Integer::Integer(Integer&& obj)
{
	cout << "move constructor" << endl;
	this->pint = (obj.pint);
	obj.pint = nullptr;
}

Integer::~Integer()
{
	cout << "destructor" << endl;
	delete this->pint;
}

Integer& Integer::operator=(Integer& obj)
{
	cout << "operator= copy" << endl;
	this->setValue(obj.getValue());
	return *this;
}

Integer& Integer::operator=(Integer&& obj)
{
	cout << "operator= move" << endl;

	if (this == &obj)
	{
		return *this;
	}
	delete this->pint;
	this->pint = obj.pint;
	obj.pint = nullptr;
	return *this;
}

int Integer::getValue()
{
	return *(this->pint);
}

void Integer::setValue(int value)
{
	*(this->pint) = value;
}