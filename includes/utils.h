#define UTILS_H

unsigned long long MAX_RAND;
short multiplier;
char* file_name;
enum algorithms { SHELL_SORT = 0, INSERTION_SORT = 1 };

int* (*alg_fs[2])(int*);

int is_a_num(char* str, int length); // check is str a number
int* (*(return_algo(char* str))) (int*); // check is str a valid algo

int* get_random_array(int size); // get array of a random numbers


void check(); // dump a number

