#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 200010;

int n;

unordered_map<string, int> mymap;
int e[N], h[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{

    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 进行拓扑排序
bool topsort(int count)
{

    int hh = 0, tt = -1;

    for (int i = 1; i <= count; i++)
    {
        if (!d[i])
        {
            q[++tt] = i;
        }
    }

    while (hh <= tt)
    {

        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {

            int j = e[i];
            d[j]--;
            if (d[j] == 0)
                q[++tt] = j;
        }
    }

    return tt == count - 1;
}

int main()
{

    cin >> n;
    string str1, str2;
    int num = 1;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n; i++)
    {

        cin >> str1 >> str2;
        if (mymap.find(str1) == mymap.end())
            mymap[str1] = num++;
        if (mymap.find(str2) == mymap.end())
            mymap[str2] = num++;

        add(mymap[str1], mymap[str2]);
        d[mymap[str2]]++; // 入度加1
    }

    if (topsort(num))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}