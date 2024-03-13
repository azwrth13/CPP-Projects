#!/bin/sh

set -v

./matrix_math -inp A
./matrix_math -inp A -out XX
ls -l DATA/XX.mtx
cat   DATA/XX.mtx


./matrix_math A + A	
./matrix_math A + B	
./matrix_math A - A	
./matrix_math A - B	
./matrix_math B x A	
./matrix_math A x B 
./matrix_math B x B     

./matrix_math A == A	# Tests equality
./matrix_math A == B	# Tests equality

./matrix_math -T C	# Transpose test
./matrix_math -T F	# Transpose test
./matrix_math -T O	# Transpose test
