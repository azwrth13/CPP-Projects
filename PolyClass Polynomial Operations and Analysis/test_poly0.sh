#!/bin/sh
	
set -v
			# Test program with deg 0 polynomials
./poly_class << EOF
0
5
0
5
2
EOF
./poly_class << EOF
0
6
0
7
2
EOF
