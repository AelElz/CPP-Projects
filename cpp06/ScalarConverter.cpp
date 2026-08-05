#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <iomanip>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(const std::string &literal)
{
	char *end;
	std::cout << std::fixed << std::setprecision(1);

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	if (literal == "inf" || literal == "inff"
		|| literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
		return;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
		return;
	}

	if (literal.length() == 1
		&& std::isprint(static_cast<unsigned char>(literal[0]))
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		char c = literal[0];

		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	long i = std::strtol(literal.c_str(), &end, 10);
	if (end != literal.c_str() && *end == '\0' && i >= INT_MIN && i <= INT_MAX)
	{
		std::cout << "char: ";
		if (i < 0 || i > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<int>(i)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(i) << "'\n";

		std::cout << "int: " << static_cast<int>(i) << "\n";
		std::cout << "float: " << static_cast<float>(i) << "f\n";
		std::cout << "double: " << static_cast<double>(i) << "\n";
		return;
	}

	double f = std::strtod(literal.c_str(), &end);
	if (end != literal.c_str()
		&& (*end == 'f' || *end == 'F') && *(end + 1) == '\0')
	{
		std::cout << "char: ";
		if (f < 0 || f > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<int>(f)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(f) << "'\n";

		std::cout << "int: ";
		if (f < static_cast<double>(INT_MIN) || f > static_cast<double>(INT_MAX))
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(f) << "\n";

		std::cout << "float: ";
		if (f > FLT_MAX)
			std::cout << "+inff\n";
		else if (f < -FLT_MAX)
			std::cout << "-inff\n";
		else
			std::cout << static_cast<float>(f) << "f\n";

		std::cout << "double: " << f << "\n";
		return;
	}

	double d = std::strtod(literal.c_str(), &end);
	if (end != literal.c_str() && *end == '\0')
	{
		std::cout << "char: ";
		if (d < 0 || d > 127)
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<int>(d)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(d) << "'\n";

		std::cout << "int: ";
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(d) << "\n";

		std::cout << "float: ";
		if (d > FLT_MAX)
			std::cout << "+inff\n";
		else if (d < -FLT_MAX)
			std::cout << "-inff\n";
		else
			std::cout << static_cast<float>(d) << "f\n";

		std::cout << "double: " << d << "\n";
		return;
	}

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}