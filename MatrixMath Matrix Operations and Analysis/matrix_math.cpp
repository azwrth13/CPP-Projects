/*----------------------------------------------------------------------------
FILE NAME:		matrix_math.cpp
DESCRIPTION:		Test program for Matrix class
USAGE:			./matrix_math -inp A
		or	./matrix_math -inp A -out X
		or	./matrix_math -h (help menu) 
COMPILER:		GNU g++ compiler on Linux
NOTES:			...

MODIFICATION HISTORY:
Author	           Date		Version
-----------        ----------   ------------
Chris Reyes        2021-04-20   1.0 Basic version
Chris Reyes	   2021-04-20   2.0 Reads files using cmd-line args
		   		    and uses "cmd" string for args
Chris Reyes	   2021-04-24	3.0 Converts to template data types
		
Chris Reyes	   2021-04-26	4.0 Overloads input/output operators
		   		    and adds -out option
Chris Reyes	   2021-04-28	5.0 Uses while loop for command-line args
		   		    Tests = operator and Copy Constructor
Chris Reyes	   2021-04-29	6.0 Copied over from Lab7 to create Proj3	
Chris Reyes	   2021-04-30	7.0 Added new matrix_ops objects
Chris Reyes	   2021-05-01	8.0 Added helper functions and help menu
Chris Reyes 	   2021-05-06	9.0 Final Version
----------------------------------------------------------------------------*/
//#include "Matrix.h"		// Specification file
#include "Matrix.cpp" // Implementation file, compiled together

const char PROGRAMMER_NAME[] = "Christopher Reyes"; // Global constant

typedef unsigned char byte;


// Prototypes
int open_file(ifstream &infile, string name, int &err);
int write_file(ofstream &outfile, string name, int &err);
int arg_count(int argc, int num, int &err);
void help ();

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
	int num;
	ifstream infile1, infile2;
	ofstream outfile;
	string cmd, name1, name2;
	// bool's to be used to print to screen
	bool flag  = true;
	bool flag2 = true;
	bool flag3 = true; 	 

	Matrix_ops<double> mat1, mat2, mat3; // Creates 3 default matrices



	if (arg_count(argc, 2, err))	return err;


	while (--argc)
	{
		cmd = *++argv;

		if (cmd == "-h")
		{
			help();
			flag  = false;
			flag2 = false;
			flag3 = false;
		}
		
		else if (cmd == "-inp")
		{
			if (arg_count(--argc, 1, err))	return err;
			
			name1 = *++argv;
			open_file(infile1, name1, err); // Read file 1
			
			if (err)	return err;
			
			infile1 >> mat1;
			mat3 = mat1;
			flag2 = false;
		}

		else if (cmd == "-out")
		{
			if (arg_count(--argc, 1, err))	return err;
			
			name2 = *++argv;
			write_file(outfile, name2, err);
			
			if (err)	return err;
		}
	        
		else if (cmd == "-T")
		{
			if (arg_count(--argc, 1, err))	return err;
			
			name1 = *++argv;
			open_file(infile1, name1, err);
		
			if (err)	return err;

			infile1 >> mat1;
			cout << "Transpose matrix:\n";
			mat3 = mat1.trans();
			flag2 = false;
		}
	
		else if (argc >= 3)
		{
			name1 = *argv;
			cmd = *++argv;
			
			name2 = *++argv;

			if (cmd == "+" || cmd == "-" || cmd == "==" || cmd == "x")
			{
				

				open_file(infile1, name1, err); // Read file 1
				open_file(infile2, name2, err); // Read file 2

				if (err)	return err;
			
				infile1 >> mat1;
				infile2 >> mat2;
			}

			if (cmd == "+")
			{
				cout << "Addition test: " << name1 << " + " << name2 << endl;
				mat3 = mat1 + mat2;
			}

			else if (cmd == "-")
			{
				cout << "Subtraction test: " << name1 << " - " << name2 << endl;
				mat3 = mat1 - mat2;
			}

			else if (cmd == "==")
			{
				cout << "Equality test: " << name1 << " == " << name2 << endl;
				if (mat1 == mat2)
					cout << "Matrices are the same!\n";
				else
					cout << "Matrices are not the same!\n";
				flag = false;
			}

			else if (cmd == "x")
			{
				
				cout << "Multiplication test: " << name1 << " x " << name2 << endl;
				mat3 = mat1 * mat2;
			}

			else
				cout << "Invalid operation\n" << endl;
				argc -= 2;
		}
	
		else	cout << "Unknown command\n" << endl;
	}

	if (flag3){
	cout << "Input 1:  mat1" << endl;
	cout << mat1;}
	
	if (flag2){
	cout << "Input 2:  mat2" << endl;
	cout << mat2;}

	if (flag){
	cout << "Results:  mat3" << endl;
	cout << mat3;}

	if (outfile)
		outfile << mat3;

	outfile.close();
	infile1.close();
	infile2.close();

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << " " << __TIME__ << endl;
	cout << endl;

	return 0;
}

/*---------------------------------------------------------------------------
FUNCTION:	help()
DESCRIPTION:	Used in cmd line args to display what program can do
RETURNS:	Nothing (void)
NOTES:		
----------------------------------------------------------------------------*/
void help()
{
	cout << "\n   List of commands for program\n";
	cout << "----------------------------------\n\n";
	cout << "  -h		: Help menu		  e.g. -h\n";
	cout << "  -inp		: Input matrix, 	  e.g. -inp A\n";
	cout << "  -out		: Output matrix to file,  e.g. cmd... -out X\n";
	cout << "  +		: Add two matrices,	  e.g. A + B\n";
	cout << "  -		: Subtract two matrices,  e.g. A - B\n";
	cout << "  x		: Multipy two matrices,   e.g. B x A\n";
	cout << "  ==		: Equality test 	  e.g. A == A\n";
	cout << "  T		: Transpose a matrix,     e.g. -T B\n";
	
}
 
/*---------------------------------------------------------------------------
FUNCTION:	open_file()
DESCRIPTION:	Used for opening files
RETURNS:	err
NOTES:		
----------------------------------------------------------------------------*/
int open_file(ifstream &infile, string name, int &err)
{
	string filename = "DATA/";
	filename += name;
	filename += ".mtx";

	infile.open(filename);

	if (!infile) // Test for errors.
	{
		cout << "\nError opening file: " << filename << "\n\n";
		err = 2;
	}
	else
		cout << "Opened: " << filename << endl;

	return err;
}

/*---------------------------------------------------------------------------
FUNCTION:	write_file()
DESCRIPTION:	Used to write file(s)
RETURNS:	err
NOTES:		
----------------------------------------------------------------------------*/
int write_file(ofstream &outfile, string name, int &err)
{
	string filename = "DATA/";
	filename += name;
	filename += ".mtx";

	outfile.open(filename);

	if (!outfile) // Test for errors.
	{
		cout << "\nError opening file: " << filename << "\n\n";
		err = 2;
	}
	else
		cout << "Output: " << filename << endl;

	return err;
}

/*---------------------------------------------------------------------------
FUNCTION:	arg_count()
DESCRIPTION:	Counts arguments
RETURNS:	err
NOTES:		
----------------------------------------------------------------------------*/
int arg_count(int argc, int num, int &err)
{
	if (argc < num)
	{
		cout << "Not enough Arguments ?\n\n";
		err = 1;
	}
	return err;
}
