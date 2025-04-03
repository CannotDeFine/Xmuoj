/*
 * @Author: cdf
 * @Date: 2025-01-12 23:16:24
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-12 23:18:17
 * @Description: 指针练习_指向指针的指针
 */

#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    x = 10;
    y = 20;
    z = 30;

    int *a[3] = {&x, &y, &z};
    for (
        // 在此处补充你的代码
        int **p = a;
        p < a + 3; ++p)
        cout << *(*p) << endl;
    return 0;
}