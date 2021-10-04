#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <iostream>

struct Data{};

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);

#endif //MAIN_H
