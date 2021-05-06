#include <stdio.h>
#include <limits.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[5] = {0, 1, 0xff, -1, 0};
	char *c_ptr = (char *)array_init1;
	c_ptr++;
	__m128i vi = _mm_cvtsi32_si128(INT_MAX);
	_mm_storeu_si128((__m128i *)c_ptr, vi);
	for(int i = 0; i < 5; i++){
		printf("Result %d= %d\n", i, array_init1[i]);
	}
	return 0;
}
