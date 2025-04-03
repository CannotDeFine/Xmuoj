/*
 * @Author: cdf
 * @Date: 2025-03-10 11:13:37
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 11:18:00
 * @Description: Trie字符串统计
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    unordered_map<string, int> myhash;
    while (n--)
    {
        char ch;
        string str;
        cin >> ch >> str;

        if (ch == 'I') myhash[str]++;
        else 
        {
            if (myhash.count(str)) cout << myhash[str] << endl;
            else cout << '0' << endl;
        }
    }

    return 0;
 }
