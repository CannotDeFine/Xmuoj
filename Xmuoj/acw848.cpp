/*
 * @Author: cdf
 * @Date: 2025-03-11 09:58:00
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-11 10:32:08
 * @Description: 拓扑排序试炼之有向图的拓扑序列
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 10010;

 int main()
 {
    int n, m;
    cin >> n >> m;

    //int graph[n][n];
    //memset(graph, 0, sizeof(graph));

    vector<int> d(n + 1, 0);
    vector<int> visited(n + 1, 0);
    vector<int> edge[n + 1];
    while (m--)
    {
        int v, u;
        cin >> v >> u;
        //if (u == v) continue;

        // 重边也没关系
        edge[v].push_back(u);
        d[u]++;
    }

    // 入度为 0 的结点入队列
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0) 
        {
            que.push(i);
            visited[i] = 1;
        }
    }

    vector<int> ans;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        ans.push_back(temp);

        for (int u : edge[temp])
        {
            d[u]--;
            if (visited[u] == 0 && d[u] == 0)
            {
                visited[u] = 1;
                que.push(u);
            }
        }
    }

    if (ans.size() != n) cout << -1 << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0) cout << ' ';
            cout << ans[i];
        }
    }

    return 0;
 }
