/*
 * @Author: cdf
 * @Date: 2025-01-13 22:55:35
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-13 23:03:37
 * @Description: 指针练习_SwapMemory
 */
#include <iostream>
using namespace std;
void SwapMemory(void *m1, void *m2, int size)
{
    // 在此处补充你的代码
    unsigned char *s1 = (unsigned char *)m1;
    unsigned char *s2 = (unsigned char *)m2;
    for (int i = 0; i < size; i++)
    {
        unsigned char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
        s1++;
        s2++;
    }
}

void PrintIntArray(int *a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ",";
    cout << endl;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {10, 20, 30, 40, 50};
    SwapMemory(a, b, 5 * sizeof(int));
    PrintIntArray(a, 5);
    PrintIntArray(b, 5);
    char s1[] = "12345";
    char s2[] = "abcde";
    SwapMemory(s1, s2, 5);
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}