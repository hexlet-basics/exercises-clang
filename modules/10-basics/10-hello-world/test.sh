ACTUAL=`tcc -run main.c`
EXPECTED="Hello, World!"

if [ "$ACTUAL" != "$EXPECTED" ]; then
    echo "Expected '$EXPECTED', but actual was '$ACTUAL'"
    exit 1
fi
