/*----------------------------------------------------------------------------
FILENAME:		cust_ports.cpp
DESCRIPTION: 		Customer Portfolio Program Project
USAGE:			./cust_ports
			./cust_ports -i
			./cust_ports -h
			./cust_ports -info
COMPILER:		GNU g++ compiler on Linux
NOTES:			uses cust_ports.h as a header file

MODIFICATION HISTORY:
Author		   Date		Version
--------------     ----------   --------------
Chris Reyes        2021-02-28   1.0 Started with sales_struct_v5
Chris Reyes        2021-02-29   1.1 Added more code specific to lab 4
Chris Reyes	   2021-03-03   1.2 Added functions for reading lines
Chris Reyes	   2021-03-04   1.3 Added printf for display to screen
Chris Reyes	   2021-03-05   1.4 Added fprintf to print to file
Chris Reyes	   2021-03-06   1.4 Final Version used for Lab4
Chris Reyes        2021-03-07   1.5 Recycled functions and structs for Proj1
Chris Reyes        2021-03-08   1.6 Added menu to call functions in i mode
Chris Reyes        2021-03-09   1.7 Added cases for menu with corresponding func
Chris Reyes        2021-03-10   1.8 Added report to screen and file
Chris Reyes        2021-03-11   1.9 Started command line mode
Chris Reyes        2021-03-12   2.0 Final version
----------------------------------------------------------------------------*/

#include "cust_ports.h"

