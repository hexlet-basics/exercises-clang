ACTUAL=`tcc -run main.c`
EXPECTED='0 : 273
20 : 293
40 : 313
60 : 333
80 : 353
100 : 373
120 : 393
140 : 413
160 : 433
180 : 453
200 : 473
220 : 493
240 : 513
260 : 533
280 : 553
300 : 573';

if [ "$ACTUAL" != "$EXPECTED" ]; then
    echo "Expected '$EXPECTED', but actual was '$ACTUAL'"
    exit 1
fi
