/*
 * @Author: cdf
 * @Date: 2024-11-10 09:54:54
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-10 09:55:01
 * @Description: xmuoj_求数列的和
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        double sum = 0.0;
        double term = n;
        
        // 计算前m项的和
        for (int i = 0; i < m; ++i) {
            sum += term;
            term = sqrt(term);  // 下一项为当前项的平方根
        }
        
        // 输出结果，保留两位小数
        cout << fixed << setprecision(2) << sum << endl;
    }
    
    return 0;
}
