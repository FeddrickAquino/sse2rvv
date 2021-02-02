#include <stdio.h>

int main(void){
	int array1[4] = {0x80ff0001, 0x7ff70f08, 0xf88f0000, 0x70};
	
	int res = 0, mask = 1;
	char *ptr = (char *)array1;
	for(int i = 0; i < 16; i++, mask = mask << 1){
		if(ptr[i] & 0x80){
			res = res | mask;
		}
	}	
	printf("Result = %x\n", res);
	return 0;
}
