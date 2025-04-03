/*
 * @Author: cdf
 * @Date: 2025-02-15 15:54:57
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-15 16:16:13
 * @Description: 机器翻译
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    int *num = (int *)malloc(sizeof(int) * m + 1);
    //int *ne = (int *)malloc(sizeof(int) * m + 1);
    num[0] = 1;
    //ne[0] = 1;
    int idx = 1, ans = 0;

    while (n--)
    {
        int word;
        cin >> word;

        int mark = 0;
        for (int i = 1; i <= m; i++)
        {
            if (num[i] == word)
            {
                mark = i;
                break;
            }
        }

        if (mark == 0)
        {
            num[idx] = word;
            num[0] ++;
            idx = idx % m + 1;
            ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}