/*
 * @Author: cdf
 * @Date: 2025-01-12 23:20:51
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-12 23:41:10
 * @Description: Memcpy之二
 */

#include <iostream>
using namespace std;
void Memcpy(void *src, void *dest, int size)
{
    unsigned char *sta = (unsigned char *)src;
    unsigned char *end = (unsigned char *)dest;

    // 判断内存是否重叠
    if (sta < end && sta + size > end)
    {
        // 如果内存区域重叠，从后往前拷贝
        sta = (unsigned char *)src + size - 1;
        end = (unsigned char *)dest + size - 1;
        for (int i = 0; i < size; ++i)
        {
            *end = *sta;
            end--;
            sta--;
        }
    }
    else
    {
        // 如果内存区域不重叠，从前往后拷贝
        for (int i = 0; i < size; ++i)
        {
            *end = *sta;
            end++;
            sta++;
        }
    }
}

void Print(int *p, int size)
{
    for (int i = 0; i < size; ++i)
        cout << p[i] << ",";
    cout << endl;
}

int main()
{
    int a[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int b[10] = {0};
    Memcpy(a, b, sizeof(a));
    Print(b, n);

    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Memcpy(c, c + 5, 5 * sizeof(int)); // 将c的前一半拷贝到后一半
    Print(c, 10);

    char s[10] = "123456789";
    Memcpy(s + 2, s + 4, 5); // 将s[2]开始的5个字符拷贝到s[4]开始的地方
    cout << s << endl;

    char s1[10] = "123456789";
    Memcpy(s1 + 5, s1 + 1, 4); // 将s1[5]开始的4个字符拷贝到s1[1]开始的地方
    cout << s1 << endl;

    return 0;
}