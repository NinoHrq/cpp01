#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int i;
		static const int j = 8;
	public:
		Fixed();
		Fixed(Fixed& other);
		Fixed& operator=(Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif