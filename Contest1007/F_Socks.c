#include <stdio.h>
#include <stdlib.h>

// 实现一个简单的HashSet
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

typedef struct HashSet
{
    Node **head;
    int capacity; // Node数组的长度
} HashSet;

// 创建一个HashSet
HashSet *createHashSet(int capacity)
{
    HashSet *hashSet = (HashSet *)malloc(sizeof(HashSet));
    hashSet->head = (Node **)malloc(sizeof(Node *) * capacity);
    // 初始化
    for (int i = 0; i < capacity; i++)
    {
        hashSet->head[i] = NULL;
    }
    hashSet->capacity = capacity;
    return hashSet;
}

// 添加一个元素
void add(HashSet *hashSet, int key)
{
    int index = key % hashSet->capacity;
    // TODO判断是否已经存在
    if (hashSet->head[index] == NULL)
    {
        hashSet->head[index] = (Node *)malloc(sizeof(Node));
        hashSet->head[index]->key = key;
        hashSet->head[index]->next = NULL;
    }
    else
    {
        Node *node = hashSet->head[index];
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->next = node;
        hashSet->head[index] = newNode;
    }
}

// 判断一个元素是否存在
int contains(HashSet *hashSet, int key)
{
    int index = key % hashSet->capacity;
    Node *node = hashSet->head[index];
    while (node != NULL)
    {
        if (node->key == key)
        {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// 删除一个元素
void pop(HashSet *hashSet, int key)
{
    int index = key % hashSet->capacity;
    Node *node = hashSet->head[index];
    Node *prev = NULL;
    while (node != NULL)
    {
        if (node->key == key) // 找到了
        {
            if (prev == NULL) // 删除的是头结点
            {
                hashSet->head[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    int N = 0; // 袜子只数
    scanf("%d", &N);

    int *socks = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &socks[i]);
    }

    HashSet *hashSet = createHashSet(N);
    // 袜子双数
    int socks_double = 0;
    for (int i = 0; i < N; i++)
    {
        if (contains(hashSet, socks[i]))
        {
            pop(hashSet, socks[i]);
            socks_double++;
        }
        else
        {
            add(hashSet, socks[i]);
        }
    }

    // 输出
    printf("%d", socks_double);

    return 0;
}

/*
int main(int argc, char const *argv[])
{
    int N = 0; // 袜子只数
    scanf("%d", &N);

    int *socks = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &socks[i]);
    }

    short socks_count[1000000000] = {0}; // 袜子计数
    // 袜子双数
    int socks_double = 0;
    for (int i = 0; i < N; i++)
    {
        if (socks_count[socks[i]])
        {
            socks_count[socks[i]] = 0;
            socks_double++;
        }
        else
        {
            socks_count[socks[i]] = 1;
        }
    }

    // 输出
    printf("%d", socks_double);

    return 0;
}
*/