#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int i;
		static const int j = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int k);
		Fixed(const float l);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed& other);
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
		static Fixed &max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream& os, const Fixed& lol);


#endif