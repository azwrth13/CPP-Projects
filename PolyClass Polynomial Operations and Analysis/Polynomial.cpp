/*----------------------------------------------------------------------------
FILENAME:               Polynomial.cpp
DESCRIPTION:            Contains overloaded functions 
USAGE:			Implementation file for Polynomial Class
COMPILER:               GNU g++ compiler on Linux
NOTES:                  Linked with Polynomial.h

MODIFICATION HISTORY:
Author             Date         Version
--------------     ----------   --------------
Chris Reyes        2021-04-01   1.0 Added contructor and destructor
Chris Reyes        2021-04-03   1.1 Added overloaded operators
Chris Reyes        2021-04-06   1.2 Added more overloaded operators
Chris Reyes        2021-04-13   1.3 Added Copy Con and Overloaded Con
----------------------------------------------------------------------------*/
#include "Polynomial.h"


/*----------------------------------------------------------------------------
FUNCTION:		Polynomial()
DESCRIPTION:		Constructor
RETURNS:		Nothing
NOTES:			Default constructor that init all values to 0
----------------------------------------------------------------------------*/
Polynomial::Polynomial()		// Constructor
{
	degree = 0;
	indef = 0;
	
	for (int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i] = 0;
}

/*----------------------------------------------------------------------------
FUNCTION:		Polynomial(const Polynomial &)
DESCRIPTION:		Copy Contructor
RETURNS:		Nothing
NOTES:			From CS202
----------------------------------------------------------------------------*/
Polynomial::Polynomial(const Polynomial &poly)	// Copy Constructor
{
	degree = poly.degree;
	indef = poly.indef;

	for (int i = 0; i < ARRAY_SIZE(coef); i++)
	{
		coef[i] = poly.coef[i];
	}
}

/*----------------------------------------------------------------------------
FUNCTION:		Polynomial(int, double [])
DESCRIPTION:		Overloaded Constructor
RETURNS:		Nothing
NOTES:			From CS202
----------------------------------------------------------------------------*/
Polynomial::Polynomial(int deg, double c[])		//Overloaded Constructor
{
	degree = deg;
	indef = 0;

	for (int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i] = 0;

	for (int i = 0; i <= degree; i++)
		coef[i] = c[i];
}

/*----------------------------------------------------------------------------
FUNCTION:		~Polynomial()
DESCRIPTION:		Destructor
RETURNS:		Nothing
NOTES:
----------------------------------------------------------------------------*/
Polynomial::~Polynomial()	// Destructor
{
		
}

/*----------------------------------------------------------------------------
FUNCTION:		operator + 
DESCRIPTION:		Adds two polynomials
RETURNS:		p2
NOTES:		
----------------------------------------------------------------------------*/
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;
	
//	cout << "\nAdding 2 polynomials: ";
	
	p2.degree = MAX(degree, p1.degree);
	
	for (int i = p2.degree; i >= 0; i--)
	{
		p2.coef[i] = coef[i] + p1.coef[i];
	}	
	return p2;
}

/*----------------------------------------------------------------------------
FUNCTION:		operator -
DESCRIPTION:		Subtracts two polynomials
RETURNS:		p2
NOTES:
----------------------------------------------------------------------------*/
Polynomial Polynomial::operator - (const Polynomial &p1)
{
	Polynomial p2;
	
//	cout << "\nSubtracting 2 polynomials: ";
	
	p2.degree = MAX(degree, p1.degree);
	
	for (int i = p2.degree; i >= 0; i--)
	{
		p2.coef[i] = coef[i] - p1.coef[i];
	}	
	return p2;
}

/*----------------------------------------------------------------------------
FUNCTION:		operator *
DESCRIPTION:		Multiplies two polynomials
RETURNS:		p2
NOTES:
----------------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const Polynomial &p1)
{
	Polynomial p2;
	
//	cout << "\nMultiplying 2 polynomials: ";

	p2.degree = degree + p1.degree;

	for (int i = 0; i < degree+1; i++)
	{
		for (int j = 0; j < p1.degree+1; j++)
		{
			p2.coef[i+j] += coef[i] * p1.coef[j];
		}
	}
	return p2;
}

/*----------------------------------------------------------------------------
FUNCTION:		operator << 
DESCRIPTION:		Outputs polynomial
RETURNS:		strm
NOTES:
----------------------------------------------------------------------------*/
ostream &operator << (ostream &strm, const Polynomial &poly)
{
	Polynomial z; 	// Dummy polynomial for uniExpo function
	string x;
	
	int j;
	if (poly.indef) j = 1;
	else j = 0;

	for (int i = poly.degree; i >= 0; i--)
	{
		if(i < poly.degree)
		{
			if(poly.coef[i] >= 0) strm << " +";
			else strm << " ";	
		}
		
		strm << poly.coef[i];


		if (j == 1 && i == 0) strm << " +C";
		if (i >= 1) 
		{
		 	x = uniExpo(i, z);	
			strm << x;
			
		
		}
		
	}
	strm << endl;

	return strm;
}

