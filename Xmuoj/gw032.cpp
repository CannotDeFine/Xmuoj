/*
 * @Author: cdf
 * @Date: 2025-01-09 20:44:13
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-10 10:13:36
 * @Description: 计算鞍点
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int num[5][5];
    map<int, int> hash;
    for (int i = 0; i < 5; i++)
    {
        int max_num = INT_MIN, l, r;
        for (int j = 0; j < 5; j++)
        {
            cin >> num[i][j];
            if (num[i][j] > max_num)
            {
                l = i;
                r = j;
                max_num = num[i][j];
            }
        }
        hash[l] = r;
    }

    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        int min_num = INT_MAX, l, r;
        for (int j = 0; j < 5; j++)
        {
            if (num[j][i] < min_num)
            {
                min_num = num[j][i];
                l = j;
                r = i;
            }
        }

        if (hash[l] == r)
        {
            cout << l + 1 << ' ' << r + 1 << ' ' << num[l][r] << endl;
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "not found" << endl;

    return 0;
}