/*----------------------------------------------------------------------------
FILE NAME:		matrix_math.cpp
DESCRIPTION:		Test program for Matrix class
USAGE:			./matrix_math -inp A
		or	./matrix_math -inp A -out X
		or	./matrix_math -inp A + B 
COMPILER:		GNU g++ compiler on Linux
NOTES:			...

MODIFICATION HISTORY:
Author	           Date		Version
-----------        ----------   ------------
Chris Reyes        2021-04-20   1.0 Basic version
Chris Reyes	   2020-04-20   2.0 Reads files using cmd-line args
				    and uses "cmd" string for args
Chris Reyes			3.0 Converts to template data types
Chris Reyes			4.0 Overloads input/output operators
				    and adds -out option
Chris Reyes			5.0 Uses while loop for command-line args
				    Tests = operator and Copy Constructor
Chris Reyes			6.0 Copied over from Lab7 to create Proj3	
----------------------------------------------------------------------------*/
//#include "Matrix.h"		// Specification file
#include "Matrix.cpp"		// Implementation file, compiled together

const char PROGRAMMER_NAME[] = "Christopher Reyes";	// Global constant

typedef unsigned char byte;

//#define TEST_OPS

//------MACROS-------
//#define TEST
//#define TYPE  int
//#define TYPE double
//#define TYPE byte
//--------------------

// Prototypes
int open_file (ifstream &infile,  string name, int &err);
int write_file(ofstream &outfile, string name, int &err);
int arg_count (int argc, int num, int &err); 

/*---------------------------------------------------------------------------
FUNCTION:	main()
DESCRIPTION:	Reads matrix from a file, creates a Matrix object,
		and displays it to the screen.
RETURNS:	0
NOTES:		int argc	// Number of parameters on the command line
		char *argv[]	// An array of pointers to C-strings
----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int err = 0;
	ifstream infile1, infile2;
	ofstream outfile;
	string cmd, name1, name2;
	
	Matrix_ops<double> mat1, mat2, mat3;	// Creates 3 default matrices

	if (arg_count(argc, 2, err))	return err;

	while(--argc)
	{
		cmd = *++argv;
		cout << "argc = " << argc << " - " << *argv << endl;

		if (cmd == "-inp")
		{
			if (arg_count(--argc, 1, err))	return err;
			name1 = *++argv;
			open_file(infile1, name1, err);		// Read file 1
			if (err)	return err;
			infile1 >> mat1;
			mat3 = mat1;
		}
		
		else if (cmd == "-out")
		{
			if (arg_count(--argc, 1, err))	return err;
			name2 = *++argv;
			write_file(outfile, name2, err);
			if (err)	return err;
		}

		else if (argc >= 3)
		{
			name1 = *argv;
			cmd   = *++argv;
			cout << "cmd = " << cmd << endl;
			name2 = *++argv;

			if (cmd == "+" || cmd == "-")
			{
				open_file(infile1, name1, err);		// Read file 1
				open_file(infile2, name2, err);		// Read file 2
				
				if (err)	return err;
				infile1 >> mat1;
				infile2 >> mat2;
			}
			
			if (cmd == "+")
			{
				cout << "Addition test...  " << endl;
				mat3 = mat1 + mat2;
			}
			
			else if (cmd == "-")
			{
				cout << "Subtraction test... " << endl;
				mat3 = mat1 - mat2;
			}
			
			else cout << "Invalid operation\n" << endl;
			argc -= 2;
		}
		else cout << "Unknown command\n" << endl;
	}
	
	cout << "Input 1:  mat1" << endl;
	cout << mat1;

	cout << "Input 2:  mat2" << endl;
	cout << mat2;

	cout << "Results:  mat3" << endl;
	cout << mat3;
		
//	cout << "Assignment test:  mat2 = mat1;" << endl;
//	mat2 = mat1;
//	cout << mat2;



//	cout << "Copy constructor test:  Matrix<T>mat4 = mat2;" << endl;
//	Matrix_ops<double> mat4 = mat2;
//	cout << mat4;

	if (outfile) outfile << mat3;
	outfile.close();
	infile1.close();
	infile2.close();
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << " " << __TIME__ << endl;
	cout << endl;
	
	return 0;
}

// Open file func
int open_file(ifstream &infile, string name, int &err)
{
	string filename = "DATA/";
	filename += name;
	filename += ".mtx";
	
	infile.open(filename);

	if (!infile)			// Test for errors.
	{
		cout << "\nError opening file: " << filename << "\n\n";
		err = 2;
	}
	else cout << "Opened: " << filename << endl;

	return err;
}

// Write file func
int write_file(ofstream &outfile, string name, int &err)
{
	string filename = "DATA/";
	filename += name;
	filename += ".mtx";
	
	outfile.open(filename);
	
	if (!outfile)			// Test for errors.
	{	
		cout << "\nError opening file: " << filename << "\n\n";
		err = 2;
	}
	else cout << "Output: " << filename << endl;

	return err;
}

// arg_count function
int arg_count(int argc, int num, int &err)
{
	if (argc < num)
	{
		cout << "Not enough Arguments ?\n\n";
		err = 1;
	}
	return err;
}
