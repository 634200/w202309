#include <stdio.h>
#include <stdlib.h>

// Fantasime 在二维坐标系的原点上。
// Fantasime 会重复传送 N 次。每次传送，他会执行以下移动之一：
// 从当前坐标 (x,y) 传送到 (x+A,y+B)。
// 从当前坐标 (x,y) 传送到 (x+C,y+D)。
// 从当前坐标 (x,y) 传送到 (x+E,y+F)。
// 在平面上有 M 个障碍，分别在点 (X1,Y1),…,(XM,YM) 上；他不能传送到这些点。
// N 次传送会产生多少条不同的路径。将数量取模 998244353 后输出。

// 判断是否在障碍物中
int isInObstacles(int x, int y, int **obstacles, int M)
{
    for (size_t i = 0; i < M; i++)
    {
        if (x == obstacles[i][0] && y == obstacles[i][1])
        {
            return 1;
        }
    }
    return 0;
}


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

    // 动态规划
    int **dp = (int **)malloc(sizeof(int *) * (N + 1));
    for (size_t i = 0; i < N + 1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (N + 1));
        for (size_t j = 0; j < N + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    // 初始化
    dp[0][0] = 1;

    // 递推
    for (size_t i = 0; i < N + 1; i++)
    {
        for (size_t j = 0; j < N + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            int x = 0;
            int y = 0;

            // 从当前坐标 (x,y) 传送到 (x+A,y+B)。
            x = i - A;
            y = j - B;
            if (x >= 0 && y >= 0 && !isInObstacles(x, y, obstacles, M))
            {
                dp[i][j] += dp[x][y];
            }

            // 从当前坐标 (x,y) 传送到 (x+C,y+D)。
            x = i - C;
            y = j - D;
            if (x >= 0 && y >= 0 && !isInObstacles(x, y, obstacles, M))
            {
                dp[i][j] += dp[x][y];
            }

            // 从当前坐标 (x,y) 传送到 (x+E,y+F)。
            x = i - E;
            y = j - F;
            if (x >= 0 && y >= 0 && !isInObstacles(x, y, obstacles, M))
            {
                dp[i][j] += dp[x][y];
            }

            dp[i][j] %= 998244353;
        }
    }

    printf("%d\n", dp[N][N]);

    return 0;
}
