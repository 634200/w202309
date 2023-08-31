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
    hashSet->capacity = capacity;
    return hashSet;
}

// 添加一个元素
void add(HashSet *hashSet, int key)
{
    int index = key % hashSet->capacity;
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
    HashSet *hashSet = createHashSet(31);
    add(hashSet, 1);
    add(hashSet, 7);
    add(hashSet, 111);

    printf("%d\n", contains(hashSet, 8));
    return 0;
}
