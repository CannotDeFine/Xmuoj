/*
 * @Author: cdf
 * @Date: 2025-03-07 21:55:39
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 21:58:41
 * @Description: 最受欢迎的颜色
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    int ans = 0, remtime = 0;
    while (cin >> n)
    {
        if (remtime == 0)
        {
            ans = n;
            remtime ++;
        }
        else if (remtime != 0 && ans != n)
        {
            remtime --;
        }
        else
        {
            remtime ++;
        }
    }

    cout << ans << endl;

    return 0;
 }