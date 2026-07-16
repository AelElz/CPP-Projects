#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat persone1("ayoub", 150);

	try
	{
		std::cout << persone1.getName() << ", " << persone1.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
