#include <string>
#include <iostream>
#include "Converter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	std::string str(argv[1]);
	Converter conv(str);
  conv.showResult();

	return (0);
}
