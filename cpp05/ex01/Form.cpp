#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _sign_grade(150), _execute_grade(150) {}

Form::Form(const std::string name, const int sign_grade, const int execute_grade)
	: _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}
	
Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {}

Form &Form::operator=(const Form &other)
{
	_is_signed = other._is_signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _is_signed;
}

int Form::getGrade() const
{
	return _sign_grade;
}

int Form::getExecuteGrade() const
{
	return _execute_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

std::ostream &operator<<(std::ostream &os, Form const &b)
{
	os << "Name: " << b.getName() << " isSigned: " << b.getSign() << " SignGrade: " << b.getGrade() << " ExecuteGrade: " << b.getExecuteGrade() << std::endl;
	return os;
}
