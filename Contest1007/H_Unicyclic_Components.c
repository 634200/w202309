#include <stdio.h>
#include <stdlib.h>

// 定义一个结构体存储连通分量
typedef struct
{
    int *vertices; // 顶点集合
    int vertexNum; // 顶点数
    int edgeNum;   // 边数
} Component;

// 从顶点 v 开始进行 DFS
void DFS(int **G, int N, int v, int *visited, Component *component)
{
    visited[v] = 1;
    component->vertices[component->vertexNum++] = v;

    // for (int i = 1; i <= N; i++)
    for (int i = v + 1; i <= N; i++) // 只遍历 v 之后的顶点
    {
        // if (G[v][i] == 1 && visited[i] == 0)
        // {
        //     component->edgeNum++;
        //     DFS(G, N, i, visited, component);
        // }
        if (G[v][i] == 1)
        {
            component->edgeNum++;
            if (visited[i] == 0)
            {
                DFS(G, N, i, visited, component);
            }
        }
    }
}

// 初始化一个连通分量
void initComponent(Component *component, int N)
{
    component->vertices = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i <= N; i++)
    {
        component->vertices[i] = -1;
    }
    component->vertexNum = 0;
    component->edgeNum = 0;
}

int componentNum = 0;

// 给定一个图，返回图中的所有连通分量
Component *getComponents(int **G, int N)
{
    Component *components = (Component *)malloc(sizeof(Component) * N);
    int *visited = (int *)malloc(sizeof(int) * (N + 1));
    // 初始化 visited
    for (int i = 0; i <= N; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }

    // int componentNum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            initComponent(&components[componentNum], N);
            DFS(G, N, i, visited, &components[componentNum]);
            componentNum++;
        }
    }

    return components;
}

int main(int argc, char const *argv[])
{
    int N; // 顶点数
    int M; // 边数
    scanf("%d %d", &N, &M);

    // 图的临接矩阵
    int **G = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 1; i <= N; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * (N + 1));
        for (int j = 1; j <= N; j++)
        {
            G[i][j] = 0;
        }
    }

    // 输入
    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }

    // 确定是否图中的每个联通分量都满足联通分量中有相同数量的点和边。
    Component *components = getComponents(G, N);
    int flag = 1;

    for (int i = 0; i < componentNum; i++)
    {
        if (components[i].vertexNum != components[i].edgeNum)
        {
            flag = 0;
            break;
        }
    }

    printf("%s\n", flag ? "Yes" : "No");

    return 0;
}
