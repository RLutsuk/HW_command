#define UTILS_H
#define ALGO_COUNT 2

unsigned long long MAX_RAND;
short multiplier;
short benchmark_mode;
char* file_name;
enum algorithms { SHELL_SORT = 0, INSERTION_SORT = 1 };
int* (*algorithm)(int*);
int* dataset;
int dataset_size;
int* random_arr;
int ra_size;
FILE* file;

int* (*alg_fs[ALGO_COUNT])(int*);

int return_num(char* str, int length); // check is str a number
int* (*(return_algo(char* str))) (int*); // check is str a valid algo

int* get_random_array(int size); // get array of a random numbers

int* read_file(char* file_name);
void write_file(char* file_name, int* source);

void dump_all();
