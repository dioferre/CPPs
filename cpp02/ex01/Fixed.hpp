#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits;

	public:
		Fixed();
		Fixed( const Fixed& toCopy );
		Fixed( const int nr );
		Fixed( const float nr );
		~Fixed();

		Fixed& operator=( const Fixed& src );


		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream &os, Fixed const &fixed );


#endif
