/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:35:34 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/22 09:05:02 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(10000) {}

Span::Span( unsigned int N ) : max_size(N) {}

Span::Span( const Span& other ) 
{
	*this = other;
}

Span::~Span() {}

Span&	Span::operator=( const Span& other )
{
	if (this != &other)
	{
		max_size = other.max_size;
		_nrs = other._nrs;
	}
	return (*this);
}

void	Span::addNumber( int nr )
{
	if (_nrs.size() >= static_cast<size_t>(max_size))
		throw std::out_of_range("Span vector already full");

	_nrs.push_back(nr);
}

void	Span::addNumberRange( int start, int end )
{
	unsigned int range = end - start + 1;

	if ( range > max_size )
	{
		std::cout << "[Span::addNumberRange] Warning: provided range is " 
				<< "greater than allocated size, range has been limited to "
				<< "the allocated size instead." << std::endl;
		range = max_size;
	}
	
	for (unsigned int i = 0; i < range; i++)
		_nrs.push_back(start + i);
}

int	Span::shortestSpan(void)
{
	if (_nrs.size() < 2)
		throw std::runtime_error("Not enough numbers");

	int	shortest = std::numeric_limits<int>::max();
	std::vector<int> tmp = _nrs;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < _nrs.size(); i++)
		shortest = std::min(shortest, tmp[i] - tmp[i - 1]);
		
	return (shortest);
}

int	Span::longestSpan(void)
{
	if (_nrs.size() < 2)
		throw std::runtime_error("Not enough numbers");

	int largest = *std::max_element(_nrs.begin(), _nrs.end());
	int	smallest = *std::min_element(_nrs.begin(), _nrs.end());
	return (largest - smallest);
}

