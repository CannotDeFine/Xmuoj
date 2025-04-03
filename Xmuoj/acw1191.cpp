/*
 * @Author: cdf
 * @Date: 2025-03-12 11:51:08
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 12:00:37
 * @Description: 拓扑排序试炼之家谱树
 */


 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<int> tree[n + 1];
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int num;
        while (cin >> num)
        {
            if (num == 0) break;
            else
            {
                tree[i].push_back(num);
                d[num]++;
            }
        }
    }

    queue<int> que;
    for (int i = 1; i <= n; i ++)
    {
        if (d[i] == 0) que.push(i);
    }

    vector<int> ans;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        ans.push_back(temp);

        for (int u : tree[temp])
        {
            d[u]--;
            if (d[u] == 0)
            {
                que.push(u);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0) cout << ' ';
        cout << ans[i];
    }

    return 0;
 }