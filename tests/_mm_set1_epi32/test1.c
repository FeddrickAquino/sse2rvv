#include <stdio.h>
#include <limits.h>

#include "../../emmintrin.h"

int main(void){
	__m128i v = _mm_set1_epi32(INT_MAX);
	int* ptr = &v;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %d\n", i, ptr[i]);
	}
	return 0;
}
