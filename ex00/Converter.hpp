#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>

class Converter
{
private:
  Converter();
  std::string str;

	char	char_value;
	int		int_value;
	float	float_value;
	double	double_value;
	bool	isValid;

	bool getValue(std::string str, int &res);
	bool getValue(std::string str, float &res);
	bool getValue(std::string str, double &res);
	bool getValue(std::string str, char &res);
	void simpleConvert(int &res);
	void simpleConvert(float &res);
	void simpleConvert(double &res);
	void simpleConvert(char &res);


public:
	Converter(std::string str);
	virtual ~Converter();
	
	void showResult();
};


#endif //CONVERTER_HPP