/*----------------------------------------------------------------------------
FUNCTION:		operator >>
DESCRIPTION:		Input degree and coef[] for polynomial
RETURNS:		strm
NOTES:
----------------------------------------------------------------------------*/
istream &operator >> (istream &strm, Polynomial &poly)
{
	cout << "\nDegree of polynomial: ";
	strm >> poly.degree;

	cout << " \nEnter " << poly.degree+1 << " coefficients: ";

	for (int i = poly.degree; i >= 0; i--)
		strm >> poly.coef[i];

	return strm;
}

/*----------------------------------------------------------------------------
FUNCTION:		uniExpo(int i, Polynomial &p)
DESCRIPTION:		Array of Unicode for exponent
RETURNS:		s
NOTES:			From CS202
			Includes dummy polynomial parameter 
			in order to be a friend
----------------------------------------------------------------------------*/
string uniExpo(int i, Polynomial &p)
{
			// Array of Unicode superscripts 
	const char* sup[] = {   "\u2070", "\u00B9", "\u00B2", 
				"\u00B3", "\u2074", "\u2075",
				"\u2076", "\u2077", "\u2078", 
				"\u2079", "\u207A", "\u207B" };

	string s = "x";
	
	s = "x";
	if (i >= 100) s += sup[i/100];
	if (i >= 10)  s += sup[i%100/10];
	s += sup[i%10];   
	
	return s;
}	

/*----------------------------------------------------------------------------
FUNCTION:		operator ()
DESCRIPTION:		Evaluates polynomial f(x)
RETURNS:		val
NOTES:
----------------------------------------------------------------------------*/
double Polynomial::operator() (double x)
{
	double val = 0;
	
	for (int i = 0; i <= degree; i++)
	{
		val += coef[i] * pow(x, i);
	}
	return val;
}
/*----------------------------------------------------------------------------
FUNCTION:		operator =
DESCRIPTION:		Assigns one polynomial to another
RETURNS:		*this
NOTES:			From CS202
----------------------------------------------------------------------------*/
Polynomial& Polynomial::operator = (const Polynomial &poly)
{
	if (this != &poly)
	{
		degree = poly.degree;

		for (int i = 0; i < ARRAY_SIZE(coef); i++)
		{
			coef[i] = poly.coef[i];
		}
	}
	return *this;
}
/*----------------------------------------------------------------------------
FUNCTION:		operator ==
DESCRIPTION:		Tests equality between two polynomials
RETURNS:		status
NOTES:			boolean function
----------------------------------------------------------------------------*/
bool Polynomial::operator == (const Polynomial &poly)
{
	bool status;

	if (degree != poly.degree) status = false;

	for (int i = 0; i < degree+1; i++)
	{
		if (coef[i] != poly.coef[i])
		{
			status = false;
			break;
		}
	}
	return status;
}
/*----------------------------------------------------------------------------
FUNCTION:		operator -- 
DESCRIPTION:		Differentiates polynomial
RETURNS:		*this
NOTES:			Differentiates using power rule
			From CS202
----------------------------------------------------------------------------*/
Polynomial& Polynomial::operator -- (int)
{
	coef[0] = 0;

	for (int i = 1; i <= degree; i++)
	{
	coef[i-1] = coef[i] * i;
	}

	coef[degree--] = 0;

	if (degree < 0)
	{
	degree = 0;
	}

	return *this;
}

/*----------------------------------------------------------------------------
FUNCTION:		operator ++  
DESCRIPTION:		Takes the indef integral
RETURNS:		*this
NOTES:			
			
----------------------------------------------------------------------------*/
Polynomial& Polynomial::operator ++ (int)
{
	
	degree++;

	for (int i = degree; i > 0; i--)	
	{
		coef[i] = coef[i-1]/i; 	
	}
	
	coef[0] = 0;
	indef = true;

	return *this;
}
