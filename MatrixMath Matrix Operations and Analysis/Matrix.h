/*----------------------------------------------------------------------------
FILE NAME:		Matrix.h
DESCRIPTION:		Matrix class specification 
USAGE:			#include "Matrix.h": in Matrix.cpp
COMPILER:		GNU g++ compiler on Linux
NOTES:			...

MODIFICATION HISTORY:
Author	           Date		Version
-----------        ----------   ------------
Chris Reyes	   2021-04-20	1.0 Basic version
Chris Reyes 	   2021-04-20	2.0 Adds better destructor
Chris Reyes	   2021-04-20   2.0 Templating Matrix class
Chris Reyes	   2021-04-22	4.0 Overloads input/output operators
Chris Reyes	   2021-04-22	5.0 Adds constructors and assignment ops
Chris Reyes	   2021-05-02   6.0 Added Matrix_ops derived class
Chris Reyes	   2021-05-03   7.0 Added overloaded operators in derived class
Chris Reyes	   2021-05-0    8.0 ...Final Version...
----------------------------------------------------------------------------*/
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;


// Base class
template <class T>
class Matrix
{
protected:
	int rows;
	int cols;
	T **array;

public:
	Matrix();				// Default Constructor
	Matrix(int rows, int cols); 		// Overloaded Constructor
	Matrix(const Matrix<T> &);		// Copy Constructor
	~Matrix();				// Destructor

	Matrix<T> &operator=(const Matrix<T> &); // Overloaded assignment

	T get(int i, int j) const;	 	// Accessor
	void set(int i, int j, T k); 		// Mutator
	void display();				// Accessor for output

	template <class T1> 			// Overloaded output op
	friend ostream &operator<<(ostream &, const Matrix<T1> &);
	template <class T1> 			// Overloaded input op
	friend istream &operator>>(istream &, Matrix<T1> &);
};

// Derived class
template <class T>
class Matrix_ops : public Matrix<T>
{
private:
	using Matrix<T>::rows;
	using Matrix<T>::cols;
	using Matrix<T>::array;

public:
	using Matrix<T>::Matrix;
	using Matrix<T>::operator=;

	Matrix_ops<T> operator+(const Matrix_ops<T> &); // Overloaded addition operator
	Matrix_ops<T> operator-(const Matrix_ops<T> &); // Overloaded subtraction operator
	bool operator==(const Matrix_ops<T> &);		// Overloaded equality operator
	Matrix_ops<T> operator*(const Matrix_ops<T> &); // Overloaded multiplication operator
	Matrix_ops<T> operator*(T);			// Overloaded multiplication operator
	Matrix_ops<T> trans();				// Transpose a matrix	
};
#endif
