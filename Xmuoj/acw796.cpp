/*
 * @Author: cdf
 * @Date: 2025-03-12 17:26:23
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 19:56:07
 * @Description: 前缀和试炼之子矩阵的和
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            prefix[i + 1][j + 1] = graph[i][j] + prefix[i + 1][j];
        }
        
        for (int j = 0; j < m; j++)
        {
            prefix[i + 1][j + 1] += prefix[i][j + 1];
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << prefix[i][j] << ' ';
        }
        cout << endl;
    }


    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x1 - 1][y2] - prefix[x2][y1 -  1] << endl;
    }

    return 0;

 }
