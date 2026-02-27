/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:41:45 by dioferre          #+#    #+#             */
/*   Updated: 2026/02/23 09:49:58 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const std::string input_file ) :
	_database(), _input_file(input_file)
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) 
{
	(void) other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other ) 
{
	if (this != &other)
	{}
	return (*this);
}

std::string BitcoinExchange::trim(const std::string& s) 
{
    size_t first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) 
        return ""; // The string is entirely whitespace (or empty)
    
    size_t last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, (last - first + 1));
}

void	BitcoinExchange::run()
{

	std::ifstream	file(_input_file.c_str());
	if (!file.is_open())
		throw CouldNotOpenFileException("Failed to open input file.");
	
	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidColumnFormatException("Invalid input file column format, should be: date | value");

	int	n = 1;

	while(std::getline(file, line))
	{	
		std::cout << "[" << n++ << "] ";

		if (trim(line).empty())
			continue;

		size_t delim_pos = line.find('|');
		if (delim_pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date_str = trim(line.substr(0, delim_pos));
        std::string amount_str = trim(line.substr(delim_pos + 1));
		if (date_str.empty() || amount_str.empty()) {
			std::cout << "Error: missing data in line => " << line << std::endl;
			continue;
		}

		char* endptr;
        float amount = static_cast<float>(std::strtod(amount_str.c_str(), &endptr));
        // If it didn't reach the very end of the string, it's garbage.
        if (*endptr != '\0') {
            std::cout << "Error: bad input => " << amount_str << std::endl;
            continue;
        }

		try
		{
			Date	closestDate = _database.getClosestDate(Date(date_str));
			float	exchange_rate = _database.getValue(closestDate);

			BitcoinTransaction	current_transction(Date(date_str), exchange_rate, amount);
			current_transction.processTransaction();
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: invalid date format => " << line << std::endl;
		}
	}
}
