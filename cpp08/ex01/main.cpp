/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:13:15 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 18:00:28 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

static void test()
{
    std::cout << "=== test du sujet ===" << std::endl;
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void testError()
{
    std::cout << "\n=== Test erreurs ===" << std::endl;

    try {
        Span a(10);
        a.addNumber(42);
        std::cout << a.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Erreur(shortestSpan): " << e.what() << std::endl;
    }

    try {
        Span b(2);
        b.addNumber(1);
        b.addNumber(2);
        b.addNumber(3);
    } catch (const std::exception &e) {
        std::cout << "Erreur (addNumber): " << e.what() << std::endl;
    }
}

static void testRangeIt()
{
    std::cout << "\n=== Range of iterators test ===" << std::endl;

    {
        std::vector<long long> src;
        src.push_back(10);
        src.push_back(20);
        src.push_back(21);
        src.push_back(100);

        Span sp(10);
        sp.addNumber(src.begin(), src.end());

        std::cout << "vector shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "vector longest : " << sp.longestSpan() << std::endl;
    }

    {
        std::list<long long> src;
        src.push_back(5);
        src.push_back(8);
        src.push_back(50);

        Span sp(10);
        sp.addNumber(src.begin(), src.end());

        std::cout << "list shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "list longest : " << sp.longestSpan() << std::endl;
    }
}

static void testBig()
{
    std::cout << "\n=== test 10000 ===" << std::endl;

    const unsigned int N = 20000;
    Span sp(N);

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::vector<long long> src;
    src.reserve(N);
    for (unsigned int i = 0; i < N; ++i)
        src.push_back(std::rand());

    sp.addNumber(src.begin(), src.end());

    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;
}

int main()
{
    try {
        test();
        testError();
        testRangeIt();
        testBig();
    } catch (const std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}


/*int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    return 0;
}*/
