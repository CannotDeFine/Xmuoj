/*
 * @Author: cdf
 * @Date: 2024-11-08 15:03:03
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 15:07:39
 * @Description: xmuoj_与指定数字相同的数字的个数
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int k;
    cin >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) if (nums[i] == k) ans++;

    cout << ans << endl;

    return 0;
}