#include <stdio.h>

int main(void){
	int array1[4] = {0xff00ff00, 0xf00ff00f, 0x0, 0xf};
	int array2[4] = {0x00000f01, 0x0ff00ff0, 0x1, 0x1};

	for(int i = 0; i < 4; i++){
		printf("Index %d= %x\n", i, array1[i] & array2[i]);
	}
	return 0;
}
