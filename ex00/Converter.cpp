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

bool Converter::getValue(std::string str, int &res) {
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

bool Converter::getValue(std::string str, char &res) {
    // try {
    //     // res = std::stoi(str);
    //     // return true;
    // }
    // catch(std::invalid_argument e) {
    //     // return false;
    // }
    // catch(std::out_of_range e) {
        return false;
    }
}

bool Converter::getValue(std::string str, float &res) {
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

bool Converter::getValue(std::string str, double &res) {
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
