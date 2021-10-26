#!/bin/sh

ACTUAL=`tcc -run main.c`
EXPECTED='0.00 : -17.78
20.00 :  -6.67
40.00 :   4.44
60.00 :  15.56
80.00 :  26.67
100.00 :  37.78
120.00 :  48.89
140.00 :  60.00
160.00 :  71.11
180.00 :  82.22
200.00 :  93.33
220.00 : 104.44
240.00 : 115.56
260.00 : 126.67
280.00 : 137.78
300.00 : 148.89';

if [ "$ACTUAL" != "$EXPECTED" ]; then
    echo "Expected '$EXPECTED', but actual was '$ACTUAL'"
    exit 1
fi
