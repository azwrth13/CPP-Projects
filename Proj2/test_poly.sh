#!/bin/sh
			# Test script for poly_class ver. 3
set -v

./poly_class << EOF
2
3 -2 1
2
2 2 2
0 2.5
EOF
./poly_class << EOF
2
1 2 3
3
1 2 3 4
3 5
EOF

