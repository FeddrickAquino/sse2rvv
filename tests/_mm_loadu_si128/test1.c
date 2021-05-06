#include <stdio.h>
#include <limits.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	unsigned int array_init1[5] = {UINT_MAX, UINT_MAX, UINT_MAX, 0, 0};
	unsigned char *ptr = (unsigned char *)array_init1;
	ptr++;

	__m128i v1 = _mm_loadu_si128((__m128i*)ptr);
	
	unsigned int *v1_ptr = (unsigned int *)&v1;
	for(int i = 0; i < 4; i++){
		printf("Result %d= %u\n", i, v1_ptr[i]);
	}
	return 0;
}
