/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:52:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/30 22:06:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <vector>

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void printHeader(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

static void printResult(bool inside, const Point &p)
{
    std::cout << "Point (" << p.getX() << ", " << p.getY() << ") --> ";
    std::cout << (inside ? BGRN "INSIDE" RESET : BRED "OUTSIDE" RESET) << "\n";
}

static void printTriangleAndPoint(const Point &A, const Point &B, const Point &C, const Point &p)
{
    const int width = 10;
    const int height = 10;
    char grid[height][width];

    // Initialize grid
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            grid[i][j] = ' ';

    // Plot points using toInt()
    grid[height - 1 - A.getY().toInt()][A.getX().toInt()] = 'A';
    grid[height - 1 - B.getY().toInt()][B.getX().toInt()] = 'B';
    grid[height - 1 - C.getY().toInt()][C.getX().toInt()] = 'C';
    grid[height - 1 - p.getY().toInt()][p.getX().toInt()] = 'P';

    std::cout << "\nTriangle and Point Visualization:\n";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            std::cout << grid[i][j];
        std::cout << "\n";
    }
}

typedef std::pair<Point, std::string> TestCase;

static TestCase makeTestCase(float x, float y, const std::string& desc)
{
    return std::make_pair(Point(x, y), desc);
}

int main()
{
    Point A(1, 1), B(5, 1), C(3, 4);

    std::vector<TestCase> tests;
    tests.push_back(makeTestCase(3, 2, "Center"));
    tests.push_back(makeTestCase(3, 3, "Upper"));
    tests.push_back(makeTestCase(1, 1, "Vertex A"));
    tests.push_back(makeTestCase(5, 1, "Vertex B"));
    tests.push_back(makeTestCase(3, 4, "Vertex C"));
    tests.push_back(makeTestCase(2, 1, "Edge AB"));
    tests.push_back(makeTestCase(4, 2, "Inside near edge BC"));
    tests.push_back(makeTestCase(0, 0, "Far outside"));
    tests.push_back(makeTestCase(3, 1.5f, "On line CA"));

    printHeader("BSP Triangle Point Test");
    std::cout << "Triangle vertices: A(" << A.getX() << "," << A.getY() << "), "
              << "B(" << B.getX() << "," << B.getY() << "), "
              << "C(" << C.getX() << "," << C.getY() << ")\n";

    for (std::vector<TestCase>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        Point p = it->first;
        bool inside = bsp(A, B, C, p);
        std::cout << it->second << ": ";
        printResult(inside, p);
        printTriangleAndPoint(A, B, C, p);
    }

    std::cout << "\n🎉 All BSP tests completed! 🎉\n";
    return 0;
}
