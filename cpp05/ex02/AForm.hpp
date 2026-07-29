#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _execute_grade;
		virtual void	performAction() const = 0;
	public:
		AForm();
		AForm(const std::string name, const int sign_grade, const int execute_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		std::string getName() const;
		bool getSign() const;
		int getGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &b);

#endif