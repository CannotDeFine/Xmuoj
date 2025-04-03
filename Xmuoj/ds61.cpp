/*
 * @Author: cdf
 * @Date: 2025-03-04 21:59:58
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-04 22:14:09
 * @Description: 图的深度优先遍历
 */

 // attention: 这是一个有向图

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 20010;
 vector<vector<int>> graph(N);
 int visit[N];
 int m, n;


 void dfs(int sta)
 {
    cout << sta << ' ';
    for (int i = 0; i < graph[sta].size(); i ++)
    {
        if (visit[graph[sta][i]] == 0)
        {
            visit[graph[sta][i]] = 1;
            dfs(graph[sta][i]);
        }
    }
 }

 void dfs_prepare()
 {
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            dfs(i);
        }
    }
 }

 int main()
 {
    cin >> n >> m;

    memset(visit, 0, sizeof(visit));

    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        graph[r].push_back(c);
    }

    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs_prepare();
    return 0;
    
 }