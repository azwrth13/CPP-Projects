/*----------------------------------------------------------------------------
FILE NAME:		poly_class.cpp
DESCRIPTION:		Driver file for proj2
USAGE:			./poly_class
COMPILER:		GNU g++ compiler on Linux
NOTES:			

MODIFICATION HISTORY:
Author	           Date		Version
-----------        ----------   ------------
Chris Reyes	   2021-04-13	1.0 Created Polynomials 
Chris Reyes 	   2021-04-14   2.0 Added functions
Chris Reyes        2021-04-15   3.0 Laid out structure of main()
Chris Reyes        2021-04-16   4.0 Final version
----------------------------------------------------------------------------*/

//#include "Polynomial.cpp"	// Implementation file
#include "Polynomial.h"	// Specification file



//Prototypes
void evaluate(Polynomial &, int);
void calc(Polynomial &);
void compare(Polynomial &, Polynomial &);

/*----------------------------------------------------------------------------
FUNCTION:		main()
DESCRIPTION:		Driver file
RETURNS:		0
NOTES:
----------------------------------------------------------------------------*/
int main()
{

	Polynomial f, g, poly[3];

	for (int n = 0; n < 2; n++)
	{
		cin >> poly[n];
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "\nPoly " << i+1 << ": ";
		cout << " p" << i+1 << "(x) = " << poly[i]; 
	}	

	cout << endl;

// Copy Constructor
	Polynomial h = *poly;
	h = poly[0];
	cout << "Cpy Ctor: h(x) = " << h;

// Addition
	cout << "Poly 1 + Poly 2: ";
	poly[2] = poly[0] + poly[1];
	cout << poly[2];

// Subtraction
	cout << "Poly 1 - Poly 2: ";
	poly[2] = poly[0] - poly[1];
	cout << poly[2];

// Multiplication
	cout << "Poly 1 * Poly 2: ";
	poly[2] = poly[0] * poly[1];
	cout << poly[2];


// Eval and Deriv	
	for (int i = 0; i <= 2; i++)
	{

// Evalutation
		evaluate(poly[i], i);

// Derivative and Integral	
		calc(poly[i]);
	}
	
	
// Assignment
	cout << "\nTesting multiple assignments...";
	cout << "\nf = g = p3" << endl;
	f = g = poly[2];
	cout << "p3: " << poly[2];
	cout << "g:  " << g;
	cout << "f:  " << f;
	cout << endl;

// Comparison
	cout << "Testing equality operator (==)\n";
	cout << "p3 vs. f:  ";
	compare(poly[2], f);
 
	cout << "p3 vs. g:  ";
	compare(poly[2], g);

	cout << "p3 vs. p1: ";
	compare(poly[2], poly[0]);
	
// Overloaded Constructor
	
	int nDeg  = 9;
	double array [10] = {1, 2, 3, 4, 5,
			     6, 7, 8, 9, 10};

	Polynomial oPoly(nDeg, array);
	cout << "\nOverloaded Constructor test...\n";
	cout << "f(x) = " << oPoly;
	
	


	cout << endl << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << " " << __TIME__ << endl;
	cout << endl;
	
	return 0;
}

/*----------------------------------------------------------------------------
FUNCTION:		evaluate(Polynomial &, int)
DESCRIPTION:		evaluates a polynomial at given value
RETURNS:		nothing
NOTES:			
----------------------------------------------------------------------------*/
void evaluate(Polynomial &p, int i)
{
	double x;
	
	cout << "\nEvaluate poly " << i+1 << ": f(x) = " << p;
	cin >> x;
	cout << "At input value : x = " << x;
	cout << "\n\t\t f(" << x << ") = " << p(x) << endl;
}

/*----------------------------------------------------------------------------
FUNCTION:		compare(Polynomial &, Polynomial &)
DESCRIPTION:		compares two polynomials 
RETURNS:		nothing
NOTES:			using overloaded (==) operator
----------------------------------------------------------------------------*/
void compare(Polynomial &p1, Polynomial &p2)
{
	cout << "";	// For some reason if there is no space here
			// the evaluation is false

	if(p1 == p2)
		cout << "True\n";
	else
		cout << "False\n";
}

/*----------------------------------------------------------------------------
FUNCTION:		calc(Polynomial &)
DESCRIPTION:		differentiates and integrates a polynomial
RETURNS:		nothing
NOTES:			using overloaded (--) operator (prefix)
			and overloaded (++) operator (postfix)
----------------------------------------------------------------------------*/
void calc(Polynomial &p)
{
	Polynomial f;

	f = p;
	cout << "Derivative of f: f'(x) = " << f--;

	f = p;
	cout << "Indef. Integral: F(x) = " << f++;	
}
