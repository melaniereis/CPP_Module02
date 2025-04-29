/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/29 16:51:48 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::_bits = 8;

/**
 * Default constructor for the Fixed class.
 *
 * Initializes the object with an internal value of 0.
 *
 * Output:
 *   ✅ Default constructor called
 */
Fixed::Fixed(void) : _value(0)
{
	std::cout << GRN "✅ Default constructor called" RESET << std::endl;
}

/**
 * Default destructor for the Fixed class.
 *
 * Simply prints a message to the console indicating that the
 * destructor was called.
 *
 * Output:
 *   ❌ Default destructor called
 */
Fixed::~Fixed(void)
{
	std::cout << RED "❌ Default destructor called" RESET << std::endl;
}

/**
 * Copy constructor for the Fixed class.
 *
 * Copies the contents of another Fixed object into a new object.
 *
 * Output:
 *   📋 Copy constructor called
 */
Fixed::Fixed(const Fixed &copy)
{
	std::cout << YEL "📋 Copy constructor called" RESET << std::endl;
	*this = copy;
}

/**
 * Copy assignment operator for the Fixed class.
 *
 * Assigns the contents of another Fixed object to the current object.
 *
 * Output:
 *   📝 Copy assignment operator called
 */
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << BLU "📝 Copy assignment operator called" RESET << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

/**
 * Retrieves the raw value of the fixed-point number.
 *
 * This function returns the internal value of the Fixed object, which is
 * an integer with a fixed number of bits. The number of bits is determined
 * by the _bits static class member variable.
 *
 * Output:
 *   🔍 getRawBits member function called
 *
 * Returns:
 *   The raw value of the fixed-point number.
 */
int Fixed::getRawBits(void) const
{
	std::cout << CYN "🔍 getRawBits member function called" RESET << std::endl;
	return (this->_value);
}

/**
 * Sets the raw value of the fixed-point number.
 *
 * This function sets the internal value of the Fixed object, which is
 * an integer with a fixed number of bits. The number of bits is determined
 * by the _bits static class member variable.
 *
 * Output:
 *   🛠️ setRawBits member function called
 *
 * Parameters:
 *   raw - The raw value to set the fixed-point number to.
 */
void Fixed::setRawBits(int const raw)
{
	std::cout << MAG "🛠️ setRawBits member function called" RESET << std::endl;
	this->_value = raw;
}
