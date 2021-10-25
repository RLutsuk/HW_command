#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "includes/utils.h"

extern unsigned long long MAX_RAND;
extern short multiplier;

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

	srand(time(NULL));

	for (int i = 0; i < size; i++)
		arr[i] = rand() % MAX_RAND;

	return arr;
}

int* is_an_algo(char* str, int length) {


	return NULL;

}


void check() {

	printf("%d\n", multiplier);

}