/*
 * @Author: cdf
 * @Date: 2025-03-05 21:36:06
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-05 22:04:04
 * @Description: 最短工期
 */
 // 考察：拓扑排序 和 动态规划

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 110;
 int graph[N][N];
 int cost[N];

 int main()
 {
    int n, m;
    cin >> n >> m;
    vector<int> in(n, 0);

    memset(graph, -1, sizeof(graph));

    for (int i = 0; i < m; i++)
    {
        int sta, end, cost;
        cin >> sta >> end >> cost;

        graph[sta][end] = cost;
        in[end] ++;
    }

    int cnt = 0, ans = 0;
    while (1)
    {
        // find the index which number is zero
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                idx = i;
                in[i] = -1;
                break;
            }
        }
        // if we can't find the index;
        if (idx == -1) break;
        cnt ++;

        for (int i = 0; i < n; i++)
        {
            if (graph[idx][i] != -1)
            {
                in[i]--;
                // calculate the latest time we need judge all the time before the target
                // we need select the max time as the earlies time of the target
                cost[i] = max (cost[i], cost[idx] + graph[idx][i]); 
                ans = max (ans, cost[i]);
            }
        }

    }
    
    if (cnt != n ) cout << "Impossible" << endl;
    else cout << ans << endl;

    return 0;

 }