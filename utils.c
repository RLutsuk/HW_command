#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "includes/utils.h"

extern unsigned long long MAX_RAND;
extern short multiplier;
extern char* file_name;
extern int* (*alg_fs[ALGO_COUNT])(int*);
extern short benchmark_mode;
extern int* dataset;
extern int* random_arr;
extern FILE* file;
extern int* (*algorithm)(int*);
extern int dataset_size;
extern int ra_size;

int return_num(char* str, int length) {

	int res = 0;

	for (int i = 0; i < length; i++) {

		if (str[i] > '9' && str[i] < '0') {
			return 0;
		}
		else {
			res += (int)(str[i] - '0') * pow(10, length - i - 1);
		}
	}

	if (res > 0)
		return res;

	else
		return 0;
}

int* get_random_array(int size) {

	int* arr = (int*)malloc(sizeof(int) * size);

	srand(time(0));

	if (!MAX_RAND)
		MAX_RAND = RAND_MAX;

	for (int i = 0; i < size; i++) {

		arr[i] = rand() % MAX_RAND;
		
	}

	return arr;
}

int* (*(return_algo(char* str))) (int*) {

	if (!strcmp(str, "shell_sort") || !strcmp(str, "shell") || !strcmp(str, "shellsort"))
		return alg_fs[SHELL_SORT];

	if(!strcmp(str, "insertion_sort") || !strcmp(str, "insertion") || !strcmp(str, "insertionsort"))
		return alg_fs[INSERTION_SORT];

	return NULL;
}


void dump_all() {


	printf("ALGO_FS array:\n");
	for (int i = 0; i < ALGO_COUNT; i++)
		printf("%p ", alg_fs[i]);
	printf("\n");

	if (MAX_RAND)
		printf("MAX_RAND = %llu\n", MAX_RAND);
	else
		printf("MAX_RAND is not defined\n");

	if (multiplier)
		printf("MULTIPLIER = %d\n", multiplier);
	else
		printf("MULTIPLIER is not defined\n");

	if(benchmark_mode)
		printf("BENCHMARK_MODE = %d\n", benchmark_mode);
	else
		printf("BENCHMARK_MODE is not defined\n");

	if(file_name)
		printf("FILE_NAME = %s\n", file_name);
	else
		printf("FILE_NAME is not defined\n");

	if(algorithm)
		printf("ALGORITHM = %p\n", algorithm);
	else
		printf("ALGORITHM is not defined\n");

	if (dataset_size > 1) {

		printf("DATASET_SIZE = %d\n", dataset_size);
		printf("DATASET ARRAY:\n");
		for (int i = 0; i < dataset_size; i++)
			printf("%d ", dataset[i]);
		printf("\n");
	}
	else
		printf("DATASET_SIZE is not defined\nDATASET ARRAY is not defined\n");

	if (ra_size)
		printf("RA_SIZE = %d\n", ra_size);
	else
		printf("RA_SIZE is not defined\n");

	if (file)
		printf("FILE is defined\n");
	else
		printf("FILE is not defined\n");

}