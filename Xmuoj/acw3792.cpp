/*
 * @Author: cdf
 * @Date: 2025-03-12 16:43:37
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 17:18:06
 * @Description: 筛质数之质数问题
 */

 // 先利用埃氏筛计算出可能的所有质数时间复杂度是O(n)

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int t;
    cin >> t;

    vector<int> to_rem;
    vector<int> is_prime(1010, 0);
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime[i] == 0) to_rem.push_back(i);
        for (int k = 2; k * i <= 1000; k++)
        {
            is_prime[k * i] = 1;
        }
    }

    vector<int> prefix;
    for (int i = 1; i < to_rem.size(); i++)
    {
        prefix.push_back(to_rem[i - 1] + to_rem[i] + 1);
    }

    vector<int> is_sum(to_rem.size(), 0);
    for (int i = 0; i < to_rem.size(); i++)
    {
        vector<int>::iterator it = find(prefix.begin(), prefix.end(), to_rem[i]);
        if (it != prefix.end()) is_sum[i] = 1;
    }

    while (t--)
    {
        int n ,k;
        cin >> n >> k;

        int ans = 0;
        for (int i = 0; i < to_rem.size() && to_rem[i] < n; i++)
        {
            if (is_sum[i] == 1) ans++;
        }

        if (ans >= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
 }
