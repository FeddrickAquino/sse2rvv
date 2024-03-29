#!/bin/bash

set -x

#make sure you first do apt-get install device-tree-compiler
#sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev

WORK_DIR=`pwd`/riscv_bioinformatics

#compiling gcc
mkdir $WORK_DIR
cd $WORK_DIR
git clone https://github.com/riscv/riscv-gnu-toolchain -b rvv-intrinsic
cd riscv-gnu-toolchain
git submodule update --init --recursive --depth 1 riscv-binutils riscv-gcc riscv-glibc riscv-dejagnu riscv-newlib riscv-gdb
mkdir build
cd build
../configure --prefix=$WORK_DIR/gcc --with-arch=rv64gcv --with-abi=lp64d
make -j32 linux 
make install
PATH=$PATH:$WORK_DIR/gcc/bin
export PATH


#compiling spike
RISCV=$WORK_DIR/spike
cd $WORK_DIR
git clone https://github.com/riscv/riscv-isa-sim
cd riscv-isa-sim
mkdir build
cd build
../configure --prefix=$RISCV
make -j64 
make install
PATH=$PATH:$RISCV/bin
export PATH

#compiling pk
cd $WORK_DIR
git clone https://github.com/riscv/riscv-pk
cd riscv-pk
mkdir build
cd build
../configure --prefix=$WORK_DIR/pk --host=riscv64-unknown-linux-gnu --with-arch=rv64gcv --with-abi=lp64d
make -j64 
make install
PATH=$PATH:$WORK_DIR/pk/riscv64-unknown-linux-gnu/bin
export PATH

#download test data set
cd $WORK_DIR
mkdir test_data
cd test_data
wget -O chr22.fa.gz https://cloudstor.aarnet.edu.au/plus/s/gQtJuWiWEb4R6tq/download
gunzip chr22.fa.gz
wget -O reads.fastq.gz https://cloudstor.aarnet.edu.au/plus/s/m2LE895IhhnRLKF/download
gunzip reads.fastq.gz

#compiling zlib
cd $WORK_DIR
mkdir zlib
cd zlib 
wget https://zlib.net/zlib-1.2.11.tar.gz
tar xf zlib-1.2.11.tar.gz
cd zlib-1.2.11/
CC=riscv64-unknown-linux-gnu-gcc CFLAGS="-march=rv64gcv -mabi=lp64d"  ./configure 
make

#compiling minimap2
cd $WORK_DIR
git clone https://github.com/FeddrickAquino/minimap2 --recursive
cd minimap2
make riscv_v=1
PATH=$PATH:$WORK_DIR/minimap2
export PATH

#running minimap2
cd $WORK_DIR/test_data
spike --isa=rv64gcv -p4 -m8096 `which pk` `which minimap2` -t 1 chr22.fa -d chr22.idx
head -n10 reads.fastq > reads_10.fastq
spike --isa=rv64gcv -p4 -m8096 `which pk` `which minimap2` -x map-ont -a -t 1 chr22.idx reads_10.fastq > reads_10.sam 
