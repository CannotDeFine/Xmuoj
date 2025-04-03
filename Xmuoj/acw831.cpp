/*
 * @Author: cdf
 * @Date: 2025-03-10 10:56:42
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 11:09:33
 * @Description: KMP字符串
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n, m;
    string pattern, text;
    
    cin >> n;
    cin >> pattern;

    cin >> m;
    cin >> text;

    vector<int> nextval(n, 0);
    int j = 0, i = 1;
    while (i < n)
    {
        while (j > 0 && pattern[j] != pattern[i])
        {
            j = nextval[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }

        nextval[i] = j;
        i++;
    }

    j = 0, i = 0;
    while (i < m)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = nextval[j - 1];
        }
        if (pattern[j] == text[i])
        {
            j ++;
        }
        if (j == n)
        {
            cout << i - n + 1 << ' ';
        }
        i++;
    }

    return 0;

 }
