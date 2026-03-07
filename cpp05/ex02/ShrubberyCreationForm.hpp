/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:06 by marvin            #+#    #+#             */
/*   Updated: 2026/03/07 22:17:37 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	SHRUBBERYCREATIONFORM_HPP
#define	SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	private:
    	std::string _target;

    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
	
	protected:
		void executeAction() const;
};

#endif