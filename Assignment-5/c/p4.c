#include <stdio.h>
#include <stdlib.h>
#include "../../custom_headers/customio.h"

void selectionsort(int *, int, int);

int main(void)
{
    printf("\n---------- RECURSIVE SELECTION SORT ----------\n");
    printf("----------------------------------------------\n");

    int len;
    int *arr = get_int_array(" Array: ", &len);

    selectionsort(arr, 0, len);

    print_int_array(" Sorted Array: ", arr, 0, len);
    free(arr);

    return 0;
}

void selectionsort(int *arr, int start, int end)
{
    if (start >= end) return;

    int min_idx = start;
    for (int i = start + 1; i < end; ++i) {
        if (arr[i] < arr[min_idx]) 
            min_idx = i;
    }

    int temp = arr[start];
    arr[start] = arr[min_idx];
    arr[min_idx] = temp;

    selectionsort(arr, start + 1, end);
}