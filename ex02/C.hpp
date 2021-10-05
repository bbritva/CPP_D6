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
	C(C &other);
	C & operator=(C const &other);
	~C();
};

#endif //C_HPP
