#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 20

int main(int argc, char const *argv[])
{
    int N = 0; // 吃了 N 盘地三鲜
    int M = 0; // 盘子的颜色数目
    scanf("%d %d", &N, &M);

    // dishes[i]表示第 i 盘地三鲜的颜色
    char **dishes = (char **)malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
    {
        dishes[i] = (char *)malloc(sizeof(char) * MAXLEN);
        scanf("%s", dishes[i]);
    }

    // pricesColor
    char **pricesColor = (char **)malloc(sizeof(char *) * (M));
    for (int i = 0; i < M; i++)
    {
        pricesColor[i] = (char *)malloc(sizeof(char) * MAXLEN);
        scanf("%s", pricesColor[i]);
    }

    // prices
    int *prices = (int *)malloc(sizeof(int) * (M + 1));
    for (int i = 0; i < M + 1; i++)
    {
        scanf("%d", &prices[i]);
    }

    // 遍历dishes，计算总价格
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        // dishes[i] = (char *)malloc(sizeof(char) * MAXLEN);
        char *dish = dishes[i];
        // 遍历pricesColor，找到dish对应的价格
        int price = 0;
        for (int j = 0; j < M; j++)
        {
            char *priceColor = pricesColor[j];
            if (strcmp(dish, priceColor) == 0)
            {
                price = prices[j + 1];
                break;
            }
        }
        // 没找到
        if (price == 0)
        {
            price = prices[0];
        }
        total += price;
    }
    printf("%d", total);
    return 0;
}
