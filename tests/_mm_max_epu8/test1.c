#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	int array1[4] = {0x7fffffff, 0xffff0000, 0x00018000, 0x1};
	int array2[4] = {0xffff0001, 0x0000ffff, 0x000fffff, 0x1};

	__m128i vi1 = _mm_loadu_si128((__m128i *)array1);
	__m128i vi2 = _mm_loadu_si128((__m128i *)array2);
	
	vi1 = _mm_max_epu8(vi1, vi2);

	unsigned char *ptr = (unsigned char *)&vi1;
	for(int i = 0; i < 16; i++){
		printf("Index %d= %x\n", i, ptr[i]);
	}
	return 0;
}
