#include <stdio.h>

int main(void){
	float vf[4] = {5.43, 5.43, 5.43, 5.43};
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n",i, vf[i]);
	}
	return 0;
}
