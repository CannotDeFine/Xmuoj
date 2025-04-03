/*
 * @Author: cdf
 * @Date: 2024-11-08 09:51:29
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-01 17:18:52
 * @Description: xmuoj_鸡尾酒疗法
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x1, y1;
    cin >> x1 >> y1;
    double rate1 = y1 / (x1 * 1.0);
    n--;

    int x, y;
    while (n--) {
        cin >> x >> y;
        double rate2 = y / (x * 1.0);

        if (rate2 - rate1 > 0.05) cout << "better" << endl;
        else if (rate1 - rate2 > 0.05) cout << "worse" << endl;
        else cout << "same" << endl;
    }

    return 0;

}