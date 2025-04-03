/*
 * @Author: cdf
 * @Date: 2025-03-05 14:09:56
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-05 15:13:08
 * @Description: 公路村村通 -- 最小生成树 prim 算法
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 1003;
 const int INF = 0x3f3f3f;
 int graph[N][N];
 int n, m;
 int visit[N], key[N];

 int prim()
 {
    fill(key, key + N, INF);
    fill(visit, visit + N, false);

    key[1] = 0;

    int totalcost = 0;
    for (int i = 1; i <= n; i++)
    {
        // to find the min_vex
        int u = -1, min_weight = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!visit[j] && key[j] < min_weight)
            {
                u = j;
                min_weight = key[j];
            }
        }

        // add the mincost to the totalcost
        if (u == -1) return -1;
        totalcost += min_weight;
        visit[u] = true;

        // relax
        for (int j = 1; j <= n; j++)
        {
            if (!visit[j] && key[j] > graph[u][j])
            {
                key[j] = graph[u][j];
            }
        }
    }

    return totalcost;
 }

 int main()
 {
    memset(graph, INF, sizeof(graph));

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int r, c, cost;
        cin >> r >> c >> cost;

        graph[r][c] = cost;
        graph[c][r] = cost;
    }

    int ans = prim();
    cout << ans;

    return 0;
 }
