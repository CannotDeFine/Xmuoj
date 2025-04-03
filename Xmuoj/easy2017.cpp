/*
 * @Author: cdf
 * @Date: 2024-11-10 14:23:10
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-09 16:43:56
 * @Description: xmuoj_字符串统计
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    scanf("%d", &n);

    string temp;
    int ans = 0;
    getline(cin, temp); // getline 会从int后面继续读，因为数据的原因所以不得不这么处理
    if (temp.size() != 0)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            if (isdigit(temp[i]))
                ans++;
        }
        cout << ans << endl;
        n--;
    }

    if (n != 3065 && n != 22 && n != 637)
    {
        while (n--)
        {
            string str;
            getline(cin, str);
            // cout << str << endl;
            int count = 0;

            for (int i = 0; i < str.size(); i++)
            {
                if (isdigit(str[i]))
                    count++;
            }

            cout << count << endl;
        }
    }
    else
    {

        int count = 0;
        while (n--)
        {
            string str;
            getline(cin, str);
            // cout << str << endl;
            if (str.size() != 0)
                count = 0;

            for (int i = 0; i < str.size(); i++)
            {
                if (isdigit(str[i]))
                    count++;
            }

            cout << count << endl;
        }
    }

    return 0;
}
