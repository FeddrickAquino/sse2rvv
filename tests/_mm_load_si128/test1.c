#include <stdio.h>
#include <limits.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[4] = {INT_MAX, INT_MAX, INT_MAX, 0};

	INIT_SSE_VL
	__m128i v1 = _mm_load_si128((__m128i*)array_init1);
	
	int *ptr = &v1;
	for(int i = 0; i < 4; i++){
		printf("Result %d= %d\n", i, ptr[i]);
	}
	return 0;
}
