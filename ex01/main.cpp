#include "main.hpp"

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


int main()
{
	Data *data = new Data();
	uintptr_t ptr;
	
	ptr = serialize(data);
	Data *data2 = deserialize(ptr);

	std::cout << "ptr = ";
	std::cout << data << "\n";
	std::cout << "uintptr_t ptr = ";
	std::cout << ptr << "\n";
	std::cout << "deserialized ptr = ";
	std::cout << data2 << "\n";
	delete data;
}
