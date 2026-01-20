#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string& s, int i) : name(s), grade(i)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {grade = other.grade;}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return(*this);
}

Bureaucrat::~Bureaucrat(){}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::string Bureaucrat::getName() const {return(name);}

int Bureaucrat::getGrade() const {return(grade);}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os<<bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (os);
}

void Bureaucrat::increment()
{
	if(grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if(grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName() << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " conldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}
