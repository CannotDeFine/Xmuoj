/*
 * @Author: cdf
 * @Date: 2024-11-08 14:40:58
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 14:46:09
 * @Description: xmuoj_正常血压
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int temp = 0;
    while (n--) {
        int n, m;
        cin >> n >> m;

        if (n >= 90 && n <= 140 && m >= 60 && m <= 90) {
            temp++;
            ans = max(ans, temp);
        } 
        else temp = 0;
    }

    cout << ans << endl;

    return 0;
}