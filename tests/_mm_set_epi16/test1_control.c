#include <stdio.h>

int main(void){
	short v[8] = {0, 32767, 32767, 32767, 32767, 32767, 32767, 32767};
	for(int i = 0; i < 8; i++){
		printf("Index %d= %d\n",i, v[i]);
	}
	return 0;
}
