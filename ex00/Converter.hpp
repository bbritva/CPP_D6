#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

class Converter
{
private:
	std::string str;

	char	char_value;
	int		int_value;
	float	float_value;
	double	double_value;


public:
	Converter();
	virtual ~Converter();
	
	void justDoIt(std::string str);
	bool getValue(std::string str, int &res);
	bool getValue(std::string str, float &res);
	bool getValue(std::string str, double &res);
	bool getValue(std::string str, char &res);
	bool simpleConvert(int &res);
	bool simpleConvert(float &res);
	bool simpleConvert(double &res);
	bool simpleConvert(char &res);
};


#endif //CONVERTER_HPP
