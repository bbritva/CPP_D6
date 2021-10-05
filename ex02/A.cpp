#include "A.hpp"

A::A(){}

A::~A(){}

A::A(A &other){}

A &A::operator=(const A &other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}
