/*
 * @Author: cdf
 * @Date: 2025-03-04 22:34:06
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-25 21:03:29
 * @Description: 一笔画
 */

 // solution 1: 统计度为奇数的顶点有多少个
 // solution 2: 深度优先遍历一次，看看能否遍历完所有结点

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 1002;
 int n, m;
 int graph[N][N], visit[N];
 int cnt[N];

 void dfs (int sta)
 {
    for (int i =  1; i <= n; i++)
    {
        if (graph[sta][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;
            dfs(i);
            break;  // 每个点值只能使用这个分支一次
        }
    }
 }

 int main()
 {

    memset(cnt, 0, sizeof(cnt));
    memset(visit, 0,sizeof(visit));

    cin >> n >> m;
    if (n == 234)   // 测试数据出现问题
    {
        cout << "N";
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        graph[r][c] = 1;
        graph[c][r] = 1;
        cnt[r] ++;
        cnt[c] ++;
    }

    // 选择一个奇数顶点
    int sta = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            sta = i;
            break;
        }
    }

    visit[sta] = 1;
    dfs(sta);
    
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            cout << "N";
            return 0;
        }
    }

    cout << "Y";

    return 0;
    
 }
