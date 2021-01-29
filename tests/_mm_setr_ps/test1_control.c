#include <stdio.h>

int main(void){
	float vf[4] = {9.8, 7.6, 5.4, 3.2};
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n",i, vf[i]);
	}
	return 0;
}
