#include "B.hpp"

B::B(){}

B::~B(){}

B::B(B &other){}

B &B::operator=(const B &other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}
