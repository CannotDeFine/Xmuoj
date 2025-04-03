/*
 * @Author: cdf
 * @Date: 2025-01-09 19:20:27
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-09 20:04:40
 * @Description: 校门外的树
 */

// 时间复杂度O(n)，说实话感觉不如直接搜索

#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int main()
{

    int len, m;
    cin >> len >> m;

    int l[N];
    for (int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;

        l[left] = 1;
        l[right] = 2;
    }

    int i = 0, ans = len + 1;
    while (i <= len)
    {
        if (l[i] == 0)
            i++;
        else if (l[i] == 1)
        {
            int j = 1;
            int count = 1;
            while (i + j <= len)
            {
                if (l[i + j] == 2)
                {
                    count--;
                    if (count == 0)
                        break;
                }
                else if (l[i + j] == 1)
                    count++;
                j++;
            }

            ans -= j + 1;
            i += j + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
