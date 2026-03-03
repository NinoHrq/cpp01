/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:43:25 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 21:23:42 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& database);
        void processInput(const std::string& input) const;

        class CouldNotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Could not open file");
				}
		};

		class InvalidColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid column format. Expected 'date,exchange_rate'");
				}
		};
        
       	class InvalidInputFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid input format. Expected 'date | value'");
				}
		}; 

		class InvalidDateFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid date format. Expected 'YYYY-MM-DD'");
				}
		};

		class InvalidPriceFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : A valid format for a value must be either a float or a positive integer, between 0 and 1000");
				}
		};
		
		class EmptyDb : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : No rates to see there");
				}
		};

		class NoEarlierDate : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error : No rates before your date.");
				}
		};
        
    private :
        std::map<std::string, double>_rates;
        
        bool isValidFormDate(const std::string& date) const;
        bool isValidValueDate(const std::string& date) const;

        double findRateDate(const std::string& date) const;
        
        std::string trim(const std::string& s) const;        
};

#endif
