#include "Fixed.hpp"

Fixed::Fixed():fixed_point_number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other):fixed_point_number(other.fixed_point_number)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_number = other.fixed_point_number;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}
