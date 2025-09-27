# 🔢 CPP Module 02 - Ad-hoc Polymorphism, Operators, Orthodox Canonical Form

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-02-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Mastering Operator Overloading and the Orthodox Canonical Form*

</div>

## 📖 Overview

**CPP Module 02** introduces the powerful concept of **operator overloading** and the **Orthodox Canonical Form**, essential pillars of modern C++ programming. Through the implementation of a fixed-point number class, you'll master ad-hoc polymorphism and learn how to make your custom classes behave like built-in types.

### 🎯 Learning Objectives

- Master operator overloading for arithmetic, comparison, and stream operations
- Understand and implement the Orthodox Canonical Form
- Learn fixed-point arithmetic and its applications
- Implement geometric algorithms using custom classes
- Practice const correctness and method overloading
- Explore Binary Space Partitioning (BSP) algorithms

## 💡 Key Concepts Introduced

- **Operator Overloading**: Making custom classes work with standard operators
- **Orthodox Canonical Form**: The four essential methods every class should have
- **Fixed-Point Arithmetic**: Alternative to floating-point for precise calculations
- **Ad-hoc Polymorphism**: Same operator, different behaviors for different types
- **Const Correctness**: Proper use of const methods and parameters
- **Binary Space Partitioning**: Geometric algorithms for point-in-triangle detection

## 📐 The Orthodox Canonical Form

Every well-designed C++ class should implement the **Big Four**:

1. **Default Constructor**: `ClassName()`
2. **Copy Constructor**: `ClassName(const ClassName& other)`
3. **Copy Assignment Operator**: `ClassName& operator=(const ClassName& other)`
4. **Destructor**: `~ClassName()`

## 🚀 Exercises

### 🏗️ Exercise 00: My First Orthodox Canonical Class
**Files**: `Fixed.cpp`, `Fixed.hpp`, `main.cpp`

Introduction to the Orthodox Canonical Form through a basic fixed-point class, demonstrating:
- The four essential methods of OCF
- Fixed-point number representation
- Basic getter and setter methods
- Constructor/destructor call tracking

**Fixed Class (Basic)**:
```cpp
class Fixed {
public:
    Fixed(void);                              // Default constructor
    Fixed(const Fixed &copy);                 // Copy constructor
    Fixed &operator=(const Fixed &copy);      // Copy assignment operator
    ~Fixed(void);                             // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;                               // Fixed-point value
    static const int _bits = 8;               // Fractional bits
};
```

**Key Features**:
- Fixed-point representation with 8 fractional bits
- Comprehensive constructor/destructor logging
- Raw bit manipulation methods
- Orthodox Canonical Form compliance

**Sample Output**:
```
✅ Default constructor called
✅ Copy constructor called
✅ Copy assignment operator called
❌ Default destructor called
❌ Default destructor called
```

**Key Learning Points**:
- Understanding the Orthodox Canonical Form
- Fixed-point number storage and representation
- Constructor chaining and object lifecycle
- Deep vs shallow copying concepts

---

### 🔄 Exercise 01: Towards Useful Fixed-Point Number Class
**Files**: `Fixed.cpp`, `Fixed.hpp`, `main.cpp`

Enhanced fixed-point class with type conversions and stream operations, showcasing:
- Parametric constructors for int and float
- Type conversion methods
- Stream insertion operator overloading
- Floating-point to fixed-point conversion

**Enhanced Fixed Class**:
```cpp
class Fixed {
public:
    Fixed(void);
    Fixed(const int value);                   // Int constructor
    Fixed(const float value);                 // Float constructor
    Fixed(const Fixed &copy);

    ~Fixed(void);

    Fixed &operator=(const Fixed &copy);

    int toInt(void) const;                    // Convert to int
    float toFloat(void) const;                // Convert to float
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int _bits = 8;
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &value);
```

**Conversion Mathematics**:
```cpp
// Float to Fixed-point
_value = roundf(value * (1 << _bits));

// Fixed-point to Float
return ((float)_value / (1 << _bits));
```

**Usage Examples**:
```cpp
Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);

std::cout << "a is " << a << std::endl;  // a is 0
std::cout << "b is " << b << std::endl;  // b is 10
std::cout << "c is " << c << std::endl;  // c is 42.4219
std::cout << "d is " << d << std::endl;  // d is 10
```

**Key Learning Points**:
- Parametric constructors and implicit conversions
- Fixed-point arithmetic and precision handling
- Stream operator overloading
- Type conversion best practices

---

