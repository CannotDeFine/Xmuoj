/*
 * @Author: cdf
 * @Date: 2025-03-10 11:18:57
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 13:42:37
 * @Description: Trie试炼之最大异或对
 */
 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;
 const int S = 31 * N;

 int son[S][2];
 int a[N];
 int n, idx;

 void insert(int num)
 {
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = num >> i & 1;
        if (!son[p][bit]) son[p][bit] = ++idx;
        p = son[p][bit];
    }
 }

 int findMaxXor(int num)
 {
    int res = 0;
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = num >> i & 1;
        if (son[p][!bit])
        {
            res = res * 2 + 1;
            p = son[p][!bit];
        }
        else
        {
            res = res * 2;
            p = son[p][bit];
        }
    }

    return res;
 }

 int main()
 {
    cin >> n;
    idx = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        insert(a[i]);
        ans = max(ans, findMaxXor(a[i]));
    }
    
    cout << ans << endl;

    return 0;
 }
