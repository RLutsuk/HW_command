#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "includes/utils.h"
#include "includes/algorithms.h"

long long return_num(char* str, long long length) {

	long long res = 0;

	for (int i = 0; i < length; i++) {

		if (str[i] > '9' || str[i] < '0')
			return 0;

		else
			res += (long long)(str[i] - '0') * pow(10, length - i - 1);
	}
	
	return res;
}

long long* get_random_array(long long size, long long MAX_RAND) {

	long long* arr = (long long*)malloc(sizeof(long long) * size);

	srand(time(0));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % MAX_RAND;

	return arr;
}

void (*(return_algo(char* str))) (long long*, long long, short) {

	if (!strcmp(str, "shell_sort") || !strcmp(str, "shell") || !strcmp(str, "shellsort"))
		return shell_sort;

	if(!strcmp(str, "insertion_sort") || !strcmp(str, "insertion") || !strcmp(str, "insertionsort"))
		return insertion_sort;

	return NULL;
}

void get_random_file(FILE* file, long long count, long long MAX_RAND) {

	long long* arr = get_random_array(count, MAX_RAND);

	write_file(file, arr, count);

	free(arr);
}

void write_file(FILE* file, long long* source, long long count) {

	for (int i = 0; i < count; i++)
		fprintf(file, "%lld\n", source[i]);
}

long long* read_file(FILE* file, long long* file_size) {

	int i = 0;
	long long* res = (long long*)malloc(sizeof(long long));

	while (fscanf(file, "%lld", &res[i]) != EOF)
		res = (long long*)realloc(res, sizeof(long long) * (++i + 1));

	*file_size = i;

	return res;
}

int check_dataset(long long* dataset, long long dataset_size) {

	for (int i = 0; i < dataset_size; i++)
		if (dataset[i] == 0)
			return 0;

	return 1;
}

clock_t benchmark(long long* arr, long long size, void (*algorithm)(long long*, long long, short), short reverse_bit) {

	clock_t start = clock();

	algorithm(arr, size, reverse_bit);

	return (clock() - start);
}