/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:59 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/29 17:47:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include "ansi.h"

class Fixed
{
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);

	Fixed(const Fixed &copy);

	~Fixed(void);

	Fixed &operator=(const Fixed &copy);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _bits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
