#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include<iostream>
#include <stdexcept>

class AForm;
class Bureaucrat {
	private:
    	const std::string name;
		int grade;
    public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw();
		};
		void increment();
		void decrement();
		void signForm(AForm &f);
		void executeForm(AForm const & form) const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif