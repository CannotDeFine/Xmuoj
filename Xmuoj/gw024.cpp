/*
 * @Author: cdf
 * @Date: 2024-11-08 14:48:03
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 14:53:01
 * @Description: xmuoj_数字反转
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int tempn = abs(n), ans = 0;
    while(tempn)
    {   
        ans = (ans * 10) + (tempn % 10);
        tempn = tempn / 10;
    }
    if (n < 0) ans = (-1) * ans;
    
    cout << ans << endl;

    return 0;
}