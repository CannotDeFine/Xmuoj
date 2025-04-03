/*
 * @Author: cdf
 * @Date: 2025-03-13 21:52:34
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-13 23:11:25
 * @Description: BFS试炼之全球变暖
 */

 #include <bits/stdc++.h>
 using namespace std;
 
 int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
 
 // BFS 用于标记岛屿，并返回岛屿所有格子的坐标
 vector<pair<int, int>> bfs(vector<vector<char>> &graph, vector<vector<int>> &visited, int n, int v, int u) {
     queue<pair<int, int>> que;
     vector<pair<int, int>> island;
     que.push({v, u});
     visited[v][u] = 1;
     island.push_back({v, u});
 
     while (!que.empty()) {
         auto it = que.front();
         que.pop();
 
         for (int i = 0; i < 4; i++) {
             int tempv = it.first + dx[i];
             int tempu = it.second + dy[i];
 
             if (tempv < 0 || tempv >= n || tempu < 0 || tempu >= n) continue;
             if (visited[tempv][tempu] == 0 && graph[tempv][tempu] == '#') {
                 visited[tempv][tempu] = 1;
                 que.push({tempv, tempu});
                 island.push_back({tempv, tempu});
             }
         }
     }
     return island;
 }
 
 // 模拟全球变暖（淹没岛屿边缘）
 void drown(vector<vector<char>> &graph, int n) {
     vector<pair<int, int>> to_drown;
 
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (graph[i][j] == '#') {
                 bool flag = false;
                 for (int k = 0; k < 4; k++) {
                     int tempi = i + dx[k];
                     int tempj = j + dy[k];
                     if (tempi < 0 || tempi >= n || tempj < 0 || tempj >= n) continue;
                     if (graph[tempi][tempj] == '.') {
                         flag = true;
                         break;
                     }
                 }
                 if (flag) to_drown.push_back({i, j});
             }
         }
     }
 
     // 统一执行淹没操作
     for (auto p : to_drown) {
         graph[p.first][p.second] = '.';
     }
 }
 
 int main() {
     int n;
     cin >> n;
 
     vector<vector<char>> graph(n, vector<char>(n));
     vector<vector<int>> visit(n, vector<int>(n, 0));
     vector<vector<int>> visited(n, vector<int>(n, 0));
     vector<vector<int>> drowned_check(n, vector<int>(n, 0));
 
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             cin >> graph[i][j];
         }
     }
 
     vector<vector<pair<int, int>>> islands;
 
     // 找到所有岛屿，并存储它们的格子坐标
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             if (visit[i][j] == 0 && graph[i][j] == '#') {
                 islands.push_back(bfs(graph, visit, n, i, j));
             }
         }
     }
 
     // 进行淹没
     drown(graph, n);
 
     int drowned_islands = 0;
 
     // 检查哪些岛屿完全消失
     for (auto &island : islands) {
         bool completely_drowned = true;
         for (auto &cell : island) {
             if (graph[cell.first][cell.second] == '#') {
                 completely_drowned = false;
                 break;
             }
         }
         if (completely_drowned) drowned_islands++;
     }
 
     cout << drowned_islands << endl;
     return 0;
 }
 