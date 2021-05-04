#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	int array1[4] = {0x7fffffff, 0xffff0000, 0x00018000, 0x1};
	int array2[4] = {0xffff0001, 0x0000ffff, 0x000fffff, 0x1};

	__m128i vi1 = _mm_loadu_si128((__m128i *)array1);
	__m128i vi2 = _mm_loadu_si128((__m128i *)array2);
	
	vi1 = _mm_max_epi16(vi1, vi2);

	short *ptr = (short *)&vi1;
	for(int i = 0; i < 8; i++){
		printf("Index %d= %x\n", i, ptr[i] & 0xffff);
	}
	return 0;
}
