#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "includes/utils.h"
#include "includes/algorithms.h"

long long return_num(char* str, long long length) {

	long long res = 0;

	for (long long i = 0; i < length; i++) {

		if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
			return -1;

		else
			res += (long long)(str[i] - '0') * pow(10, length - i - 1);
	}

	return res;
}

long long* get_random_array(long long size, unsigned long long max_random) {

	long long* arr = (long long*)malloc(sizeof(long long) * size);

	srand(time(0));

	for (long long i = 0; i < size; i++)
		arr[i] = rand() % max_random;

	return arr;
}

void (*(return_algo(char* str))) (long long*, long long, short) {

	if (!strcmp(str, "shell_sort") || !strcmp(str, "shell") || !strcmp(str, "shellsort"))
		return shell_sort;

	if(!strcmp(str, "insertion_sort") || !strcmp(str, "insertion") || !strcmp(str, "insertionsort"))
		return insertion_sort;

	return NULL;
}

void get_random_file(FILE* file, long long count, unsigned long long max_random) {

	long long* arr = get_random_array(count, max_random);

	write_file(file, arr, count);

	free(arr);
}

void write_file(FILE* file, long long* source, long long count) {

	for (long long i = 0; i < count; i++)
		fprintf(file, "%lld\n", source[i]);
}

long long* read_file(FILE* file, long long* file_size) {

	long long i = 0;
	long long* res = (long long*)malloc(sizeof(long long));

	char* temp = (char*)malloc(sizeof(char) * 100);

	while (fscanf(file, "%s", temp) != EOF){

		if((res[i] = return_num(temp, strlen(temp))) == -1)
			return NULL;

		res = (long long*)realloc(res, sizeof(long long) * (++i + 1));
	}

	*file_size = i;

	return res;
}

short check_dataset(long long* dataset, long long dataset_size) {

	for (long long i = 0; i < dataset_size; i++)
		if (dataset[i] == 0)
			return 0;

	return 1;
}

clock_t benchmark(long long* arr, long long size, void (*algorithm)(long long*, long long, short), short reverse_bit) {

	clock_t start = clock();

	algorithm(arr, size, reverse_bit);

	return (clock() - start);
}
