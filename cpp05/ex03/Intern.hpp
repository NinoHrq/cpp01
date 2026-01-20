#ifndef	INTERN_HPP
#define	INTERN_HPP

#include <string>

class AForm;
class	Intern {
    public:
        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
