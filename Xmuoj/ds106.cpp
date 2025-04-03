/*
 * @Author: cdf
 * @Date: 2025-02-16 13:51:10
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-16 14:04:13
 * @Description: 两个有序链表的交集
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> l1;
    vector<int> l2;

    int num;
    cin >> num;
    while (num != -1)
    {
        l1.push_back(num);
        cin >> num;
    }
    l1.push_back(-1);

    cin >> num;
    while (num != -1)
    {
        l2.push_back(num);
        cin >> num;
    }
    l2.push_back(-1);

    int i = 0, j = 0;
    vector<int> ans;
    while (l1[i] != -1 && l2[j] != -1)
    {
        if (l1[i] == l2[j]) 
        {
            ans.push_back(l1[i]);
            i++;
            j++;
        }
        else if (l1[i] < l2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    for (int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}