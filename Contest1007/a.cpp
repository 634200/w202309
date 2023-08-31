#include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <stack>
using namespace std;

// const int N = 100010;

// int h[N];
int n, k;

int main()
{

    cin >> n >> k;
    int flag = 0;
    int *h = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++)
    {

        if (h[i] - h[i - 1] <= k)
        {
            cout << h[i];
            flag = 1;
            break;
        }
    }

    if (!flag)
        cout << -1;
    return 0;
}
/**************************************************************
    Problem: 1062
    User: 2020118052 [范佳辰]
    Language: C++
    Result: 答案错误
****************************************************************/