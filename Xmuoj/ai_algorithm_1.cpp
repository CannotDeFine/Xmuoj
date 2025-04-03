/*
 * @Author: cdf
 * @Date: 2025-03-07 20:21:14
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 20:28:16
 * @Description: 魔法符文 -- 分治和递归
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    int ans = 0, remtime = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (remtime == 0)
        {
            remtime++;
            ans = temp;
        }
        else if (remtime != 0 && ans != temp)
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