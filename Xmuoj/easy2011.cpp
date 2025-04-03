/*
 * @Author: cdf
 * @Date: 2024-11-09 23:14:02
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 23:19:30
 * @Description: xmuoj_多项式求值
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        double ans = 0;
        for (int i = 1; i <= num; i++) {
            ans += pow(-1, i-1) * (1 / (i * 1.0));
        }

        cout << fixed << setprecision(2) << ans << endl;
        
    }

    return 0;
}