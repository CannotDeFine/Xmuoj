/*
 * @Author: cdf
 * @Date: 2024-11-08 23:35:37
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 23:43:26
 * @Description: xmuoj_找第一个只出现一次的字符
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int ch_num[26] = {0};
    queue<char> rem;
    for (int i = 0; i < str.size(); i++) {
        if (ch_num[str[i] - 'a'] == 0) rem.push(str[i]);
        ch_num[str[i] - 'a']++;
    }

    char ch;
    while (!rem.empty()) {
        ch = rem.front();
        rem.pop();

        if (ch_num[ch - 'a'] == 1) {
            cout << ch << endl;
            break;
        }
    }

    return 0;
}