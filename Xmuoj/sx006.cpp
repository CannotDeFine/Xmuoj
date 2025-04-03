/*
 * @Author: cdf
 * @Date: 2025-03-12 14:25:19
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 14:50:05
 * @Description:  DFS试炼之小猫爬山
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 20;
 int n, max_weight;
 vector<int> cats(N);
 vector<int> sum(N);

 int ans = N;

 void dfs (int u, int k)
 {
    // 剪枝：如果当前的数量已经大于当前找到的最小数量
    if (k >= ans) return;
    if (u == n)
    {
        ans = k;
        return;
    }

    // 搜索当前已经找到的缆车，看看能不能放下当前的小猫
    for (int i = 0; i < k; i++)
    {
        if (sum[i] + cats[u] <= max_weight) // 如果当前缆车能装下
        {
            sum[i] += cats[u];
            dfs(u + 1, k);
            sum[i] -= cats[u];  // 恢复现场
        }
    }

    // 下面考虑新加一辆缆车的情况
    sum[k] = cats[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;     // 恢复现场
 }

 int main()
 {
    cin >> n >> max_weight;

    // 输入小猫的重量并且从小到大排序
    for (int i = 0; i < n; i++) cin >> cats[i];
    sort(cats.begin(), cats.end(), greater<>());

    dfs(0, 0);

    cout << ans << endl;

    return 0;

 }
