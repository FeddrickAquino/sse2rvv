#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	INIT_SSE_VL
	float array1[4] = {0.12, 3.45, 6.78, 9.10};
	__m128 v = vle32_v_f32m1(array1);
	float retval = _mm_cvtss_f32(v);
	printf("%f\n", retval);
	return 0;
}
