#include <stdio.h>

void towerOfHanoi(int, char, char, char);

int main(void)
{
    printf("\n---------- TOWER OF HANOI ----------\n");
    printf("------------------------------------\n");

    int n;
    printf(" Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}

void towerOfHanoi(int n, char from, char to, char aux)
{
    static int moves = 1;

    if (n == 1) {
        printf(" %d) Move disk 1 from rod %c to rod %c.\n", moves++, from, to);
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    printf(" %d) Move disk %d from rod %c to rod %c.\n", moves++, n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}