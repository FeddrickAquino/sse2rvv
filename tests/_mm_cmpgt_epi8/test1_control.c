#include <stdio.h>

int main(void){
        int array1[4] = {0xff00ff00, 0xf00ff00f, 0x0, 0xf};
        int array2[4] = {0x00000f01, 0x0ff00ff0, 0x1, 0x1};
	
	char *c1 = (char*)array1, *c2 = (char*)array2;
        for(int i = 0; i < 16; i++, c1++, c2++){
                printf("Index %d= %x\n", i, (*c1 > *c2) ? 0xff : 0);
        }
        return 0;
}
