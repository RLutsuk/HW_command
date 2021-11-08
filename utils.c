#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "includes/utils.h"

int return_num(char* str, int length) {

	int res = 0;

	for (int i = 0; i < length; i++) {

		if (str[i] > '9' || str[i] < '0')
			return 0;

		else
			res += (int)(str[i] - '0') * pow(10, length - i - 1);
	}

	if (res > 0)
		return res;

	return 0;
}

int* get_random_array(int size) {

	int* arr = (int*)malloc(sizeof(int) * size);

	srand(time(0));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % MAX_RAND;

	return arr;
}

void (*(return_algo(char* str))) (int*, int, int) {

	if (!strcmp(str, "shell_sort") || !strcmp(str, "shell") || !strcmp(str, "shellsort"))
		return alg_fs[SHELL_SORT];

	if(!strcmp(str, "insertion_sort") || !strcmp(str, "insertion") || !strcmp(str, "insertionsort"))
		return alg_fs[INSERTION_SORT];

	return NULL;
}

void get_random_file(FILE* file, int count) {

	int* arr = get_random_array(count);

	write_file(file, arr, count);

	free(arr);
}

void write_file(FILE* file, int* source, int count) {

	for (int i = 0; i < count; i++)
		fprintf(file, "%d\n", source[i]);
}

int* read_file(FILE* file, int* file_size) {

	int i = 0;
	int* res = (int*)malloc(sizeof(int));

	while (fscanf(file, "%d", &res[i]) != EOF)
		res = (int*)realloc(res, sizeof(int) * (++i + 1));

	*file_size = i;

	return res;
}

int check_dataset() {

	for (int i = 0; i < dataset_size; i++)
		if (dataset[i] == 0)
			return 0;

	return 1;
}

clock_t benchmark(int* arr, int size, void (*algorithm)(int*, int, int), int reverse_bit) {

	clock_t start = clock();

	algorithm(arr, size, reverse_bit);

	return (clock() - start);
}