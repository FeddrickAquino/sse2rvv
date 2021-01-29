#include <stdio.h>

int main(void){
        int array1[4] = {0xff00ff00, 0xf00ff00f, 0x1, 0xf};
        int array2[4] = {0x00000f01, 0x0ff00ff0, 0x1, 0x1};
	
	int *c1 = array1, *c2 = array2;
        for(int i = 0; i < 4; i++, c1++, c2++){
                printf("Index %d= %x\n", i, (*c1 > *c2) ? 0xffffffff : 0);
        }
        return 0;
}
