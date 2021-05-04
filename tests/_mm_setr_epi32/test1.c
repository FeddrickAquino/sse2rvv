#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	__m128i iv = _mm_setr_epi32(4, 3, 2, 1);
	int* ptr = &iv;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %d\n", i, ptr[i]);
	}
	return 0;
}
