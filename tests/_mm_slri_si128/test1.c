#include <stdio.h>

#include "../../emmintrin.h"

void print_vi(__m128i vi);

int main(void){
	INIT_SSE_VL
	int array1[4] = {0x12345678, 0x9ABCDEF0, 0x12003400, 0x56007800};
	__m128i vi = _mm_load_si128((__m128i *)(array1));

	__m128i vi1 = _mm_srli_si128(vi, 1);
	printf("First test\n");
	print_vi(vi1);

	__m128i vi2 = _mm_srli_si128(vi, 8);
        printf("Second test\n");
	print_vi(vi2);

	__m128i vi3 = _mm_srli_si128(vi, 16);
        printf("Third test\n");
	print_vi(vi3);
	return 0;
}

void print_vi(__m128i vi){
	for(int i = 0, *ptr = (int *)(&vi); i < 4; i++, ptr++){
		printf("Index %d= %x\n", i, *ptr);
	}
}
