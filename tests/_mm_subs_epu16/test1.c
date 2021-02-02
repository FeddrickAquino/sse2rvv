#include <stdio.h>

// Library for sse intrinsic
#include "../../emmintrin.h"

int main(void){
	int array_init1[4] = {0x7fff8000, 0xffff, 0xffff0001, 0x00010001};
        int array_init2[4] = {0x0002ffff, 0xffff, 0x0002000f, 0x7fff7fff};

	INIT_SSE_VL
	__m128i v1 = _mm_loadu_si128((__m128i*)array_init1);
	__m128i v2 = _mm_loadu_si128((__m128i*)array_init2);	

	v1 = _mm_subs_epu16(v1, v2);
	unsigned short* ptr = (unsigned short *)&v1;
	
	for(int i = 0; i < 8; i++){
		printf("Result %d= %x\n", i, ptr[i]);
	}
	return 0;
}
