/*
 * @Author: cdf
 * @Date: 2025-02-20 21:59:51
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-20 22:10:07
 * @Description: 稀疏矩阵加法
 */
 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    int row, col;
    cin >> row >> col;

    int a[row + 1][col + 1];
    memset(a, 0, sizeof(int) * (row + 1) * (col + 1));
    int r, c, val;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> r >> c >> val;
        a[r][c] = val;
    }

    int row1, col1;
    cin >> row1 >> col1;
    int b[row1 + 1][col1 + 1];
    memset(b, 0, sizeof(int) * (row1 + 1) * (col1 + 1));
    cin >> n;
    while (n--)
    {
        cin >> r >> c >> val;
        b[r][c] = val;
    }

    if (row != row1 || col1 != col)
    {
        cout << "ERROR" << endl;
        return 0;
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            a[i][j] = a[i][j] + b[i][j];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
 
    return 0;
 }