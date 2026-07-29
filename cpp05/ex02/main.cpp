#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

static void tryExecute(Bureaucrat const &b, AForm &f)
{
	try
	{
		f.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << b.getName() << " couldn't execute " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "===== Bureaucrat grade limits =====" << std::endl;
	try { Bureaucrat tooHigh("Napoleon", 0); }
	catch (std::exception &e) { std::cout << "Error: " << e.what() << std::endl; }
	try { Bureaucrat tooLow("Peasant", 151); }
	catch (std::exception &e) { std::cout << "Error: " << e.what() << std::endl; }

	Bureaucrat boss("Ana", 1);
	Bureaucrat clerk("Jim", 150);
	Bureaucrat mid("Sam", 50);
	std::cout << boss << std::endl;
	std::cout << clerk << std::endl;
	std::cout << mid << std::endl;

	std::cout << std::endl << "===== ShrubberyCreationForm =====" << std::endl;
	ShrubberyCreationForm shrub("garden");
	std::cout << shrub;
	clerk.signForm(shrub);   // grade 150 vs sign grade 145 -> fail
	mid.signForm(shrub);     // grade 50 vs sign grade 145 -> success
	tryExecute(clerk, shrub); // signed, but exec grade 150 vs 137 -> fail
	tryExecute(boss, shrub);  // grade 1 -> success, creates garden_shrubbery

	std::cout << std::endl << "===== RobotomyRequestForm =====" << std::endl;
	RobotomyRequestForm robot("Bender");
	clerk.signForm(robot);   // 150 vs 72 -> fail
	mid.signForm(robot);     // 50 vs 72 -> success
	tryExecute(mid, robot);  // signed, 50 vs exec 45 -> fail
	for (int i = 0; i < 3; i++)
		tryExecute(boss, robot); // grade 1, 50/50 random outcome, run a few times

	std::cout << std::endl << "===== PresidentialPardonForm =====" << std::endl;
	PresidentialPardonForm pardon("Bob");
	tryExecute(boss, pardon); // not signed yet -> fail
	mid.signForm(pardon);    // 50 vs 25 -> fail
	boss.signForm(pardon);   // 1 vs 25 -> success
	tryExecute(mid, pardon);  // signed, 50 vs exec 5 -> fail
	tryExecute(boss, pardon); // success

	return 0;
}
