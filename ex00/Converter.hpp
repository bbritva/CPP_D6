#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits.h>
#include <stdint.h>

#define INT_OK 1
#define CHAR_OK 1 << 1

class Converter
{
private:
  Converter();

	char	char_value;
	int		int_value;
	float	float_value;
	double	double_value;
	bool	isValid;
  uint8_t flags;

	void simpleConvert(double &res);


public:
	Converter(std::string str);
	Converter(Converter &other);

  uint8_t getFlags() const;

  Converter& operator=(Converter const &other);

  char getCharValue() const;
  int getIntValue() const;
  float getFloatValue() const;
  bool getIsValid() const;

  double getDoubleValue() const;

  virtual ~Converter();

};

std::ostream& operator<<(std::ostream &stream, const Converter &conv);


#endif //CONVERTER_HPP