### ⚖️ Exercise 02: Now We're Talking
**Files**: `Fixed.cpp`, `Fixed.hpp`, `main.cpp`

Complete operator overloading implementation, demonstrating:
- Arithmetic operators (+, -, *, /)
- Comparison operators (<, >, <=, >=, ==, !=)
- Increment/decrement operators (++, --)
- Min/max static functions

**Complete Fixed Class**:
```cpp
class Fixed {
public:
    // Orthodox Canonical Form
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);
    ~Fixed(void);
    Fixed &operator=(const Fixed &copy);

    // Comparison operators
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // Increment/Decrement operators
    Fixed &operator++(void);          // Pre-increment
    Fixed operator++(int);            // Post-increment
    Fixed &operator--(void);          // Pre-decrement
    Fixed operator--(int);            // Post-decrement

    // Static min/max functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Conversion methods
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _value;
    static const int _bits = 8;
};
```

**Operator Implementation Examples**:
```cpp
// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_value > rhs._value;
}

// Pre-increment
Fixed &Fixed::operator++(void) {
    this->_value++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}
```

**Usage Examples**:
```cpp
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));

std::cout << a << std::endl;           // 0
std::cout << ++a << std::endl;         // 0.00390625
std::cout << a << std::endl;           // 0.00390625
std::cout << a++ << std::endl;         // 0.00390625
std::cout << a << std::endl;           // 0.0078125

std::cout << b << std::endl;           // 10.1016

std::cout << Fixed::max(a, b) << std::endl;  // 10.1016
```

**Key Learning Points**:
- Complete operator overloading suite
- Pre vs post increment/decrement operators
- Static function overloading with const variants
- Operator precedence and associativity

---

### 📐 Exercise 03: BSP (Binary Space Partitioning)
**Files**: `Fixed.cpp`, `Fixed.hpp`, `Point.cpp`, `Point.hpp`, `bsp.cpp`, `main.cpp`

Geometric application using fixed-point arithmetic, demonstrating:
- Point class implementation using Fixed coordinates
- Binary Space Partitioning algorithm
- Point-in-triangle detection
- Real-world application of custom classes

**Point Class**:
```cpp
class Point {
public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point &copy);
    Point &operator=(const Point &copy);
    ~Point(void);

    Fixed getX(void) const;
    Fixed getY(void) const;

private:
    const Fixed _x;                   // Const Fixed-point x coordinate
    const Fixed _y;                   // Const Fixed-point y coordinate
};
```

**BSP Function**:
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

**Algorithm Implementation**:
The BSP function determines if a point lies inside a triangle using the barycentric coordinate system:

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate vectors
    Fixed v0x = c.getX() - a.getX();
    Fixed v0y = c.getY() - a.getY();
    Fixed v1x = b.getX() - a.getX();
    Fixed v1y = b.getY() - a.getY();
    Fixed v2x = point.getX() - a.getX();
    Fixed v2y = point.getY() - a.getY();

    // Calculate dot products
    Fixed dot00 = v0x * v0x + v0y * v0y;
    Fixed dot01 = v0x * v1x + v0y * v1y;
    Fixed dot02 = v0x * v2x + v0y * v2y;
    Fixed dot11 = v1x * v1x + v1y * v1y;
    Fixed dot12 = v1x * v2x + v1y * v2y;

    // Calculate barycentric coordinates
    Fixed invDenom = Fixed(1) / (dot00 * dot11 - dot01 * dot01);
    Fixed u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    Fixed v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if point is in triangle
    return (u > Fixed(0)) && (v > Fixed(0)) && (u + v < Fixed(1));
}
```

**Test Cases**:
```cpp
// Triangle vertices
Point A(0, 0);
Point B(10, 0);
Point C(5, 10);

// Test points
Point inside(5, 3);      // Should be inside
Point outside(15, 5);    // Should be outside
Point onEdge(5, 0);      // Should be outside (on edge)
Point vertex(0, 0);      // Should be outside (vertex)

std::cout << "Point (5,3) is " << (bsp(A, B, C, inside) ? "inside" : "outside") << std::endl;
```

**Key Learning Points**:
- Geometric algorithm implementation
- Const member variables and their initialization
- Real-world application of operator overloading
- Precision benefits of fixed-point arithmetic in geometry

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - My First Orthodox Canonical Class
```bash
cd ex00
make
./fixed
```

### Exercise 01 - Towards Useful Fixed-Point Number Class
```bash
cd ex01
make
./fixed
```

### Exercise 02 - Now We're Talking
```bash
cd ex02
make
./fixed
```

### Exercise 03 - BSP
```bash
cd ex03
make
./bsp
# Tests various points against triangle vertices
```

## 🧪 Testing Examples

### Fixed-Point Precision Test
```bash
# Test floating-point precision
Fixed a(42.42f);
Fixed b(42.42f);
std::cout << (a == b) << std::endl;  // Should output: 1 (true)

