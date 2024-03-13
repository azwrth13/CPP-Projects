# MatrixMath: Matrix Operations and Analysis

## Introduction

MatrixMath is a versatile C++ program designed for matrix manipulation, providing functionalities such as matrix addition, subtraction, multiplication, equality testing, and transposition. Built on a template class, it supports operations on matrices of various data types, offering flexibility for mathematical computations and analysis.

## Features

- **Matrix Operations:** Supports addition, subtraction, and multiplication of matrices.
- **Matrix Equality:** Compares two matrices for equality, allowing for precise validation of matrix operations.
- **Matrix Transposition:** Calculates the transpose of a given matrix, useful for various linear algebra applications.
- **Flexible Data Types:** Utilizes C++ templates, enabling operations on matrices of integers, floating-point numbers, or any other data types.
- **File Input/Output:** Reads matrices from files and writes operation results back, facilitating data persistence and analysis.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GNU g++)
- Basic understanding of matrix operations and C++ programming

### Compilation

Use the provided Makefile to compile the MatrixMath program. In your terminal, navigate to the project directory and run:

```bash
make
```

This compiles the source code and generates an executable named `matrix_math`.

### Running the Program

To perform matrix operations, run the compiled executable followed by the desired commands and arguments. The program supports various command-line arguments for different operations.

Examples:

```bash
./matrix_math -inp A                # Reads matrix A from file
./matrix_math A + B                 # Adds matrices A and B
./matrix_math A x B                 # Multiplies matrices A and B
./matrix_math -inp A -out Result    # Reads matrix A and writes to file "Result"
./matrix_math -T A                  # Transposes matrix A
```

## Usage Examples

MatrixMath can be used for a wide range of matrix operations. Here are a few examples:

- **Adding Two Matrices:**
  To add matrix A to matrix B, use:
  ```bash
  ./matrix_math A + B
  ```

- **Multiplying Two Matrices:**
  For matrix multiplication, use:
  ```bash
  ./matrix_math A x B
  ```

- **Transposing a Matrix:**
  To transpose matrix A, use:
  ```bash
  ./matrix_math -T A
  ```

## Testing

The program includes test scripts (`test_mat1.sh` and `test_mat2.sh`) to demonstrate and validate the functionalities with predefined matrices. Execute these scripts to run the tests:

```bash
./test_mat1.sh
./test_mat2.sh
```

## License

MatrixMath is open-source software available under the MIT License.

## Author

- **Christopher Reyes**

Explore the power of matrix operations with MatrixMath, your go-to tool for mathematical computations and linear algebraic analyses.
