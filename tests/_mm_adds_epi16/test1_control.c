#include <stdio.h>

int main(void){
	int array_init1[4] = {0x7fff8000, 0xffff, 0xffff0001, 0x00010001};
	int array_init2[4] = {0x0002ffff, 0xffff, 0x0002000f, 0x7fff7fff};	

	int array_sat[4] = {0x7fff8000, 0xfffe, 0x00010010, 0x7fff7fff};

	short *s1 = (short *)array_sat;
	for(int i = 0; i < 8; i++){
		printf("Result %d= %x\n", i, s1[i]  & 0xffff);
	}
	return 0;
}
