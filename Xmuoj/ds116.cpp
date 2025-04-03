/*
 * @Author: cdf
 * @Date: 2025-02-26 20:48:03
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-26 21:48:54
 * @Description: KMP字符串匹配
 */

 // 实际上是求最长公共前后缀的问题 
 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    string text;
    string pattern;

    cin >> text;
    cin >> pattern;

    int n = text.size();
    int m = pattern.size();
    if (m == 0)
    {
        return 0;
    }

    vector<int> next(m, 0);
    int i = 1, j = 0;
    // j指针的作用：当前最大前缀的长度
    while (i < m)
    {
        // 跳转到上一个可能的前缀匹配位置
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = next[j - 1];
        }
        // 如果当前位置的
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        next[i] = j;
        i++;
    }
    
    i = 0;
    j = 0;
    while (i < n)
    {
        while (j > 0 && text[i] != pattern[j])
        {
            j = next[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            cout << i - m + 1 << endl;
        }
        i++;
    }

    for (int k = 0; k < next.size(); k++)
    {
        if (k == next.size() - 1) cout << next[k];
        else cout << next[k] << ' ';
    }

    return 0;
 }