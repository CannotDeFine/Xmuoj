/*
 * @Author: cdf
 * @Date: 2025-03-04 21:05:14
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-04 21:58:14
 * @Description: 列出列出连通集
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 15;
 int graph[N][N], n, m;
 int visit[N];

 vector<vector<int>> ans_dfs;
 vector<vector<int>> ans_bfs;
 vector<int> ans_temp;

 void dfs(int sta)
 {
    for (int i = 0; i < n; i ++)
    {
        if (graph[sta][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;
            ans_temp.push_back(i);
            dfs(i);
        }
    }
 }

 void dfs_prepare()
 {
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            ans_temp.push_back(i);
            dfs(i);

            ans_dfs.push_back(ans_temp);
            ans_temp.clear();
        }
    }

 }

 void dfs_print()
 {
    for (int i = 0; i < ans_dfs.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans_dfs[i].size(); j++)
        {
            if (j == ans_dfs[i].size() - 1) cout << ans_dfs[i][j];
            else cout << ans_dfs[i][j] << ' ';
        }
        cout << "}" << endl;
    }
 }


 void bfs(int sta)
 {
    queue<int> que;
    que.push(sta); 

    while (!que.empty())
    {
        int temp = que.front();
        que.pop();

        for (int i = 0; i < n; i++)
        {
            if (graph[temp][i] == 1 && visit[i] == 0)
            {
                visit[i] = 1;
                ans_temp.push_back(i);
                que.push(i);
            }
        }
        
    }
 }

 void bfs_prepare()
 {
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            ans_temp.push_back(i);
            bfs(i);

            ans_bfs.push_back(ans_temp);
            ans_temp.clear();
        }
    }
 }

 void bfs_print()
 {
    for (int i = 0; i < ans_bfs.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans_bfs[i].size(); j++)
        {
            if (j == ans_bfs[i].size() - 1) cout << ans_bfs[i][j];
            else cout << ans_bfs[i][j] << ' ';
        }
        cout << "}" << endl;
    }
 }

 int main()
 {
    // input the row and col of the graph
    cin >> n >> m;

    memset(graph, 0, sizeof(graph));
    memset(visit, 0, sizeof(visit));

    // initial the graph
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        graph[r][c] = 1;
        graph[c][r] = 1;
    }

    dfs_prepare();
    dfs_print();
    
    memset(visit, 0, sizeof(visit));

    bfs_prepare();
    bfs_print();

    return 0;

 }