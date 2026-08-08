#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>   // <typeinfo> is forbidden by the subject

Base	*generate(void)
{
	int	r = std::rand() % 3;

	if (r == 0)
		return (new A());
	if (r == 1)
		return (new B());
	return (new C());
}

// pointer: dynamic_cast returns NULL when the type does not match
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
}

// reference: it can't be NULL, so a failed dynamic_cast throws instead
void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}
}

int	main(void)
{
	std::srand(std::time(NULL));

	int	i = 0;

	while (i < 5)
	{
		Base	*p = generate();

		std::cout << "pointer   -> ";
		identify(p);
		std::cout << "reference -> ";
		identify(*p);
		delete p;
		std::cout << std::endl;
		i++;
	}
}
