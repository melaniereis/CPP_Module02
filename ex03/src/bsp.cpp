/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:16:59 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/30 21:52:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = (point.getX() - b.getX()) * (a.getY() - b.getY()) -
			(a.getX() - b.getX()) * (point.getY() - b.getY());
	Fixed d2 = (point.getX() - c.getX()) * (b.getY() - c.getY()) -
			(b.getX() - c.getX()) * (point.getY() - c.getY());
	Fixed d3 = (point.getX() - a.getX()) * (c.getY() - a.getY()) -
			(c.getX() - a.getX()) * (point.getY() - a.getY());

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return(!(has_neg && has_pos) && d1 != 0 && d2 != 0 && d3 != 0);
}
