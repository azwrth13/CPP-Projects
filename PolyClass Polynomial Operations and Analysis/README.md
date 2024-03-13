# PolyClass: Polynomial Operations and Analysis

## Introduction

PolyClass is a C++ program designed for performing various operations on polynomials, including addition, subtraction, multiplication, differentiation, and indefinite integration. It leverages the power of object-oriented programming to manipulate polynomial objects, offering an intuitive and efficient way to work with polynomial equations.

## Features

- **Polynomial Operations:** Supports basic arithmetic operations (addition, subtraction, multiplication) on polynomials.
- **Polynomial Derivation and Integration:** Allows for the calculation of the derivative and indefinite integral of polynomial expressions.
- **Polynomial Evaluation:** Enables evaluating polynomial expressions for a given value of x.
- **Overloaded Operators:** Utilizes C++ operator overloading to make polynomial operations more intuitive, such as using `+`, `-`, `*` for arithmetic, `>>` and `<<` for input and output, and more.
- **Dynamic Polynomial Degree and Coefficients:** Supports polynomials of varying degrees with dynamic input for coefficients.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GNU g++)
- Basic knowledge of C++ and terminal/command line usage

### Compilation

To compile PolyClass, you'll need the source code files (`Polynomial.h`, `Polynomial.cpp`, `poly_class.cpp`) and a Makefile. Compile the program using the Makefile provided:

```bash
make
```

This command will compile the source code and generate an executable named `poly_class`.

### Running the Program

To run PolyClass, simply execute the compiled binary:

```bash
./poly_class
```

The program will prompt you to enter polynomial degrees and coefficients, followed by the choice of operation you'd like to perform.

## Usage Examples

PolyClass supports a variety of operations that you can perform on polynomials. Here are some examples of how you can use it:

1. **Adding Polynomials:**
   Input two polynomials when prompted and select the addition operation to see the resulting polynomial.

2. **Finding the Derivative:**
   After entering a polynomial, choose the option to differentiate it and see the derivative polynomial.

3. **Evaluating a Polynomial:**
   Enter a polynomial and then choose to evaluate it at a specific value of x.

## Testing

Included in the PolyClass package are several shell scripts (`test_poly.sh`, `test_bi.sh`, `test_poly0.sh`) designed to test various functionalities of the program, from basic operations to more complex scenarios involving bi-variate polynomials and zero-degree polynomials.

To run the tests, execute the shell scripts from your terminal:

```bash
./test_poly.sh
```

## License

This project is open-source and available under the MIT License.

## Author

- **Christopher Reyes**

PolyClass aims to provide an easy-to-use and comprehensive tool for polynomial manipulation, suitable for educational purposes, mathematical analysis, and more.
