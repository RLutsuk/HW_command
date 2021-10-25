#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "includes/algorithms.h"
#include "includes/benchmark.h"
#include "includes/fhandle.h"
#include "includes/utils.h"

extern unsigned long long MAX_RAND;
extern short multiplier = 1;
extern file_name;

int* (*alg_fs[2])(int*) = {shell_sort, insertion_sort};

int main(int argc, char** argv) {

	for (int i = 1; i < argc; i++) {

		printf("%s , i = %d\n", argv[i], i);


		if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--algorithm")) {

			// check is next arg possible algorithm and make variable for it

		}

		else if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--benchmark")) {

			// set benchmark mode

		}

		else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file")) {

			// check is next arg existing file

			file_name = argv[i];

			FILE* file = fopen(file_name, "w+");

			if (!file) {

				// file cannot be opened
				
				return 0;
			}

			// call a function from fhandle.c to read from file


		}

		else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {

			// help option

		}

		else if (!strcmp(argv[i], "-m") || !strcmp(argv[i], "--max-num")) {

			// set maximum random generated number, default is RAND_MAX constant = 2147483647

			if ((i + 1) < argc && is_a_num(argv[i + 1], strlen(argv[i + 1]))) {

				MAX_RAND = is_a_num(argv[i + 1], strlen(argv[i + 1]));

				if (!is_a_num(argv[i + 1], strlen(argv[i + 1]))) {

					// bad number input, should be > 0

					return 0;
				}


				i++;

			}

			else {

				// next argument should be a valid number

				return 0;
			}

		}

		else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--no-sort")) {

			// generate file with random numbers without sorting

		}

		else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "--reverse")) {

			// set reverse flag
			multiplier = -1;

		}

		else {

			// unknown option

			return 0;
		}


	}


	return 0;
}