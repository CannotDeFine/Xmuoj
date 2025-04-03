/*
 * @Author: cdf
 * @Date: 2025-02-17 14:37:53
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-17 15:39:58
 * @Description：求解迷宫从入口到出口的路径
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n;
vector<pair<int, int>> ans;     //  ans
vector<vector<int>> maze;       // 矩阵
vector<vector<bool>> visited;   // 访问数组

bool dfs(int i, int j) {
    if (i == n - 2 && j == n - 2) {
        ans.push_back({i, j});
        return true;
    }

    if (i < 0 || i >= n || j < 0 || j >= n) return false;

    if (maze[i][j] == 1 || visited[i][j]) return false;

    ans.push_back({i, j});
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        // 如果发现一条路径直接 return
        if (dfs(ni, nj)) { 
            return true;
        }
    }

    visited[i][j] = false;
    ans.pop_back();
    return false;
}

int main() {
    cin >> n;
    maze = vector<vector<int>>(n, vector<int>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    if (maze[1][1] != 0 || maze[n - 2][n - 2] != 0) {
        cout << "NO" << endl;
        return 0;
    }

    if (dfs(1, 1)) {
        for (auto p : ans) {
            cout << "(" << p.first << "," << p.second << ")";
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}