/*----------------------------------------------------------------------------
FUNCTION:		main()
DESCRIPTION:    	Main function of the program
RETURNS:        	0
NOTES:          
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int yrs;
	int num_recs = 0;
	bool mode = 0;
	Customer_data *cust = new Customer_data [20];
	
	char filen[20];
	FILE *fp;
	char rpt[20];

	
//	Args(argc, argv, cust);
	
	if (argc > 1 && strcmp(argv[1], "-h")==0)
	{
		 help();
	}
	else if (argc > 1 && !strcmp(argv[1], "-i"))
	{
		 read_file(filen, cust, num_recs);
		 Menu(cust, num_recs, fp, yrs, rpt);	
		 
	}
	else if(argc > 1 && !strcmp(argv[1], "-info"))
	{
		read_file(filen, cust, num_recs);
	        show_out(cust, num_recs);	
	}
	else
	{
		 read_file(filen, cust, num_recs);
		 Menu(cust, num_recs, fp, yrs, rpt);	
	}

	delete [] cust;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << " " << __TIME__ << endl << endl;

	return 0;
}
/*----------------------------------------------------------------------------
FUNCTION:		Args()
DESCRIPTION:		Checks args
RETURNS:		Nothing(void)
NOTES:			Checks args... unfinished
----------------------------------------------------------------------------*/
void Args(int argc, char *argv[], Customer_data *s)
{
		



}
/*----------------------------------------------------------------------------
FUNCTION:		Menu()
DESCRIPTION:		Menu for controlling flow from user input
RETURNS:		Nothing(void)
NOTES:			Default interactive mode
----------------------------------------------------------------------------*/
void Menu(Customer_data *cust, int &num_recs, FILE *fp, int yrs, char *rpt)
{
	bool status = 1;
	char choice;


	while(status)
	{
	cout << endl <<  endl;
	cout << "-----------------------------------------------------------\n";
	cout << "                      Interactive Menu                    \n";
	cout << "-----------------------------------------------------------\n";
	cout << "1) Create new portfolios\n";
	cout << "2) Create stock and bond accounts and invest funds\n";
	cout << "3) Display information for one customer\n";
	cout << "a) Display information for all customers and their accounts\n";
	cout << "4) Display projections of portfolio accounts in the future\n";
	cout << "5) Write a report to screen and file\n";
	cout << "6) Write data to .dat file\n";
	cout << "q) Quit out of the program\n";
	cout << "------------------------------------------------------------\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "------------------------------------------------------------\n";
		switch(choice)
		{
			case '1': new_ports(cust, num_recs);
			break;
			
			case '2': new_ports_acc(cust);
			break;
			
			case '3': output_one(cust);
			break;
			
			case 'a': show_out(cust, num_recs);
			break;
			
			case '4': output_one_rpt(cust, yrs);
			break;
		
			case '5': show_out_records(num_recs, cust, yrs, rpt);
			break;

			case '6': show_fout(fp, cust, num_recs);
			break;
			
			case 'q': status = false;
			break;
		}
	}
}
/*----------------------------------------------------------------------------
FUNCTION:		new_ports()
DESCRIPTION:		Adds customer ports
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void new_ports(Customer_data s[], int &num_recs)
{
	bool status = true;
	char a;
	int i = num_recs;
	char newID[6] = "";	

	while(status)
	{
		cout << "Enter a 5 char customer ID: ";
		cin >> newID;
			while(strlen(newID)!=5)
			{	
				cout << "Try again: ";
				cin >> newID;
			}	  
		
		for(int j = 0; j < sizeof(newID);j++)
		{
			newID[j]=toupper(newID[j]);
		}
		strcpy((s+i)->Customer_ID, newID);
	
		cout << "First name: ";
		cin >> (s+i)->First_name;

		cout << "Middle name: ";
		cin >> (s+i)->Middle_name;

		cout << "Last name: ";
		cin >> (s+i)->Last_name;


		cout << "Tax ID: ";
		cin >> (s+i)->Tax_ID_number;

		cout << "Phone number: ";
		cin >> (s+i)->Phone_number;

		num_recs += 1;
		i++;
		
		cout << "Account added, would you like to add another?[y/n] ";
		cin >> a;

		if (a == 'n') status = false;
	}	 
}

/*----------------------------------------------------------------------------
FUNCTION:		new_ports_acc()
DESCRIPTION:		Adds accounts to ports
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void new_ports_acc(Customer_data s[])
{
	int acct;
	char ID[6] = "";
	int i = 0;
	char a;
	char aID[6] = "";

	cout << "Enter a 5 char customer ID: ";
	cin >> ID;
	
	while(strlen(ID)!=5)
	{
		cout << "Try again: ";
		cin >> ID;
	}
	
	for(int j = 0; j < sizeof(ID);j++)
	{
		ID[j]=toupper(ID[j]);
	}
	
	for (int i = 0; i < 20; i++)
	{
		if(strcmp(ID, s[i].Customer_ID)==0)
		{	
			acct = i;
			break;	
		}	
	}

	while(i < 5)
	{
	
		cout << "Enter a 6 char account ID: ";
		cin >> aID;
	
			while(strlen(aID)!=6)
			{
				cout << "Try again: ";
				cin >> aID;
			}

	for(int j = 0; j < sizeof(ID);j++)
	{
		aID[j]=toupper(aID[j]);
	}

	strcpy((s+acct)->Accounts[i].Acct_ID,aID);

	cout << "Account balance: ";
	cin >> (s+acct)->Accounts[i].Acct_Balance;

	cout << "Rate: ";
	cin >> (s+acct)->Accounts[i].Growth_Rate;

	cout << "Compound per year: ";
	cin >> (s+acct)->Accounts[i].Comp_per_yr;
	
	i++;

	if (i != 5)
	{
		cout << "Would you like to add another? [y/n]: ";
		cin >> a;
	}
	
	else if(i ==5)
		cout << "Max accounts reached: " << i;
	
	if (a == 'n') break;
	}
}
/*----------------------------------------------------------------------------
FUNCTION:		output_one_rpt()
DESCRIPTION:		Shows one customer's report
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void output_one_rpt(Customer_data s[], int yrs)
{
	int acct;
	char ID[6] = "";
	char years[5] = "";

	cout << "Enter a 5 char customer ID: ";
	cin >> ID;
	
	while(strlen(ID)!=5)
	{
	cout << "Try again: ";
	cin >> ID;
	}

	for(int j = 0; j < sizeof(ID);j++)
	{
		ID[j]=toupper(ID[j]);
	}

	cout << "No. of years projected [Default 1]: ";
	cin.ignore();
	cin.getline(years, 4);

	if (*years == 0) yrs = 1;
	
	else yrs = atoi(years);
		
	for (int i = 0; i < 20; i++)
	{
		if(strcmp(ID, s[i].Customer_ID)==0)
		{	
			acct = i;
			report_screen(s+acct, yrs);
			break;	
		}	
	}	
}
/*----------------------------------------------------------------------------
FUNCTION:		output_one()
DESCRIPTION:		Shows one customer's record
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void output_one(Customer_data s[])
{
	int acct;
	char ID[6] = "";

	cout << "Enter a 5 char customer ID: ";
	cin >> ID;
	
	while(strlen(ID)!=5)
	{
	cout << "Try again: ";
	cin >> ID;
	}

	for(int j = 0; j < sizeof(ID);j++)
	{
		ID[j]=toupper(ID[j]);
	}
	
	for (int i = 0; i < 20; i++)
	{
		if(strcmp(ID, s[i].Customer_ID)==0)
		{	
			acct = i;
			output(acct,s+acct);
			break;	
		}	
	}	
}
/*----------------------------------------------------------------------------
FUNCTION:		read_file()
DESCRIPTION:		Opens input file and reads dat into struct
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void read_file(char * filen, Customer_data *s, int &num_recs)
{
	
	cout << "Input file name [Default TestDB.dat]: ";
	cin.getline(filen, 20);
	
	if (*filen == 0)
		{
			char Default[]= "TestDB.dat";
			strcpy(filen, Default);
		}
	

	ifstream ifile(filen);
		
		if(!ifile)
		{
			cout << "\nError opening file, please press q and try again." << filen << endl << endl;
		}
		else
		{
			cout << "Input file: " << filen << endl;
			num_recs = read_in(ifile, s);
			ifile.close();
		}
}
/*---------------------------------------------------------------------------
FUNCTION:		read_in()
DESCRIPTION:		Reads a full record into struct 
RETURNS:		num
NOTES:			Code from CS202
---------------------------------------------------------------------------*/

