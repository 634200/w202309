#include <stdio.h>
#include <stdlib.h>

// Fantasime 在二维坐标系的原点上。
// Fantasime 会重复传送 N 次。每次传送，他会执行以下移动之一：
// 从当前坐标 (x,y) 传送到 (x+A,y+B)。
// 从当前坐标 (x,y) 传送到 (x+C,y+D)。
// 从当前坐标 (x,y) 传送到 (x+E,y+F)。
// 在平面上有 M 个障碍，分别在点 (X1,Y1),…,(XM,YM) 上；他不能传送到这些点。
// N 次传送会产生多少条不同的路径。将数量取模 998244353 后输出。

// 测试用例
// 2 2
// 1 1 1 2 1 3
// 1 2
// 2 2

// 5

#define MOD 998244353

int arrFind(int **arr, int len, int x, int y)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i][0] == x && arr[i][1] == y)
        {
            return 1;
        }
    }
    return 0;
} // arrFind

int main(int argc, char const *argv[])
{
    int N; // 传送次数
    int M; // 障碍数
    scanf("%d %d", &N, &M);

    int A, B, C, D, E, F;
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

    // 障碍
    int **obstacles = (int **)malloc(sizeof(int *) * M);
    for (size_t i = 0; i < M; i++)
    {
        obstacles[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &obstacles[i][0], &obstacles[i][1]);
    }

    // 初始化三维数组dp
    int ***dp = (int ***)malloc(sizeof(int **) * (N + 1));
    for (size_t i = 0; i < N + 1; i++)
    {
        dp[i] = (int **)malloc(sizeof(int *) * (N + 1));
        for (size_t j = 0; j < N + 1; j++)
        {
            dp[i][j] = (int *)malloc(sizeof(int) * (N + 1));
            for (size_t k = 0; k < N + 1; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    // 初始化dp[0][0][0]
    dp[0][0][0] = 1;

    // 遍历所有状态
    for (size_t i = 0; i <= N; i++)
    {
        for (size_t j = 0; j <= N - i; j++)
        {
            for (size_t k = 0; k <= N - i - j; k++)
            {
                if (!arrFind(obstacles, M, A * i + C * j + E * k,
                             B * i + D * j + F * k))
                {
                    if (i)
                    {
                        dp[i][j][k] += dp[i - 1][j][k];
                    }
                    if (j)
                    {
                        dp[i][j][k] += dp[i][j - 1][k];
                    }
                    if (k)
                    {
                        dp[i][j][k] += dp[i][j][k - 1];
                    }
                    dp[i][j][k] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (size_t i = 0; i <= N; i++)
    {
        for (size_t j = 0; j <= N - i; j++)
        {
            ans += dp[i][j][N - i - j];
            ans %= MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}
