/*
 * @Author: cdf
 * @Date: 2024-11-09 14:41:04
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 14:44:23
 * @Description: xmuoj_计算球的体积
 */

#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415927;

int main ()
{
    double r;

    while (cin >> r) {
        double ans = (4.0 / 3.0) * PI * pow(r, 3);

        cout << fixed << setprecision(3);
        cout << ans << endl;         
    }

    return 0;
}