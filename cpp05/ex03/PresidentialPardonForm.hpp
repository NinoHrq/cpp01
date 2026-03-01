/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:35 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:46:36 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
    	std::string _target;

    public:
        PresidentialPardonForm(const std::string& _target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
	
	protected:
		void executeAction() const;
};

#endif
