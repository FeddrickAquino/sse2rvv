#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	__m128i v = _mm_cvtsi32_si128(-1);
	int *ptr = &v;
	for(int i = 0; i < 4; i++, ptr++){
		printf("Index %d= %d\n", i, *ptr);
	}
	return 0;
}
