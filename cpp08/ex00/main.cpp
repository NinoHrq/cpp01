/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:37:03 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 16:10:28 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include<algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    const std::vector<int> v = {1,2,3};
    auto it = easyfind(v, 3);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    
    auto i = easyfind(v, 8);
    if (i == v.end())
        std::cout << "Not Found"<< std::endl;
      
    return(0);
}