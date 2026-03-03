/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:43:27 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 21:49:06 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
        *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
        _rates = other._rates;
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::loadDatabase(const std::string& database)
{
    std::ifstream file(database.c_str());
    if(!file.is_open())
        throw CouldNotOpenFile();
    
    std::string line;
    
    std::getline(file, line);
    line = trim(line);
    if (line.empty())
        throw InvalidColumnFormat();   
    if(line != "date,exchange_rate")
        throw InvalidColumnFormat();

    while(std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;
        size_t pos = line.find(',');
        if(pos == std::string::npos)
            throw InvalidColumnFormat();
        
        std::string dateStr = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);

        dateStr = trim(dateStr);
        rateStr = trim(rateStr);

        if(!isValidFormDate(dateStr) || !isValidValueDate(dateStr))
            throw InvalidDateFormat();
        std::stringstream ss(rateStr);
        double rate;
        char extra;
        if (!(ss >> rate) || (ss >> extra) || rate < 0)
            throw InvalidPriceFormat();
        _rates[dateStr] = rate;
    }
}

void BitcoinExchange::processInput(const std::string& input) const
{
    std::ifstream file(input.c_str());
    if(!file.is_open())
        throw CouldNotOpenFile();
    
    std::string line;
    
    std::getline(file, line);
    line = trim(line);
    if (line.empty())
        throw InvalidInputFormat();   
    if(line != "date | value")
        throw InvalidInputFormat();
    
    while(std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;
        size_t pos = line.find('|');
        if(pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        dateStr = trim(dateStr);
        valueStr = trim(valueStr);

        if(!isValidFormDate(dateStr) || !isValidValueDate(dateStr))
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        std::stringstream ss(valueStr);
        double value;
        char extra;
        if (!(ss >> value) || (ss >> extra))
        {
                std::cout << "Error : A valid format for a value must be either a float or a positive integer.\n";
                continue;
        }
        if(value < 0 || value > 1000)
        {
            if(value < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            else if(value > 1000)
            {
                std::cout << "Error: to large a number." << std::endl;
                continue;
            }
        }
        double rate;
        try
        {
            rate = findRateDate(dateStr);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        double result = value * rate;
        std::cout << dateStr << " => " << value << " = " << result << std::endl; 
    }
}

double BitcoinExchange::findRateDate(const std::string& date) const
{
    if (_rates.empty())
        throw EmptyDb();
    
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if ((it != _rates.end()) && (it->first == date))
        return it->second;
    else if(it ==_rates.begin())
        throw NoEarlierDate();
    else if(it == _rates.end())
    {
        --it;
        return it->second;
    }
    else
    {
        --it;
        return it->second;
    }
}

std::string BitcoinExchange::trim(const std::string& s) const
{
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::isValidFormDate(const std::string& date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    return true;
}

static bool isLeapYear(int y)
{
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

bool BitcoinExchange::isValidValueDate(const std::string& date) const
{

    if (!isValidFormDate(date))
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12)
        return false;
    if (d < 1)
        return false;

    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeapYear(y))
        daysInMonth[1] = 29;

    if (d > daysInMonth[m - 1])
        return false;

    return true;
}