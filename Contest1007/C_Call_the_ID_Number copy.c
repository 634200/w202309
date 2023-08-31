#include <stdio.h>
#include <stdlib.h>

int k;
int main()
{
    scanf("%d", &k);
    int *h = (int *)malloc((k + 1) * sizeof(int));
    for (size_t i = 1; i <= k; i++)
    {
        scanf("%d", &h[i]);
    }

    for (size_t i = 1; i <= k; i++)
    {
        if (h[i] > 0)
        {
            h[h[i]] = -abs(h[h[i]]);
        }
    }

    int count = 0;
    for (size_t i = 1; i <= k; i++)
    {
        if (h[i] > 0)
        {
            count++;
        }
    }

    printf("%d\n", count);
    for (size_t i = 1; i <= k; i++)
    {
        if (h[i] > 0)
        {

            printf("%d", i);
            if (--count > 0)
            {
                printf(" ");
            }
        }
    }

    return 0;
}
