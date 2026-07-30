#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _sign_grade(150), _execute_grade(150) {}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}
	
AForm::AForm(const AForm &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_is_signed = other._is_signed;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _is_signed;
}

int AForm::getGrade() const
{
	return _sign_grade;
}

int AForm::getExecuteGrade() const
{
	return _execute_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (_is_signed == false)
		throw FormNotSignedException();
	if (executor.getGrade() > _execute_grade)
		throw GradeTooLowException();
	performAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}

std::ostream &operator<<(std::ostream &os, AForm const &b)
{
	os << "Name: " << b.getName() << " isSigned: " << b.getSign() << " SignGrade: " << b.getGrade() << " ExecuteGrade: " << b.getExecuteGrade() << std::endl;
	return os;
}
