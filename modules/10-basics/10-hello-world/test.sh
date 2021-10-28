ACTUAL=`tcc -run main.c`
EXPECTED="Hello, World!"

if [ "$ACTUAL" != "$EXPECTED" ]; then
    echo "Expected:\n$EXPECTED\nReceived:\n$ACTUAL"
    exit 1
fi
