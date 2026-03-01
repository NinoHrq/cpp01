/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:52:31 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 21:47:37 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstddef>  

template<typename T_array, typename T_fct>
void iter(T_array *array,const std::size_t length, const T_fct& fct)
{
    std::size_t i = 0;
    
    while(i < length)
    {
        fct(array[i]);
        i++;
    }       
}
/*template<typename T_array, typename T_fct>
void iter(const T_array *array, const std::size_t length, const T_fct& fct)
{
    std::size_t i = 0;
    
    while(i < length)
    {
        fct(array[i]);
        i++;
    }       
}*/

#endif