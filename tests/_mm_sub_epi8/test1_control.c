#include <stdio.h>

int main(void){
	int array_init1[4] = {0, 0, 0, 0xff000ff0};
	int array_init2[4] = {0, 0, 0, 0x01010110};
	
	char *c1 = (char *)array_init1, *c2 = (char *)array_init2;
	for(int i = 0; i < 16; i++, c1++, c2++){
		printf("Result %d= %x\n", i, (*c1 - *c2) & 0xff);
	}
	return 0;
}

