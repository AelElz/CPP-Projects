#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\033[33m" << "--- 1. Invalid grades ---" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat tooHigh("Bro", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("GGbro", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 2. Increment / decrement ---" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	bob.incrementGrade();
	std::cout << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 3. Invalid form grades ---" << "\033[0m" << std::endl;
	try
	{
		Form bad("Bad Form", 0, 40);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Form bad("Bad Form", 50, 200);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 4. Signing ---" << "\033[0m" << std::endl;
	Form taxForm("Tax Form", 50, 40);
	Bureaucrat jim("Jim", 90);
	Bureaucrat ana("Ana", 30);

	std::cout << taxForm;
	jim.signForm(taxForm);
	ana.signForm(taxForm);
	std::cout << taxForm;
}