int read_in(istream &ifile, Customer_data *s)
{
	int num = 0;
	int n = 0;
	int acc_no = 0;
	char line[80], *p;

	while(ifile.getline(line, 79))
	{
		p = skip_spaces(line);
		if (*p == 0)
		{
			if(n>1) num++;
			n = 0;
			acc_no = 0;
		}
		else n++;
		if (n == 1) strcpy(s[num].Customer_ID, p);
		if (n == 2) read_name(&s[num], p);
		if (n == 3) strcpy(s[num].Tax_ID_number, p);
		if (n == 4) strcpy(s[num].Phone_number, p);
		if (n >= 5) read_acc((s + num) -> Accounts +acc_no++, p);
	}

	return num;
}
/*---------------------------------------------------------------------------
FUNCTION:		read_name()
DESCRIPTION:		Reads customer data into struct
RETURNS:		Nothing(void)
NOTES:			Code from CS202
---------------------------------------------------------------------------*/
void read_name(Customer_data *cust, char *p)
{
	char *d;

	d = strchr(p, ',');
	*d = 0;
	strcpy(cust->Last_name, p);

	p = skip_spaces(d+1);
	d = strchr(p, ',');
	*d = 0;
	strcpy(cust->First_name, p);

	p = skip_spaces(d+1);
	strcpy(cust->Middle_name, p);
}
/*---------------------------------------------------------------------------
FUNCTION:		read_acc()
DESCRIPTION:		Reads account information into struct
RETURNS:		Noithing(void)
NOTES:			Code from CS202
---------------------------------------------------------------------------*/
void read_acc(Acct_info *acct, char *p)
{
	char *d;

	d = strchr(p, ' ');
	*d = 0;
	strcpy(acct->Acct_ID,p);

	p = skip_spaces(d+1);
	d = strchr(p, ' ');
	*d = 0;
	acct->Acct_Balance = atof(p);

	p = skip_spaces(d+1);
	d = strchr(p, ' ');
	*d = 0;
	acct->Growth_Rate = atof(p);

	p = skip_spaces(d+1);
	acct->Comp_per_yr = atoi(p);
}
/*----------------------------------------------------------------------------
FUNCTION:		show_out()
DESCRIPTION:		Display Customer data
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void show_out(Customer_data s[], int num)
{
	
	for (int i = 0; i < num; i++)
	{
		output(i, s+i);
	}
}
/*----------------------------------------------------------------------------
FUNCTION:		show_out_records()
DESCRIPTION:		Display Customer records
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void show_out_records(int num, Customer_data s[], int yrs, char * rpt)
{	
 	char years[5] = "";

	cout << "No. of years projected [Default 1]: ";
	cin.ignore();
	cin.getline(years, 4);

	if (*years == 0) yrs = 1;
	
	else yrs = atoi(years);


	cout << "Output file name [Default Customer_RPT.txt]: ";
	cin.getline(rpt, 20);

	if(*rpt == 0)
	{
		char Default[] = "Customer_RPT.txt";
		strcpy(rpt, Default);
	} 

	 	
	ofstream report(rpt);
		
		if(!rpt)
		{
			cout << "Error opening file: " << rpt << endl;
		}
		else
		{		

			for (int i = 0; i < num; i++)
			{
				report_screen(s+i, yrs);
				report_screen_file(s+i, yrs, report);
			}
			
			cout << "\nOutput file: " << rpt << endl;
		}
		
	report.close();	

}
/*---------------------------------------------------------------------------
FUNCTION:		skip_spaces()
DESCRIPTION:		skips spaces
RETURNS:		p
NOTES:			From CS202
---------------------------------------------------------------------------*/
char* skip_spaces(char *line)
{
	char *p = line;
	while(isspace(*p)) p++;

	return p;
}
/*----------------------------------------------------------------------------
FUNCTION:		output()
DESCRIPTION:		Displays customer data
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void output(int i, Customer_data *cust)
{
	cout << endl;
	printf("Record No. : %d\n", i+1);
	printf("Customer ID: %s\n", cust->Customer_ID);
	printf("Last   Name: %s\n", cust->Last_name);
	printf("Middle Name: %s\n", cust->Middle_name);
	printf("First  Name: %s\n", cust->First_name);
	printf("Tax ID Num : %s\n", cust->Tax_ID_number);
	printf("Phone No.  : %s\n", cust->Phone_number);
	
	show_acc(cust->Accounts);
}
/*-----------------------------------------------------------------------------
FUNCTION:		show_acc()
DESCRIPTION:		Displays account info
RETURNS:		Nothing(void)
NOTES:
------------------------------------------------------------------------------*/
void show_acc(Acct_info *p)
{
	for (int i = 0; i < 5; i++)
	{
	    if (*p->Acct_ID)
	    {
			if (i==0)
			{
		    	cout << "\t     Acct ID     Balance   rate    C/Y" << endl;
		    	cout << "\t     -------     -------   ----    ---" << endl;
			}
				printf("Acct No: %d : %s %12.2f %6.2f %6d\n", i+1,
		       			p->Acct_ID, p->Acct_Balance, p->Growth_Rate, p->Comp_per_yr);
	    }
			p++;
    }
}
/*----------------------------------------------------------------------------
FUNCTION:		report_screen()
DESCRIPTION:		Displays customer report
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void report_screen(Customer_data *cust, int yrs)
{	
	char line[180] = "";
	if (*cust->Customer_ID)
	{
	printf("\n");
	printf("CustID  Last_Name       First_Name      Middle      Tax_ID       Phone\n");
	printf("------  --------------  --------------  ----------  -----------  ---------------\n");
	printf("%-6s  %-14s  %-14s  %-10s  %-12s %-15s\n", cust->Customer_ID, cust->Last_name, cust->First_name, 
				                    cust->Middle_name, cust->Tax_ID_number, cust-> Phone_number);
	printf("\t------------------------------------------------------------------------\n");
	
	show_report(cust->Accounts, yrs);
        }		
}
/*-----------------------------------------------------------------------------
FUNCTION:		show_report()
DESCRIPTION:		Displays account info for report
RETURNS:		Nothing(void)
NOTES:
------------------------------------------------------------------------------*/
void show_report(Acct_info *p, int j)
{

	double total = 0;
	double total_proj = 0;
	int num_a;
	char line [180] = "";	
	
	for (int i = 0; i < 5; i++)
	{	
	  p->proj = p->Acct_Balance * pow((1 + (p->Growth_Rate/100) / p->Comp_per_yr), j*p->Comp_per_yr);
			total += p->Acct_Balance;
			total_proj += p->proj;
	    
		if (*p->Acct_ID)
		{
			if (i==0)
			{
		    	     printf("\tAccounts          Balance       %% Rate   C/Y      Projections  (%d yr)\n",j);
		    	     printf("\t--------        ------------    ------   ---     ------------\n");
			}
			     printf("\t%s          %12.2f    %6.2f%6d     %12.2f\n",p->Acct_ID, 
				      p->Acct_Balance, p->Growth_Rate, p->Comp_per_yr,p->proj);
		}
	
			p++;
	}
			     printf("\t------\n");
			     printf("\tTotals:         %12.2f                   \t%13.2f\n", total, total_proj);			
}
/*----------------------------------------------------------------------------
FUNCTION:		show_size()
DESCRIPTION:		Size of the struct and pointers
RETURNS:		Nothing(void)
NOTES:			For testing purposes only
----------------------------------------------------------------------------*/
void show_size(Customer_data *cust)
{
	printf("The size of 'Customer_data'  is: %zu\n", sizeof(Customer_data));
	printf("The size of 'Acct_info' is: %zu\n", sizeof(Acct_info));
	printf("The size of 'cust' ptr  is: %zu\n", sizeof(cust));
}
/*----------------------------------------------------------------------------
FUNCTION:		show_fout()
DESCRIPTION:		Prints to file
RETURNS:		Nothing(void)
NOTES:			uses fprintf from C
----------------------------------------------------------------------------*/
void show_fout(FILE *fp, Customer_data s[], int num)
{
	char option[2];
	char name[12];
	const char *fout;
	char letter[2] = "y";

	cout << "Would you like to change outfile name? [Default: testout.dat]\n";
	cout << "Enter y or n: ";
	cin >> option;
	
	if(strcmp(option, letter)==0)
	{
		cout << "Enter a file name: \n";
		cin >> name;
		fout = name;
	}
	else 
	{
		fout = "testout.dat";
	}
	
	fp = fopen(fout, "w");

	if (fp == NULL)
	{
		cout << "Error opening output file" << fout;
	}
	else
	{
		cout << "\nOutput file: " << fout;
		for (int i = 0; i < num; i++)
		{
			foutput(fp, i, s+i);
		}

	}

	fclose(fp);
}
/*----------------------------------------------------------------------------
FUNCTION:		foutput()
DESCRIPTION:		Outputs to file, customer data
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void foutput(FILE *fp, int i, Customer_data *cust)
{
	fprintf(fp, "    %s\n", cust->Customer_ID);
	fprintf(fp, "    %s", cust->Last_name);
	fprintf(fp, ", %s", cust->First_name);
	fprintf(fp, ", %s\n", cust->Middle_name);
	fprintf(fp, "    %s\n", cust->Tax_ID_number);
	fprintf(fp, "    %s\n", cust->Phone_number);
	
	out_acc(fp, cust->Accounts);
	fprintf(fp, "\n");
}
/*----------------------------------------------------------------------------
FUNCTION:		out_acc()
DESCRIPTION:		Outputs to file, account info
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void out_acc(FILE *fp, Acct_info *p)
{
	for (int i = 0; i < 5; i++)
	{
	    if (*p->Acct_ID)
	    {
		fprintf(fp, "    %s %10.2f %5.2f %2d\n",p->Acct_ID, p->Acct_Balance, 
						      p->Growth_Rate, p->Comp_per_yr);
	    }
			p++;
    }
}
/*----------------------------------------------------------------------------
FUNCTION:		report_screen_file()
DESCRIPTION:		Writes report to screen
RETURNS:		Nothing(void)
NOTES:
----------------------------------------------------------------------------*/
void report_screen_file(Customer_data *cust, int yrs, ostream &out)
{	
	char line[180] = "";
	if (*cust->Customer_ID)
	{
	sprintf(line,"\n");
	out << line;
	sprintf(line,"CustID  Last_Name       First_Name      Middle      Tax_ID       Phone\n");
	out << line;
	sprintf(line,"------  --------------  --------------  ----------  -----------  ---------------\n");
	out << line;
	sprintf(line,"%-6s  %-14s  %-14s  %-10s  %-12s %-15s\n", cust->Customer_ID, cust->Last_name, cust->First_name, 
				                    cust->Middle_name, cust->Tax_ID_number, cust-> Phone_number);
	out << line;
 	sprintf(line,"\t------------------------------------------------------------------------\n");
	out << line;

	show_report_file(cust->Accounts, yrs, out);
        }		
}
/*-----------------------------------------------------------------------------
FUNCTION:		show_report_file()
DESCRIPTION:		Writes report account info
RETURNS:		Nothing(void)
NOTES:
------------------------------------------------------------------------------*/
void show_report_file(Acct_info *p, int j, ostream &out)
{

	double total = 0;
	double total_proj = 0;
	int num_a;
	char line [180] = "";	
	
	for (int i = 0; i < 5; i++)
	{	
	  p->proj = p->Acct_Balance * pow((1 + (p->Growth_Rate/100) / p->Comp_per_yr), j*p->Comp_per_yr);
			total += p->Acct_Balance;
			total_proj += p->proj;
	    
		if (*p->Acct_ID)
		{
			if (i==0)
			{
				
		    	     sprintf(line,"\tAccounts          Balance       %% Rate   C/Y      Projections  (%d yr)\n",j);
			     out << line;
		    	     sprintf(line,"\t--------        ------------    ------   ---     ------------\n");
			     out << line;
			}
			     sprintf(line,"\t%s          %12.2f    %6.2f%6d     %12.2f\n",p->Acct_ID, 
				      p->Acct_Balance, p->Growth_Rate, p->Comp_per_yr,p->proj);
			     out << line;
			
		}
	
			p++;
	}
			     sprintf(line,"\t------\n");
		             out << line;
			     sprintf(line,"\tTotals:         %12.2f                   \t%13.2f\n", total, total_proj);
			     out << line;	
}
/*----------------------------------------------------------------------------
FUNCTION:		help()
DESCRIPTION:		Help menu
RETURNS:		Nothing(void)
NOTES:			called with command line
----------------------------------------------------------------------------*/
void help()
{
	cout << "------------------------------------------------\n";
	cout << "                    HELP MENU                   \n";
	cout << "------------------------------------------------\n";
	cout << "\n";
	cout << "The following are valid command line arguments: \n\n";
	cout << "-h          Opens the help menu                                    \n";
	cout << "-i          Opens up interactive menu                              \n";
	cout << "-f          Opens and reads an input file into a structure array   \n";
	cout << "-cust       Follows -f argument, with input of cust ID             \n";
	cout << "-info       Follows -cust arg, and displays info for given customer\n";
	cout << "-rpt        Optionally follows -f, writes report to screen and file\n";
	cout << "-out        Follows -f argument, will write out to given file      \n";
	cout << "-num_years  Follows -cust arg, print out report with given years for given ID\n";

}
