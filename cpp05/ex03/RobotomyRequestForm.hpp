/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:46:41 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:46:42 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef	ROBOTOMYREQUESTFORM_HPP
#define	ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"


class	RobotomyRequestForm : public AForm {
	private:
    	std::string _target;

    public:
        RobotomyRequestForm(const std::string& _target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
	
	protected:
		void executeAction() const;
};

#endif