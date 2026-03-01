/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:42:52 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

//ERANGE si jms overflow
//strtod = convertisseur char* en double
//floor retourne l'entier le plus grand inf ou égale a l'input
//strtod ne comprends que les char* dc on use c_str pour transformer std::string en char*
//substr retourne la chaine de char a partir de start jusqu'à end (ici on enlève f)
//std::string::npos ==> pas trouvé


#include "ScalarConverter.hpp"

#include <cstdlib>  
#include <cerrno>    
#include <limits>    
#include <iostream>  
#include <cctype>    
#include <cmath>     

static bool IntDouble(double v)
{
    return (v == std::floor(v));
}

static void print_char(double v)
{
    if (std::isnan(v) || std::isinf(v) || v < 0.0 || v > 127.0)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(v);
    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: '" << c << "'" << std::endl;
}

static void print_int(double v)
{
    if (std::isnan(v) || std::isinf(v)
        || v < static_cast<double>(std::numeric_limits<int>::min())
        || v > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    int i = static_cast<int>(v);
    std::cout << "int: " << i << std::endl;
}

static void print_float(double v)
{
    if (std::isnan(v))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (std::isinf(v))
    {
        if (v > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return;
    }

    float f = static_cast<float>(v);

    if (IntDouble(v))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
}

static void print_double(double v)
{
    if (std::isnan(v))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (std::isinf(v))
    {
        if (v > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return;
    }

    if (IntDouble(v))
        std::cout << "double: " << v << ".0" << std::endl;
    else
        std::cout << "double: " << v << std::endl;
}

void ScalarConverter::convert(std::string const & literal)
{
    // 1) Pseudo-littéraux (format imposé)
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    double value = 0.0;

    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        unsigned char c = static_cast<unsigned char>(literal[1]);
        if (!std::isprint(c))
            return; 
        value = static_cast<double>(literal[1]);
    }
    else
    {
        bool hasF = false;
        if (literal.size() > 1 && literal[literal.size() - 1] == 'f')
            hasF = true;
        std::string num = hasF ? literal.substr(0, literal.size() - 1) : literal;
        if (num == "" || num == "+" || num == "-" || num == ".")
            return;
        if (hasF
            && num.find('.') == std::string::npos
            && num.find('e') == std::string::npos
            && num.find('E') == std::string::npos)
            return;

        char* end = 0;
        errno = 0;
        value = std::strtod(num.c_str(), &end);

        if (end == num.c_str())
            return;
        if (*end != '\0')
            return;
        if (errno == ERANGE)
            return;
    }

    print_char(value);
    print_int(value);
    print_float(value);
    print_double(value);
}