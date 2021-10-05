/**
At least:
- default constructor
- copy constructor
- assignation operator overload
- destructor.
 */

#ifndef C_HPP
#define C_HPP

#include <cstdlib>

#include "Base.hpp"

class C : public Base
{
public:
	C();
	~C();
};

#endif //C_HPP
