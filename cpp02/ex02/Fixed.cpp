#include "Fixed.hpp"

Fixed::Fixed() : i(0 * (1 << j)) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : i(other.i){
	//std::cout << "Copy constructor called" << std::endl;
	//*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if(this != &other)
	{
		//std::cout << "Copy assignment operator called" << std::endl;
		this->setRawBits(other.getRawBits());
	}
	return(*this);
}

Fixed::~Fixed() {
		//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
	i = k << j;
}
Fixed::Fixed(const float l) {
	//std::cout << "Float constructor called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const {
	return i > other.i;
}

bool Fixed::operator<(const Fixed& other) const {
	return i < other.i;
}

bool Fixed::operator>=(const Fixed& other) const {
	return i >= other.i;
}

bool Fixed::operator<=(const Fixed& other) const {
	return i <= other.i;
}

bool Fixed::operator==(const Fixed& other) const {
	return i == other.i;
}

bool Fixed::operator!=(const Fixed& other) const {
	return i != other.i;
}

// +, -, *, / : ne pas modifier *this, marquer const, et renvoyer par valeur
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed r;
    r.setRawBits(this->i + other.i);
    return r;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed r;
    r.setRawBits(this->i - other.i);
    return r;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed r;
    r.setRawBits((this->i * other.i) >> j);      // j = nombre de bits fractionnaires
    return r;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed r;
    r.setRawBits((this->i << j) / other.i);
    return r;
}


Fixed& Fixed::operator++() { ++i; return *this; }
Fixed Fixed::operator++(int) { Fixed tmp(*this); ++(*this); return tmp; }

Fixed& Fixed::operator--() { --i; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); --(*this); return tmp; }


Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if(a < b)
		return a;
	else
		return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b) {
	if(a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if(a > b)
		return a;
	else
		return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b) {
	if(a > b)
		return a;
	else
		return b;
}