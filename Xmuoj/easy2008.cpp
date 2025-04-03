/*
 * @Author: cdf
 * @Date: 2024-11-09 23:22:02
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 23:22:06
 * @Description: xmuoj_数值统计
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        int negativeCount = 0, zeroCount = 0, positiveCount = 0;
        double num;
        
        // 读取 n 个数并统计负数、零和正数的个数
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (num < 0) {
                negativeCount++;
            } else if (num == 0) {
                zeroCount++;
            } else {
                positiveCount++;
            }
        }
        
        // 输出统计结果
        cout << negativeCount << " " << zeroCount << " " << positiveCount << endl;
    }
    
    return 0;
}
