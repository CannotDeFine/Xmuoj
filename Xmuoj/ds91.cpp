/*
 * @Author: cdf
 * @Date: 2025-03-06 16:48:08
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-06 16:51:20
 * @Description: 排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<long> nums(n);
    for (int i = 0 ; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) cout << nums[i];
        else cout << nums[i] << ' ';
    }

    return 0;
 }
