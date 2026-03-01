/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:33:43 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 00:22:50 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
    private :
    T                   *arr;
    unsigned int        sz;
    
    public :
    Array();
    Array(unsigned int n);
    Array(Array const &copy);
    ~Array();

    Array &operator=(Array const &copy);
    T &operator[](unsigned int i);
    const T &operator[](unsigned int i) const;

    unsigned int    size() const;
};

#include "Array.tpp"

#endif