#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed():fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other):fixed_point(other.fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point = other.fixed_point;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return (float)fixed_point / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
	return fixed_point >> fractional_bits;
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
