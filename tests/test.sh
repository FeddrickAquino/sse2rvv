#!/bin/sh

CC=riscv64-unknown-linux-gnu-gcc
SPIKE=spike

#compile the test
$CC -static -o test1 test1.c
gcc -o test1_control test1_control.c

#run the program
$SPIKE --isa=rv64gcv `which pk` test1 > test1.out
./test1_control > test1_control.out

#remove first line in test1.out
sed -i '1d' test1.out

#compare output
diff test1.out test1_control.out --brief -y || exit 1

#delete output and binary file
rm test1.out test1_control.out test1 test1_control

exit 0
