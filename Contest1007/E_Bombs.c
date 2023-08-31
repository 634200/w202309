#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(int argc, char const *argv[])
{
    int R, C;
    //  4 4
    scanf("%d %d", &R, &C);

    // R行C列char数组
    char **map = (char **)malloc(R * sizeof(char *));
    for (int i = 0; i < R; i++)
    {
        map[i] = (char *)malloc(C * sizeof(char));
    }

    // .1.#
    // ###.
    // .#2.
    // #.##
    for (int i = 0; i < R; i++)
    {
        scanf("%s", map[i]);
    }

    // 遍历找到炸弹（数字）的位置
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++) // 0 1 2 3
        {
            // 如果是数字，说明这个位置有炸弹
            int bomb = map[i][j] - '0';
            if (bomb >= 0 && bomb <= 9)
            {
                map[i][j] = '.';
                // 所有与炸弹曼哈顿距离不大于炸弹爆炸威力的格子都会变为空格子。
                for (int r = max(0, i - bomb); r <= min(i + bomb, R - 1); r++)
                {
                    for (int c = max(0, j - bomb); c <= min(j + bomb, C - 1); c++)
                    {
                        if (abs(r - i) + abs(c - j) <= bomb && map[r][c] == '#')
                        {
                            map[r][c] = '.';
                        }
                    }
                }
            }
        }
    }

    // ...#
    // #...
    // ....
    // #...
    for (int i = 0; i < R; i++)
    {
        printf("%s\n", map[i]);
    }

    return 0;
}
