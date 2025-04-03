/*
 * @Author: cdf
 * @Date: 2025-03-10 09:30:01
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 10:09:31
 * @Description: 前缀和试炼之k倍区间
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n, num;
    cin >> n >> num;

    vector<int> pre(n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i == 0) pre[i] = nums[i];
        else pre[i] = nums[i] + pre[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        if (pre[i] % num == 0) ans ++;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((pre[j] - pre[i]) % num == 0) ans ++;
            //cout << pre[j] << '-' << pre[i] << '=' << pre[j] - pre[i] << endl;
        }
    }
    if (pre[n - 1] % num == 0) ans++;

    cout << ans << endl;

    return 0;

 }
