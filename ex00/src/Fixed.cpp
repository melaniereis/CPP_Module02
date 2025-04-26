/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/26 16:50:50 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << GRNHB "Fixed Point initialized to 0 ✅" RESET << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << REDHB "Fixed Point destroyed... ☠" RESET << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _value(copy._value)
{
	*this = copy;
	std::cout << YELHB "Fixed Point copied from value..." RESET << copy._value << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
}
