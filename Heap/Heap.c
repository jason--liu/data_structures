#include <stdio.h>

void Insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while (i > 1 && temp > H[i / 2]) {
        H[i] = H[i / 2];
        i = i / 2;
    }

    H[i]=temp;
}

int Delete(int H[], int n)
{
    int i, j, val;
    int temp;

    val = H[1];
    /* x = H[n]; */
    H[1] = H[n];
    H[n] = val;
    i = 1;
    j = i * 2;

    while (j < n - 1) {
        if (H[j + 1] > H[j])
            j++;
        if (H[i] < H[j]) {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2 * j;
        } else
            break;
    }
    return val;
}

int main(int argc, char* argv[])
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 2; i <= 7; i++) {
        Insert(H, i);
    }

    /* printf("Delete val is %d\n", Delete(H, 7)); */

    /* Heap Sort */
    for (i = 7; i > 1; i--)
        Delete(H, i);

    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}
