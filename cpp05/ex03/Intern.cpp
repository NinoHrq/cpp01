#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm* makeShrub(const std::string& target) {return new ShrubberyCreationForm(target);}
static AForm* makeRobo(const std::string& target) {return new RobotomyRequestForm(target);}
static AForm* makePres(const std::string& target) {return new PresidentialPardonForm(target);}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creator[3])(const std::string&) = {
        &makeShrub,
        &makeRobo,
        &makePres
    };

    for(int i = 0; i < 3; ++i)
    {
        if(formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creator[i](target);
        }
    }
    std::cout << "Intern couldn't create " << formName << " .(unknown form)" << std::endl;
    return NULL;
}
