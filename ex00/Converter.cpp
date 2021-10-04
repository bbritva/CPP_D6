//
// Created by Gregorio Velva on 10/2/21.
//

#include "Converter.hpp"

Converter::Converter()
{}

Converter::~Converter()
{
}

void Converter::justDoIt(std::string str)
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
    if (lenght(str) == 3 && str[0] == '\'' && str[2] == '\'')
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
    float_value = static_cast<float>res;
    double_value = static_cast<double>res;
    if (res >= 0 && res <= 256)
        char_value = res;
    else
        char_value = 0;
}

void Converter::simpleConvert(char &res)
{
    int_value = res;
    float_value = static_cast<float>int_value;
    double_value = static_cast<double>int_value;
    char_value = res;
}

void Converter::simpleConvert(float &res)
{
    int_value = static_cast<int>res;
    float_value = res;
    double_value = static_cast<double>res;
    if (int_value >= 0 && int_value <= 256)
        char_value = int_value;
    else
        char_value = 0;
}

void Converter::simpleConvert(double &res)
{
    int_value = static_cast<int>res;
    float_value = static_cast<float>res;
    double_value = res;
    if (int_value >= 0 && int_value <= 256)
        char_value = int_value;
    else
        char_value = 0;
}