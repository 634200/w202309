#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 2.5e3.0;

    // int a = 3;
    // a += a -= a * a;
    // printf("%d\n", a);

    printf("%f", 3.5 - 5 / 2 + 1.2 + 5 % 2);

    int a = 2, b = 3, c = 4;
    c = a, a = b, b = c;
    printf("%d %d %d\n", a, b, c);

    int x, y;
    for (y = 1, x = 1; y <=50; y++)
    {
        if (x>=10)
        {
            break;
        }
        if (x % 2 == 1)
        {
            x += 5;
            continue;
        }
        x -= 3;
    }
    printf("%d\n", x);
    printf("%d\n", y);

    int arr[5 + 5];
    return 0;
}
