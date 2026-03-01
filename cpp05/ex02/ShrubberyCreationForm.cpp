/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:03 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:46:04 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
    {
        AForm::operator=(other);
		_target = other._target;
    }
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void    ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out)
        return;
    
    out << "          &&& &&  & &&\n";
    out << "      && &\\/&\\|& ()|/ @, &&\n";
    out << "      &\\/(/&/&||/& /_/)_&/_&\n";
    out << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
    out << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
    out << "&&   && & &| &| /& & % ()& /&&\n";
    out << " ()&_---()&\\&\\|&&-&&--%---()~\n";
    out << "      &&     \\|||\n";
    out << "               |||\n";
    out << "               |||\n";
    out << "               |||\n";
    out << "       , -=-~  .-^- _\n";

};
