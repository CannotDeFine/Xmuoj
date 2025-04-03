/*
 * @Author: cdf
 * @Date: 2025-03-05 22:05:23
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-06 16:45:33
 * @Description: 哈利波特的魔咒
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int INF = 1e9;
int graph[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    // 正确初始化邻接矩阵
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    // 读入变形魔咒数据
    for (int i = 0; i < m; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from][to] = len;
        graph[to][from] = len;
    }

    // Floyd-Warshall 算法
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] < INF && graph[k][j] < INF) // 防止溢出
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    // 找最优动物
    int ans = INF, ans_idx = -1;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            temp = max(temp, graph[i][j]); // 计算最远的距离
        }

        if (temp < ans)
        {
            ans = temp;
            ans_idx = i;
        }
    }

    if (ans == INF) cout << "0\n"; // 说明有不可达的点
    else cout << ans_idx << " " << ans << endl;

    return 0;
}
