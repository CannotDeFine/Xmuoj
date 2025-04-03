/*
 * @Author: cdf
 * @Date: 2025-01-09 19:08:36
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-09 19:14:12
 * @Description: 雇佣兵
 */
#include<bits/stdc++.h>
using namespace std;

int main() {

    int m, n, x;
    cin >> m >> n >> x;

    while (m >= n && n * x >= m) {
    
        x -= ceil(m * 1.0 / n);     // 补充体力
        n += m / n;                 // 战斗力增加
    
    }

    cout << n << endl;

    return 0;
}