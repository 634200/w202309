#include <stdio.h>
#include <stdlib.h>

int test()
{
    static a = 1;
    a++;
    return a;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", test());
    printf("%d\n", test());
    printf("%d\n", test());
    return 0;
}