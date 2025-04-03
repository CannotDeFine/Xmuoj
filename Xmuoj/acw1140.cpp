/*
 * @Author: cdf
 * @Date: 2025-03-12 21:48:36
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 22:16:15
 * @Description: 最小生成树试炼之最短网络
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int INF = 1e9;

 int prim(vector<vector<int>> &graph, int n)
 {
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);
    int ans = 0;

    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int min_dis = INF, u = -1;
        for (int j = 0; j < n; j++)         // find the min edge
        {
            if (visited[j] == 0 && min_dis > dist[j])
            {
                min_dis = dist[j];
                u = j;
            }
        }

        if (u == -1) return -1;
        ans += min_dis;
        visited[u] = 1;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && graph[u][j] < dist[j])
            {
                dist[j] = graph[u][j];
            }
        }
    }

    return ans;
 }

 int main()
 {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << prim(graph, n) << endl;

    return 0;
 }
