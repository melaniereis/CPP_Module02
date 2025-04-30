/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:03:30 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/30 22:07:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

/**
 * Default constructor for the Point class.
 *
 * Initializes the point with coordinates (0, 0).
 */
Point::Point(void) : _x(0), _y(0)
{
	std::cout << GRN "✅ Default constructor called" RESET << std::endl;
}

/**
 * Constructor for the Point class.
 *
 * Initializes the point with the given x and y coordinates.
 *
 * Parameters:
 *   x - The x coordinate of the point.
 *   y - The y coordinate of the point.
 */
Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << GRN "✅ Float constructor called" RESET << std::endl;
}

/**
 * Copy constructor for the Point class.
 *
 * Initializes a new point with the same coordinates as another point.
 *
 * Parameters:
 *   copy - The point to copy from.
 */
Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
	std::cout << GRN "📋 Copy constructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for the Point class.
 *
 * Assigns the coordinates of another point to this point.
 *
 * Parameters:
 *   copy - The point to copy from.
 *
 * Returns:
 *   A reference to this point.
 */
Point &Point::operator=(const Point &copy)
{
	if (this != &copy)
	{
		this->_x = copy.getX();
		this->_y = copy.getY();
		std::cout << BLU "📝 Copy assignment operator called" RESET << std::endl;
	}
	return (*this);
}

/**
 * Default destructor for the Point class.
 *
 * Outputs:
 *   🗑️ Defautlt destructor called
 */
Point::~Point(void)
{
	std::cout << RED "🗑️ Defautlt destructor called" RESET << std::endl;
}

/**
 * Retrieves the x-coordinate of the point.
 *
 * Returns:
 *   The x-coordinate of the point.
 */
Fixed Point::getX(void) const
{
	return (this->_x);
}

/**
 * Retrieves the y-coordinate of the point.
 *
 * Returns:
 *   The y-coordinate of the point.
 */
Fixed Point::getY(void) const
{
	return (this->_y);
}
