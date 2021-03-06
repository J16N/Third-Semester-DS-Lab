#include <stdio.h>
#include <stdlib.h>
#include "customio.h"

int *get_int_array(char *label, int *len)
{
    printf("%s", label);
    *len = 0;
    int c;
    int *arr = NULL;
    do {
        int temp;
        scanf("%d", &temp);
        arr = realloc( arr, (*len + 1) * sizeof(int) );
        arr[(*len)++] = temp;
        c = getchar();
    } while (c != '\n');
    
    return arr;
}

void print_int_array(char *label, int *arr, int low, int high)
{
    printf("%s", label);
    for (int i = low; i < high; i++)
        printf("%d%s", arr[i], i + 1 == high ? "\n" : ", ");
}