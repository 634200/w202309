#include <iostream>
// #include <algorithm>
#include <string>

using namespace std;

const int N = 200010;

int n, h[N] = {0};
int st[N] = {0}; // 标记这个人 是否被喊过
int main()
{

    cin >> n;
    int num = n;
    // memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if (st[i] > 0) // 被喊过
            continue;
        st[h[i]]++;
        if (st[h[i]] == 1)
            num--; // ！！！num如果被喊过多次
    }
    cout << num << endl;

    string res = "";

    for (int i = 1; i <= n; i++)
    {
        if (st[i] == 0)
            res += to_string(i) + " ";
    }
    res = res.substr(0, res.size() - 1);
    cout << res;
    return 0;
}