/*
 * @Author: cdf
 * @Date: 2024-11-10 23:33:28
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-10 11:49:49
 * @Description: xmuoj_成绩排序
 */

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
    {
        if (a.second >= b.second)
            return true;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, string>> stu(n);
    for (int i = 0; i < n; i++)
        cin >> stu[i].second >> stu[i].first;

    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << stu[i].second << ' ' << stu[i].first << endl;
        else
            cout << stu[i].second << ' ' << stu[i].first;
    }
    return 0;
}