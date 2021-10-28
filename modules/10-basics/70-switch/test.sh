#!/bin/sh

while read case; do
    set -- $case

    ACTUAL=`tcc -run test.c $1`
    EXPECTED=$2

    if [ "$ACTUAL" != "$EXPECTED" ]; then
        echo "Expected:\n$EXPECTED\nReceived:\n$ACTUAL"
        exit 1
    fi

done < cases.txt
