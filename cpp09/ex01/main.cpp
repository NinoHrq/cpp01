/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:39:15 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 23:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
        return 1;
    }

    try
    {
        int result = RPN::eval(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception&)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}