#include <stdio.h>

#include <riscv_vector.h>

int main(void){
	size_t len = vsetvl_e8m1(128);
	printf("len = %d\n", len);

	len = vsetvl_e16m1(128);
        printf("len = %d\n", len);

	len = vsetvl_e32m1(128);
	printf("len = %d\n", len);
	vint8m1_t iv1 = vmv_v_x_i8m1(-1);
	vint32m1_t iv2 = vreinterpret_v_i8m1_i32m1(iv1);
	char* ptr = &iv1;
	for(int i = 0; i < 16; i++)
		printf("Index %d= %d\n", i, ptr[i]);
	return 0;
}
