#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, s, res, p[N], c[N], cnt[N];
bool full[N];

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> c[i];
        cnt[i] = c[i];
        full[i] = false;
    }

    // 模拟训练过程，直到所有士兵都完成要求
    while (true)
    {
        bool all_full = true;
        for (int i = 1; i <= n; i++)
        {
            if (!full[i])
            {
                all_full = false;
                break;
            }
        }
        if (all_full)
            break; // 所有士兵都已完成

        int sum = 0; // 所有未完成士兵单独训练一轮的费用之和
        for (int i = 1; i <= n; i++)
        {
            if (!full[i])
            {
                sum += p[i];
            }
        }

        if (sum >= s)
        {             // 组团训练更划算
            res += s; // 每次组团训练固定花费 s 枚金币
            for (int i = 1; i <= n; i++)
            {
                if (!full[i])
                {
                    c[i]--; // 每位未完成训练的士兵都训练一次
                    if (c[i] == 0)
                        full[i] = true;
                }
            }
        }
        else
        { // 单独训练更划算，直接完成所有剩余训练
            for (int i = 1; i <= n; i++)
            {
                if (!full[i])
                {
                    res += p[i] * c[i];
                    c[i] = 0;
                    full[i] = true;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}