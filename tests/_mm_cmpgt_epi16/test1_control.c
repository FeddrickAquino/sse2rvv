#include <stdio.h>

int main(void){
	short array1[8] = {0xff00, 0xff00, 0xf00f, 0xf00f, 0, 0x1, 0, 0xf};
        short array2[8] = {0, 0xf01, 0xff0, 0x0ff0, 0, 0x1, 0, 0x1};

	short *c1 = array1, *c2 = array2;
        for(int i = 0; i < 8; i++, c1++, c2++){
                printf("Index %d= %x\n", i, (*c1 > *c2) ? 0xffff : 0);
        }
        return 0;
}
