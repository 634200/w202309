#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int M = 1E5 + 10;
const int N = 3E2 + 1;
const long long MOD = 998244353;

int n, m;
long long a, b, c, d, e, f;

set<pair<long long, long long>> st;

long long dp[N][N][N];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f);
    for (int i = 1; i <= m; i++)
    {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        st.insert(make_pair(x, y));
    }

    dp[0][0][0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            for (int k = 0; k <= n - i - j; k++)
            {
                if (st.find(make_pair(a * i + c * j + e * k,
                                      b * i + d * j + f * k)) == st.end())
                {
                    if (i)
                    {
                        dp[i][j][k] += dp[i - 1][j][k];
                    }
                    if (j)
                    {
                        dp[i][j][k] += dp[i][j - 1][k];
                    }
                    if (k)
                    {
                        dp[i][j][k] += dp[i][j][k - 1];
                    }
                    dp[i][j][k] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            ans += dp[i][j][n - i - j];
            ans %= MOD;
        }
    }

    printf("%lld", ans);
}