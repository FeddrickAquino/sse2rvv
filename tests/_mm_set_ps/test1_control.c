#include <stdio.h>

int main(void){
	float vf[4] = {3.2, 5.4, 7.6, 9.8};
	for(int i = 0; i < 4; i++){
		printf("Index %d= %f\n",i, vf[i]);
	}
	return 0;
}
