#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "includes/utils.h"

extern unsigned long long MAX_RAND;
extern short multiplier;
extern int* (*alg_fs[2])(int*);

int is_a_num(char* str, int length) {

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

	printf("%p\n", alg_fs[SHELL_SORT]);
	printf("%p\n", alg_fs[INSERTION_SORT]);

	if (!strcmp(str, "shell_sort") || !strcmp(str, "shell") || !strcmp(str, "shellsort"))
		return alg_fs[SHELL_SORT];

	if(!strcmp(str, "insertion_sort") || !strcmp(str, "insertion") || !strcmp(str, "insertionsort"))
		return alg_fs[INSERTION_SORT];

	return NULL;
}


void check() { // tmp function

	printf("%d\n", multiplier);

}