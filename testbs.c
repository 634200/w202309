#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // 如果中间元素等于目标元素，则返回索引
        if (arr[mid] == target)
        {
            return mid;
        }

        // 如果中间元素大于目标元素，则在左半部分继续查找
        if (arr[mid] > target)
        {
            high = mid - 1;
        }

        // 如果中间元素小于目标元素，则在右半部分继续查找
        else
        {
            low = mid + 1;
        }
    }

    // 如果找不到目标元素，则返回-1
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
    {
        printf("目标元素不存在\n");
    }
    else
    {
        printf("目标元素在索引 %d 处\n", result);
    }

    return 0;
}