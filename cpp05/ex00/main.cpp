/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:15 by marvin            #+#    #+#             */
/*   Updated: 2026/03/07 22:26:22 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int	main()
{
try { Bureaucrat x("X", 0); }
catch (const std::exception& e) { std::cout << e.what() << "\n"; }

try { Bureaucrat y("Y", 164); }
catch (const std::exception& e) { std::cout << e.what() << "\n"; }

try { Bureaucrat z("Z", 150); z.decrement(); }
catch (const std::exception& e) { std::cout << e.what() << "\n"; }

try { Bureaucrat a("A", 42); Bureaucrat b(a); std::cout << b << "\n"; }
catch (const std::exception& e) { std::cout << "copy -> " << e.what() << "\n"; }

}