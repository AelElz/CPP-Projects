#include <iostream>
#include <vector>
#include "Span.hpp"

void	printSpans(Span &sp) {
	try
	{
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> vec;
	int i = 0;
	while (i < 5)
	{
		vec.push_back(i * i);
		i++;
	}

	std::cout << "=== Example ===" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	printSpans(sp);

	std::cout << "\n=== not enough numbers ===" << std::endl;
	Span few(3);
	few.addNumber(42);
	printSpans(few);

	std::cout << "\n=== span already full ===" << std::endl;
	try
	{
		Span full(1);
		full.addNumber(1);
		full.addNumber(2);
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\n=== addRange ===" << std::endl;
	Span range(5);
	range.addRange(vec.begin(), vec.end());
	range.showNumbers();
	printSpans(range);

	std::cout << "\n=== addRange too big ===" << std::endl;
	try
	{
		Span small(2);
		small.addRange(vec.begin(), vec.end());
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\n=== 10000 numbers ===" << std::endl;
	Span big(10000);
	i = 0;
	while (i < 10000)
	{
		big.addNumber(i * 3);
		i++;
	}
	printSpans(big);
}
