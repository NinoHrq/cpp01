#include "Fixed.hpp"

Fixed::Fixed() : i(0 * (1 << j)) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : i(other.i){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if(this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->setRawBits(other.getRawBits());
	}
	return(*this);
}

Fixed::~Fixed() {
		std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const 
{
	//std::cout << "getRawBits member function called" << std::endl;
	return ( i );
}

void Fixed::setRawBits( int const raw )
{
	i = raw;
}

Fixed::Fixed(const int k) {
	std::cout << "Int constructor called" << std::endl;
	i = k << j;
}
Fixed::Fixed(const float l) {
	std::cout << "Float constructor called" << std::endl;
	i = roundf(l * (1 << j));
}

float Fixed::toFloat(void) const {
	return((float)i / (1 << j));
}
int Fixed::toInt(void) const {
	return(i >> j);
}

std::ostream &operator<<(std::ostream& os, const Fixed& lol){
	os << lol.toFloat();
	return(os);
}