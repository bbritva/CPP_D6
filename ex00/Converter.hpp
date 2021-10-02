#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

class Converter
{
public:
	Converter();
	virtual ~Converter();
	
	void justDoIt(std::string str);
};


#endif //CONVERTER_HPP
