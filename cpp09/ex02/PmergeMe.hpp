/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:26:15 by marvin            #+#    #+#             */
/*   Updated: 2026/03/04 16:56:15 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <string>
#include <climits>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;

    static bool isAllDigits(const std::string &s);
    static int parsePositiveInt(const std::string &s);
    static void printVec(const std::vector<int> &v, const std::string& label);
    static void printDeq(const std::deque<int> &dq, const std::string& label);

    public : 
        PmergeMe();
        ~PmergeMe();

        void verif(int ac, char **av);
        void run();
};

#endif