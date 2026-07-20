#ifndef BUREAUCRAFT_HPP
#define BUREAUCRAFT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Grade is too high!"; }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Grade is too low!"; }
		};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);


#endif