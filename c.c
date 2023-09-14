#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    for (long long i = 0; i < 2147483648; i++)
        x++;

    if (x < 0)
        printf("x is negative\n");

    if (x >= 0)
        printf("x is positive\n");

    return 0;
}
