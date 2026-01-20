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
