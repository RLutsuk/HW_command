#define ALGO_COUNT 2

unsigned long long MAX_RAND;
short multiplier;
short benchmark_mode;
char* file_name;
enum algorithms { SHELL_SORT = 0, INSERTION_SORT = 1 };
void (*algorithm)(int*, int);
int* dataset;
int dataset_size;
int* random_arr;
int ra_size;
FILE* file;
clock_t* shell_times;
clock_t* insert_times;

void (*alg_fs[ALGO_COUNT])(int*, int);

int return_num(char* str, int length); // check is str a number
void (*(return_algo(char* str))) (int*, int); // check is str a valid algo

int* get_random_array(int size); // get array of a random numbers

int* read_file();
void write_file(char* file_name, int* source, int count);
void get_random_file(int count, char* file_name);

void dump_all();

int check_dataset();
