#include <stdio.h>
#include <limits.h>

int main(void){
	unsigned int array_init1[4] = {UINT_MAX, UINT_MAX, UINT_MAX, 0};
	for(int i = 0; i < 4; i++){
		printf("Result %d= %u\n", i, array_init1[i]);
	}
	return 0;
}
