/*
 * @Author: cdf
 * @Date: 2025-03-05 20:35:41
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-05 21:03:35
 * @Description: 任务调度的合理性
 */

 // 拓扑排序的判定
 // 依赖集合的判定是：该任务指向的任务

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;
    vector<int> in(n + 1, 0);
    vector<int> visited(n + 1, 0);
    vector<int> graph[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;

        while (m--)
        {
            int m;
            cin >> m;
            graph[i].push_back(m);  // 这边要理解依赖子集的定义
            in[m] ++;
        }
    }

    int cnt = 0;
    while (1)
    {
        int idx = -1;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0 && visited[i] == 0)
            {
                idx = i;
                break;
            }
        }
        if (idx == -1) break;

        cnt ++;
        visited[idx] = 1;
        for (int i = 0; i < graph[idx].size(); i++)
        {
            in[graph[idx][i]]--;
        }
        
    }

    if (cnt == n) cout << 1;
    else cout << 0;

    return 0;
 }
