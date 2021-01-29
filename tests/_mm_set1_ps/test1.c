#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	__m128 fv = _mm_set1_ps(5.43);
	float* ptr = &fv;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n", i, ptr[i]);
	}
	return 0;
}
