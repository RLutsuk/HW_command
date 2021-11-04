#define ALGO_COUNT 2

unsigned long long MAX_RAND;
enum algorithms { SHELL_SORT = 0, INSERTION_SORT = 1 };
int* dataset;
int dataset_size;

void (*alg_fs[ALGO_COUNT])(int*, int, int);

int return_num(char* str, int length); // check is str a number
void (*(return_algo(char* str))) (int*, int, int); // check is str a valid algo

int* get_random_array(int size); // get array of a random numbers

int* read_file(FILE* file, int* file_size);
void write_file(FILE* file, int* source, int count);
void get_random_file(FILE* file, int count);

//void dump_all();

int check_dataset();
