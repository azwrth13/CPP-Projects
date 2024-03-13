#!/bin/sh

set -v

./matrix_math -inp F
./matrix_math -inp F -out XX
ls -l DATA/XX.mtx
cat   DATA/XX.mtx


./matrix_math F + F	
./matrix_math F + C	
./matrix_math C - C	
./matrix_math C - B	
./matrix_math A x F	
./matrix_math F x F 
./matrix_math B x B     

./matrix_math C == C	#Tests equality
./matrix_math O == O	#Tests equality

./matrix_math -T A	#Transpose test
./matrix_math -T B	#Transpose test
./matrix_math -T O	#Transpose test
