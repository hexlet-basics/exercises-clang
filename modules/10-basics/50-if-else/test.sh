ACTUAL=`tcc -run main.c`
EXPECTED='1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz';

if [ "$ACTUAL" != "$EXPECTED" ]; then
    echo "Expected '$EXPECTED', but actual was '$ACTUAL'"
    exit 1
fi
