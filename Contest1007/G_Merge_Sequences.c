#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // 如果中间元素等于目标元素，则返回索引
        if (arr[mid] == target)
        {
            return mid;
        }

        // 如果中间元素大于目标元素，则在左半部分继续查找
        if (arr[mid] > target)
        {
            high = mid - 1;
        }

        // 如果中间元素小于目标元素，则在右半部分继续查找
        else
        {
            low = mid + 1;
        }
    }

    // 如果找不到目标元素，则返回-1
    return -1;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);

    // 分配内存
    int *A = (int *)malloc(sizeof(int) * N);
    int *B = (int *)malloc(sizeof(int) * M);

    // 输入（初始化）
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }

    // 合并
    int *C = (int *)malloc(sizeof(int) * (N + M));
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        C[k++] = A[i];
    }
    for (int i = 0; i < M; i++)
    {
        C[k++] = B[i];
    }

    // 排序
    qsort(C, N + M, sizeof(int), compare);

    // 输出A中的每个元素在C中的位置
    for (int i = 0; i < N; i++)
    {
        int index = binarySearch(C, 0, N + M - 1, A[i]) + 1;
        printf("%d", index);
        if (i != N - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // 输出B中的每个元素在C中的位置
    for (int i = 0; i < M; i++)
    {
        int index = binarySearch(C, 0, N + M - 1, B[i]) + 1;
        printf("%d", index);
        if (i != M - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
