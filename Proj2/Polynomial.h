/*----------------------------------------------------------------------------
FILENAME:               Polynomial.h
DESCRIPTION:            Header file for poly_class.cpp and Polynomial.cpp
USAGE:			Class declaration, prototypes, and ADTS
COMPILER:               GNU g++ compiler on Linux
NOTES:                  

MODIFICATION HISTORY:
Author             Date         Version
--------------     ----------   --------------
Chris Reyes        2021-02-28   1.0 Created class and ADT's
Chris Reyes        2021-02-29   1.1 Added library <cmath>
Chris Reyes        2021-03-03   1.2 Added overloaded operators +-*
Chris Reyes        2021-03-04   1.3 Added overloaded operators >> <<
Chris Reyes        2021-03-04   1.4 Added overloaded operators ()==--=
----------------------------------------------------------------------------*/
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
 
#include <iostream>
#include <cmath>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

const char PROGRAMMER_NAME[] = "Christopher Reyes";

class Polynomial			// Polynomial class definition
{
	private:
		int degree;		// Degree of polynomial 
		double coef[9];		// Array of coefficients
		bool indef;		// Flag to print constant C if indef

	public:
		Polynomial  (                  );		// Constructor
		~Polynomial (                  );		// Destructor
		Polynomial  (const Polynomial &);		// Copy Constructor
		Polynomial  (int, double []);			// Overloaded Constructor
			
		Polynomial  operator +  (const Polynomial &);	// Addition
		Polynomial  operator -  (const Polynomial &);	// Subtraction
		Polynomial  operator *  (const Polynomial &);	// Multiplication
		Polynomial& operator =  (const Polynomial &);	// Assignment
		bool	    operator == (const Polynomial &);	// Equality
		double      operator () (double);	 	// Evaluation	
		
		Polynomial& operator -- (int);			// Post decrement derivative
		Polynomial& operator ++ (int);			// Post increment indef integral


		friend istream &operator >> (istream &, Polynomial &);		//Input polynomial
		friend ostream &operator << (ostream &, const Polynomial &);	//Output polynomial
		friend string uniExpo(int i, Polynomial &);			// Unicode exponent
};

#endif /*__POLYNOMIAL_H__ */
