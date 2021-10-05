#include "C.hpp"

C::C(){}

C::~C(){}

C::C(C &other){}

C &C::operator=(const C &other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}
