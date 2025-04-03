/*
 * @Author: cdf
 * @Date: 2024-11-08 16:51:29
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-08 17:05:18
 * @Description: xmuoj_图像模糊处理
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n,vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> nums[i][j];
    }

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> ans(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1) ans[i][j] = nums[i][j];
            else{
                int sum = nums[i][j];
                for (int k = 0; k < 4; k++) sum += nums[i + dx[k]][j + dy[k]];

                ans[i][j] = round(sum / (5 * 1.0));
            }
            
            if (j == m-1) cout << ans[i][j];    // 输出末尾空格处理
            else cout << ans[i][j] << ' ';  
        }
        cout << endl;
    }

    return 0;
}