/*
 * @Author: cdf
 * @Date: 2025-03-12 15:48:00
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-12 16:36:23
 * @Description: DFS试炼之n皇后问题
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 13;

 vector<vector<char>> queen(N, vector<char>(N, '.'));
 //vector<int> row(N, 0);
 vector<int> col(N, 0);
 int n, ans = 0;

 bool check (int r, int c)
 {
    int tr = r, tc = c;
    while (tc >= 0 && tr >= 0)
    {
        if (queen[tr][tc] == 'Q') return false;
        tc--;
        tr--;
    }

    tr = r, tc = c;
    while (tc < n && tr < n)
    {
        if (queen[tr][tc] == 'Q') return false;
        tc++;
        tr++;
    }

    tr = r, tc = c;
    while (tc >=0 && tr < n)
    {
        if (queen[tr][tc] == 'Q') return false;
        tc--;
        tr++;
    }

    tr = r, tc = c;
    while (tc < n && tr >= 0)
    {
        if (queen[tr][tc] == 'Q') return false;
        tr--;
        tc++;
    }

    return true;
 }

 void dfs(int cnt)
 {
    if (cnt == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << queen[i][j];
            }
            cout << endl;
        }
        cout << endl;
        ans++;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (col[i] == 0 && check(cnt ,i))  // 先判断前面两个条件
        {
            col[i] = 1;
            queen[cnt][i] = 'Q';
            dfs(cnt + 1);

            col[i] = 0;
            queen[cnt][i] = '.';
        }
    }
 }

 int main()
 {
    cin >> n;

    dfs(0);

    //cout << ans << endl;

    return 0;
 }