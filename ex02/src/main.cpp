/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:52:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/30 15:40:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/**
 * Prints a header with the name of the project.
 *
 * This function prints a simple header with the name of the project and some
 * decoration. It also prints a newline after the header.
 */
static void printHeader()
{
	std::cout << BGRN << "=====================================" << RESET << std::endl;
	std::cout << BLUHB << "    Fixed Point Number Class         " << RESET << std::endl;
	std::cout << BGRN << "=====================================" << RESET << std::endl;
	std::cout << std::endl;
}

/**
 * Prints a visual separator line.
 *
 * This function outputs a separator line to the console, which can be used
 * to visually distinguish between different sections of output. It prints
 * a newline before and after the separator for additional spacing.
 */
static void printSeparator()
{
	std::cout << std::endl;
	std::cout << WHT << "-------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
}

/**
 * Runs the tests provided by the subject.
 *
 * This function prints a header indicating the tests being run and a separator
 * line. It then creates four `Fixed` objects: `a`, `b`, `c`, and `d`. `a` is
 * assigned the value 1234.4321, `b` is assigned the value 10, `c` is assigned
 * the value 42.42, and `d` is created using the copy constructor and takes `b`
 * as its argument. The raw bits of each object are then printed to the console,
 * as well as each object converted to an integer using the `toInt` method.
 */
static void runSubjectTests()
{
	std::cout << YELHB << "            Subject Tests            " << RESET << std::endl;
	printSeparator();

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}


/**
 * Runs additional tests for the Fixed class.
 *
 * This function prints a header indicating the tests being run and a separator
 * line. It then creates eight `Fixed` objects: `a`, `b`, `c`, `d`, `e`, `f`, `g`,
 * and `h`. `a` is assigned the value 1.5, `b` is assigned the value 0, `c` is
 * assigned the value 100, `d` is assigned the value -42, `e` is assigned the
 * value 3.14159, `f` is assigned the value -123.456, `g` is created using the
 * copy constructor and takes `b` as its argument, and `h` is created using the
 * copy assignment operator and takes `c` as its argument. The raw bits and
 * values of each object are then printed to the console, as well as each object
 * converted to an integer and a float using the `toInt` and `toFloat` methods.
 * This function also tests the arithmetic, comparison, min/max, and
 * increment/decrement operators.
 *
 * The raw bits and values of each object are then printed to the console, as
 * well as each object converted to an integer and a float using the `toInt`
 * and `toFloat` methods. The arithmetic, comparison, min/max, and
 * increment/decrement operators are also tested.
 */
static void runAditionalTests()
{
	std::cout << YELHB << "          Additional Tests           " << RESET << std::endl;
	printSeparator();

	Fixed a(1.5f), b(0), c(100), d(-42), e(3.14159f), f(-123.456f), g(b), h(c);

	std::cout << "\n❓ Object States:" << std::endl;
	std::cout << "a: " << a << " (as int: " << a.toInt() << ", as float: " << a.toFloat() << ")" << std::endl;
	std::cout << "b: " << b << " (as int: " << b.toInt() << ", as float: " << b.toFloat() << ")" << std::endl;
	std::cout << "c: " << c << " (as int: " << c.toInt() << ", as float: " << c.toFloat() << ")" << std::endl;
	std::cout << "d: " << d << " (as int: " << d.toInt() << ", as float: " << d.toFloat() << ")" << std::endl;
	std::cout << "e: " << e << " (as int: " << e.toInt() << ", as float: " << e.toFloat() << ")" << std::endl;
	std::cout << "f: " << f << " (as int: " << f.toInt() << ", as float: " << f.toFloat() << ")" << std::endl;
	std::cout << "g (copy of b): " << g << std::endl;
	std::cout << "h (assigned from c): " << h << std::endl;

	printSeparator();

	std::cout << "\n❓ Arithmetic Operations:" << std::endl;
	std::cout << "a + e = " << (a + e) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "e * a = " << (e * a) << std::endl;
	std::cout << "c / a = " << (c / a) << std::endl;

	printSeparator();

	std::cout << "\n❓ Comparison Operations:" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a == g: " << (a == g) << std::endl;
	std::cout << "h >= c: " << (h >= c) << std::endl;
	std::cout << "f != d: " << (f != d) << std::endl;

	printSeparator();

	std::cout << "\n❓ Min/Max Functions:" << std::endl;
	std::cout << "min(a, e): " << Fixed::min(a, e) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	printSeparator();

	std::cout << "\n❓ Increment/Decrement:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after a++: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a after a--: " << a << std::endl;
}


/**
 * Entry point of the application.
 *
 * This function initializes the test environment by printing a header and
 * separators. It sequentially runs a series of tests including the subject
 * tests, copy constructor test, copy assignment test, and independence after
 * copy test. Each test is followed by a separator for clarity. After all tests
 * are completed, a success message is displayed.
 *
 * @return int Returns 0 upon successful completion.
 */

int main(void)
{
	printHeader();

	printSeparator();
	runSubjectTests();
	printSeparator();

	runAditionalTests();
	printSeparator();


	std::cout << GRNHB " 🎉 Success! All tests completed! 🎉" RESET << std::endl;
	printSeparator();
	return 0;
}
