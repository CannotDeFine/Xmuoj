/*
 * @Author: cdf
 * @Date: 2025-01-11 12:11:27
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-11 12:15:07
 * @Description: 矩阵转置
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[j][i] << ' ';
        }
        cout << endl;
    }

    return 0;
}