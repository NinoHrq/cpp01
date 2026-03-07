/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:48 by marvin            #+#    #+#             */
/*   Updated: 2026/03/07 22:14:56 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::srand(std::time(NULL));

        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 70);
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm sh("home");
        RobotomyRequestForm   ro("Bender");
        PresidentialPardonForm pr("Arthur");

        std::cout << "\n- executer sans signer -\n";
        boss.executeForm(sh);

        std::cout << "\n- signer et essayer d'executer en ayant un grade trop bas -\n";
        boss.signForm(sh);
        low.executeForm(sh);

        std::cout << "\n- cas valide -\n";
        boss.executeForm(sh);      // crée home_shrubbery

        boss.signForm(ro);
        boss.executeForm(ro);      // 50% success/fail

        boss.signForm(pr);
        boss.executeForm(pr);      // message de pardon

        std::cout << "\n- essayer avec des grades moyens -\n";
        mid.signForm(ro);          // mid=70 peut signer robotomy (72)
        mid.executeForm(ro);       // mais exécuter robotomy demande 45 → mid échoue
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
