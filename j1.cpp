#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 100010;

vector<int> res;
unordered_map<int, int> mymap;

int C[N]; // 节点的颜色1

int n;

int e[N << 1];  // 是一个数组，用来存储每个节点的值（颜色）。e[i]表示节点i的值，e[a] = b表示节点a的值为b，表示a指向b。
int h[N << 1];  // 是一个数组，用来模拟邻接表的头结点数组。h[i]表示以节点i为起点的第一个边的索引。
int idx;        // 是一个变量，用来表示当前可用的边的索引。
int ne[N << 1]; // 是一个数组，用来存储每条边的下一个边的索引。ne[i]表示边i的下一条边的索引。
bool st[N];     // 是一个数组，用来标记节点是否已经遍历过。st[i]为true表示节点i已经被遍历过，否则为false。

void add(int x, int y)
{
    e[idx] = y;     // e[i] 表示 e[a] = b 如果 a -> b
    ne[idx] = h[x]; // ne[i] 表示 ne[a] = b 如果 a -> b
    h[x] = idx++;
}

void dfs(int cur)
{

    int currentColor = C[cur];
    st[cur] = true;

    // 如果路径上没有该点的染色
    if (mymap.find(currentColor) == mymap.end())
    {
        mymap[currentColor] = 1;
        res.push_back(cur);
    }
    else
        mymap[currentColor] = mymap[currentColor] + 1;

    for (int i = h[cur]; i != -1; i = ne[i])
    {
        if (!st[e[i]])
        {
            dfs(e[i]);
        }
    }

    st[cur] = false;

    mymap[currentColor] = mymap[currentColor] - 1;

    if (mymap[currentColor] == 0)
        mymap.erase(currentColor);
}

int main()
{

    cin >> n;

    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &C[i]);
    }

    int x, y;
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    dfs(1);

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size() - 1; i++)
    {
        printf("%d\n", res[i]);
    }

    cout << res[res.size() - 1];
    return 0;
}