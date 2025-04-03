/*
 * @Author: cdf
 * @Date: 2025-03-07 13:56:59
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-07 14:20:05
 * @Description: 三元组顺序表表示的稀疏矩阵转置运算
 */

 #include <bits/stdc++.h>
 using namespace std;

 struct node
 {
    int r;
    int c;
    int val;
 };

 bool cmp(node a, node b)
 {
    return (a.r < b.r) || (a.r == b.r && a.c < b.c);
 }

 int main()
 {
    int r, c;
    cin >> r >> c;

    int n;
    cin >> n;
    vector<node> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i].c >> matrix[i].r >> matrix[i].val;
    }

    sort (matrix.begin(), matrix.end(), cmp);

    //cout << n << endl; // xmu oj fault
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i].val == 0) continue; 
        cout << matrix[i].r << ' ' << matrix[i].c << ' ' << matrix[i].val << endl;
    }

    return 0;
 }
