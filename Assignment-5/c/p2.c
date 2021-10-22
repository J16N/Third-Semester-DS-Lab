/*
 * QUICKSORT
 * (USING HOARE'S PARTITION-EXCHANGE ALGORITHM)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../custom_headers/customio.h"

int partition(int *, int, int);
void quicksort(int *, int, int);

int main(void)
{
    int len;
    int *arr = get_int_array("Array: ", &len);
    
    quicksort(arr, 0, len - 1);

    print_int_array("Sorted Array: ", arr, 0, len);
    free(arr);

    return 0;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i >= j) return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        print_int_array("Sub-array: ", arr, low, high + 1);
    }
}

void quicksort(int *arr, int low, int high)
{
    if (low > high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot);
        quicksort(arr, pivot + 1, high);
    }
}