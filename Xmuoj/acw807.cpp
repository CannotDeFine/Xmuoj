/*
 * @Author: cdf
 * @Date: 2025-03-12 12:23:01
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 12:28:44
 * @Description: 区间求和
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i == 0) prefix[i] = nums[i];
        else prefix[i] = prefix[i - 1] + nums[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l] + nums[l] << endl; 
    }

    return 0;
 }
