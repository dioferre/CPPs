#include "Fixed.hpp"
#include "Point.hpp"


float	crossProduct(Point const &v1, Point const &v2)
{
	return ( v1.getX() * v2.getY() - v1.getY() * v2.getX() );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	d1 = crossProduct(point - a, b - a);
	float	d2 = crossProduct(point - b, c - b);
	float	d3 = crossProduct(point - c, a - c);

	bool	hasNeg( d1 <= 0 || d2 <= 0 || d3 <= 0 );
	bool	hasPos( d1 >= 0 || d2 >= 0 || d3 >= 0 );

	return ( !(hasNeg && hasPos) );
}
