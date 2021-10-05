/**
At least:
- default constructor
- copy constructor
- assignation operator overload
- destructor.
 */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
public:
	A();
	A(A &other);
	A & operator=(A const &other);
	~A();
};

#endif //A_HPP
