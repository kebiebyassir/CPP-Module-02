/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykebieb <ykebieb@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:11:54 by ykebieb           #+#    #+#             */
/*   Updated: 2026/01/16 11:11:55 by ykebieb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed_point;
		static const int fractional_bits;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed &operator=(const Fixed& other); // Copy assignment operator4
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(); // Destructor
		int getRawBits(void) const; // Getter
		void setRawBits(int const raw); // Setter
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& Fixed);

#endif
