#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat persone("ayoub", 2);
		persone.decrementGrade();
		std::cout << persone << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}
