#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5
#define INF 9999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start, int dist[MAX_VERTICES], bool visited[MAX_VERTICES])
{
    // 初始化距离数组和访问标志数组
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    // 设置起始顶点的距离为0
    dist[start] = 0;

    // 循环遍历所有顶点
    for (int count = 0; count < MAX_VERTICES - 1; count++)
    {
        int minDist = INF;
        int minIndex;

        // 找到当前距离最短的顶点
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                minIndex = i;
            }
        }

        // 标记该顶点已访问
        visited[minIndex] = true;

        // 更新其他顶点的距离
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            if (!visited[i] && graph[minIndex][i] && dist[minIndex] != INF && dist[minIndex] + graph[minIndex][i] < dist[i])
            {
                dist[i] = dist[minIndex] + graph[minIndex][i];
            }
        }
        // 打印dist
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            printf("%d ", dist[i]);
        }
        printf("\n");
    }
}

int main()
{
    // 1->2 26
    // 1->3 3
    // 1->5 6
    // 3->2 22
    // 4->2 1
    // 4->3 6
    // 5->2 15
    // 5->3 6
    // 5->4 8
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 26, 3, INF, 6},
        {INF, 0, INF, INF, INF},
        {INF, 22, 0, INF, INF},
        {INF, 1, 6, 0, INF},
        {INF, 15, 6, 8, 0}};

    int start = 0; // 起始顶点

    int dist[MAX_VERTICES];     // 最短路径长度数组
    bool visited[MAX_VERTICES]; // 访问标志数组

    dijkstra(graph, start, dist, visited);

    // 输出最短路径长度
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        printf("1->%d: %d\n", i + 1, dist[i]);
    }

    return 0;
}