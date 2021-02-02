#include <stdio.h>

int main(void){
	int array1[4] = {0x12345678, 0x90ABCDEF, 0xFEDCBA09, 0x87654321};
	short *ptr = (short *)array1;
	for(int i = 0; i < 16; i++){
		printf("Index %d= %x\n", i, ptr[(i % 8)] & 0xffff);
	}
}
