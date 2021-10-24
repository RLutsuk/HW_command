#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "includes/algorithms.h"
#include "includes/benchmark.h"
#include "includes/fhandle.h"

int main(int argc, char** argv) {

	for (int i = 1; i < argc; i++) {

		printf("%s\n", argv[i]);


		if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--algorithm")) {

			// check is next arg possible algorithm and make variable for it

		}

		else if (!strcmp(argv[i], "-b") || !strcmp(argv[i], "--benchmark")) {

			// set benchmark mode

		}

		else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file")) {

			// check is next arg existing file

		}

		else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {

			// help option
		}

		else if (!strcmp(argv[i], "-m") || !strcmp(argv[i], "--max-num")) {

			// set maximum random generated number, default is RAND_MAX constant = 2147483647

		}

		else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--no-sort")) {

			// just generate file with random numbers without sorting

		}

		else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "--reverse")) {

			// set reverse flag

		}

		else if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--verbose")) {

			// set verbose output

		}

		else {

			// unknown option

		}

	}


	return 0;
}