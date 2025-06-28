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

		// Overload Operators lel
		Fixed& operator=( const Fixed& src );

		// Comparison Operators
		bool operator<( const Fixed& src );
		bool operator>( const Fixed& src );
		bool operator<=( const Fixed& src );
		bool operator>=( const Fixed& src );
		bool operator==( const Fixed& src );
		bool operator!=( const Fixed& src );

		// Arithmetic Operators
		float operator+( const Fixed& src );
		float operator-( const Fixed& src );
		float operator*( const Fixed& src );
		float operator/( const Fixed& src );

		// Pre Increment/Decrement Operators
		Fixed& operator++( void );
		Fixed& operator--( void );
		// Post Increment/Decrement Operators
		Fixed operator++( int ); 
		Fixed operator--( int );
		// The "(int)" is just a placeholder for the compiler to distinguish between which of these
		// is post and pre incrementation / decrementation. 


		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static const Fixed&	min(const Fixed& var1, const Fixed& var2);
		static const Fixed&	max(const Fixed& var1, const Fixed& var2);
};

std::ostream&	operator<<( std::ostream &os, Fixed const &fixed );


#endif
