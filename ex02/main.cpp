#include <sys/time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, nullptr);
	srand(static_cast<unsigned int>(curr_time.tv_usec));
	switch (rand() % 3)
	{
		case 0:
		{
			std::cout << "A" << CREATE;
			return new A();
		}
		case 1:
		{
			std::cout << "B" << CREATE;
			return new B();
		}
		default:
		{
			std::cout << "C" << CREATE;
			return new C();
		}
	}
}

void identify(Base* p){
	Base *base;

	base = dynamic_cast<A*>(p);
	if (base)
		std::cout << "A" << IDENTIFY;
	base = dynamic_cast<B*>(p);
	if (base)
		std::cout << "B" << IDENTIFY;
	base = dynamic_cast<C*>(p);
	if (base)
		std::cout << "C" << IDENTIFY;
}

void identify(Base& p){
	Base base;
	try
	{
		base = dynamic_cast<A&>(p);
		std::cout << "A" << IDENTIFY;
	}
	catch (std::bad_cast& bce)
	{}
	try
	{
		base = dynamic_cast<B&>(p);
		std::cout << "B" << IDENTIFY;
	}
	catch (std::bad_cast& bce)
	{}
	try
	{
		base = dynamic_cast<C&>(p);
		std::cout << "C" << IDENTIFY;
	}
	catch (std::bad_cast& bce)
	{}
}

int main()
{
	Base *p;
	for (int i = 0; i < 15; ++i)
	{
		p = generate();
		identify(p);
		delete p;
	}
	for (int i = 0; i < 15; ++i)
	{
		p = generate();
		identify(*p);
		delete p;
	}
}
