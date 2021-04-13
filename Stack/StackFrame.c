#include <stdio.h>

int sum = 0;
int FunGaosi(int value)
{
    if (value == 1)
        return 1;
    sum = value + FunGaosi(value - 1);
    return sum;
}

int main()
{
    printf("%d", FunGaosi(4));
    getchar();
    return 0;
}
