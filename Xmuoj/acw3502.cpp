/*
 * @Author: cdf
 * @Date: 2025-03-12 13:16:47
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 14:23:04
 * @Description: DFS试炼之不同路径数
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 const int N = 6;

 unordered_set<int> myset;
 vector<vector<int>> graph(N, vector<int>(N, 0));
 int n, m, k;
 int ans = 0;
 int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

 void dfs (int i, int j, int len, int num)
 {
    if (len == k + 1)
    {
        if (myset.empty() || myset.find(num) == myset.end()) // if we find the new number
        {
            ans++;
            myset.insert(num);
            //cout << num << endl;
        }
        return;
    }

    for (int i1 = 0; i1 < 4; i1++)
    {
        int tempi = i + dx[i1];
        int tempj = j + dy[i1];
        if (tempi < 0 || tempi >= n || tempj < 0 || tempj >= m) continue;
        dfs(tempi, tempj, len + 1, num * 10 + graph[tempi][tempj]);
    }
 }

 int main()
 {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(i, j, 0, 0);
        }
    }

    cout << ans << endl;

    return 0;
 }
