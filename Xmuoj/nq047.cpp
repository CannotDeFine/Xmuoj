/*
 * @Author: cdf
 * @Date: 2025-02-15 14:51:13
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-15 15:09:29
 * @Description: 数组去重问题
 */

#include<bits/stdc++.h>
using namespace std;

int SumofUnique(int a[], int size) //返回数组前size个数中的不同数的个数。
{
    set<int> myset;

    for (int i = 0; i < size; i ++)
    {
        myset.insert(a[i]);
        //cout << a[i] << endl;
    }
    
    return myset.size();
}

int main() {

    int n, s;
    cin >> n >> s;

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    
    int ans = SumofUnique(a, s);
    cout << n - s + ans << endl;

    return 0;
}