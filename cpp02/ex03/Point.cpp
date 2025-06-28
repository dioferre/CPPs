#include "Point.hpp"


Point::Point(): _x(0), _y(0)
{
}

Point::Point( const float x, const float y ): _x(x), _y(y)
{
}

Point::Point( const Point& toCopy ): _x(toCopy.getX()), _y(toCopy.getY())
{
}

Point::~Point()
{
}

Point& Point::operator=( const Point& src )
{
	(void)src;

	return (*this);
}

Point Point::operator-( const Point& src ) const
{
	return ( Point(getX() - src.getX(), getY() - src.getY()) );
}

float Point::getX() const
{
	return (_x.toFloat());
}

float Point::getY() const
{
	return (_y.toFloat());
}
