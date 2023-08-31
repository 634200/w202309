#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int K = 0;                                       // 没有被喊到 ID 的人的数量
    scanf("%d", &K);                                 // 输入 K
    int *IDs = (int *)malloc((K + 1) * sizeof(int)); // 存储 ID 的数组
    for (size_t i = 1; i <= K; i++)
    {
        scanf("%d", &IDs[i]);
    }

    for (size_t i = 1; i <= K; i++)
    {
        if (IDs[i] > 0) // 没被叫过，叫i位置的人
        {

            IDs[IDs[i]] = -abs(IDs[IDs[i]]); // 叫过的人 ID 变为负数
        }
    }

    // 存储没被叫过的人数
    int count = 0;

    for (size_t i = 1; i <= K; i++)
    {
        if (IDs[i] > 0)
        {
            count++;
        }
    }

    printf("%d\n", count);
    // 输出没被叫过的人的 ID
    for (size_t i = 1; i <= K; i++)
    {
        if (IDs[i] > 0)
        {
            // printf("%d", IDs[i]);
            printf("%d", i);
            // 最后一个不输出空格
            // count--;
            if (--count > 0)
            {
                printf(" ");
            }
        }
    }

    return 0;
}
