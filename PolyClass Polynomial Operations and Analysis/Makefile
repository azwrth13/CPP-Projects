#------------------------------------------------------------------------------
# FILE NAME:	Makefile
# DESCRIPTION:	Makefile for a C++ program
# PURPOSE:	Build a program executable
# MODIFICATION HISTORY:
# 
# Author	Date		Modification(s)
# -----------   -----------     ---------------
# Chris Reyes   2021-03-10      Version 2 for building poly_class_v2
# Chris Reyes   2021-03-11	Version 3 for building poly_class_v3
# Chris Reyes   2021-04-06      Version 4 for building poly_class part of Proj2
#------------------------------------------------------------------------------
#
#	This is our original generic makefile command that will build 
# 	any stand alone ".cpp" source file.
#	Usage: e.g., make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

#	This will build the two object files required for "poly_class"
#	and link them into a single executable.
#	Usage: make poly_class

poly_class: Polynomial.o poly_class.o
	g++ -o $@ $@.o Polynomial.o -std=c++11

#	This will build the two object files required for "poly_class"
#	which are dependent on Polynomial.h

%.o : %.cpp Polynomial.h
	g++ -c $< -std=c++11
