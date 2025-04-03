/*
 * @Author: cdf
 * @Date: 2024-11-09 23:09:43
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 23:09:47
 * @Description: xmuoj_ASCII码排序
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char chars[3];
    
    while (cin >> chars[0] >> chars[1] >> chars[2]) {
        // 对三个字符进行排序
        sort(chars, chars + 3);
        
        // 按要求输出，字符之间用空格分隔
        cout << chars[0] << " " << chars[1] << " " << chars[2] << endl;
    }
    
    return 0;
}
