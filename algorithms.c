#include <stdio.h>

#include "includes/algorithms.h"

void shell_sort(int* arr, int size, int reverse_bit) {

    int i, j, step;
    int tmp;

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

void insertion_sort(int* arr, int size, int reverse_bit) {

    int temp;

    for (int i = 0; i < size; i++) {

        int bsearch_res = i;
        temp = arr[i];

        if ((bsearch_res = bsearch_more(arr, i + 1, temp)) < i) {

            for (int j = i; j > bsearch_res; j--)
                arr[j] = arr[j - 1];

            arr[bsearch_res] = temp;
        }
    }
}

int bsearch_more(int* arr, int size, int key) {

    int mid = arr[size / 2];

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