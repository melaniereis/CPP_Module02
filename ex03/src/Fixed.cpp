/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:16:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 09:07:27 by meferraz         ###   ########.fr       */
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
	// std::cout << GRN "✅ Default constructor called" RESET << std::endl;
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
	// std::cout << GRN "✅ Int constructor called" RESET << std::endl;
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
	// std::cout << GRN "✅ Float constructor called" RESET << std::endl;
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
	// std::cout << RED "❌ Default destructor called" RESET << std::endl;
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
	// std::cout << YEL "📋 Copy constructor called" RESET << std::endl;
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
	// std::cout << BLU "📝 Copy assignment operator called" RESET << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

/**
 * Compares two Fixed objects for greater than.
 *
 * This function returns true if the left-hand side object has a greater raw value
 * than the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object has a greater raw value than right-hand side
 *   object, and false otherwise.
 */
bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

/**
 * Compares two Fixed objects for less than.
 *
 * This function returns true if the left-hand side object has a lesser raw value
 * than the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object has a lesser raw value than right-hand side
 *   object, and false otherwise.
 */
bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

/**
 * Compares two Fixed objects for greater than or equal to.
 *
 * This function returns true if the left-hand side object has a raw value
 * greater than or equal to the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object has a raw value greater than or equal to
 *   right-hand side object, and false otherwise.
 */
bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

/**
 * Compares two Fixed objects for less than or equal to.
 *
 * This function returns true if the left-hand side object has a raw value
 * less than or equal to the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object has a raw value less than or equal to
 *   right-hand side object, and false otherwise.
 */
bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

/**
 * Compares two Fixed objects for equality.
 *
 * This function returns true if the left-hand side object has the same raw value
 * as the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object has the same raw value as right-hand side
 *   object, and false otherwise.
 */
bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

/**
 * Compares two Fixed objects for inequality.
 *
 * This function returns true if the left-hand side object does not have the same
 * raw value as the right-hand side object, and false otherwise.
 *
 * Output:
 *   None
 *
 * Returns:
 *   True if left-hand side object does not have the same raw value as right-hand
 *   side object, and false otherwise.
 */
bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

/**
 * Adds two Fixed objects together.
 *
 * This function returns a new Fixed object whose raw value is the sum of the
 * raw values of the left-hand side and right-hand side objects.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A new Fixed object whose raw value is the sum of the raw values of the
 *   left-hand side and right-hand side objects.
 */
Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

/**
 * Subtracts the right-hand side Fixed object from the left-hand side Fixed
 * object.
 *
 * This function returns a new Fixed object whose raw value is the difference
 * of the raw values of the left-hand side and right-hand side objects.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A new Fixed object whose raw value is the difference of the raw values of
 *   the left-hand side and right-hand side objects.
 */
Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

/**
 * Multiplies the left-hand side Fixed object by the right-hand side Fixed
 * object.
 *
 * This function returns a new Fixed object whose raw value is the product of the
 * raw values of the left-hand side and right-hand side objects.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A new Fixed object whose raw value is the product of the raw values of the
 *   left-hand side and right-hand side objects.
 */
Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

/**
 * Divides the left-hand side Fixed object by the right-hand side Fixed object.
 *
 * This function returns a new Fixed object whose raw value is the division of
 * the raw values of the left-hand side and right-hand side objects.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A new Fixed object whose raw value is the division of the raw values of the
 *   left-hand side and right-hand side objects.
 */
Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/**
 * Increments the Fixed object by one.
 *
 * This function increments the internal integer value of the Fixed object by
 * one and returns the object itself.
 *
 * Output:
 *   None
 *
 * Returns:
 *   The Fixed object itself after incrementing.
 */
Fixed Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

/**
 * Decrements the Fixed object by one.
 *
 * This function decrements the internal integer value of the Fixed object by
 * one and returns the object itself.
 *
 * Output:
 *   None
 *
 * Returns:
 *   The Fixed object itself after decrementing.
 */
Fixed Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

/**
 * Post-increments the Fixed object by one.
 *
 * This function increments the internal integer value of the Fixed object by
 * one, but returns a copy of the object itself before the incrementation took
 * place.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A copy of the Fixed object before the incrementation took place.
 */
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;
	return (temp);
}

/**
 * Post-decrements the Fixed object by one.
 *
 * This function decrements the internal integer value of the Fixed object by
 * one, but returns a copy of the object itself before the decrementation took
 * place.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A copy of the Fixed object before the decrementation took place.
 */
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value--;
	return (temp);
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
	// std::cout << CYN "🔍 getRawBits member function called" RESET << std::endl;
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
	// std::cout << MAG "🛠️ setRawBits member function called" RESET << std::endl;
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

/**
 * Overloads the output stream operator for the Fixed class.
 *
 * This function allows the Fixed object to be printed to an output stream.
 * The function converts the fixed-point number to a floating-point
 * representation and prints it to the output stream.
 *
 * Output:
 *   None
 *
 * Parameters:
 *   out - The output stream to print to.
 *   fixed - The Fixed object to print.
 *
 * Returns:
 *   The output stream.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/**
 * Retrieves the minimum of two Fixed objects.
 *
 * This function returns a reference to the Fixed object with the
 * lesser raw value. If both objects have the same raw value, it
 * returns a reference to the first object.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A reference to the Fixed object with the lesser raw value.
 */
const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}
/**
 * Retrieves the minimum of two Fixed objects.
 *
 * This function returns a reference to the Fixed object with the
 * lesser raw value. If both objects have the same raw value, it
 * returns a reference to the first object.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A reference to the Fixed object with the lesser raw value.
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

/**
 * Retrieves the maximum of two Fixed objects.
 *
 * This function returns a reference to the Fixed object with the
 * greater raw value. If both objects have the same raw value, it
 * returns a reference to the first object.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A reference to the Fixed object with the greater raw value.
 */
const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

/**
 * Retrieves the maximum of two Fixed objects.
 *
 * This function returns a reference to the Fixed object with the
 * greater raw value. If both objects have the same raw value, it
 * returns a reference to the first object.
 *
 * Output:
 *   None
 *
 * Returns:
 *   A reference to the Fixed object with the greater raw value.
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
