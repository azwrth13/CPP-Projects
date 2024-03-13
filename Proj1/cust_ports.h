/*----------------------------------------------------------------------------
FILENAME:               cust_ports.h
DESCRIPTION:            Header file for cust_ports.cpp
USAGE:			Structure declarations, libraries, prototypes, 
			and ADT's
COMPILER:               GNU g++ compiler on Linux
NOTES:                  

MODIFICATION HISTORY:
Author             Date         Version
--------------     ----------   --------------
Chris Reyes        2021-02-28   1.0 Created Structures and ADT's
Chris Reyes        2021-02-29   1.1 Added prototypes
Chris Reyes        2021-03-03   1.2 Added more libraries
Chris Reyes        2021-03-04   1.3 Added ARRAY_SIZE definition
Chris Reyes        2021-03-04   1.4 Added final protoypes for file output
Chris Reyes        2021-03-06   1.5 Copied over from Lab4
Chris Reyes        2021-03-08   1.6 Added prototypes for menu
Chris Reyes        2021-03-10   1.7 Added prototypes to write out to files
Chris Reyes        2021-03-12   1.8 Final Version
----------------------------------------------------------------------------*/
#ifndef __CUST_PORTS_H__
#define __CUST_PORTS_H__


#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

const char PROGRAMMER_NAME[] = "Christopher Reyes";

struct Acct_info
{
    char Acct_ID [7];
    double Acct_Balance;
    double Growth_Rate;
    int Comp_per_yr;
    double proj;
};

struct Customer_data
{
    int rec_num;
    char Customer_ID [6];
    char Last_name [20];
    char First_name [20];
    char Middle_name [20];
    char Tax_ID_number [20];
    char Phone_number [20];
    Acct_info Accounts[5];
};

// Prototypes
void read_file(char * filen, Customer_data *s, int &num_recs);
int read_in(istream &filen, Customer_data* s);
void read_name(Customer_data *cust, char *p);
void read_acc(Acct_info *acct, char *p);
void output(int i, Customer_data *s);
void show_out(Customer_data s[], int num);
void show_acc(Acct_info *p);
char *skip_spaces(char *line);
void show_size(Customer_data *cust);
void foutput(FILE *fp, int i, Customer_data *cust);
void show_fout(FILE *fp, Customer_data s[], int num);
void out_acc(FILE *fp, Acct_info *p);
void Menu(Customer_data *cust, int &num_recs, FILE *fp, int yrs, char * rpt);
void output_one(Customer_data s[]);
void new_ports(Customer_data s[], int &num_recs);
void new_ports_acc(Customer_data s[]);
void report_screen(Customer_data *cust, int yrs);
void show_report(Acct_info *p, int j);
void show_out_records(int i, Customer_data s[], int yrs, char *rpt);
void output_one_rpt(Customer_data s[], int yrs);
void report_screen_file(Customer_data *cust, int yrs, ostream &out);
void show_report_file(Acct_info *p, int j, ostream &out);
void help();
void Args(int argc, char *argv[],Customer_data *s);
#endif
