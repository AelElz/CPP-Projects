#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int> _vec;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		void addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;
		void showNumbers() const;

		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Span is full";
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "No span to find";
				}
		};
};

#endif