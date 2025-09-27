/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:41:45 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/27 17:48:59 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Date::Date() : year_(2000), month_(1), day_(1) {}

Date::Date( int y, int m, int d) : year_(y), month_(m), day_(d) {}

Date::Date( const Date& other ) : year_(other.year_), month_(other.month_),
day_(other.day_) {}

Date::~Date() {}

Date&	Date::operator=( const Date& other )
{
	if (this != &other)
	{
		year_ = other.year_;
		month_ = other.month_;
		day_ = other.day_;
	}
	return (*this);
}
