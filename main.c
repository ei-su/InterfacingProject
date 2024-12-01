#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void x64SAXPYfunction(long long int n, float* x, float* y, float* z, float a);

void cLangSAXPYfunction(long long int n, float* x, float* y, float* z, float a) {
	int i;
	for (i = 0; i < n; i++)
		z[i] = a * x[i] + y[i];
}

int main() {
	/*unsigned long long int ARRAY_SIZE = 1048576;*/ // 2^20
	unsigned long long int ARRAY_SIZE = 16777216; // 2^24
	/*unsigned long long int ARRAY_SIZE = 1073741824;*/ // 2^30
	unsigned long long int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);
	// timer variable
	clock_t start, end;
	double time_taken;
	//	declare array
	float a = 0;
	float* x;
	float* y;
	float* zArrayInC;
	float* zArrayInx64;
	x = (float*)malloc(ARRAY_BYTES);
	y = (float*)malloc(ARRAY_BYTES);
	zArrayInC = (float*)malloc(ARRAY_BYTES);
	zArrayInx64 = (float*)malloc(ARRAY_BYTES);

	printf("A ~~> ");
	scanf_s("%f", &a);

	// initialize array
	for (int i = 0; i < ARRAY_SIZE; i++) {
		x[i] = (float)rand() / (RAND_MAX / 20.0) - 10.0;
		y[i] = (float)rand() / (RAND_MAX / 20.0) - 10.0;
		zArrayInC[i] = 0.0;
		zArrayInx64[i] = 0.0;
	}
	
	//~~~~~~~~~~ C language ~~~~~~~~~~
	// call C function
	start = clock();
	cLangSAXPYfunction(ARRAY_SIZE, x, y, zArrayInC, a);
	end = clock();
	time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
	printf("Time (in C, as ms) = %lf ms\n", time_taken);
	// sanity check by printing
	for (int i = 0; i < 10; i++) {
	printf("new value of Z[%d] in C = %f\n", i, zArrayInC[i]);
	}
	
	//~~~~~~~~~~ x86-64 ~~~~~~~~~~
		// call x64 function
		start = clock();
		x64SAXPYfunction(ARRAY_SIZE, x, y, zArrayInx64, a);
		end = clock();
		time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
		printf("\nTime (in ASM, as ms) = %lf ms\n", time_taken);
		// sanity check by printing
		for (int i = 0; i < 10; i++) {
			printf("new value of Z[%d] in asm = %f\n", i, zArrayInx64[i]);
		}

	//~~~~~~~~~~ Correctness Checker ~~~~~~~~~~
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (zArrayInC[i] == zArrayInx64[i]) {
			continue;
		}
		else {
			printf("\n\nIncorrect outputs for the C and x86-64 kernels.");
			printf("\nzArrayInC[%d] = %f", i, zArrayInC[i]);
			printf("\nzArrayInx64[%d] = %f\n", i, zArrayInx64[i]);
			break;
		}

	}

		return 0;
}
