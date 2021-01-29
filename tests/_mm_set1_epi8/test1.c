#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	__m128i v = _mm_set1_epi8(127);
	char* ptr = &v;
	for(int i = 0; i < 16; i++){
		printf("Index %d= %d\n", i, ptr[i]);
	}
	return 0;
}
