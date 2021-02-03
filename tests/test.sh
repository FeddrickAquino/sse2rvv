#!/bin/sh

#compile the test
/data/riscv/gcc-rvv-intrinsic/linux/bin/riscv64-unknown-linux-gnu-gcc -static -o test1 test1.c
gcc -o test1_control test1_control.c

#run the program
spike --isa=rv64gcv /data/riscv/riscv-pk/build/build/pk test1 > test1.out 2>&1
./test1_control > test1_control.out 2>&1

#remove first line in test1.out
sed -i '1d' test1.out

#compare output
diff test1.out test1_control.out --brief -y || exit 1

#delete output
rm test1.out test1_control.out

exit 0
