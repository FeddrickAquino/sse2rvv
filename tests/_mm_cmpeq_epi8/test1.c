#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	int array1[4] = {0xff00ff00, 0xf00ff00f, 0x0, 0xf};
	int array2[4] = {0x00000f01, 0x0ff00ff0, 0x1, 0x1};
	__m128i v1 = _mm_load_si128((__m128i *)array1), v2 = _mm_load_si128((__m128i *)array2);
	v1 = _mm_cmpeq_epi8(v1, v2);

	char *ptr = &v1;
	for(int i = 0; i < 16; i++, ptr++){
		printf("Index %d= %x\n", i, *ptr);
	}
	return 0;
}
