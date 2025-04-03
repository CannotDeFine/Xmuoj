/*
 * @Author: cdf
 * @Date: 2024-11-07 19:48:46
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-07 20:25:47
 * @Description: xmuoj_求整数的和和均值
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    long long ans = 0;

    cin >> n;
    int count = n;

    while (n--) {
        cin >> temp;
        ans += temp;
    }
    double average = ans / (count * 1.0);
    
    printf("%ld %.5lf", ans, average);
    return 0;
}
