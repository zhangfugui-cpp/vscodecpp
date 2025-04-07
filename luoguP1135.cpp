#include <iostream>
using namespace std;
const int N = 205;
int n, a, b, K[N];
int res = 205;   // 记录最少按键次数
bool visited[N]; // 记录楼层是否已访问

void dfs(int cur, int cnt)
{
    if (cur < 1 || cur > n || visited[cur] || cnt >= res)
    {
        return;
    }
    if (cur == b)
    {
        res = min(res, cnt);
        return;
    }
    visited[cur] = true;

    // 按下“上”按钮
    dfs(cur + K[cur], cnt + 1);
    // 按下“下”按钮
    dfs(cur - K[cur], cnt + 1);

    // 恢复访问状态
    visited[cur] = false;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> K[i];
    }
    dfs(a, 0);
    if (res == 205)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}