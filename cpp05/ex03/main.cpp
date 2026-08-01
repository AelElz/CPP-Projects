#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::cout << "\033[33m" << "--- 1. Invalid grades ---" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat tooHigh("Bro", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("GGbro", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
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
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "--- 3. Sign and execute ---" << "\033[0m" << std::endl;
	Bureaucrat jim("Jim", 150);
	Bureaucrat ana("Ana", 1);
	ShrubberyCreationForm shrub("garden");

	std::cout << shrub;
	ana.executeForm(shrub);
	jim.signForm(shrub);
	ana.signForm(shrub);
	ana.executeForm(shrub);

	std::cout << "\033[33m" << std::endl << "--- 4. Polymorphism ---" << "\033[0m" << std::endl;
	srand(time(NULL));
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur");
	AForm *forms[2] = {&robot, &pardon};

	int i = 0;
	while (i < 2)
	{
		ana.signForm(*forms[i]);
		ana.executeForm(*forms[i]);
		i++;
	}

	std::cout << "\033[33m" << std::endl << "--- 5. Intern ---" << "\033[0m" << std::endl;
	Intern someRandomIntern;
	AForm *made;

	made = someRandomIntern.makeForm("Coffee", "Ana");
	if (made == NULL)
		std::cout << "no form created" << std::endl;

	made = someRandomIntern.makeForm("RobotomyRequestForm", "World");
	std::cout << "\n";
	if (made != NULL)
	{
		ana.signForm(*made);
		ana.executeForm(*made);
		delete made;
	}
}
