/*
 * @Author: cdf
 * @Date: 2025-03-10 15:41:38
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 15:45:37
 * @Description: 交换操作
 */

#include <iostream>

using namespace std;

void swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    // 实现引用的交换
}

void swap2(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // 实现指针的交换
}

void swap3(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // 实现指针引用的交换
}

int main()
{

    int x1, y1;

    cin >> x1 >> y1;

    swap1(x1, y1);

    cout << x1 << " " << y1 << endl;

    int x2, y2;

    cin >> x2 >> y2;

    swap2(&x2, &y2);

    cout << x2 << " " << y2 << endl;

    int a, b;

    cin >> a >> b;

    int *pa = &a;

    int *pb = &b;

    swap3(pa, pb);

    cout << a << " " << b << endl;

    return 0;
}
