#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void x64SAXPYfunction(long long int n, float a, float* x, float* y, float* z);

void cLangSAXPYfunction(long long int n, float a, float* x, float* y, float* z) {
	int i;
	for (int i = 0; i < n; i++)
		z[i] = a * x[i] + y[i];
}

int main() {
	unsigned long long int ARRAY_SIZE = 536870912;
	unsigned long long int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
	// timer variable
	clock_t start, end;
	double time_taken;
	//	declare array
	float a = 0;
	float* x;
	float* y;
	float* z;
	x = (float*)malloc(ARRAY_BYTES);
	y = (float*)malloc(ARRAY_BYTES);
	z = (float*)malloc(ARRAY_BYTES);

	printf("A ~~> ");
	scanf_s("%f", &a);

	//~~~~~~~~~~ C language ~~~~~~~~~~
	// initialize array
	for (int i = 0; i < ARRAY_SIZE; i++) {
		x[i] = 5.0;
		y[i] = 5.0;
		z[i] = 0.0;
	}
	//// get inputs for x
	//printf("x ~~> ");
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	scanf_s("%f", &x[i]);
	//}
	//// get inputs for y
	//printf("y ~~> ");
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	scanf_s("%f", &y[i]);
	//}
	// call C function
	start = clock();
	cLangSAXPYfunction(ARRAY_SIZE, a, x, y, z);
	end = clock();
	time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
	printf("Time (in C, as ms) = %lf ms\n", time_taken);
	// sanity check by printing
	for (int i = 0; i < 10; i++)
		printf("new value of x[%d] in C = %f\n", i, z[i]);

	//// ~~~~~~~~~~ x86-64 ~~~~~~~~~~
	//// re-initialize array
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	x[i] = 0.0;
	//	y[i] = 0.0;
	//	z[i] = 0.0;
	//}
	//// in assembly
	//start = clock();
	//x64SAXPYfunction(ARRAY_SIZE, a, x, y, z);
	//end = clock();
	//time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
	//printf("Time (in ASM, as ms) = %lf ms\n", time_taken);
	//// sanity check by printing
	//for (int i = 0; i < 10; i++)
	//	printf("new value of x[%d] in asm = %f\n", i, x[i]);
	return 0;
}