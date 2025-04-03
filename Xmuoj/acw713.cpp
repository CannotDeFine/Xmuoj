/*
 * @Author: cdf
 * @Date: 2025-03-12 12:04:27
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 12:05:33
 * @Description: 区间2
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    int in = 0;
    int out = 0;
    while (n--)
    {
        int num;
        cin >> num;

        if (num >= 10 && num <= 20) in++;
        else out ++;
    }

    cout << in << ' ' << "in" << endl;
    cout << out << ' ' << "out" << endl;

    return 0;
 }
