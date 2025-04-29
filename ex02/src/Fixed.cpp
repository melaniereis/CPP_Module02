/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/29 22:14:47 by meferraz         ###   ########.fr       */
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
 * Integer constructor for the Fixed class.
 *
 * Initializes a Fixed object using an integer value.
 * The integer value is converted to a fixed-point value
 * by shifting the bits to the left by a number of positions
 * equal to the _bits static class member variable.
 *
 * Output:
 *   Int constructor called
 */
Fixed::Fixed(const int value) : _value(value << _bits)
{
	std::cout << GRN "✅ Int constructor called" RESET << std::endl;
}

/**
 * Float constructor for the Fixed class.
 *
 * Initializes a Fixed object using a floating-point value.
 * The floating-point value is converted to a fixed-point value
 * by multiplying it with 2 raised to the power of the number of
 * fractional bits (_bits) and rounding the result.
 *
 * Output:
 *   ✅ Float constructor called
 *
 * Parameters:
 *   value - The floating-point value to be converted to fixed-point.
 */

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
	std::cout << GRN "✅ Float constructor called" RESET << std::endl;
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

bool Fixed::operator>(const Fixed &fixedPointObj)
{
	return (this->getRawBits() > fixedPointObj.getRawBits());
}

bool Fixed::operator<(const Fixed &fixedPointObj)
{
	return (this->getRawBits() < fixedPointObj.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixedPointObj)
{
	return (this->getRawBits() >= fixedPointObj.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixedPointObj)
{
	return (this->getRawBits() <= fixedPointObj.getRawBits());
}

bool Fixed::operator==(const Fixed &fixedPointObj)
{
	return (this->getRawBits() == fixedPointObj.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixedPointObj)
{
	return (this->getRawBits() != fixedPointObj.getRawBits());
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

/**
 * Converts the fixed-point number to a floating-point number.
 *
 * This function calculates the floating-point representation of the
 * fixed-point number by dividing the internal integer value by 2 raised
 * to the power of the _bits static class member variable.
 *
 * Returns:
 *   The floating-point representation of the fixed-point number.
 */

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _bits));
}

/**
 * Retrieves the integer value of the fixed-point number.
 *
 * This function returns the integer value of the fixed-point number.
 * The result is obtained by shifting the internal value of the
 * Fixed object right by a number of bits equal to the value of
 * the _bits static class member variable.
 *
 * Output:
 *   🔝 toInt member function called
 *
 * Returns:
 *   The integer value of the fixed-point number.
 */
int Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
