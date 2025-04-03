/*
 * @Author: cdf
 * @Date: 2024-11-09 14:06:14
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 14:11:03
 * @Description: xmuoj_密码翻译
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            if(str[i] == 'z') str[i] = 'a';
            else if (str[i] == 'Z') str[i] = 'A';
            else str[i] += 1;
        }
    }

    cout << str << endl;

    return 0;
}