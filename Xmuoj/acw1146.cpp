/*
 * @Author: cdf
 * @Date: 2025-03-12 22:29:09
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 23:01:53
 * @Description: 新的开始 --prim算法
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int INF = 1e9;

 int prim(vector<vector<int>> &graph, int n)
 {
    vector<int> visited(n + 1, 0);
    vector<int> dis(n + 1, INF);

    int ans = 0;
    dis[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        int minDis = INF, u = -1;
        for (int j = 0; j <= n; j++)
        {
            if (visited[j] == 0 && dis[j] < minDis)
            {
                minDis = dis[j];
                u = j;
            }
        }

        if (u == -1) return -1;
        ans += minDis;
        visited[u] = 1;

        for (int j = 0; j <= n; j++)
        {
            dis[j] = min(dis[j], graph[u][j]);
        }
    }

    return ans;
 }

 int main()
 {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> graph[0][i];
        graph[i][0] = graph[0][i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j]; 
        }
    }

    cout << prim(graph, n) << endl;

    return 0;
 }
