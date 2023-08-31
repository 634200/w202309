#include <iostream>

using namespace std;

const int N = 1E5 + 10;

int n;
int c[N];
bool flag[N];
bool vis[N];

class edge
{
public:
    int to;
    int next;
} e[N << 1];
int ep;

class point
{
public:
    int head_e;
    int c;
} p[N];

void _add_edge(int from, int to)
{
    ep++;
    e[ep].to = to;
    e[ep].next = p[from].head_e;

    p[from].head_e = ep;
}

void add_edge(int a, int b)
{
    _add_edge(a, b);
    _add_edge(b, a);
}

void dfs(int i)
{
    vis[i] = true;
    if (!c[p[i].c])
    {
        flag[i] = true;
    }

    c[p[i].c]++;

    for (int j = p[i].head_e; j != 0; j = e[j].next)
    {
        if (!vis[e[j].to])
        {
            dfs(e[j].to);
        }
    }

    c[p[i].c]--;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i].c);
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (flag[i])
        {
            printf("%d\n", i);
        }
    }

    return 0;
}