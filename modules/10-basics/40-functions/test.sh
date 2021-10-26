#!/bin/sh

while read case; do
    set -- $case

    ACTUAL=`tcc -run main.c $1`
    EXPECTED=$2

    if [ "$ACTUAL" != "$EXPECTED" ]; then
        echo "Expected '$EXPECTED', but actual was '$ACTUAL'"
        exit 1
    fi

done < cases.txt
