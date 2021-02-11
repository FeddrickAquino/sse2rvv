#!/bin/sh

CC=/data/riscv/rvv_intrinsic_tools/compiler/linux/bin/riscv64-unknown-linux-gnu-gcc
SPIKE=/home/fedaqu/riscv/tools-rv/spike/bin/spike
PK=/data/riscv/rvv_intrinsic_tools/pk/pk

#compile the test
$CC -static -o test1 test1.c
gcc -o test1_control test1_control.c

#run the program
$SPIKE --isa=rv64gcv $PK test1 > test1.out 2>&1
./test1_control > test1_control.out 2>&1

#remove first line in test1.out
sed -i '1d' test1.out

#compare output
diff test1.out test1_control.out --brief -y || exit 1

#delete output
rm test1.out test1_control.out

exit 0
