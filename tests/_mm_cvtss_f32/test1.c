#include <stdio.h>

#include "../../emmintrin.h"

int main(void){
	float array1[4] = {0.12, 3.45, 6.78, 9.10};
	vfloat32m1_t v = vle32_v_f32m1(array1, 4);
	float retval = _mm_cvtss_f32(vfloat32m1_to_m128(v));
	printf("%f\n", retval);
	return 0;
}
