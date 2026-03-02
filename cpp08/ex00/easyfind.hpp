/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:09:00 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 16:09:03 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "Easyfind.tpp"

#endif