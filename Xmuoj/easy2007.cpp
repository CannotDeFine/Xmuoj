/*
 * @Author: cdf
 * @Date: 2024-11-09 14:58:50
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-09 15:04:42
 * @Description: xmuoj_平方和和立方和
 */


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    
    while (cin >> m >> n) {
        // 保证m是区间的最小值，n是区间的最大值
        if (m > n) {
            swap(m, n);
        }

        int evenSquareSum = 0; // 偶数的平方和
        int oddCubeSum = 0;    // 奇数的立方和

        // 遍历从m到n的所有整数
        for (int i = m; i <= n; ++i) {
            if (i % 2 == 0) {
                evenSquareSum += i * i;   // 偶数的平方
            } else {
                oddCubeSum += i * i * i;  // 奇数的立方
            }
        }

        cout << evenSquareSum << " " << oddCubeSum << endl;
    }
    
    return 0;
}
