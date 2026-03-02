/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:37:06 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 15:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    auto i = std::find(container.begin(), container.end(), value);
    return(i);
}