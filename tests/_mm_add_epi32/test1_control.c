#include <stdio.h>

int main(void){
	int array_init1[4] = {0x7fffffff, 0xffffffff, 0x7fffffff, 0x0};
        int array_init2[4] = {0x00000001, 0x00000001, 0x80000000, 0xf};

	for(int i = 0; i < 4; i++){
		printf("Result %d= %x\n", i, array_init1[i] + array_init2[i]);
	}
	return 0;
}

