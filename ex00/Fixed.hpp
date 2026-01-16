/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykebieb <ykebieb@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:11:34 by ykebieb           #+#    #+#             */
/*   Updated: 2026/01/16 11:11:35 by ykebieb          ###   ########.fr       */
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
		Fixed &operator=(const Fixed& other); // Copy assignment operator
		~Fixed(); // Destructor
		int getRawBits(void) const; // Getter
		void setRawBits(int const raw); // Setter
};

#endif
