/*
 * @Author: cdf
 * @Date: 2024-11-09 15:13:23
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-18 16:19:02
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;//邻接表存图, pair{顶点编号, 权值}, 用着方便一点
int n, y;
vector<int> minCost;

//遍历图以获取每个结点的路径最小权
//dp思想 : 结点v的minCost 等于 min (v的父结点的minCost, v的父结点到v这条边的权值)
//v为当前结点编号, last为上一个结点(用于避免重复遍历, 可以用visit数组替代), m为v的路径最小权值
int dfs(int v, int last, int m)
{
    minCost[v] = m;
    for(auto &i : g[v])
    {
        if(i.first == last) continue;
        dfs(i.first, v, min(m, i.second));//i.first结点的最小权值为min(m, weight(v --> i.first) )
    }
}

int main() {
    int T; cin >> T;
    while( T-- )
    {
        cin >> n >> y;
        g.resize(n);
        minCost.resize(n);

        for(int i=1; i<n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});//题中没有明确这条边是a->b还是b->a, 所以为了保险视为无向边
        }
        dfs(0, -1, 1e9);//由于根结点没有父结点, 所以最小权手动给一个极大值
        sort(minCost.begin(), minCost.end());

        if(n == y) cout << 0 << endl;//当n==y时不需要删除任何结点
        else cout << minCost[n-y-1] + 1 << endl;//+1的原因是X要严格大于权值才能删

        g.clear();
    }

    return 0;
}
