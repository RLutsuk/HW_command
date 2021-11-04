#include <time.h>
#include <stdio.h>

#include "includes/benchmark.h"

clock_t benchmark(int* arr, int size, void (*algorithm)(int*, int, int), int reverse_bit) {

	clock_t start = clock();

	algorithm(arr, size, reverse_bit);

	clock_t end = clock();

	printf("clock_t result = %ld\n", end - start);

	return (end - start);
}