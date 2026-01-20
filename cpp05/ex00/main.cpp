#include "Bureaucrat.hpp"

int	main()
{/*
	try
	{
		Bureaucrat a("Roger", 1);
		a.increment();
        std::cout << a << std::endl;

        Bureaucrat b ("Toto", 148);
        b.decrement();
        std::cout << b << std::endl;

        Bureaucrat c ("Nino", 150);
        c.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << " " << std::endl;
	}
*/
	// 1) test grade trop haut
try { Bureaucrat x("X", 0); }
catch (const std::exception& e) { std::cout << "0 -> " << e.what() << "\n"; }

// 2) test grade trop bas
try { Bureaucrat y("Y", 151); }
catch (const std::exception& e) { std::cout << "151 -> " << e.what() << "\n"; }

// 3) test decrement à 150
try { Bureaucrat z("Z", 150); z.decrement(); }
catch (const std::exception& e) { std::cout << "150 dec -> " << e.what() << "\n"; }

// 4) test copie
try { Bureaucrat a("A", 42); Bureaucrat b(a); std::cout << b << "\n"; }
catch (const std::exception& e) { std::cout << "copy -> " << e.what() << "\n"; }

}