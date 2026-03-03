/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:39:13 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 22:47:13 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
# define RPN_HPP

#include <string>

class RPN {
    public:
        static int eval(const std::string& expr);
    private:
        RPN();
};

#endif