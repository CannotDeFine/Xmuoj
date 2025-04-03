/*
 * @Author: cdf
 * @Date: 2025-03-12 17:22:11
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 17:23:33
 * @Description: 序列统计
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    unordered_set<int> rem;
    while (n--)
    {
        int m;
        cin >> m;

        rem.insert(m);
    }

    cout << rem.size() << endl;

    return 0;
 }
