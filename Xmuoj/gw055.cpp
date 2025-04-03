/*
 * @Author: cdf
 * @Date: 2024-11-11 23:30:55
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-27 20:41:38
 * @Description: xmuoj_分数线的划定
 */

#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second || (a.first < b.first && a.second == b.second);
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> mem(n);
    for (int i = 0; i < n; i++)
        cin >> mem[i].first >> mem[i].second;

    sort(mem.begin(), mem.end(), cmp);

    int total = floor(m * 1.5);
    int scoreline = mem[total].second;
    for (int i = total; i < n && mem[i].second == scoreline; i++)
    {
        total++;
    }

    cout << scoreline << ' ' << total << endl;
    for (int i = 0; i < total; i++)
        cout << mem[i].first << ' ' << mem[i].second << endl;

    return 0;
}