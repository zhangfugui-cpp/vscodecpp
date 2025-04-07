#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int a2, a3, a4, b4, b6;
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        int res = 0;
        int sum = 2 * a2 + 3 * a3 + 4 * a4; // 人数总数;
        if (b6 != 0)
        { // 先处理六人桌数量
            if (b6 * 6 >= sum)
            {
                cout << sum << endl;
                continue;
            }
            else
            {
                int bigcnt = sum / 6;
                if (bigcnt >= b6)
                    bigcnt = b6;
                res += bigcnt * 6;
                sum -= res;
            }
        }
        if (b4 != 0)
        {
            if (b4 * 4 >= sum)
            {
                cout << 2 * a2 + 3 * a3 + 4 * a4 << endl;
                continue;
            }
            else
            {
                int smallcnt = sum / 4;
                if (smallcnt >= b4)
                    smallcnt = b4;
                res += smallcnt * 4;
            }
        }
        cout << res;
    }
    // 请在此输入您的代码
    return 0;
}