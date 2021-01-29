#include <stdio.h>

int main(void){
	int array_init1[4] = {1, 2, 4, 8};
	int array_init2[4] = {1, 2, 4, 8};

	for(int i = 0; i < 4; i++){
		printf("Result %d= %d\n", i, array_init1[i] + array_init2[i]);
	}
	return 0;
}

