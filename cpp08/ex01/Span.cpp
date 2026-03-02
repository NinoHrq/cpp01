/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:13:21 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 17:31:01 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator =(const Span &other)
{
    if(this != &other)
    {
        _N = other._N;
        _v = other._v;
    }
    return(*this);
}

Span::~Span() {}

void Span::addNumber(long long n){
    if(_v.size() >= _N)
        throw FullContainerException();
    _v.push_back(n);
}

long long Span::longestSpan() const
{
    if(_v.size() < 2)
      throw NotEnoughNumbersException();
    std::vector<long long>::const_iterator minIt = std::min_element(_v.begin(), _v.end());
    std::vector<long long>::const_iterator maxIt = std::max_element(_v.begin(), _v.end());
    return(*maxIt - *minIt);  
}

long long Span::shortestSpan() const
{
    if(_v.size() < 2)
      throw NotEnoughNumbersException();
    std::vector<long long> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    long long minSpan = tmp[1] - tmp[0];
    for (int i = 1; i < tmp.size() - 1; i++)
    {
        long long diff = tmp[i + 1] - tmp[i];
        if(diff < minSpan)
            minSpan = diff;
    }
    return(minSpan);
}

const char *Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container");
}
