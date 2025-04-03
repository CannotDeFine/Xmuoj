/*
 * @Author: cdf
 * @Date: 2025-03-10 15:48:37
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 16:30:15
 * @Description: 最长连续不重复子序列
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = 0;
    vector<int> s(n, 0);
    for (int i = 0, j = 0; i < n; i++)
    {
        s[nums[i]]++;

        while (s[nums[i]] > 1)
        {
            s[nums[j]]--;
            j++;
        }

        ans = max (ans, i - j + 1);
    }

    cout << ans << endl;

    return 0;
 }
