#include "copy_construct.h"

Integer::Integer()
{
	this->m_int = new int{ 0 };
}

Integer::Integer(int value)
{
	this->m_int = new int{value};
}

Integer::~Integer()
{
	delete this->m_int;
}

int Integer::getValue() const
{
	return *(this->m_int);
}

void Integer::setValue(int value)
{
	*m_int = value;
}


Integer::Integer(const Integer& obj)
{
	this->m_int = new int{ *(obj.m_int) };
}