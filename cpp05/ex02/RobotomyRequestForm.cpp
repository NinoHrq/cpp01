/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:57 by marvin            #+#    #+#             */
/*   Updated: 2026/03/07 22:17:45 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target)
{}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
    {
        AForm::operator=(other);
		_target = other._target;
    }
	return(*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){}

void    RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRIIILLL...DRIILLLL... *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
};



/*#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    ...
}

A METTRE DANS LE MAIN
*/