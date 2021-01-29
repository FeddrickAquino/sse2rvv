#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	__m128i v = _mm_set1_epi16(32767);
	short* ptr = &v;
	for(int i = 0; i < 8; i++){
		printf("Index %d= %d\n", i, ptr[i]);
	}
	return 0;
}
