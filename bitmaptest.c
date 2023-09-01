#include <stdio.h>
#include <stdlib.h>

// 实现一个位图
typedef struct
{
    int length;
    unsigned int *data; // 32bit
} Bitmap;

Bitmap *bitmap_create(int length)
{
    Bitmap *bitmap = (Bitmap *)malloc(sizeof(Bitmap));
    bitmap->length = length;

    int dataLength = (length + 31) / 32; // 向上取整
    bitmap->data = (unsigned int *)malloc(sizeof(unsigned int) * dataLength);
    return bitmap;
}

void bitmap_set(Bitmap *bitmap, int index)
{
    if (index < 0 || index >= bitmap->length)
    {
        return;
    }

    int data_index = index / 32;
    int bit_index = index % 32;
    bitmap->data[data_index] |= (1 << bit_index);
}

void bitmap_clear(Bitmap *bitmap, int index)
{
    if (index < 0 || index >= bitmap->length)
    {
        return;
    }

    int data_index = index / 32;
    int bit_index = index % 32;
    bitmap->data[data_index] &= ~(1 << bit_index);
}

int bitmap_get(Bitmap *bitmap, int index)
{
    if (index < 0 || index >= bitmap->length)
    {
        return 0;
    }

    int data_index = index / 32;
    int bit_index = index % 32;
    return (bitmap->data[data_index] & (1 << bit_index)) != 0;
}

void bitmap_destroy(Bitmap *bitmap)
{
    if (bitmap == NULL)
    {
        return;
    }

    if (bitmap->data != NULL)
    {
        free(bitmap->data);
    }

    free(bitmap);
}

int main()
{
    Bitmap *bitmap = bitmap_create(100);
    bitmap_set(bitmap, 0);
    bitmap_set(bitmap, 55);

    printf("%d\n", bitmap_get(bitmap, 66));
    printf("%d\n", bitmap_get(bitmap, 55));
    printf("%d\n", bitmap_get(bitmap, 0));

    bitmap_clear(bitmap, 55);
    printf("%d\n", bitmap_get(bitmap, 55));

    bitmap_destroy(bitmap);

    return 0;
}
