#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	__m128 v = _mm_setzero_ps();
	float* ptr = &v;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n", i, ptr[i]);
	}
	return 0;
}
