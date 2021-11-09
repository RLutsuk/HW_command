#include <stdio.h>

#include "includes/algorithms.h"

void shell_sort(long long* arr, long long size, short reverse_bit) {

    long long i, j, step;
    long long tmp;

    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++) {

        tmp = arr[i];

            for (j = i; j >= step; j -= step) {

                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }

            arr[j] = tmp;
        }
}

void insertion_sort(long long* arr, long long size, short reverse_bit) {

    long long temp;

    for (long long i = 0; i < size; i++) {

        long long bsearch_res = i;
        temp = arr[i];

        if ((bsearch_res = bsearch_more(arr, i + 1, temp)) < i) {

            for (long long j = i; j > bsearch_res; j--)
                arr[j] = arr[j - 1];

            arr[bsearch_res] = temp;
        }
    }
}

long long bsearch_more(long long* arr, long long size, long long key) {

    long long mid = arr[size / 2];

    if (mid > key) {

        if (size == 1)
            return 0;

        return bsearch_more(arr, size / 2, key);
    }


    else if (mid < key) {

        if (size == 1)
            return 1;

        return ((size / 2) + bsearch_more(arr + size / 2, size - size / 2, key));
    }

    return (size / 2);
}