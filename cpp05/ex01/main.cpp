#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
Form f("TaxForm", 50, 20);
std::cout << f << std::endl;

Bureaucrat b("Bob", 60);
b.signForm(f);
std::cout << f << std::endl;

Bureaucrat a("Alice", 1);
a.signForm(f);
std::cout << f << std::endl;

}