#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	int array1[4] = {0x12345678, 0x90ABCDEF, 0xFEDCBA09, 0x87654321};

	__m128i tmp = _mm_loadu_si128((__m128i *)array1);
	for(int i = 0; i < 16; i++){
		printf("Index %d= %x\n", i, _mm_extract_epi16(tmp, i));
	}
	return 0;
}
