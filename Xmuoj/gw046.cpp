/*
 * @Author: cdf
 * @Date: 2025-01-10 10:41:22
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-11 13:04:09
 * @Description: 输出Program
 */

#include <iostream>
using namespace std;
void Print(const char *p1, const char *p2)
{
    for (; p1 != p2; p1++)
        cout << *p1;
    
}

int main()
{
    const char *s = "ProgrammingSkill";
    Print(s, s + 7);
    cout << endl;
    Print(s, s + 3);
    cout << endl;

    return 0;
}