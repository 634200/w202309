#include <stdio.h>
#include <stdlib.h>

// Fantasime 在二维坐标系的原点上。
// Fantasime 会重复传送 N 次。每次传送，他会执行以下移动之一：
// 从当前坐标 (x,y) 传送到 (x+A,y+B)。
// 从当前坐标 (x,y) 传送到 (x+C,y+D)。
// 从当前坐标 (x,y) 传送到 (x+E,y+F)。
// 在平面上有 M 个障碍，分别在点 (X1,Y1),…,(XM,YM) 上；他不能传送到这些点。
// N 次传送会产生多少条不同的路径。将数量取模 998244353 后输出。

// 超时

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

int num = 0;

void tp(int x, int y, int A, int B, int C, int D, int E, int F, int **obstacles, int M, int n)
{
    // int num = 0;
    int newX = x + A;
    int newY = y + B;
    if (!isInObstacles(newX, newY, obstacles, M))
    {
        if (n > 1)
        {
            tp(newX, newY, A, B, C, D, E, F, obstacles, M, n - 1);
        }
        else
        {
            num++;
        }
    }

    newX = x + C;
    newY = y + D;
    if (!isInObstacles(newX, newY, obstacles, M))
    {
        if (n > 1)
        {
            tp(newX, newY, A, B, C, D, E, F, obstacles, M, n - 1);
        }
        else
        {
            num++;
        }
    }

    newX = x + E;
    newY = y + F;
    if (!isInObstacles(newX, newY, obstacles, M))
    {
        if (n > 1)
        {
            tp(newX, newY, A, B, C, D, E, F, obstacles, M, n - 1);
        }
        else
        {
            num++;
        }
    }

    // return num % 998244353;
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

    // 传送
    // int num = tp(0, 0, A, B, C, D, E, F, obstacles, M, N);
    tp(0, 0, A, B, C, D, E, F, obstacles, M, N);
    printf("%d\n", num % 998244353);

    return 0;
}
