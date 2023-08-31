#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100010

typedef struct Edge
{
    int to;
    int next;
} Edge;

typedef struct Point
{
    int headEdge;
    int color;
} Point;

// 创建所有节点
Point points[MAX_N];

// 创建所有边
Edge edges[MAX_N * 2];

// 创建访问数组
int visited[MAX_N];

// 创建颜色计数数组
int count[MAX_N];

// 创建标记数组
int flag[MAX_N];

void addEdgeInternal(Edge *edges, Point *points, int from, int to)
{
    static int edgeCount = 0;
    edgeCount++;
    edges[edgeCount].to = to;
    edges[edgeCount].next = points[from].headEdge;

    points[from].headEdge = edgeCount;
}

// 添加边
void addEdge(int a, int b)
{
    addEdgeInternal(edges, points, a, b);
    addEdgeInternal(edges, points, b, a);
}

void dfs(int root)
{
    visited[root] = 1;
    int rootPointColor = points[root].color;
    if (!count[rootPointColor])
    {
        flag[root] = 1;
    }

    count[rootPointColor]++;

    for (int i = points[root].headEdge; i != 0; i = edges[i].next)
    {
        int to = edges[i].to;
        if (!visited[to])
        {
            dfs(to);
        }
    }

    count[rootPointColor]--;
}

int main(int argc, char const *argv[])
{

    int N; // 节点数
    scanf("%d", &N);

    // 初始化
    for (size_t i = 0; i <= N; i++)
    {
        points[i].headEdge = 0;
        points[i].color = 0;
    }

    // 读入节点
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &points[i].color);
    }

    // 初始化
    for (size_t i = 0; i < (N + 1) * 2; i++)
    {
        edges[i].to = 0;
        edges[i].next = 0;
    }

    // 读入边
    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    // 初始化
    for (size_t i = 0; i <= N; i++)
    {
        visited[i] = 0;
        count[i] = 0;
        flag[i] = 0;
    }

    // 从第一个节点开始遍历
    dfs(1);

    // 输出结果
    for (size_t i = 1; i <= N; i++)
    {
        if (flag[i])
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
