#include <stdio.h>

#include "includes/algorithms.h"

void shell_sort(long long* arr, long long size, short reverse_bit) {

    long long step = (size >> 1);

    while(step) {

        for(long long i = step; i < size; i++) {

            for(long long k = i - step; k >= 0 && (reverse_bit * arr[k]) > (reverse_bit * arr[k + step]); k -= step) {

                long long temp = arr[k];
                arr[k] = arr[k + step];
                arr[k + step] = temp;
            }
        }

        step >>= 1;
    }
}

void insertion_sort_slow(long long* arr, long long size, short reverse_bit) {

    long long temp;
    long long index;
 
    for (long long i = 1; i < size; i++) {

        temp = arr[i];
        index = i - 1;

        while(index >= 0 && (reverse_bit * arr[index]) > (reverse_bit * temp)) {
            arr[index + 1] = arr[index];
            index--;
        }

        arr[index + 1] = temp;
    }
}

void insertion_sort(long long* arr, long long size, short reverse_bit) {

    long long temp;

    for (long long i = 0; i < size; i++) {

        long long bsearch_res = i;
        temp = arr[i];

        if ((bsearch_res = bsearch_more(arr, i, temp)) < i) {

            for (long long j = i; j > bsearch_res; j--)
                arr[j] = arr[j - 1];

            arr[bsearch_res] = temp;
        }
    }

    if(reverse_bit == -1)
        for(long long i = 0; i < (size >> 1); i++) {

            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
}

long long bsearch_more(long long* arr, long long size, long long key) {

    long long mid = arr[(size >> 1)];

    if (mid > key) {

        if (size == 1)
            return 0;

        return bsearch_more(arr, (size >> 1), key);
    }

    else if (mid < key) {

        if (size == 1)
            return 1;

        return ((size >> 1) + bsearch_more(arr + (size >> 1), size - (size >> 1), key));
    }

    return (size >> 1);
}