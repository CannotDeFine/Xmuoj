/*
 * @Author: cdf
 * @Date: 2024-11-09 23:11:26
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 23:11:38
 * @Description: xmuoj_求奇数的积
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        int product = 1;
        int num;
        
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (num % 2 != 0) { // 检查是否为奇数
                product *= num;
            }
        }
        
        cout << product << endl;
    }
    
    return 0;
}
