/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:59 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/29 16:01:51 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include "ansi.h"

class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed &operator=(const Fixed &copy);
	Fixed(const Fixed &copy);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _bits;
};

#endif
