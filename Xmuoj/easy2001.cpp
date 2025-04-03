/*
 * @Author: cdf
 * @Date: 2024-11-09 14:17:05
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 19:56:28
 * @Description: xmuoj_计算两点间的距离
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1, y1, x2, y2;

    // 使用循环不断读取每组数据直到文件结尾
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        // 计算两点间距离
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        // 输出结果，保留两位小数
        cout << fixed << setprecision(2) << distance << endl;
    }

    return 0;
}