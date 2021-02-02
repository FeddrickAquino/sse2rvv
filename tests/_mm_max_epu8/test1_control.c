#include <stdio.h>

int main(void){
	int array1[4] = {0x7fffffff, 0xffff0000, 0x00018000, 0x1};
	int array2[4] = {0xffff0001, 0x0000ffff, 0x000fffff, 0x1};

	unsigned char *s1 = (unsigned char *)&array1, *s2 = (unsigned char *)array2;
	for(int i = 0; i < 16; i++, s1++, s2++){
		printf("Index %d= %x\n", i, ((*s1 > *s2) ? *s1 : *s2));
	}
	return 0;
}
