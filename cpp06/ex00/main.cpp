/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:42:45 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:42:46 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

static void run_test(const std::string& s)
{
    std::cout << "=============================\n";
    std::cout << "Input: " << s << "\n";
    ScalarConverter::convert(s);
    std::cout << std::endl;
}

int main()
{
    run_test("42");
    run_test("-42");
    run_test("97");      
    run_test("31");      
    run_test("128");     
    run_test("42.0");
    run_test("-4.2");
    run_test("4.2");
    run_test("42.0f");
    run_test("-4.2f");
    run_test("4.2f");
    run_test("nan");
    run_test("nanf");
    run_test("+inf");
    run_test("-inf");
    run_test("+inff");
    run_test("-inff");
    run_test("'a'");
    run_test("'Z'");
    run_test("'0'");
    run_test("' '");
    run_test("2147483647");   
    run_test("-2147483648");  
    run_test("2147483648");   
    run_test("-2147483649");  
    run_test("");
    run_test("+");
    run_test("-");
    run_test(".");
    run_test("..");
    run_test("4..2");
    run_test("4.2ff");
    run_test("abc");
    run_test("42abc");
    run_test("'ab'");
    run_test("''");
    run_test("'\\n'");
    run_test("42f");

    return 0;
}
