#include <stdio.h>

void print_array(int array[], int n);

int main(void){
	int array[4] = {0x12345678, 0x9ABCDEF0, 0x12003400, 0x56007800};
	
	int array1[4] = {0x34567800, 0xBCDEF012, 0x0034009A, 0x00780012};
	printf("First test\n");
	print_array(array1, 4);

	int array2[4] = {0, 0, 0x12345678, 0x9ABCDEF0};
	printf("Second test\n");
        print_array(array2, 4);

	int array3[4] = {0};
	printf("Third test\n");
        print_array(array3, 4);
}

void print_array(int array[], int n){
	for(int i = 0; i < n; i++){
		printf("Index %d= %x\n", i, array[i]);
	}
}
