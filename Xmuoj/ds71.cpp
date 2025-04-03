#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAXN = 500;
int dist[MAXN][MAXN], cost[MAXN][MAXN];  // 存储距离和费用
int d[MAXN], c[MAXN];                    // 记录最短距离和最小费用
bool visited[MAXN];                       // 访问标记
int n, m, s, dTarget;                     // 城市数、高速公路数、起点、终点

void dijkstra(int s) {
    fill(d, d + n, INF);
    fill(c, c + n, INF);
    fill(visited, visited + n, false);
    d[s] = 0;
    c[s] = 0;

    for (int i = 0; i < n; i++) {  // 迭代 n 次
        int u = -1, minDist = INF;

        // 找到当前未访问节点中 d[] 最小的节点
        for (int j = 0; j < n; j++) {
            if (!visited[j] && d[j] < minDist) {
                u = j;
                minDist = d[j];
            }
        }

        if (u == -1) return;  // 所有点都访问完了
        visited[u] = true;

        // 更新所有邻接点
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u][v] != INF) {
                int newDist = d[u] + dist[u][v];
                int newCost = c[u] + cost[u][v];

                if (newDist < d[v]) {  // 发现更短路径
                    d[v] = newDist;
                    c[v] = newCost;
                } else if (newDist == d[v] && newCost < c[v]) {  // 路径长度相同但费用更低
                    c[v] = newCost;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> dTarget;

    // 初始化邻接矩阵
    fill(&dist[0][0], &dist[0][0] + MAXN * MAXN, INF);
    fill(&cost[0][0], &cost[0][0] + MAXN * MAXN, INF);

    for (int i = 0; i < m; i++) {
        int u, v, length, toll;
        cin >> u >> v >> length >> toll;
        dist[u][v] = dist[v][u] = length;
        cost[u][v] = cost[v][u] = toll;
    }

    dijkstra(s);
    cout << d[dTarget] << " " << c[dTarget] << endl;

    return 0;
}
