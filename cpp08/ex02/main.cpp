/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:04:40 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 20:35:29 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"
#include <iostream>


/*int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    return 0;
}*/


/*int main()
{
    MutantStack<int> numbers;

    // Test push
    for (int i = 1; i <= 5; ++i)
        numbers.push(i * 10);

    // Test top
    std::cout << "Top element: " << numbers.top() << std::endl;

    // Test pop
    numbers.pop();
    std::cout << "After pop, new top: " << numbers.top() << std::endl;

    // Test size
    std::cout << "Size: " << numbers.size() << std::endl;

    // Test iteration
    std::cout << "All elements:" << std::endl;
    for (MutantStack<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << std::endl;

    // Test reverse iteration
    std::cout << "Reverse order:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
        std::cout << *rit << std::endl;

    // Test copy constructor
    MutantStack<int> copy(numbers);
    std::cout << "Copy size: " << copy.size() << std::endl;

    return 0;
}*/


#include <list>

int main()
{
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "Back element: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "Size after pop_back: " << lst.size() << std::endl;

    std::cout << "Forward iteration:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Reverse iteration:" << std::endl;
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
        std::cout << *rit << std::endl;

    return 0;
}