/*
 * @Author: cdf
 * @Date: 2024-10-31 23:21:10
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-07 10:01:52
 * @Description: gw014_判断是否在方形内
 */
#include <bits/stdc++.h>
using namespace std;

int main () 
{
    int x, y;
    cin >> x >> y;
    if (abs(x) <= 1 && abs(y) <= 1) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}