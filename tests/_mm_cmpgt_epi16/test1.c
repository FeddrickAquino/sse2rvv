#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	short array1[8] = {0xff00, 0xff00, 0xf00f, 0xf00f, 0, 0x1, 0, 0xf};
	short array2[8] = {0, 0xf01, 0xff0, 0x0ff0, 0, 0x1, 0, 0x1};
	__m128i v1 = _mm_load_si128((__m128i *)array1), v2 = _mm_load_si128((__m128i *)array2);
	v1 = _mm_cmpgt_epi16(v1, v2);

	short *ptr = &v1;
	for(int i = 0; i < 8; i++, ptr++){
		printf("Index %d= %x\n", i, *ptr & 0xffff);
	}
	return 0;
}
