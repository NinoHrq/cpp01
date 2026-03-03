/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:43:30 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 17:18:23 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: ./btc [file]" << std::endl;
        return(1);
    }
    try{
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.processInput(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
