#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void printmap(char **map, int R, int C)
{
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int R, C;
    //  4 4
    scanf("%d %d", &R, &C);

    // R行C列char数组
    char **map = (char **)malloc(R * sizeof(char *));
    for (size_t i = 0; i < R; i++)
    {
        map[i] = (char *)malloc(C * sizeof(char));
    }
    // #.##
    for (size_t i = 0; i < R; i++)
    {
        scanf("%s", map[i]);
    }

    // 遍历找到炸弹（数字）的位置
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++) // 0 1 2 3
        {
            // 如果是数字，说明这个位置有炸弹
            int bomb = map[i][j] - '0';
            if (bomb >= 0 && bomb <= 9)
            {
                map[i][j] = '.';
                // 所有与炸弹曼哈顿距离不大于炸弹爆炸威力的格子都会变为空格子。
                for (size_t p = 0; p <= bomb; p++)
                {
                    for (size_t q = 0; q <= bomb - p; q++)
                    {
                        printf("%d %d\n", i + p, j + q);
                        if (i + p < R && j + q < C && map[i + p][j + q] == '#') // 下右
                        {
                            map[i + p][j + q] = '.';
                        }
                        printf("%d %d\n", i + p, j - q);
                        if (i + p < R && j - q >= 0 && map[i + p][j - q] == '#') // 下左
                        {
                            map[i + p][j - q] = '.';
                        }
                        printf("%d %d\n", i - p, j + q);
                        if (i - p >= 0 && j + q < C && map[i - p][j + q] == '#') // 上右
                        {
                            map[i - p][j + q] = '.';
                        }
                        printf("%d %d\n", i - p, j - q);
                        if (i - p >= 0 && j - q >= 0 && map[i - p][j - q] == '#') // 上左
                        {
                            map[i - p][j - q] = '.';
                        }
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < R; i++)
    {
        printf("%s\n", map[i]);
    }

    return 0;
}
