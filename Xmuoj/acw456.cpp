/*
 * @Author: cdf
 * @Date: 2025-03-11 10:32:01
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-11 11:00:29
 * @Description: 拓扑排序试炼之车站分级
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n, m;
    cin >> n >> m;

    vector<int> edge[n + 1];
    vector<int> d(n + 1);
    while (m--)
    {
        int num;
        cin >> num;
        
        int pre = 0;
        while (num--)
        {
            int point;
            cin >> point;

            if (pre == 0)
            {
                pre = point;
                continue;
            }
            edge[point].push_back(pre);
            d[pre]++;
        }
    }

    int depth =  0;
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            que.push(i);
        }
    }

    int now = que.size();
    int cnt = 0;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        
        // 表示该层的遍历结束了
        now --;
        
        for (int u : edge[temp])
        {
            d[u]--;
            if (d[u] == 0)
            {
                cnt++;
                que.push(u);
            }
        }

        if (now == 0)
        {
            depth++;
            now = cnt;
            cnt = 0;
        }
    }

    cout << depth << endl;

    return 0;

 }
