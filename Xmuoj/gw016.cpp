/*
 * @Author: cdf
 * @Date: 2024-11-07 19:44:02
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-07 20:09:18
 * @Description: xmuoj_简单计算器
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 0;
    char op;

    cin >> n >> m >> op;
    
    switch (op)
    {
    case '+':
        ans = n + m;
        break;
    case '-':
        ans = n - m;
        break;
    case '*':
        ans = n * m;
        break;
    case '/':
        if (m == 0) {
            cout << "Divided by zero!" << endl;
            return 0;
        }
        ans = n / m;
    default:
        cout << "Invalid operator!" << endl;
        return 0;
        break;
    }

    cout << ans << endl;
    
    return 0;
}