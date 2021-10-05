//
// Created by Gregorio Velva on 10/2/21.
//

#include "Converter.hpp"

Converter::Converter(std::string str)
{
    int     int_res;
    char    char_res;
    float   float_res;
    double  double_res;

	isValid = true;
    if (getValue(str, float_res))
        simpleConvert(float_res);
    else if (getValue(str, double_res))
        simpleConvert(double_res);
    else if (getValue(str, int_res))
        simpleConvert(int_res);
    else if (getValue(str, char_res))
        simpleConvert(char_res);
    else
        isValid = false;
    //вся конвертация при создании объекта
}

Converter::~Converter()
{
}

bool Converter::getValue(std::string str, int &res)
{
    try {
    	const char *s = str.c_str();
        res = strtod(s, NULL);
        return true;
    }
    catch(std::invalid_argument e) {
        return false;
    }
    catch(std::out_of_range e) {
        return false;
    }
}

bool Converter::getValue(std::string str, char &res)
{
    if (str.length() == 1)
    {
        res = str[0];
        return true;
    }
    return false;
}

bool Converter::getValue(std::string str, float &res)
{
    try {
        res = std::stof(str);
        return true;
    }
    catch(std::invalid_argument e) {
        return false;
    }
    catch(std::out_of_range e) {
        return false;
    }
}

bool Converter::getValue(std::string str, double &res)
{
    try {
        res = std::stod(str);
        return true;
    }
    catch(std::invalid_argument e) {
        return false;
    }
    catch(std::out_of_range e) {
        return false;
    }
}

void Converter::simpleConvert(int &res)
{
    int_value = res;
    float_value = static_cast<float>(res);
    double_value = static_cast<double>(res);
    if (res >= 0 && res <= 256)
        char_value = res;
    else
        char_value = 0;
}

void Converter::simpleConvert(char &res)
{
    int_value = res;
    float_value = static_cast<float>(int_value);
    double_value = static_cast<double>(int_value);
    char_value = res;
}

void Converter::simpleConvert(float &res)
{
    int_value = static_cast<int>(res);
    float_value = res;
    double_value = static_cast<double>(res);
    if (int_value >= 0 && int_value <= 256)
        char_value = int_value;
    else
        char_value = 0;
}

void Converter::simpleConvert(double &res)
{
    int_value = static_cast<int>(res);
    float_value = static_cast<float>(res);
    double_value = res;
    if (int_value >= 0 && int_value <= 256)
        char_value = static_cast<char>(int_value);
    else
        char_value = 0;
}

Converter::Converter() : char_value(0), int_value(0), float_value(0), double_value(0), isValid(false)
{
}

Converter::Converter(Converter &other) :  char_value(other.char_value),
                                          int_value(other.int_value),
                                          float_value(other.float_value),
                                          double_value(other.double_value),
                                          isValid(other.isValid)
{
}

std::ostream& operator<<(std::ostream &stream, const Converter &conv)
{
  if (conv.getIsValid())
  {
    stream << "int_value = " << conv.getIntValue() << "\n";
    stream << "char_value = " << conv.getCharValue() << "\n";
    stream << "float_value = " << conv.getFloatValue() << "\n";
    stream << "double_value = " << conv.getDoubleValue() << "\n";
  }
  else
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

