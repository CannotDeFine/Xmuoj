/*
 * @Author: cdf
 * @Date: 2025-03-14 21:58:40
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 23:06:16
 * @Description: 树的重心
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;
 int h[N], e[N * 2], ne[N * 2];
 int visited[N];
 int idx = 0, ans = 0;

 void add(int v, int u)
 {
    e[idx] = u;
    ne[idx] = h[v]; // 插入到头结点后面
    h[v] = idx;     // 头插法插入结点
    idx++;
 }

 int main()
 {
    int n;
    cin >> n;

    memset(h, -1, sizeof(h));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;

        add (v, u);
        add (u, v);
    }

    dfs(1);
    cout << ans << endl;

    return 0;
 }
