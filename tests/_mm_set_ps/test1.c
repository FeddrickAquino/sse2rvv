#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	__m128 fv = _mm_set_ps(9.8, 7.6, 5.4, 3.2);
	float* ptr = &fv;
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n", i, ptr[i]);
	}
	return 0;
}
