ME:    Makefile
# DESCRIPTION:  Makefile for a C++ program
# PURPOSE:      Build a program executable on Linux
#
# MODIFICATION HISTORY:
# Author        Date          Modification(s)
# -----------   ----------    ---------------
# Chris Reyes   2021-02-01    Version 1
# Chris Reyes   2021-02-23    Version 2 dependent on .h files
# Chris Reyes   2021-02-23    Version 3 generic for .h files
#-------------------------------------------------------------------------------

#	This is our original generic makefile command that will build
#	any stand alone ".cpp" source file.
#	Usage: make cust_ports.cpp


.cpp :
	g++ -o $* $*.cpp -std=c++11

#	This will build executables that have dependencies on .h files
#	Usage: make cust_ports.cpp

%: %.cpp %.h
	g++ -o $* $*.cpp -std=c++11

