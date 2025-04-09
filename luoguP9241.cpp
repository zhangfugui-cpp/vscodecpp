#include <iostream>
using namespace std;
const int N = 15;
int n;
struct
{
    int t; // 到达时刻
    int d; // 盘旋时间
    int l; // 降落时间
} plane[N];
bool vis[N];
bool res;

void dfs(int cnt, int time)
{
    if (cnt == n)
    {
        res = true;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && plane[i].t + plane[i].d >= time)
        { // 这架飞机可以降落
            vis[i] = true;
            dfs(cnt + 1, max(time, plane[i].t) + plane[i].l);
            vis[i] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> plane[i].t >> plane[i].d >> plane[i].l;
        }
        res = false;
        dfs(0, 0);
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}