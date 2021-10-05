/**
At least:
- default constructor
- copy constructor
- assignation operator overload
- destructor.
 */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
public:
	B();
	B(B &other);
	B & operator=(B const &other);
	~B();
};

#endif //B_HPP
