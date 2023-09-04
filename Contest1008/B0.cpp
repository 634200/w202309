#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
char s[N];
int ne[N];
int dp[N];
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    s[n + 1] = '#', dp[n + 1] = 0;
    scanf("%s", s + 2 + n);
    n = strlen(s + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        dp[i] = min(dp[i], dp[i - j] + 1);
        //        printf("%c %d %d %d\n",s[i], i - j, i, dp[i]);
        ne[i] = j;
    }
    if (dp[n] == INF)
        puts("-1");
    else
        printf("%d\n", dp[n]);
    //    puts(s + 1);
    return 0;
}