#include "Base.hpp"

int main()
{
	int grade;
	
	grade = 56;
	Base vova("vova", grade);
	std::cout << vova;
	try
	{
		grade = 55;
		std::cout << CREATE_MSG << grade << ".\n";
		Base dima(BURO_NAME, grade);
		std::cout << dima;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		grade = -55;
		std::cout << CREATE_MSG << grade << ".\n";
		Base dima(BURO_NAME, grade);
		std::cout << dima;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		grade = 155;
		std::cout << CREATE_MSG << grade << ".\n";
		Base dima(BURO_NAME, grade);
		std::cout << dima;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	return 0;
}
