/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:52:32 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/29 16:50:43 by meferraz         ###   ########.fr       */
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
 * line. It then creates three `Fixed` objects: `a`, `b`, and `c`. `b` is
 * created using the copy constructor and `c` is created using the copy
 * assignment operator. Finally, the raw bits of each object are printed to the
 * console.
 */
static void runSubjectTests()
{
	std::cout << YELHB << "            Subject Tests            " << RESET << std::endl;
	printSeparator();

	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

/**
 * Runs a test for the copy constructor.
 *
 * This function prints a header indicating the test being run and a separator
 * line. It then creates two `Fixed` objects: `original` and `copy`. `copy` is
 * created using the copy constructor and takes `original` as its argument.
 * The raw bits of both objects are then printed to the console.
 */
static void runCopyConstructorTest()
{
	std::cout << CYNHB " 🧪 Test 1: Copy Constructor" RESET << std::endl;
	printSeparator();

	Fixed original;
	original.setRawBits(42);
	Fixed copy(original);

	std::cout << "Original raw bits: " << original.getRawBits() << std::endl;
	std::cout << "Copy     raw bits: " << copy.getRawBits() << std::endl;
}

/**
 * Runs a test for the copy assignment operator.
 *
 * This function prints a header indicating the test being run and a separator
 * line. It then creates two `Fixed` objects: `a` and `b`. `a` is assigned the
 * value 123 and `b` is assigned `a` using the copy assignment operator.
 * The raw bits of both objects are then printed to the console.
 */
static void runCopyAssignmentTest()
 {
	std::cout << CYNHB " 🧪 Test 2: Copy Assignment" RESET << std::endl;
	printSeparator();

	Fixed a;
	a.setRawBits(123);
	Fixed b;
	b = a;

	std::cout << "a raw bits: " << a.getRawBits() << std::endl;
	std::cout << "b raw bits: " << b.getRawBits() << std::endl;
}

/**
 * Runs a test for independence after copy.
 *
 * This function prints a header indicating the test being run and a separator
 * line. It then creates three `Fixed` objects: `x`, `y`, and `z`. `y` is
 * created using the copy constructor and takes `x` as its argument, and `z` is
 * created using the copy assignment operator and takes `x` as its argument.
 * The raw bits of each object are then modified and printed to the console.
 */
static void runIndependenceTest()
{
	std::cout << CYNHB " 🧪 Test 3: Independence After Copy" RESET << std::endl;
	printSeparator();

	Fixed x;
	x.setRawBits(1000);
	Fixed y(x);
	Fixed z;
	z = x;

	x.setRawBits(1);
	y.setRawBits(2);
	z.setRawBits(3);

	std::cout << "x raw bits (should be 1): " << x.getRawBits() << std::endl;
	std::cout << "y raw bits (should be 2): " << y.getRawBits() << std::endl;
	std::cout << "z raw bits (should be 3): " << z.getRawBits() << std::endl;
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

	std::cout << YELHB << "          Additional Tests           " << RESET << std::endl;
	printSeparator();

	runCopyConstructorTest();
	printSeparator();

	runCopyAssignmentTest();
	printSeparator();

	runIndependenceTest();
	printSeparator();

	std::cout << GRNHB " 🎉 Success! All tests completed! 🎉" RESET << std::endl;
	printSeparator();
	return 0;
}
