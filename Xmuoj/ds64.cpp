/*
 * @Author: cdf
 * @Date: 2025-03-05 13:23:26
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-05 14:05:03
 * @Description: 六度空间
 */
 
 // about bfs

#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
vector<int> adj[N]; // 邻接表存图
int n, m;

// BFS 计算 6 度以内的可达节点数量
void bfs(int start) {
    vector<bool> visited(n + 1, false);
    queue<int> que;

    que.push(start);
    visited[start] = true;
    int count = 1, depth = 0;

    que.push(-1); // -1 表示层结束
    while (!que.empty()) {
        int node = que.front();
        que.pop();

        if (node == -1) {
            depth++;
            if (que.empty() || depth >= 6) break;
            que.push(-1); // 标记新一层开始
            continue;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                count++;
                que.push(neighbor);
            }
        }
    }

    double percentage = (count * 100.0) / n;
    printf("%d: %.2lf%%\n", start, percentage);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    return 0;
}
