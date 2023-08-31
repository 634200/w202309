#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N, D; // N：鼠标点击次数，D：鼠标双击间隔
    scanf("%d %d", &N, &D);
    int *arr = (int *)malloc(sizeof(int) * N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (size_t i = 1; i < N; i++)
    {
        if (arr[i] - arr[i - 1] <= D)
        {
            printf("%d", arr[i]);
            return 0;
        }
    }
    printf("-1");

    return 0;
}
