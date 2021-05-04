#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	int array1[4] = {0x80ff0001, 0x7ff70f08, 0xf88f0000, 0x70};

	printf("Result = %x\n", _mm_movemask_epi8(_mm_loadu_si128((__m128i *)(array1))));
	return 0;
}
