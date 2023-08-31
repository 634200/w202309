// from gpt3 Error

#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int A, B, C, D, E, F;
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

    // int obstacles[M][2];
    int **obstacles = (int **)malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
        obstacles[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &obstacles[i][0], &obstacles[i][1]);
    }

    // int dp[N + 1][N + 1];
    int **dp = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i <= N; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (N + 1));
    }

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
                for (int k = 0; k < M; k++)
                {
                    if (obstacles[k][0] == i && obstacles[k][1] == j)
                    {
                        continue;
                    }
                    if (i >= A && j >= B)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - A][j - B]) % MOD;
                    }
                    if (i >= C && j >= D)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - C][j - D]) % MOD;
                    }
                    if (i >= E && j >= F)
                    {
                        dp[i][j] = (dp[i][j] + dp[i - E][j - F]) % MOD;
                    }
                }
            }
        }
    }

    printf("%d\n", dp[N][N]);

    return 0;
}