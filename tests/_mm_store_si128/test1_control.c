#include <stdio.h>
#include <limits.h>

int main(void){
	int array_init1[4] = {INT_MAX, 0, 0, 0};
	for(int i = 0; i < 4; i++){
		printf("Result %d= %d\n", i, array_init1[i]);
	}
	return 0;
}
