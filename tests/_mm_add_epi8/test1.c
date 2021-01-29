#include <stdio.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[4] = {0, 0, 0, 0xff000ff0};
	int array_init2[4] = {0, 0, 0, 0x01010110};

	INIT_SSE_VL
	__m128i v1 = _mm_loadu_si128((__m128i*)array_init1);
	__m128i v2 = _mm_loadu_si128((__m128i*)array_init2);	

	v1 = _mm_add_epi8(v1, v2);
	char* ptr = (char *)&v1;
	
	for(int i = 0; i < 16; i++){
		printf("Result %d= %d\n", i, ptr[i]);
	}
	return 0;
}
