#include <time.h>
#include <stdio.h>

#include "includes/benchmark.h"

clock_t benchmark(int* arr, int size, void (*algorithm)(int*, int)) {

	clock_t start = clock();

	algorithm(arr, size);

	clock_t end = clock();

	printf("clock_t result = %ld\n", end - start);

	return (end - start);
}