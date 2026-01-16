/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykebieb <ykebieb@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:12:11 by ykebieb           #+#    #+#             */
/*   Updated: 2026/01/16 11:12:12 by ykebieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed():fixed_point(0)
{}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixed_point = other.fixed_point;
	return *this;
}

Fixed::Fixed(const int value)
{
	fixed_point = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
	fixed_point = roundf(value * (1 << fractional_bits));
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
	return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixed_point) / (1 << fractional_bits);
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

bool Fixed::operator<(const Fixed& other) const
{
	return fixed_point < other.fixed_point;
}

bool Fixed::operator>(const Fixed& other) const
{
	return fixed_point > other.fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed& other) const
{
	return fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return fixed_point != other.fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(fixed_point + other.fixed_point);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(fixed_point - other.fixed_point);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((fixed_point * other.fixed_point) >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((fixed_point << fractional_bits) / other.fixed_point);
	return result;
}

Fixed& Fixed::operator++()
{
	fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed last(*this);
	this->fixed_point++;
	return last;
}

Fixed& Fixed::operator--()
{
	fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed last(*this);
	this->fixed_point--;
	return last;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
