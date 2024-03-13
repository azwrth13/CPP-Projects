/*----------------------------------------------------------------------------
FILE NAME:		Matrix.cpp
DESCRIPTION:		Matrix class implementation
USAGE:			#include "Matrix.cpp" in matrix_test5.cpp
COMPILER:		GNU g++ compiler on Linux
NOTES:			...

MODIFICATION HISTORY:
Author	           Date		Version
-----------        ----------   ------------
Chris Reyes        2021-04-20   1.0 Basic version
Chris Reyes	   2021-04-22	2.0 Adds better destructor
Chris Reyes	   2021-04-25	3.0 Converts to template data types
Chris Reyes	   2021-04-27	4.0 Overloads input/output operators
Chris Reyes	   2021-04-30	5.0 Adds constructors and assignment ops
Chris Reyes	   2021-05-07   6.0 Final version
----------------------------------------------------------------------------*/

#include "Matrix.h"

/*---------------------------------------------------------------------------
FUNCTION:	Matrix()
DESCRIPTION:	Default constructor
RETURNS: 	Nothing	
NOTES:		Initializes (assigns) rows, cols, and array to zero or NULL 
----------------------------------------------------------------------------*/
template <class T>
Matrix<T>::Matrix()
{
	rows = 0;
	cols = 0;

	array = NULL;
#ifdef TEST
	cout << "Default constructor:  " << rows << " X " << cols << endl;
#endif
}

/*---------------------------------------------------------------------------
FUNCTION:	Matrix()
DESCRIPTION:	Overloaded constructor
RETURNS:	Nothing
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new T *[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];

		for (int j = 0; j < cols; j++) // Not neccesary until
			array[i][j] = 0;		   // multiplication
	}
#ifdef TEST
	cout << "Ovrlded constructor:  " << rows << " X " << cols << endl;
#endif
}

/*---------------------------------------------------------------------------
FUNCTION:	Matrix()
DESCRIPTION:	Copy constructor
RETURNS:	Nothing
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix<T>::Matrix(const Matrix<T> &m)
{
	rows = m.rows;
	cols = m.cols;

	array = new T *[rows];

#ifdef TEST
	cout << "Cpy     constructor:  " << rows << " X " << cols << endl;
#endif

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = m.array[i][j];
		}
	}
}

// Assignment operator
/*---------------------------------------------------------------------------
FUNCTION:	Operator = ()
DESCRIPTION:	Assignment operator
RETURNS:	
NOTES:		*this
----------------------------------------------------------------------------*/
template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &m)
{
	for (int i = 0; i < rows; i++) // delete lhs matrix
	{
		delete[] array[i];
	}
	delete[] array;

	rows = m.rows;
	cols = m.cols;

	array = new T *[rows];

#ifdef TEST
	cout << "Asgmnt operator = :   " << rows << " X " << cols << endl;
#endif

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = m.array[i][j];
		}
	}
	return *this;
}

/*---------------------------------------------------------------------------
FUNCTION:	get()
DESCRIPTION:	Accessor
RETURNS:	array[i][j]
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
T Matrix<T>::get(int i, int j) const
{
	return array[i][j];
}

/*---------------------------------------------------------------------------
FUNCTION:	set()
DESCRIPTION:	Settor
RETURNS:	
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
void Matrix<T>::set(int i, int j, T val)
{
	array[i][j] = val;
}

/*---------------------------------------------------------------------------
FUNCTION:	display()
DESCRIPTION:	Displays matrix
RETURNS:	
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
void Matrix<T>::display()
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(6) << get(i, j);
		}
		cout << endl;
	}
	cout << endl;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator << ()
DESCRIPTION:	Displays matrix 	
RETURNS:	out
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
ostream &operator<<(ostream &out, const Matrix<T> &mat)
{
	out << setw(6) << mat.rows << " X " << mat.cols << endl;

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			out << setw(6) << mat.array[i][j];
		}
		out << endl;
	}
	return out;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator >> ()
DESCRIPTION:	Inputs matrix
RETURNS:	in
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
istream &operator>>(istream &in, Matrix<T> &m1)
{
	char let_x;
	int m, n;

#ifdef TEST
	cout << "Input  operator >> :  " << endl;
#endif

	in >> m >> let_x >> n;
	Matrix<T> mat(m, n); // Creates temp matrix from input

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			in >> mat.array[i][j];
		}
	}
	m1 = mat; // Overwrites rhs matrix using =
	return in;
}

/*---------------------------------------------------------------------------
FUNCTION:	~Matrix ()
DESCRIPTION:	Destructor
RETURNS:	
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
#ifdef TEST
	cout << "Matrix  destructor :  " << rows << " X " << cols << endl;
#endif
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator + ()
DESCRIPTION:	Adds two matrices
RETURNS:	m3
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator+(const Matrix_ops<T> &m2)
{
	if (rows != m2.rows || cols != m2.cols)
	{
		cout << "Addition:	Invalid Dimensions" << endl;
		Matrix_ops<T> m3; // return null matrix
		return m3;
	}

	Matrix_ops<T> m3(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3.array[i][j] = array[i][j] + m2.array[i][j];
		}
	}
	return m3;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator - ()
DESCRIPTION:	Subtracts two matrices
RETURNS:	m3
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator-(const Matrix_ops<T> &m2)
{
	if (rows != m2.rows || cols != m2.cols)
	{
		cout << "Subtraction:	Invalid Dimensions" << endl;
		Matrix_ops<T> m3; // return null matrix
		return m3;
	}

	Matrix_ops<T> m3(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3.array[i][j] = array[i][j] - m2.array[i][j];
		}
	}
	return m3;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator == ()
DESCRIPTION:	Tests equality of two matrices
RETURNS:	status
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
bool Matrix_ops<T>::operator==(const Matrix_ops<T> &m2)
{
	bool status = true;

	if ((rows != m2.rows) || (cols != m2.cols))
		status = false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] != m2.array[i][j])
			{
				status = false;
			}
		}
	}
	return status;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator * ()
DESCRIPTION:	Scales a matrix
RETURNS:	m3
NOTES:		Not currently in use	
----------------------------------------------------------------------------*/
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator*(T z)
{
	Matrix_ops<T> m3(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3.array[i][j] = array[i][j] * z;
		}
	}
	return m3;
}

/*---------------------------------------------------------------------------
FUNCTION:	Operator * ()
DESCRIPTION:	Multiplies two matrices
RETURNS:	m3
NOTES:		
----------------------------------------------------------------------------*/
template <class T>
Matrix_ops<T> Matrix_ops<T>::operator*(const Matrix_ops<T> &m2)
{
	if (cols != m2.rows)
	{
		cout << "Multiplication: Invalid dimensions" << endl;
		Matrix_ops<T> m3;
		return m3;
	}

	Matrix_ops<T> m3(rows, m2.cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m2.cols; j++)
		{
			for (int k = 0; k < rows; k++)
			{
				m3.array[i][j] += array[i][k] * m2.array[k][j];
			}
		}
	}
	return m3;
}

/*---------------------------------------------------------------------------
FUNCTION:	trans()
DESCRIPTION:	Transpose a matrix
RETURNS:	m3
NOTES:		Opted to store transposed matrix in new matrix, to be able
		to return it
----------------------------------------------------------------------------*/
template <class T>
Matrix_ops<T> Matrix_ops<T>::trans()
{
	Matrix_ops<T> m3(cols, rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3.array[j][i] = array[i][j];
		}
	}
	return m3;
}
