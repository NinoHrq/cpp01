/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:52:28 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 21:47:58 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& x)
{
    std::cout << x << "\n";
}

void add_one(int& x)
{
    x += 1;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    const std::size_t n = 4;

    std::cout << "Print int array:\n";
    iter(a, n, print<int>);

    std::cout << "int array (add_one):\n";
    iter(a, n, add_one);
    iter(a, n, print<int>);

    const int ca[] = {10, 20, 30};
    std::cout << "Print const int array:\n";
    iter(ca, 3, print<int>);

    std::string s[] = {"salut", "42", "cpp"};
    std::cout << "Print string array:\n";
    iter(s, 3, print<std::string>);

    return 0;
}