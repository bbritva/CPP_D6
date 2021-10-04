#include "main.hpp"

Data* deserialize(uintptr_t raw)
{
	return dynamic_cast<Data *>(raw);
}

uintptr_t serialize(Data* ptr)
{
	return static_cast<uintptr_t>(ptr);
}


int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	std::string str(argv[1]);
	return (0);
}
