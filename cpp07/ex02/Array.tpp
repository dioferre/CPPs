/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:11:14 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/16 13:38:09 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array( unsigned int n ) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array( const Array& other ) : _array(new T[other.size()]), _size(other.size())
{
	for (unsigned int i = 0; i < other._size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
	if (this != &other)
	{
		delete[] _array;
		_size = other.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < other.size(); i++)
			_array[i] = other._array[i];
	}
	
	return (*this);
}

template <typename T>
T& Array<T>::operator[]( int index )
{
	if ( static_cast<unsigned int>(index) >= _size || index < 0 )
		throw std::out_of_range("Index is out of bounds");
	return (_array[index]);
}

template <typename T>
T const &Array<T>::operator[]( int index ) const
{
	if ( static_cast<unsigned int>(index) >= _size || index < 0 )
		throw std::out_of_range("Index is out of bounds");
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
	return (_size);
}

#endif