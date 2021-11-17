long long return_num(char* str, long long length); // function returning an integer if str is an integer
void (*(return_algo(char* str))) (long long*, long long, short); // function returning algorithm if str is a valid algorithm

long long* get_random_array(long long size, unsigned long long max_random); // function returning array of random generated integers

long long* read_file(FILE* file, long long* file_size); // function reading array of integers from file
void write_file(FILE* file, long long* source, long long count); // function writing array of integers to file
void get_random_file(FILE* file, long long count, unsigned long long max_random); // function writing array of random integers to file

short check_dataset(long long* dataset, long long dataset_size); // function checking dataset for null numbers

clock_t benchmark(long long* arr, long long size, void (*algorithm)(long long*, long long, short), short reverse_bit); // function for benchmarking algorithms
