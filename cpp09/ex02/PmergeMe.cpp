/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:26:19 by marvin            #+#    #+#             */
/*   Updated: 2026/03/04 22:08:46 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

#include <vector>
#include <set>
#include <deque>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include <cctype>

static std::vector<int> sortVecFjohnson(const std::vector<int> &in);
static std::deque<int>  sortDeqFjohnson(const std::deque<int> &in);

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::isAllDigits(const std::string &s)
{
    if(s.empty())
        return false;
    
    for (std::string::size_type i = 0; i < s.size(); i++)
    {
        if(!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }    
    return true;
}

int PmergeMe::parsePositiveInt(const std::string &s)
{
    if(!isAllDigits(s))
        throw std::runtime_error(std::string("Error : not a number: ") + s);
    
    errno = 0;
    char *end = 0;
    long v = strtol(s.c_str(), &end, 10);
    
    if(errno != 0)
        throw std::runtime_error(std::string("Error : errno != 0 (overflow/underflow): ") + s);
    else if(end == s.c_str())
        throw std::runtime_error(std::string("Error : no numbers to read: ") + s);
    else if (*end != '\0')
        throw std::runtime_error(std::string("Error : char after numbers: ") + s);
    else if (v <= 0 || v > INT_MAX)
        throw std::runtime_error(std::string("Error : Only positives int <= INT_MAX: ") + s);
    else
        return(static_cast<int>(v));
}

void PmergeMe::verif(int ac, char **av)
{
    std::set<int> seen;

    for (int i = 1; i < ac; ++i)
    {
        const std::string token(av[i]);

        int value = parsePositiveInt(token);
        if(!seen.insert(value).second)
           throw std::runtime_error(std::string("Error : No duplicates ") + token); 
        _vec.push_back(value);
        _deq.push_back(value);
    }
}

static double elapsedT (clock_t start, clock_t end)
{
    return((double)(end - start) * 1000000.0 / (double)CLOCKS_PER_SEC);
}

static void makePairsVec(const std::vector<int> &in, std::vector< std::pair<int,int> > &pairs, bool &haselmtiso, int &elmtiso)
{
    pairs.clear();
    haselmtiso = false;

    for(std::size_t i = 0; i < in.size(); i += 2)
    {
        if(i + 1 < in.size())
        {
            int a = in[i];
            int b = in[i + 1];
            
            if(a < b)
                pairs.push_back(std::make_pair(a,b));
            else
                pairs.push_back(std::make_pair(b,a));
        }
        else
            haselmtiso = true;
            elmtiso = in[i];        
    }
}

static void makePairsDeq(const std::deque<int> &in, std::vector< std::pair<int,int> > &pairs, bool &haselmtiso, int &elmtiso)
{
    pairs.clear();
    haselmtiso = false;

    for(std::size_t i = 0; i < in.size(); i += 2)
    {
        if(i + 1 < in.size())
        {
            int a = in[i];
            int b = in[i + 1];
            
            if(a < b)
                pairs.push_back(std::make_pair(a,b));
            else
                pairs.push_back(std::make_pair(b,a));
        }
        else
            haselmtiso = true;
            elmtiso = in[i];        
    }
}

static std::vector<std::size_t> jacobsthalIndices(std::size_t n)
{
    std::vector<std::size_t> order;
    if (n == 0)
        return order;

    order.push_back(0);

    std::size_t j0 = 0;
    std::size_t j1 = 1;

    std::size_t prev = 1;

    while (prev < n)
    {
        std::size_t j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;

        std::size_t cur = j2;
        if (cur > n)
            cur = n;

        for (std::size_t i = cur; i > prev; --i)
            order.push_back(i - 1);

        prev = cur;
    }
    return order;
}

static void buildMainChainVec(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &mainChain)
{
    std::vector<int> larges;
    larges.reserve(pairs.size());

    for (std::size_t i = 0; i < pairs.size(); ++i)
        larges.push_back(pairs[i].second);

    larges = sortVecFjohnson(larges);

    mainChain = larges;
}

static void buildMainChainDeq(const std::vector< std::pair<int,int> > &pairs, std::deque<int> &mainChain)
{
    std::deque<int> larges;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        larges.push_back(pairs[i].second);

    larges = sortDeqFjohnson(larges);

    mainChain = larges;
}


static void insertSmallsVec(const std::vector< std::pair<int,int> > &pairs, std::vector<int> &mainChain, bool haselmtiso, int elmtiso)
{
    std::vector<std::size_t> order = jacobsthalIndices(pairs.size());
    for(std::size_t k = 0; k < order.size(); ++k)
    {
        std::size_t i = order[k];
        int small = pairs[i].first;
        int large = pairs[i].second;

        std::vector<int>::iterator itL = std::find(mainChain.begin(), mainChain.end(), large);
        if(itL == mainChain.end())
            itL = mainChain.end();

        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), itL, small);
        mainChain.insert(pos, small);
    }
    if(haselmtiso)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), elmtiso);
        mainChain.insert(pos, elmtiso);   
    }
}

static void insertSmallsDeq(const std::vector< std::pair<int,int> > &pairs, std::deque<int> &mainChain, bool haselmtiso, int elmtiso)
{
    std::vector<std::size_t> order = jacobsthalIndices(pairs.size());
    for(std::size_t k = 0; k < order.size(); ++k)
    {
        std::size_t i = order[k];
        int small = pairs[i].first;
        int large = pairs[i].second;

        std::deque<int>::iterator itL = std::find(mainChain.begin(), mainChain.end(), large);
        if(itL == mainChain.end())
            itL = mainChain.end();

        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), itL, small);
        mainChain.insert(pos, small);
    }
    if(haselmtiso)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), elmtiso);
        mainChain.insert(pos, elmtiso);   
    } 
}

static std::vector<int> sortVecFjohnson(const std::vector<int> &in)
{
    if (in.size() <= 1)
        return in;
    std::vector< std::pair<int,int> > pairs;
    bool haselmtiso = false;
    int elmtiso = 0;

    makePairsVec(in, pairs, haselmtiso, elmtiso);
    
    std::vector<int> mainChain;
    buildMainChainVec(pairs, mainChain);

    insertSmallsVec(pairs, mainChain, haselmtiso, elmtiso);
    
    return mainChain;
}

static std::deque<int> sortDeqFjohnson(const std::deque<int> &in)
{
    if (in.size() <= 1)
        return in;
    std::vector< std::pair<int,int> > pairs;
    bool haselmtiso = false;
    int elmtiso = 0;

    makePairsDeq(in, pairs, haselmtiso, elmtiso);
    
    std::deque<int> mainChain;
    buildMainChainDeq(pairs, mainChain);

    insertSmallsDeq(pairs, mainChain, haselmtiso, elmtiso);
    
    return mainChain;
}

void PmergeMe::run()
{
    printVec(_vec, "Before: ");
    std::size_t n = _vec.size();
    clock_t start = clock();
    std::vector<int> tmpVec = sortVecFjohnson(_vec);
    clock_t end = clock();
    printVec(tmpVec, "After: ");
    double Tvec = elapsedT(start, end);
    std::cout << "Time to process a range of "<< n << " elements with std::vector : " << Tvec << " µs." << std::endl;
    
    std::size_t m = _deq.size();
    clock_t startd = clock();
    std::deque<int> tmpDq = sortDeqFjohnson(_deq);
    clock_t endd = clock();
    double Tdq = elapsedT(startd, endd);
    std::cout << "Time to process a range of "<< m << " elements with std::deque : " << Tdq << " µs." << std::endl;
}

void PmergeMe::printVec(const std::vector<int> &v, const std::string &label)
{
    std::cout << label;
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << (it + 1 != v.end() ? " " : "");
    std::cout << std::endl;
}

void PmergeMe::printDeq(const std::deque<int> &dq, const std::string &label)
{
    std::cout << label;
    for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
        std::cout << *it << (it + 1 != dq.end() ? " " : "");
    std::cout << std::endl;
}
