/*
 * @Author: cdf
 * @Date: 2025-01-09 16:03:54
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-09 16:17:39
 * @Description: 集合试炼之求差集
 */

// 哈希表的应用，map中元素有序，unordered_map元素没有顺序

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        map<int, int> hasha;
        map<int, int> hashb;

        int num = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            hasha[num]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            hashb[num]++;
        }

        bool flag = true;
        for (auto elem : hasha)
        {
            for (int j = 0; j < elem.second - hashb[elem.first]; j++)
            {
                cout << elem.first << ' ';
                flag = false;
            }
        }

        if (flag)
            cout << "NULL" << ' ';
        cout << endl;
    }

    return 0;
}