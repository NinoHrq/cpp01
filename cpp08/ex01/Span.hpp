/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:13:25 by marvin            #+#    #+#             */
/*   Updated: 2026/03/02 17:46:31 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
#include <iterator>

class Span {
    private :
        unsigned int _N;
        std::vector<long long> _v;
    public :
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(long long n);
        long long shortestSpan() const;
        long long longestSpan() const;
        template <typename It>
        void addNumber(It first, It last);

        class FullContainerException : public std::exception
	    {
		    public:
			    virtual const char *what() const throw();
	    };

	    class NotEnoughNumbersException : public std::exception
	    {
		    public:
			    virtual const char *what() const throw();
	    };
    
};

template <typename It>
void Span::addNumber(It first, It last)
{
   std::ptrdiff_t dist = std::distance(first, last);

    if (dist < 0)
        throw FullContainerException();
    if(_v.size() + static_cast<size_t>(dist) > _N)
        throw FullContainerException();

    _v.insert(_v.end(), first, last);
}

#endif
