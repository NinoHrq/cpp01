/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:09 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:46:10 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
: name("Default"), _isSigned(false), gradeToSign(150), gradeToExecute(150)
{}


AForm::AForm(const std::string& s, int ts, int te) : name(s), _isSigned(false), gradeToSign(ts), gradeToExecute(te)
{
	if (ts < 1 || te < 1)
		throw GradeTooHighException();
	else if (ts > 150 || ts > 150)
		throw GradeTooLowException();
    
}

AForm::AForm(const AForm& other)
: name(other.name), _isSigned(other._isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return(*this);
}

AForm::~AForm(){}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        _isSigned = true;
    else
        throw (AForm::GradeTooLowException());
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("The form is not signed ...");
}

const std::string& AForm::getName() const {return(name);}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw (AForm::GradeTooLowException());
    executeAction(); 
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm \"" << form.getName() << "\"" << " | signed: " << (form.isSigned() ? "yes" : "no") << " | gradeToSign: " << form.getGradeToSign()
        << " | gradeToExecute: " << form.getGradeToExecute();
    return os;
}
