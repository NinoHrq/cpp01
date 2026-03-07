/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:30 by marvin            #+#    #+#             */
/*   Updated: 2026/03/07 22:08:35 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f("TaxForm", 50, 20);
        std::cout << f << std::endl;

        Bureaucrat b("Bob", 161);
        b.signForm(f);
        std::cout << f << std::endl;

        Bureaucrat a("Alice", 1);
        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}