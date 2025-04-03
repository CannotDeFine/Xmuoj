/*
 * @Author: cdf
 * @Date: 2025-01-12 23:04:21
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-12 23:12:34
 * @Description: 求最大公因数_辗转相除
 */
#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    while (a % b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    cout << b;

    return 0;
}