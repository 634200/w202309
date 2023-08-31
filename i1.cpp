#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

set<pair<int, int>> myset;

int a[5], b[5];
int n, m;
int res = 0;

void dfs(int x, int y, int cur)
{

    if (myset.count(make_pair(x, y)) > 0)
        return;

    if (cur == n)
    {
        res = (res + 1) % 998244353;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {

        dfs(x + a[i], y + b[i], cur + 1);
    }
}

int main()
{

    cin >> n >> m;
    int x, y;

    for (int i = 1; i <= 3; i++)
    {
        scanf("%d%d", &x, &y);
        a[i] = x;
        b[i] = y;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        myset.insert(make_pair(x, y));
    }

    dfs(0, 0, 0);
    cout << res;

    return 0;
}