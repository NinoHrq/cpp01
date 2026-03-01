/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:24 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:45:25 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: name("Default"), _isSigned(false), gradeToSign(150), gradeToExecute(150)
{}


Form::Form(const std::string& s, int ts, int te) : name(s), _isSigned(false), gradeToSign(ts), gradeToExecute(te)
{
	if (ts < 1 || te < 1)
		throw GradeTooHighException();
	else if (ts > 150 || ts > 150)
		throw GradeTooLowException();
    
}

Form::Form(const Form& other)
: name(other.name), _isSigned(other._isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return(*this);
}

Form::~Form(){}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        _isSigned = true;
    else
        throw (Form::GradeTooLowException());
}

bool Form::isSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const std::string& Form::getName() const {return(name);}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form \"" << form.getName() << "\"" << " | signed: " << (form.isSigned() ? "yes" : "no") << " | gradeToSign: " << form.getGradeToSign()
        << " | gradeToExecute: " << form.getGradeToExecute();
    return os;
}
