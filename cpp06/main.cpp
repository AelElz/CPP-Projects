/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:00 by raveriss          #+#    #+#             */
/*   Updated: 2026/08/04 16:05:14 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclusion du fichier d'en-tête de la classe ScalarConverter */
#include "ScalarConverter.hpp"

/* Inclusion de la bibliothèque standard pour l'utilisation de flux d'entrée/sortie standard */
#include <iostream>

/* Inclusion de la bibliothèque standard pour std::ostringstream */
#include <sstream>

/* Inclusion de la bibliothèque standard pour std::string */
#include <cstring>

/* Inclusion de la bibliothèque standard pour pour INT_MIN, INT_MAX */
#include <climits>

/* Inclusion de la bibliothèque standard pour les limites des types flottants */
#include <cfloat>

/* Inclusion de la bibliothèque standard pour obtenir les limites des types numériques */
#include <limits>

/* Inclusion de la bibliothèque standard pour std::fixed, std::setprecision */
#include <iomanip>

/* Definitions of ANSI color codes for console output */
#define GREY        "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define NC          "\033[0m"

/**
 *  @brief Macro for asserting test results and displaying appropriate messages
 */
#define ASSERT_TEST(expression, message) \
	if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
	else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }

/**
 * @brief Teste la conversion d'une chaîne de caractères et compare le résultat attendu
 */
void testConversion(const std::string& input, const std::string& expectedOutput) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    ScalarConverter::convert(input);
    
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TEST(output == expectedOutput, "Input: " + input + "\n" + output);
}

/**
 * @brief Converts a numeric value to a string using std::ostringstream
 */
template<typename T>
std::string toString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

/**
 * @brief Specialization of toString for float type
 */
template<>
std::string toString<float>(float value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
}

/**
 * @brief Specialization of toString for double type
 */
template<>
std::string toString<double>(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
}

/**
 *  @brief Point d'entrée principal du programme
 */
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);

	return (0);
}