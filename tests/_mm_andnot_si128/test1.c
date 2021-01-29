#include <stdio.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[4] = {-1, -1, 0, 0};
	int array_init2[4] = {-1, -1, 0, 1};

	INIT_SSE_VL
	__m128i v1 = _mm_loadu_si128((__m128i*)array_init1);
	__m128i v2 = _mm_loadu_si128((__m128i*)array_init2);	

	v1 = _mm_andnot_si128(v1, v2);
	int* ptr = (int *)&v1;
	
	for(int i = 0; i < 4; i++){
		printf("Result %d= %d\n", i, ptr[i]);
	}
	return 0;
}
