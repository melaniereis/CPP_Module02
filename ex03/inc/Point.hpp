/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:03:53 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/30 22:11:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "ansi.h"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point(void);
		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
