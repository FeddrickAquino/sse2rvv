#include <stdio.h>
#include <limits.h>
#include <emmintrin.h>

int main(void){
	unsigned int array_init1[5] = {UINT_MAX, UINT_MAX, UINT_MAX, 0, 0};
	unsigned char *unaligned_ptr = (unsigned char *)array_init1;
	unaligned_ptr++;
	__m128i v = _mm_loadu_si128((__m128i *)unaligned_ptr);

	int *v_ptr = (int *)&v;
	for(int i = 0; i < 4; i++){
		printf("Result %d= %u\n", i, v_ptr[i]);
	}
	return 0;
}
