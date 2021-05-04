#include <stdio.h>
#include <limits.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	
	int array_init1[4] = {0, 1, 0xff, -1};
	
	__m128i vi = _mm_cvtsi32_si128(INT_MAX);
	_mm_store_si128((__m128i *)array_init1, vi);
	for(int i = 0; i < 4; i++){
		printf("Result %d= %d\n", i, array_init1[i]);
	}
	return 0;
}
