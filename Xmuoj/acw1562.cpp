/*
 * @Author: cdf
 * @Date: 2025-03-13 21:06:29
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-13 21:50:22
 * @Description: BFS试炼之微博转发
 */

 #include <bits/stdc++.h>
 using namespace std;

 int bfs(vector<vector<int>> &follow, int n, int f, int l)
 {
    vector<int> visited(n + 1, 0);
    queue<int> que;
    que.push(f);
    visited[f] = 1;

    int ans = 0, depth = 0, cnt = 0, now = 1;

    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        now--;

        for (int i = 0; i < follow[temp].size(); i++)
        {
            if (visited[follow[temp][i]] == 0)
            {
                visited[follow[temp][i]] = 1;
                que.push(follow[temp][i]);
                cnt++;
            }
        }

        if (now == 0)
        {
            depth++;
            if (depth == l) return cnt + ans;

            ans += cnt;
            now = cnt;
            cnt = 0;
        }
        
    }

    return ans;

 }

 int main()
 {
    int n, l;
    cin >> n >> l;

    vector<vector<int>> follow(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        while (num--)
        {
            int fo;
            cin >> fo;
            follow[fo].push_back(i);
        }
    }

    int q;
    cin >> q;
    while (q --)
    {
        int f;
        cin >> f;

        cout << bfs(follow, n, f, l) << endl;
    }

    return 0;
 }
