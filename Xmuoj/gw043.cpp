/*
 * @Author: cdf
 * @Date: 2024-11-09 00:01:23
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 00:10:07
 * @Description: xmuoj_最长最短单词 learn stringstream
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;
    int min_len = INT_MAX, max_len = 0;
    string ans_min, ans_max;
    while (ss >> word) {
        if (word.size() < min_len) { ans_min = word; min_len = word.size(); }
        if (word.size() > max_len) { ans_max = word; max_len = word.size(); }
    }

    cout << ans_max << endl << ans_min << endl;

    return 0;
}