#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int p[N], bian[N], dian[N];

// 寻找父节点
int find(int x)
{

    if (p[x] != x)
        p[x] = find(p[x]);

    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        dian[i] = 1;
        bian[i] = 0;
    }

    int a, b;
    while (m--)
    {

        cin >> a >> b;

        if (find(a) == find(b))
            bian[p[find(a)]] += 1; // 如果是在一个并查集， 边数 + 1
        else
        {

            bian[find(b)] += bian[find(a)] + 1; // 边数和点数同时加1
            dian[find(b)] += dian[find(a)];
            p[find(a)] = find(b);
        }
    }

    int flag = 0;
    for (int i = 1; i <= n; i++)
    {

        if (bian[find(i)] != dian[find(i)])
        {
            puts("No");
            flag = 1;
            break;
        }
    }

    if (!flag)
        puts("Yes");
    return 0;
}