# Test arithmetic operations
Fixed c = a + b;
Fixed d = a * Fixed(2);
std::cout << (c == d) << std::endl;  // Should output: 1 (true)
```

### BSP Geometric Tests
```cpp
// Triangle: (0,0), (10,0), (5,10)
Point A(0, 0), B(10, 0), C(5, 10);

// Test cases
Point center(5, 3);        // Inside triangle
Point outside(15, 5);      // Outside triangle
Point edge(5, 0);          // On edge (counts as outside)
Point vertex(0, 0);        // On vertex (counts as outside)

std::cout << "Center: " << bsp(A, B, C, center) << std::endl;    // 1
std::cout << "Outside: " << bsp(A, B, C, outside) << std::endl;  // 0
std::cout << "Edge: " << bsp(A, B, C, edge) << std::endl;        // 0
std::cout << "Vertex: " << bsp(A, B, C, vertex) << std::endl;    // 0
```

## 🏗️ Project Structure

```
CPP_Module02/
├── README.md
├── ex00/                    # My First Orthodox Canonical Class
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── Fixed.hpp
│   └── src/
│       ├── Fixed.cpp
│       └── main.cpp
├── ex01/                    # Towards Useful Fixed-Point Number Class
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── Fixed.hpp
│   └── src/
│       ├── Fixed.cpp
│       └── main.cpp
├── ex02/                    # Now We're Talking
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   └── Fixed.hpp
│   └── src/
│       ├── Fixed.cpp
│       └── main.cpp
└── ex03/                    # BSP
    ├── Makefile
    ├── inc/
    │   ├── ansi.h
    │   ├── Fixed.hpp
    │   └── Point.hpp
    └── src/
        ├── Fixed.cpp
        ├── Point.cpp
        ├── bsp.cpp
        └── main.cpp
```

## 💡 Key Takeaways

1. **Orthodox Canonical Form**: Essential for proper C++ class design
2. **Operator Overloading**: Making custom types behave like built-in types
3. **Fixed-Point Arithmetic**: Alternative to floating-point for precision-critical applications
4. **Const Correctness**: Proper use of const methods and parameters
5. **Ad-hoc Polymorphism**: Same interface, different implementations
6. **Geometric Algorithms**: Real-world applications of custom classes
7. **Binary Representations**: Understanding how numbers are stored and manipulated

## 🎯 Skills Developed

- ✅ Orthodox Canonical Form implementation
- ✅ Complete operator overloading suite
- ✅ Fixed-point arithmetic and precision handling
- ✅ Stream operator implementation
- ✅ Const method design and usage
- ✅ Static function overloading
- ✅ Geometric algorithm implementation
- ✅ Custom type design and integration

## ⚠️ Common Pitfalls & Solutions

1. **Operator Precedence**: Remember that custom operators follow standard precedence
2. **Return Types**: Assignment operators should return references to `*this`
3. **Const Correctness**: Comparison operators should be const methods
4. **Pre/Post Increment**: Post-increment should return by value, pre by reference
5. **Fixed-Point Precision**: Be aware of precision limitations in calculations
6. **Copy vs Assignment**: Understand when copy constructor vs assignment operator is called

## 🔗 Mathematical Background

### Fixed-Point Representation
- **Storage**: Integer with implied fractional point
- **Conversion**: `fixed_value = float_value * (2^fractional_bits)`
- **Precision**: `1/(2^fractional_bits)` (e.g., 8 bits = 1/256 ≈ 0.00390625)

### BSP Algorithm
- **Barycentric Coordinates**: Express point position relative to triangle vertices
- **Inside Test**: Point is inside if all barycentric coordinates are positive
- **Edge Cases**: Points on edges or vertices are typically considered outside

## 🔗 Next Steps

After mastering Module 02, you'll be ready to tackle:
- **Module 03**: Inheritance hierarchies and virtual functions
- **Module 04**: Subtype polymorphism and abstract classes
- **Module 05**: Exception handling mechanisms

---

<div align="center">

*"Precision is not just accuracy, it's the foundation of reliable software."*

**Module 02 Complete** ✨ | **Previous**: [← Module 01](../CPP_Module01/README.md) | **Next**: [Module 03 →](../CPP_Module03/README.md)

</div>
