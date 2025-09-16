#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T*			_array;
	unsigned int _size;
public:
	Array();
	Array( unsigned int n );
	Array( const Array& other );
	~Array();

	Array&	operator=( const Array& other );

	T& operator[]( int index );
	const T& operator[]( int index ) const;

	unsigned int	size(void) const;
} ;

#endif