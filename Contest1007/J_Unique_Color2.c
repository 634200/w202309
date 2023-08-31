#include <stdio.h>
#include <stdlib.h>

/*
10
3 1 4 1 5 9 2 6 5 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/

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

void addEdgeInternal(Edge *edges, Point *points, int from, int to)
{
    static int edgeCount = 0;
    edgeCount++;
    edges[edgeCount].to = to;
    edges[edgeCount].next = points[from].headEdge;

    points[from].headEdge = edgeCount;
}

// 添加边
void addEdge(Edge *edges, Point *points, int a, int b)
{
    addEdgeInternal(edges, points, a, b);
    addEdgeInternal(edges, points, b, a);
}

void dfs(Point *points, Edge *edges, int root, int *visited, int *count, int *flag)
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
        // printf("root: %d, i: %d\n", root, i);
        int to = edges[i].to;
        if (!visited[to])
        {
            dfs(points, edges, to, visited, count, flag);
        }
    }

    count[rootPointColor]--;
}

int main(int argc, char const *argv[])
{

    int N; // 节点数
    scanf("%d", &N);

    // 创建所有节点
    Point *points = (Point *)malloc(sizeof(Point) * (N + 1));
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

    // 创建所有边
    Edge *edges = (Edge *)malloc(sizeof(Edge) * (N + 1) * 2);
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
        addEdge(edges, points, a, b);
    }

    // 创建访问数组
    int *visited = (int *)malloc(sizeof(int) * (N + 1));

    // 创建颜色计数数组
    int *count = (int *)malloc(sizeof(int) * (N + 1));

    // 创建标记数组
    int *flag = (int *)malloc(sizeof(int) * (N + 1));

    // 初始化
    for (size_t i = 0; i <= N; i++)
    {
        visited[i] = 0;
        count[i] = 0;
        flag[i] = 0;
    }

    // 从第一个节点开始遍历
    dfs(points, edges, 1, visited, count, flag);

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
