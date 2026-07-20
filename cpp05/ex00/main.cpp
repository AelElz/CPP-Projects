#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat persone1("ayoub", 1);
		persone1.incrementGrade();
		std::cout << persone1 << std::endl;

		persone1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

/*
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Alice", 75);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.decrementGrade();
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 1);
		std::cout << b << std::endl;
		b.incrementGrade(); // grade 1, can't go higher -> throws
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Charlie", 200); // invalid -> throws in constructor
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
} 
*/