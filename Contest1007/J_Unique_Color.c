#include <stdio.h>
#include <stdlib.h>

// 返回一个数组，数组中的第 i 个元素表示，从节点 i 到节点 start 的最短路径的前一个节点。
int *dijkstra(int **graph, int N, int start)
{
    // 初始化路径、距离和访问标志数组
    int *path = (int *)malloc(sizeof(int) * (N + 1));
    int *dist = (int *)malloc(sizeof(int) * (N + 1));
    int *visited = (int *)malloc(sizeof(int) * (N + 1));
    for (int i = 0; i < N + 1; i++)
    {
        path[i] = -1;
        dist[i] = 0x7fffffff;
        visited[i] = 0;
    }
    dist[start] = 0;

    // 循环遍历所有顶点
    for (int count = 0; count < N; count++)
    {
        int minDist = 0x7fffffff;
        int minIndex;

        // 找到当前距离最短的顶点
        for (int i = 1; i < N + 1; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                minIndex = i;
            }
        }

        // 标记该顶点已访问
        visited[minIndex] = 1;

        // 更新其他顶点的距离
        for (int i = 1; i < N + 1; i++)
        {
            if (!visited[i] && graph[minIndex][i] && dist[minIndex] != 0x7fffffff && dist[minIndex] + graph[minIndex][i] < dist[i])
            {
                dist[i] = dist[minIndex] + graph[minIndex][i];
                path[i] = minIndex;
            }
        }
    }
    // free(dist);
    // free(visited);

    return path;
}

int main(int argc, char const *argv[])
{
    // 给定一个 N 个节点的树。第 i 条边连接了节点 A_i 和 B_i。节点 i 被涂上颜色 C_i（这个问题中，颜色使用整数表示）。
    // 找到所有好节点。

    int N; // 节点数
    scanf("%d", &N);

    // 创建所有节点
    int *nodes = (int *)malloc(sizeof(int) * (N + 1));
    // 读入节点颜色
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &nodes[i]);
    }

    int **G = (int **)malloc(sizeof(int *) * (N + 1));
    for (int i = 0; i < N + 1; i++)
    {
        G[i] = (int *)malloc(sizeof(int) * (N + 1));
        for (int j = 0; j < N + 1; j++)
        {
            G[i][j] = 0;
        }
    }

    // 读入节点关系
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        G[a][b] = 1;
        G[b][a] = 1;
    }

    // Dijkstra找到1到其他节点的最短路径
    int *path = dijkstra(G, N, 1);

    // int *good_nodes = (int *)malloc(sizeof(int) * (N + 1));

    // 遍历所有节点
    int flag = 0;
    for (int i = 1; i <= N; i++)
    {
        int j = i;
        while ((j = path[j]) != -1)
        {
            if (nodes[j] == nodes[i])
            {
                // good_nodes[i] = 0;
                break;
            }
        }
        if (j == -1)
        {
            if (flag)
            {
                printf("\n");
            }
            flag = 1;
            printf("%d", i);
            // good_nodes[i] = 1;
        }
    }

    // 打印所有好节点的编号
    // int flag = 0;
    // for (int i = 1; i <= N; i++)
    // {
    //     if (good_nodes[i] == 1)
    //     {
    //         if (flag)
    //         {
    //             printf("\n");
    //         }
    //         flag = 1;
    //         printf("%d", i);
    //     }
    // }

    return 0;
}

/*
// 树
typedef struct TreeNode
{
    int color;
    int *children;
    int num_children;
} TreeNode;

// 如果一个节点 x 到节点 1 的最短路径中，不包含和 x 相同颜色的节点（不包括 x 本身），那么我们称 x 是好节点。
void dfs(TreeNode *nodes, int node, int color, int *good_nodes)
{
    // 检查当前节点是否是好节点
    if (nodes[node].color < color)
    {
        good_nodes[node] = 1;
    }

    // 遍历当前节点的子节点
    for (int i = 0; i < nodes[node].num_children; i++)
    {
        int child = nodes[node].children[i];

        // 递归调用DFS函数
        dfs(nodes, child, color, good_nodes);
    }
}

int main(int argc, char const *argv[])
{
    // 给定一个 N 个节点的树。第 i 条边连接了节点 A_i 和 B_i。节点 i 被涂上颜色 C_i（这个问题中，颜色使用整数表示）。
    // 找到所有好节点。

    int N; // 节点数
    scanf("%d", &N);

    // 创建所有节点
    TreeNode *nodes = (TreeNode *)malloc(sizeof(TreeNode) * (N + 1));
    // 读入节点颜色
    for (int i = 1; i <= N; i++)
    {
        // 在创建节点时，为子节点数组分配内存
        nodes[i].children = (int *)malloc(sizeof(int) * (N + 1));
        nodes[i].num_children = 0;
        scanf("%d", &nodes[i].color);
    }

    // 读入节点关系
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        // 将节点 b 添加到节点 a 的子节点数组中
        nodes[a].children[nodes[a].num_children] = b;
        nodes[a].num_children++;
    }

    // 创建一个数组来记录好节点
    int *good_nodes = (int *)malloc(sizeof(int) * (N + 1));

    // 初始化所有节点为非好节点
    memset(good_nodes, 0, sizeof(int) * (N + 1));

    // 调用DFS函数
    dfs(nodes, 1, nodes[1].color, good_nodes);

    // 打印所有好节点的编号
    for (int i = 1; i <= N; i++)
    {
        if (good_nodes[i] == 1)
        {
            printf("%d ", i);
        }
    }

    // 释放内存
    // free(nodes);
    // free(good_nodes);

    return 0;
}
*/