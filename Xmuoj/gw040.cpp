/*
 * @Author: cdf
 * @Date: 2024-11-08 23:11:59
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 23:32:09
 * @Description: xmuoj_统计数字字符的个数
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int ans = 0;
    for (int i = 0; i <= str.size(); i++) {
        if (isdigit(str[i])) ans++;
    }

    cout << ans << endl;
    return 0;
}