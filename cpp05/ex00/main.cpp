#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\033[33m" << "--- 1. Invalid grades ---" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat tooHigh("Bernd", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("Olaf", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 2. Valid bureaucrat ---" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob << std::endl;

	std::cout << "\033[33m" << std::endl << "--- 3. Increment ---" << "\033[0m" << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 4. Decrement ---" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	tim.decrementGrade();
	std::cout << tim << std::endl;
	try
	{
		tim.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
