#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    // msvc编译器不支持变长数组
    int arr[n];
    return 0;
}
