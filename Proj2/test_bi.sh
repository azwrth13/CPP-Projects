#!/bin/sh
	
set -v
			# Test program with deg 0 polynomials
./poly_class << EOF
1
5 3
1
5 7
2
EOF
./poly_class << EOF
1
6 2
1
7 3
3.5
EOF
