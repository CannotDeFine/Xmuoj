/*
 * @Author: cdf
 * @Date: 2025-03-04 22:17:12
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-04 22:31:30
 * @Description: 路径判断
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 15;
 int n, m, sta, des;
 int graph[N][N], visited[N];

 bool dfs(int beg)
 {
    if (beg == des) return true;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[beg][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                if (dfs(i)) return true;
            }
        }
    }
    return false;
 }

 int main()
 {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;

        graph[r][c] = 1;
        graph[c][r] = 1;
    }

    cin >> sta >> des;
    visited[sta] = 1;
    if (dfs(sta)) cout << "There is a path between " << sta << " and " << des << ".";
    else cout << "There is no path between " << sta << " and " << des << ".";

    return 0;
 }
