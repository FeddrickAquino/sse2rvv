#include <stdio.h>

#include <riscv_vector.h>

int main(void){
	vsetvl_e32m1(128);
	vint32m1_t iv1 = vmv_v_x_i32m1(-1);
	vint8m1_t iv2 = vreinterpret_v_i32m1_i8m1(iv1);
	char* ptr = &iv2;
	for(int i = 0; i < 16; i++)
		printf("Index %d= %d\n", i, ptr[i]);
	return 0;
}
