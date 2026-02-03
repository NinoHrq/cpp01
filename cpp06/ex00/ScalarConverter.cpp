#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iostream>
#include <cctype>
#include <cmath>
#include <limits>

void ScalarConverter::convert(std::string const & literal){
    if(literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
    {
        if(literal == "nan" || literal == "nanf"){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if(literal == "+inf" || literal == "+inff"){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if(literal == "-inf" || literal == "-inff"){
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;}
        return;
    }

    double value;

    if((literal.size()  == 3) && (literal[0] == '\'') && (literal[2] == '\''))
    {
        if(!std::isprint(literal[1]))
            return;
        else
            value = static_cast<double>(literal[1]); 
    }
    else{
        bool hasF = false;

        if(literal.size() > 1 && literal[literal.size() - 1] == 'f')
            hasF = true;

        std::string num;

        if(hasF == true)
            num = literal.substr(0, literal.size() - 1);
        else
            num = literal;
        if(num == "" || num == "+" || num == "-" || num == ".")
            return;

        char* end = 0;
        errno = 0;
        value = std::strtod(num.c_str(), &end);

        if(end == num.c_str())
            return;
        if (*end != '\0')
            return;
        if(errno == ERANGE) 
            return;

        int dtype;

        if(hasF)
            dtype = 1;
        else if(num.find('.') != std::string::npos)
            dtype = 2;
        else 
            dtype = 0;
        if(std::isnan(value) || std::isinf(value))
            std::cout << "char: impossible" << std::endl;
        else if(value < 0 || value > 127)
            std::cout << "char: impossible" << std::endl;
        else{
            char c = static_cast<char>(value);
            if(!std::isprint(c))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << c << "'" << std::endl;}


        if(std::isnan(value) || std::isinf(value))
            std::cout << "int: impossible" << std::endl;
        else if(value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else{
            int i = static_cast<int>(value);
            std::cout << "int: " << i << std::endl;} 


        if(std::isnan(value))
            std::cout << "float: nanf" << std::endm;
        else if (std::isinf(value))
        {
            if (value > 0)
                std::cout << "float: +inff" << std::endl;
            else
                std::cout << "float: -inff" << std::endl;
        }
        else{
            float f = static_cast<float>(value);
            if(value == static_cast<int>(value))
                std::cout << "float: " << f << ".0f" << std::endl;
            else
                std::cout << "float: " << f << "f" << std::endl;}


        if(std::isnan(value))
            std::cout << "double: nanf" << std::endm;
        else if (std::isinf(value))
        {
            if (value > 0)
                std::cout << "double: +inf" << std::endl;
            else
                std::cout << "double: -inf" << std::endl;
        }
        else{
            double d = static_cast<double>(value);
            if(value == static_cast<int>(value))
                std::cout << "double: " << d << ".0" << std::endl;
            else
                std::cout << "double: " << d << std::endl;}
}

//ERANGE si jms overflow
//strtod = convertisseur char* en double
//strtod ne comprends que les char* dc on use c_str pour transformer std::string en char*
//substr retourne la chaine de char a partir de start jusqu'à end (ici on enlève f)
//std::string::npos ==> pas trouvé