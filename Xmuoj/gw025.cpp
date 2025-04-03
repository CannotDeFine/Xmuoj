/*
 * @Author: cdf
 * @Date: 2025-01-08 20:42:10
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 20:57:27
 * @Description: 求特殊自然数
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i = 10;

    while (1)
    {

        string temp9, temp7;
        int temp = i;

        while (temp)
        {
            temp9 += (temp % 9) + '0';
            temp = temp / 9;
        }

        temp = i;
        while (temp)
        {
            temp7 += (temp % 7) + '0';
            temp = temp / 7;
        }

        reverse(temp7.begin(), temp7.end());

        if (temp7.size() == 3 && temp9.size() && temp7 == temp9)
        {
            reverse(temp9.begin(), temp9.end()); // 因为数码生成时是反向排序的
            cout << i << endl;
            cout << temp7 << endl;
            cout << temp9;
            break;
        }

        i++;
    }

    return 0;
}