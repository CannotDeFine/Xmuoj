/*
 * @Author: cdf
 * @Date: 2024-11-08 19:30:08
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 20:14:37
 * @Description: xmuoj_第i位替换
 */

#include <bits/stdc++.h>
using namespace std;

int bitManipulation1(int n, int m, int i)
{
    return (n & ~(1 << i)) | ((m >> i & 1) << i);
    // 先将 n 的第 i 位置于 0
    // 然后取 m 的第 i 位 置位置
}

int main()
{

    int n, m, i, t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m >> i;
        cout << bitManipulation1(n, m, i) << endl;
    }
    return 0;
}
