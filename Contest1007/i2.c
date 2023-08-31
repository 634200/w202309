// from copilot Error

#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

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
    int N, M;
    scanf("%d %d", &N, &M);

    int A, B, C, D, E, F;
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

    int **obstacles = (int **)malloc(sizeof(int *) * M);
    for (size_t i = 0; i < M; i++)
    {
        obstacles[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &obstacles[i][0], &obstacles[i][1]);
    }

    int ***dp = (int ***)malloc(sizeof(int **) * (N + 1));
    for (size_t i = 0; i <= N; i++)
    {
        dp[i] = (int **)malloc(sizeof(int *) * 301);
        for (size_t j = 0; j <= 300; j++)
        {
            dp[i][j] = (int *)malloc(sizeof(int) * 301);
            for (size_t k = 0; k <= 300; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j <= 300; j++)
        {
            for (size_t k = 0; k <= 300; k++)
            {
                if (dp[i - 1][j][k] == 0)
                {
                    continue;
                }
                if (j >= A && k >= B && !isInObstacles(j - A, k - B, obstacles, M))
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - A][k - B]) % MOD;
                }
                if (j >= C && k >= D && !isInObstacles(j - C, k - D, obstacles, M))
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - C][k - D]) % MOD;
                }
                if (j >= E && k >= F && !isInObstacles(j - E, k - F, obstacles, M))
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - E][k - F]) % MOD;
                }
            }
        }
    }

    printf("%d\n", dp[N][0][0]);

    return 0;
}