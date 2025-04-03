/*
 * @Author: cdf
 * @Date: 2024-11-09 14:14:20
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 14:14:23
 * @Description: xmuoj_指针练习输出"Hello"
 */

#include <iostream>
using namespace std;
int main() {
    char s[] = "Hello";  
    char *p;
    for (p = s; *p != '\0'; p++)
        cout << *p;
    return 0;
}
