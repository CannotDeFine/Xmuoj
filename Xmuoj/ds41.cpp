/*
 * @Author: cdf
 * @Date: 2025-02-27 11:23:42
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-27 14:34:28
 * @Description: 列出叶结点
 */

 #include<bits/stdc++.h>
 using namespace std;

 struct node
 {
    int left;
    int right;
 };


 int main()
 {
    int n;
    cin >> n;

    // solve the input and help find the root of the tree
    node t[n];
    vector<int> visit(n, 0);
    for (int i = 0; i < n; i++)
    {
        char l, r;
        cin >> l >> r;

        if (l == '-') t[i].left = -1;
        else 
        {
            t[i].left = l - '0';
            visit[t[i].left] = 1;
        }

        if (r == '-') t[i].right = -1;
        else 
        {
            t[i].right = r - '0';
            visit[t[i].right] = 1;
        }
    }

    // find the root of tree
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0) root = i;
    }

    queue<int> que;
    que.push(root);
    vector<int> ans;
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();

        if (t[tmp].left == -1 && t[tmp].right == -1) ans.push_back(tmp);
        if (t[tmp].left != -1) que.push(t[tmp].left);
        if (t[tmp].right != -1) que.push(t[tmp].right);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1) cout << ans[i];
        else cout << ans[i] << ' ';
    }

    return 0;
 }