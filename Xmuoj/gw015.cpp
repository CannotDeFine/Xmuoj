/*
 * @Author: cdf
 * @Date: 2024-10-31 23:40:47
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-07 20:09:02
 * @Description: xumoj_苹果和虫子
 */
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, x, y;

    cin >> n >> x >> y;
    double res = (y * 1.0) / (x * 1.0);
    cout << n - ceil(res) << endl;

    return 0;
}