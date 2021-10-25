#define UTILS_H

unsigned long long MAX_RAND;
short multiplier;
char* file_name;

int is_a_num(char* str, int length); // check is str a number
int* is_an_algo(char* str, int length); // check is str a valid algo

int* get_random_array(int size); // get array of a random numbers


void check(); // dump a number

