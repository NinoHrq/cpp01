/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:39 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:45:40 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;
class	AForm {
	private:
    	const std::string name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;

    public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const	AForm& other);
		AForm& operator=(const	AForm& other);
		virtual ~AForm();
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
		void	execute(Bureaucrat const & executor) const;
		class	FormNotSignedException : public std::exception
		{
			public:
			const char* what() const throw();
		};
	
	protected:
		virtual void executeAction() const = 0;
};
std::ostream &operator<<(std::ostream &os, const AForm& form);

#endif