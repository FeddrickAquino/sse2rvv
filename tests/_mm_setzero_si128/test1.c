#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	__m128i v = _mm_setzero_si128();
	int* ptr = &v;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %d\n", i, ptr[i]);
	}
	return 0;
}
