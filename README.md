# sse2rvv

A C header file that converts Intel SSE intrinsics to RISC-V Vector intrinsic.

## Introduction

`sse2rvv` is a translator of Intel SSE (Streaming SIMD Extensions) intrinsics to [RISC-V Vector](https://github.com/riscv/rvv-intrinsic-doc). This repository was
initially created with the intention of making [minimap2](https://github.com/lh3/minimap2) work with RISC-V Vector intrinsics. 
The header file `sse2rvv.h` in this repository currently contains several of the functions provided in official `<emmintrin.h>` from Intel intrinsics

Due to the nature of RISC-V Vector registers having different `VLEN` depending on the architecture, for the purpose of this repository, 
we assume the system/simulator that uses this header file have `VLEN` of 128bits

## Result

From this repository, I have demonstrated that:

- `sse2rvv` can be used on application that requires Intel's intrinsic to be run on RISC-V platform that supports vector instruction.
- Running minimap2 on RISC-V platform that utilizes `sse2rvv` reduces the instruction count by 2.67 in comparison to traditional vector to loop conversion approach.

## Get Started

To test it out, we would need to have:

### RISC-V GNU toolchain with RVV intrinsic

[riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain/tree/rvv-intrinsic) with rvv intrinsics enabled. 
Go to the **Installation (Linux)** section, and follow the build step there, with addition of the flag `--with-arch=rv64gcv --with-abi=lp64d`.

### RISC-V ISA simulator

[Spike](https://github.com/riscv/riscv-isa-sim) is a RISC-V ISA simulator that can be used for our purpose. Follow the **Build Steps** section to get Spike on your machine.

### RISC-V Proxy Kernel (pk)

We need a Proxy Kernel since I'm assuming this repository will be used for program that will be run in an Operating System in particular Linux distributions. Follow the 
**Build Steps** there, and for the configure part, you would use the flag `--host=riscv64-unknown-linux-gnu --with-arch=rv64gcv`. Remember to put the toolchain program that you obtained in **RISC-V GNU toolchain with RVV intrinsic** into your PATH.

### How to run

Inside the directory `tests`, there are directories that contains a unit test for each Intel intrinsic implemented inside the `sse2rvv.h`. To run this unit tests on
your machine, you would need to modify the `tests/test.sh` file, particularly the path to your RISC-V GNU toolchain programs, Spike, and riscv-pk. After you modified this
to the right path, run `./test_all.sh` in the `tests` directory, and see all the unit tests run and (hopefully) pass. 

To get all the 3 programs above, we have provided a script called `riscv_minimap2.sh`, which will download and compile the RVV Toolchain, Spike, pk, and minimap2. In addition, it will also run minimap2 with a test data.

## Usage

- Put the file `sse2rvv.h` in to your source code directory.

- Locate `#include <emmintrin.h>` in the code and replace them with `#include "sse2rvv.h"`.

- Put `INIT_SSE_VL` somewhere before the first Intel's intrinsic code. This is an important step, and if missed, would result in undeterministic behavior.

## Reference 

- [rvv-intrinsic-doc](https://github.com/riscv/rvv-intrinsic-doc)
- [RISC-V Vector specification](https://github.com/riscv/riscv-v-spec)
- [sse2neon](https://github.com/DLTcollab/sse2neon)
- [Intel intrinsics guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)
