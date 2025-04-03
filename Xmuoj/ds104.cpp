/*
 * @Author: cdf
 * @Date: 2025-02-16 11:50:51
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-24 18:27:41
 * @Description: 多项式求和
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 double evaluatePolynomial(int n, double x0, const vector<double>& coefficients) {
    double result = 0.0;
    for (double coef : coefficients) {
        result = result * x0 + coef;  // Horner方法
    }
    return result;
}

int main() {
    int n;
    double x0;
    
    // 读取 n 和 x0
    cin >> n >> x0;
    
    vector<double> coefficients(n + 1);
    
    // 读取系数（从最高次到最低次）
    for (int i = 0; i <= n; i++) {
        cin >> coefficients[i];
    }
    
    // 计算多项式值
    double result = evaluatePolynomial(n, x0, coefficients);
    
    // 输出结果，保留三位小数
    cout << fixed << setprecision(3) << result << endl;
    
    return 0;
}