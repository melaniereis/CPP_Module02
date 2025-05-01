/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:52:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/01 09:57:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

struct TestCase
{
	Point point;
	const char *description;
};

static void printHeader(const std::string &title)
{
	std::cout << RED << "\n========== " << title << " ==========" << RESET << "\n";
	std::cout << std::endl;
}

// Function to test a point inside/outside triangle
void testPointInsideTriangle(Point &P, Point &A, Point &B, Point &C)
{
	std::cout << "(" << BGRN << P.getX() << "," << P.getY() << RESET << ")" << std::endl;
	if (bsp(A, B, C, P))
		std::cout << BGRN << "Point INSIDE Triangle ABC" << RESET << std::endl;
	else
		std::cout << BRED << "Point OUTSIDE Triangle ABC" << RESET << std::endl;
}

static void printTriangleAndPoint(const Point &A, const Point &B, const Point &C, const Point &p)
{
	const int width = 10;
	const int height = 10;
	char grid[height][width];

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			grid[i][j] = ' ';

	grid[height - 1 - A.getY().toInt()][A.getX().toInt()] = 'A';
	grid[height - 1 - B.getY().toInt()][B.getX().toInt()] = 'B';
	grid[height - 1 - C.getY().toInt()][C.getX().toInt()] = 'C';
	grid[height - 1 - p.getY().toInt()][p.getX().toInt()] = 'P';

	std::cout << "\n"
			  << BBLU << "Triangle and Point Visualization:" << RESET << "\n";
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
			std::cout << grid[i][j];
		std::cout << "\n";
	}
}

int main()
{
	printHeader("BSP TESTING PROGRAM");

	// Triangle vertices
	Point A(0.0f, 0.0f);
	Point B(0.0f, 8.0f);
	Point C(8.0f, 0.0f);

	std::cout << WHTB << "Triangle A(" << A.getX() << ", " << A.getY() << ")";
	std::cout << ", B(" << B.getX() << ", " << B.getY() << ")";
	std::cout << ", C(" << C.getX() << ", " << C.getY() << ")" << RESET << "\n";

	// Inside the triangle
	Point Pd(4.0f, 3.0f);
	// On the edges of the triangle
	Point Pe(4.0f, 4.0f);
	Point Pf(4.0183f, 3.9f);	 // Close to the border but inside
	Point Pg(4.00389f, 4.4035f); // Close to the border but outside
	// Outside the triangle
	Point Ph(-4.00389f, -4.4035f);

	// Vertices
	Point Pi(0.0f, 0.0f);
	Point Pj(0.0f, 8.0f);
	Point Pk(8.0f, 0.0f);

	// Testing each point
	std::cout << "\n"
			  << BRED << "=== Testing Inside Points ===" << RESET << "\n";
	std::cout << "\nTesting Point Pd: ";
	testPointInsideTriangle(Pd, A, B, C);
	printTriangleAndPoint(A, B, C, Pd);

	std::cout << "\n"
			  << BRED << "=== Testing Points on the Edges ===" << RESET << "\n";
	std::cout << "\nTesting Point Pe: ";
	testPointInsideTriangle(Pe, A, B, C);
	printTriangleAndPoint(A, B, C, Pe);

	std::cout << "\nTesting Point Pf: ";
	testPointInsideTriangle(Pf, A, B, C);
	printTriangleAndPoint(A, B, C, Pf);

	std::cout << "\nTesting Point Pg: ";
	testPointInsideTriangle(Pg, A, B, C);
	printTriangleAndPoint(A, B, C, Pg);

	std::cout << "\n"
			  << BRED << "=== Testing Outside Points ===" << RESET << "\n";
	std::cout << "\nTesting Point Ph: ";
	testPointInsideTriangle(Ph, A, B, C);
	printTriangleAndPoint(A, B, C, Ph);

	std::cout << "\n"
			  << BRED << "=== Testing Points on Vertices ===" << RESET << "\n";
	std::cout << "\nTesting Point Pi: ";
	testPointInsideTriangle(Pi, A, B, C);
	printTriangleAndPoint(A, B, C, Pi);

	std::cout << "\nTesting Point Pj: ";
	testPointInsideTriangle(Pj, A, B, C);
	printTriangleAndPoint(A, B, C, Pj);

	std::cout << "\nTesting Point Pk: ";
	testPointInsideTriangle(Pk, A, B, C);
	printTriangleAndPoint(A, B, C, Pk);

	std::cout << "\n🎉 All BSP tests completed! 🎉\n";
	return 0;
}
