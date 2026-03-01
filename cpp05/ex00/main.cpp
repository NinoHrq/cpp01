/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:45:15 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 18:10:34 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int	main()
{
try { Bureaucrat x("X", 0); }
catch (const std::exception& e) { std::cout << "0 -> " << e.what() << "\n"; }

try { Bureaucrat y("Y", 151); }
catch (const std::exception& e) { std::cout << "151 -> " << e.what() << "\n"; }

// test decrement à 150
try { Bureaucrat z("Z", 150); z.decrement(); }
catch (const std::exception& e) { std::cout << "150 dec -> " << e.what() << "\n"; }

try { Bureaucrat a("A", 42); Bureaucrat b(a); std::cout << b << "\n"; }
catch (const std::exception& e) { std::cout << "copy -> " << e.what() << "\n"; }

}