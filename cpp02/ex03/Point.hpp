#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		// Constructors
		Point();
		Point( const float x, const float y );
		Point( const Point& toCopy );		// Copy constructor

		// Destructor
		~Point();

		// Overload Operators
		Point& operator=( const Point& src );
		Point operator-( const Point& src ) const;

		// Getters
		float	getX()const;
		float	getY()const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);


#endif
