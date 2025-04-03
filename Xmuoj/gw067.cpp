/*
 * @Author: cdf
 * @Date: 2025-01-01 17:08:51
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-02 17:29:03
 * @Description: 鸡兔同笼
 */

#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    if (num % 2 == 1)
        cout << "0 0" << endl;
    else
    {
        if (num % 4 == 0)
            cout << num / 4 << " " << num / 2 << endl;
        else
            cout << num / 4 + 1 << " " << num / 2 << endl;
    }

    return 0;
}