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
        res = std::stoi(str);
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
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
    {
        res = str[1];
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

void Converter::showResult()
{
  std::cout << "int_value = " << int_value << "\n";
  std::cout << "char_value = " << char_value << "\n";
  std::cout << "float_value = " << float_value << "\n";
  std::cout << "double_value = " << double_value << "\n";

}
