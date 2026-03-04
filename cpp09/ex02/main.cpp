/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:26:21 by marvin            #+#    #+#             */
/*   Updated: 2026/03/04 16:55:54 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>

int main (int ac, char **av)
{
    try
    {
        if(ac < 2)
            throw std::runtime_error("Error : Ussage : ./PmergeMe x y ...");
        
        PmergeMe pm;
        pm.verif(ac,av);
        pm.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return(1);
    }
    
    return (0);
}
