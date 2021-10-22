#include <stdio.h>
#include <stdlib.h>
#include "../../custom_headers/customio.h"

void merge(int *, int, int, int);
void mergesort(int *, int, int);

int main(void)
{
    int len;
    int *arr = get_int_array("Array: ", &len);

    mergesort(arr, 0, len - 1);

    print_int_array("Sorted Array: ", arr, 0, len);
    free(arr);

    return 0;
}

void merge(int *arr, int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) 
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }

    while (i <= mid) 
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergesort(int *arr, int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}