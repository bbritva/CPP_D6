//
// Created by Gregorio Velva on 10/2/21.
//

#include "Converter.hpp"
#include <cstring>

Converter::Converter(std::string str)
{
	double double_res;
	isValid = true;
	flags = 0;
	const char *cstr = str.c_str();
	char *ptr;
	double_res = strtod(cstr, &ptr);
	if (cstr == ptr)
	{
		isValid = false;
		std::cout << "Err\n";
	} else
		simpleConvert(double_res);
}

Converter::~Converter()
{
}

void Converter::simpleConvert(double &res)
{
	if (res <= INT32_MAX && res >= INT32_MIN)
	{
		int_value = static_cast<int>(res);
		flags |= INT_OK;
	}
	float_value = static_cast<float>(res);
	double_value = res;
	if (flags & INT_OK && int_value >= 0 && int_value <= 256)
	{
		char_value = static_cast<char>(int_value);
		flags |= CHAR_OK;
	}
}

Converter::Converter() : char_value(0), int_value(0), float_value(0),
						 double_value(0), isValid(false), flags(0)
{
}

Converter::Converter(Converter &other) : char_value(other.char_value),
										 int_value(other.int_value),
										 float_value(other.float_value),
										 double_value(other.double_value),
										 isValid(other.isValid),
										 flags(other.flags)
{
}

std::ostream &operator<<(std::ostream &stream, const Converter &conv)
{
	if (conv.getIsValid())
	{
		if (conv.getFlags() & INT_OK)
			stream << "int_value = " << conv.getIntValue() << "\n";
		else
			stream << "int_value = " << "Impossible" << "\n";
		if (conv.getFlags() & CHAR_OK)
		{
			if (std::isprint(conv.getCharValue()))
				stream << "char_value = \'" << conv.getCharValue() << "\'\n";
			else
				stream << "char_value = " << "Not printable" << "\n";
		} else
			stream << "char_value = " << "Impossible" << "\n";
		if (conv.getFloatValue() ==
			static_cast<float>(static_cast<long long>(conv.getFloatValue())))
			stream << "float_value = " << conv.getFloatValue() << ".0f\n";
		else
			stream << "float_value = " << conv.getFloatValue() << "f\n";
		if (conv.getDoubleValue() ==
			static_cast<float>(static_cast<long long>(conv.getDoubleValue())))
			stream << "double_value = " << conv.getDoubleValue() << ".0\n";
		else
			stream << "double_value = " << conv.getDoubleValue() << "\n";
	} else
		stream << "Wrong argument!\n";
	return stream;

}

Converter &Converter::operator=(const Converter &other)
{
	if (this == &other)
		return (*this);
	this->int_value = other.int_value;
	this->char_value = other.char_value;
	this->float_value = other.float_value;
	this->double_value = other.double_value;
	this->isValid = other.isValid;
	this->flags = other.flags;
	return (*this);
}

char Converter::getCharValue() const
{
	return char_value;
}

int Converter::getIntValue() const
{
	return int_value;
}

float Converter::getFloatValue() const
{
	return float_value;
}

double Converter::getDoubleValue() const
{
	return double_value;
}

bool Converter::getIsValid() const
{
	return isValid;
}

uint8_t Converter::getFlags() const
{
	return flags;
}
