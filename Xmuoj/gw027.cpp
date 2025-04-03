/*
 * @Author: cdf
 * @Date: 2024-11-08 14:55:59
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 15:00:36
 * @Description: xmuoj_数字统计
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int i = l; i <= r; i++) {
        int temp = i, count = 0;
        while(temp) {
            if (temp % 10 == 2) count++;
            temp = temp / 10;
        }

        ans += count;
    }

    cout << ans << endl;
    
    return 0;
}