/*
 * @Author: cdf
 * @Date: 2025-01-13 23:04:17
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-13 23:20:11
 * @Description: mysort
 */

#include <iostream>
using namespace std;
struct A
{
    int nouse1;
    int nouse2;
    int n;
};
// 在此处补充你的代码
void mysort(void *a, int size, size_t len, int (*f)(const void *, const void *))
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // 获取两个元素的指针
            void *p1 = (char *)a + j * len;
            void *p2 = (char *)a + (j + 1) * len;

            // 使用比较函数 f 来比较两个元素
            if (f(p1, p2) > 0) {
                // 交换两个元素
                for (size_t k = 0; k < len; ++k) {
                    char temp = *((char *)p1 + k);
                    *((char *)p1 + k) = *((char *)p2 + k);
                    *((char *)p2 + k) = temp;
                }
            }
        }
    }
}

int MyCompare1(const void *e1, const void *e2)
{
    int *p1 = (int *)e1;
    int *p2 = (int *)e2;
    return *p1 - *p2;
}
int MyCompare2(const void *e1, const void *e2)
{
    int *p1 = (int *)e1;
    int *p2 = (int *)e2;
    if ((*p1 % 10) - (*p2 % 10))
        return (*p1 % 10) - (*p2 % 10);
    else
        return *p1 - *p2;
}
int MyCompare3(const void *e1, const void *e2)
{
    A *p1 = (A *)e1;
    A *p2 = (A *)e2;
    return p1->n - p2->n;
}

int a[20];
A b[20];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i].n = a[i];
        }
        mysort(a, n, sizeof(int), MyCompare1);
        for (int i = 0; i < n; ++i)
            cout << a[i] << ",";
        cout << endl;
        mysort(a, n, sizeof(int), MyCompare2);
        for (int i = 0; i < n; ++i)
            cout << a[i] << ",";
        cout << endl;
        mysort(b, n, sizeof(A), MyCompare3);
        for (int i = 0; i < n; ++i)
            cout << b[i].n << ",";
        cout << endl;
    }
    return 0;
}