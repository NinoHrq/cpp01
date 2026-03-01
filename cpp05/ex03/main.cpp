/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:27 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:46:28 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    // 1) cas valide
    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    // 2) cas invalide
    AForm* f2 = intern.makeForm("coffee request", "Nino");
    return 0;
}

