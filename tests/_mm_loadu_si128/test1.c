#include <stdio.h>
#include <limits.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	unsigned int array_init1[4] = {UINT_MAX, UINT_MAX, UINT_MAX, 0};

	__m128i v1 = _mm_loadu_si128((__m128i*)array_init1);
	
	unsigned int *ptr = &v1;
	for(int i = 0; i < 4; i++){
		printf("Result %d= %u\n", i, ptr[i]);
	}
	return 0;
}
