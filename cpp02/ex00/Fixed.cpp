#include "Fixed.hpp"

Fixed::Fixed() : i(0 * (1 << j)) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& other) : i(other.i){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(Fixed& other) {
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
	std::cout << "getRawBits member function called" << std::endl;
	return ( i );
}

void Fixed::setRawBits( int const raw )
{
	i = raw;
}
