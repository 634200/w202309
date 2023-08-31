#include <stdio.h>
#include <stdlib.h>

#define LEN 8

int judge(char *h)
{

    // int b1 = 0, b2 = 0, k = 0, r1 = 0, r2 = 0;
    int b1 = -1, b2 = -1, k = -1, r1 = -1, r2 = -1;
    for (size_t i = 0; i < LEN; i++)
    {

        if (h[i] == 'B' && b1 == -1)
            b1 = i;
        else if (h[i] == 'B')
            b2 = i;

        if (h[i] == 'K')
            k = i;

        if (h[i] == 'R' && r1 == -1)
            r1 = i;
        else if (h[i] == 'R')
            r2 = i;
    }

    return (k > r1 && k < r2 && (b1 + b2) % 2 == 1);
}

int main(int argc, char const *argv[])
{
    char charArr[LEN];
    for (size_t i = 0; i < LEN; i++)
    {
        scanf("%c", &charArr[i]);
    }
    int yes_or_no = judge(charArr);
    printf("%s", yes_or_no ? "Yes" : "No");

    return 0;
}

/*
int judge(char arr[])
{
    // 找到K
    int k = -1;
    for (size_t i = 0; i < LEN; i++)
    {
        if (arr[i] == 'K')
        {
            k = i;
            break;
        }
    }
    // 从k的位置向前找R
    int rNum = 0;
    for (size_t i = k; i >= 0; i--)
    {
        if (arr[i] == 'R')
        {
            rNum++;
            // if (++rNum > 1)
            // {
            //     return 0;
            // }
        }
    }
    return rNum == 1;
}
*/

/*
int judge(char arr[])
{
    int r = -1;

    for (size_t i = 0; i < LEN; i++)
    {
        switch (arr[i])
        {
        case 'K':
            if (r == -1)
            {
                return 0; // K__
            }
            else
            {
                return 1; // RK
            }
        case 'R':
            if (r == -1) // 第一个R
            {
                r = i; // R__
            }
            else
            {
                return 0;
            }
            break;
        }
    }
    return 0;
}*/