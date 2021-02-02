#include <stdio.h>

int main(void){
	int array1[4] = {0x7fffffff, 0xffff0000, 0x00018000, 0x1};
	int array2[4] = {0xffff0001, 0x0000ffff, 0x000fffff, 0x1};

	short *s1 = (short *)&array1, *s2 = (short *)array2;
	for(int i = 0; i < 8; i++, s1++, s2++){
		printf("Index %d= %x\n", i, ((*s1 > *s2) ? *s1 : *s2) & 0xffff);
	}
	return 0;
}
