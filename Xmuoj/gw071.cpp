/*
 * @Author: cdf
 * @Date: 2025-02-27 16:44:46
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-27 22:26:42
 * @Description: 排列
 */

 #include <bits/stdc++.h>
 using namespace std;

 // 可以考虑存储上优化一下
 void dfs (vector<vector<int>> &ans,vector<int> &tmp,vector<int> &visit, int n)
 {
    if (tmp.size() == n)
    {
        ans.push_back(tmp);
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                visit[i] = 1;
                tmp.push_back(i);
                dfs(ans, tmp, visit, n);
                visit[i] = 0;
                tmp.pop_back();
            }
        }
    }
    return ;
 }

 int main()
 {
    int n;
    cin >> n;

    while (n--)
    {
        int m, k;
        cin >> m >> k;

        vector<int> rem(m);
        for (int i = 0; i < m; i++) cin >> rem[i];
        vector<vector<int>> ans;
        vector<int> tmp, visit(m + 1, 0);
        
        dfs(ans, tmp, visit, m);
        //cout << "end of get the all order !" << endl;

        int idx = -1;
        for (int i = 0; i < ans.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < ans[i].size(); j++)
            {
                if (ans[i][j] != rem[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag) 
            {
                idx = i;
                break;
            }
        }
        //cout << "end of find the order idx" << endl;
        k = k % ans.size();
        idx = (idx + k) % ans.size();

        for (int i = 0; i < ans[idx].size(); i++)
        {
            if (i == ans[idx].size() - 1) cout << ans[idx][i];
            else cout << ans[idx][i] << ' ';
        }
        cout << endl;
    }

    return 0;
 }