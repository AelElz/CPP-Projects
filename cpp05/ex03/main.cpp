#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// A grade outside [1, 150] throws from the constructor, so the object is
	// never created and main has to catch it.
	std::cout << "===== Invalid grades =====" << std::endl;
	try
	{
		Bureaucrat napoleon("Napoleon", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "grade 0   -> " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat peasant("Peasant", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "grade 151 -> " << e.what() << std::endl;
	}

	// Grade 1 is the highest and 150 the lowest, so incrementing makes the
	// number go down. Crossing either bound throws.
	std::cout << std::endl << "===== Increment / decrement =====" << std::endl;
	Bureaucrat best("Best", 1);
	Bureaucrat worst("Worst", 150);
	worst.incrementGrade();
	std::cout << worst << std::endl;
	try
	{
		best.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "grade 1, incremented   -> " << e.what() << std::endl;
	}
	try
	{
		worst.decrementGrade();
		worst.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "grade 150, decremented -> " << e.what() << std::endl;
	}

	// Jim can do nothing, Sam can sign the easy forms, Ana can do everything.
	std::cout << std::endl << "===== The bureaucrats =====" << std::endl;
	Bureaucrat jim("Jim", 150);
	Bureaucrat sam("Sam", 50);
	Bureaucrat ana("Ana", 1);
	std::cout << jim << std::endl;
	std::cout << sam << std::endl;
	std::cout << ana << std::endl;

	// signForm() and executeForm() print their own errors, so from here on
	// main needs no try/catch.
	std::cout << std::endl << "===== ShrubberyCreationForm (145 / 137) =====" << std::endl;
	ShrubberyCreationForm shrub("garden");
	std::cout << shrub;
	ana.executeForm(shrub);   // not signed yet -> fail
	jim.signForm(shrub);      // 150 vs 145 -> fail
	sam.signForm(shrub);      // 50 vs 145 -> signed
	jim.executeForm(shrub);   // 150 vs 137 -> fail
	sam.executeForm(shrub);   // 50 vs 137 -> writes garden_shrubbery

	std::cout << std::endl << "===== RobotomyRequestForm (72 / 45) =====" << std::endl;
	RobotomyRequestForm robot("Bender");
	jim.signForm(robot);      // 150 vs 72 -> fail
	sam.signForm(robot);      // 50 vs 72 -> signed
	sam.executeForm(robot);   // 50 vs 45 -> fail
	ana.executeForm(robot);   // 1 vs 45 -> drills, then succeeds or fails 50/50
	ana.executeForm(robot);

	std::cout << std::endl << "===== PresidentialPardonForm (25 / 5) =====" << std::endl;
	PresidentialPardonForm pardon("Arthur");
	
	sam.signForm(pardon);     // 50 vs 25 -> fail
	ana.signForm(pardon);     // 1 vs 25 -> signed

	sam.executeForm(pardon);  // 50 vs 5 -> fail
	ana.executeForm(pardon);  // 1 vs 5 -> pardoned

	// Same call three times, three different actions: execute() is written
	// once in the abstract base, but the action comes from the real type.
	std::cout << std::endl << "===== Same call, three behaviours =====" << std::endl;
	AForm *forms[3];
	forms[0] = &shrub;
	forms[1] = &robot;
	forms[2] = &pardon;
	for (int i = 0; i < 3; i++)
		ana.executeForm(*forms[i]);

	return 0;
}
