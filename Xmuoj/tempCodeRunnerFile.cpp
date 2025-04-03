/*
 * @Author: cdf
 * @Date: 2025-03-13 21:52:34
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-13 22:36:54
 * @Description: BFS试炼之全球变暖
 */

 #include <bits/stdc++.h>
 using namespace std;

 int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

 void bfs (vector<vector<char>> graph, vector<vector<int>> &visited, int n, int v, int u)
 {
    queue<pair<int, int>> que;
    que.push({v, u});
    visited[v][u] = 1;

    while (!que.empty())
    {
        auto it = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int tempv = it.first + dx[i];
            int tempu = it.second + dy[i];

            if (tempv < 0 || tempv >= n || tempu < 0 || tempu >= n) continue;
            if (visited[tempv][tempu] == 0 && graph[tempv][tempu] == '#')
            {
                visited[tempv][tempu] = 1;
                que.push({tempv, tempu});
            }
        }
    }

 }

 void drown (vector<vector<char>> &graph, int n)
 {
    vector<vector<char>> backup(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            backup[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == '#')
            {
                bool flag = false;
                for (int k = 0; k < 4; k++)
                {
                    int tempi = i + dx[k];
                    int tempj = j + dy[k];
                    if (tempi < 0 || tempi >= n || tempj < 0 || tempj >= n) continue;
                    if (backup[tempi][tempj] == '.')
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag) graph[i][j] = '.';
            }
        }
    }
 }

 int main()
 {
    int n;
    cin >> n;

    vector<vector<char>> graph(n, vector<char>(n));
    vector<vector<int>> visit(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // 先判断有多少个岛屿
    int pre_num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == 0 && graph[i][j] == '#')
            {
                bfs (graph, visit, n, i , j);
                pre_num ++;
            }
        }
    }
    cout << "pre_num :" << pre_num << endl;

    // 进行淹没
    drown(graph, n);

    // 再次判断岛屿的数量
    int after_num = 0;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0 && graph[i][j] == '#')
            {
                bfs (graph, visited, n, i, j);
                after_num ++;
            }
        }
    }
    cout << "after_num :" << after_num << endl;

    cout << pre_num - after_num << endl;
    

    return 0;

 }
