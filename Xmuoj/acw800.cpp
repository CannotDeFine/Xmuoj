/*
 * @Author: cdf
 * @Date: 2025-01-19 20:05:12
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-19 21:08:37
 * @Description: 数组元素的目标和
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, x;
    cin >> n >> m >> x;

    int num;
    vector<int> b(m);
    unordered_map<int,int> hash;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        hash[x - num] = i;    
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
        if (hash.count(b[j])) cout << hash[b[j]] << ' ' << j << endl;
    }

    return 0;
}