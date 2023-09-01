#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <unordered_map>

const int N = 2;

int arr[N]; // 0 0
int arr1[1];

int arrLen(int arr[])
{
    return sizeof(arr) / sizeof(arr[0]);
}

int arrLen0(int *arr1)
{
    return sizeof(arr1) / sizeof(arr1[0]); // 4/4 = 1
}

int main(int argc, char const *argv[])
{
    arr[N] = 99; // 0 0 1
    printf("%d\n", arr[N]);

    for (int i = 0; i < 2 * N; i++)
    {
        printf("%d ", arr[i]);
    }

    // print arr1
    printf("\n");
    printf("arr1: arr1[0] = %d\n", arr1[0]);
    printf("arr1: arr1[1] = %d\n", arr1[1]);

    printf("arr: arrLen(arr) = %d\n", arrLen(arr));    // 2
    printf("arr1: arrLen(arr1) = %d\n", arrLen(arr1)); // 1

    printf("arr: len(arr) = %d\n", sizeof(arr) / sizeof(arr[0]));     // 2
    printf("arr1: len(arr1) = %d\n", sizeof(arr1) / sizeof(arr1[0])); // 1

    printf("p:%d\n", 0 [arr]); // 0
    printf("p:%d\n", 1 [arr]); // 0

    printf("p:%d\n", 0 [arr1]); // 99
    printf("p:%d\n", arr1[0]);  // 99

    // c/cpp本质
    printf("p:%d\n", *(arr1 + 0)); // 0
    printf("p:%d\n", *(0 + arr1)); // 0

    int arr2[2] = {1, 2};
    int *p = arr2;
    int *arrp = (int *)malloc(sizeof(int) * 2);
    arrp[0] = 1;
    arrp[1] = 2;

    printf("p:%d\n", *(arrp + 0)); // 1
    printf("p:%d\n", *(arrp + 1)); // 1

    // int *const p1 = arr2;

    // const int *p1 = arr2;
    int* pp = arr2;
    // arr2 = pp; // 数组名本质是一个指针常量，不能被赋值

    return 0;
}
