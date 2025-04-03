/*
 * @Author: cdf
 * @Date: 2025-02-28 20:26:33
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-28 21:03:45
 * @Description: 是否是完全二叉搜索树 —— 完全二叉树的递归创建
 */

 #include <bits/stdc++.h>
 using namespace std;

 // 数组一定要开得足够大，否则如果出现单调的数组可能出现越界的情况
 int a[1000000], n, maxnode, x;

 void CreateTree(int node)
 {
    maxnode = max(node, maxnode);
    if (a[node] == 0) // if the node don't have number
    {
        a[node] = x;
    }
    else            // if the node have number , we need to judge put it on the left or  right
    {
        if (x > a[node]) CreateTree(node * 2);
        else CreateTree(node * 2 + 1);
    }
 }

 void Print()
 {
    // cout << "Now we begin to print the ans!" << endl;
    cout << a[1];
    // 数组按照顺序输出就是层序遍历序列
    for (int i = 2; i <= maxnode; i++)
    {
        if (a[i] != 0) cout << ' ' << a[i];
    }

    // 如果最大下标和此时的结点数相等，说明是完全二叉树
    if (maxnode == n) cout << '\n' << "YES" ;
    else cout << '\n' << "NO";
 }

 int main ()
 {
    cin >> n;
    memset (a, 0,sizeof(a));
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        CreateTree(1);          // 每次都要插入一个结点
    }
    Print();

    return 0;
 }