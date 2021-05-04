#include <stdio.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[4] = {0x7fffffff, 0xffffffff, 0x7fffffff, 0x0};
	int array_init2[4] = {0x00000001, 0x00000001, 0x80000000, 0xf};

	__m128i v1 = _mm_loadu_si128((__m128i*)array_init1);
	__m128i v2 = _mm_loadu_si128((__m128i*)array_init2);	

	v1 = _mm_add_epi32(v1, v2);
	int* ptr = (int *)&v1;
	
	for(int i = 0; i < 4; i++){
		printf("Result %d= %x\n", i, ptr[i]);
	}
	return 0;
}
