/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:27 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:45:28 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;
class Form {
	private:
    	const std::string name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;

    public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
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
		void	beSigned(const Bureaucrat& b);
		const	std::string& getName() const;
		bool	isSigned() const;
		int		getGradeToSign() const;
		int		getGradeToExecute() const;
};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif