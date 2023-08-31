int n, m;
int a, b, c, d, e, f;
set<pair<int, int>> fail;
// i:type1 j:type2 k:type3
int dp[301][301][301] = {0};
void solve()
{
    read(n, m, a, b, c, d, e, f);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        read(x, y);
        fail.insert({x, y});
    }
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + j <= n; j++)
        {
            for (int k = 0; i + j + k <= n; k++)
            {
                if (i == j && j == k && i == 0)
                    continue;
                dp[i][j][k] = (i ? dp[i - 1][j][k] : 0) + (j ? dp[i][j - 1][k] : 0) + (k ? dp[i][j][k - 1] : 0);
                if (fail.find({i * a + j * c + k * e, i * b + j * d + k * f}) != fail.end())
                    dp[i][j][k] = 0;
                dp[i][j][k] %= M;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + j <= n; j++)
        {
            int k = n - i - j;
            (ans += dp[i][j][k]) %= M;
        }
    }
    cout << ans << endl;
}