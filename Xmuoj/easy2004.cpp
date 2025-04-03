/*
 * @Author: cdf
 * @Date: 2024-11-09 19:35:12
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 19:56:45
 * @Description: xmuoj_成绩换算
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int score;
    char convert[11] = {'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A'};
    while (cin >> score)
    {
        if (score > 100 || score < 0)
            cout << "Score is error!" << endl;
        else
            cout << convert[score / 10] << endl;
    }

    return 0;
}