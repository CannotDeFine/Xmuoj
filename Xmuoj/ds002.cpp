/*
 * @Author: cdf
 * @Date: 2025-02-20 22:38:41
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-20 23:38:11
 * @Description: 火车进出站
 */

 #include<bits/stdc++.h>
 using namespace std;
 const int N = 21;
 
 int n;
 int visit[N];
 vector<int> ans;
 int countnum = 0;

 // 判断是否合法
 bool can_stack()
 {
    int now = 1;
    int i = 0;

    stack<int> sta;

    while (now <= n)
    {
        if (now == ans[i])
        {
            now ++;
            i ++;
        }
        else if (!sta.empty() && sta.top() == ans[i])
        {
            i++;
            sta.pop();
        }
        else
        {
            sta.push(now);
            now ++; 
        }
    }

    while (!sta.empty())
    {
        if (ans[i] != sta.top())
        {
            return false;
        }
        i++;
        sta.pop();
    }

    return true;
 }

 // 生成字典序列
 void BackTracing()
 {
    if (ans.size() == n)
    {
        if (can_stack() && countnum < 20)  // 注意次数限制
        {
            countnum ++;
            for (int i = 0; i < n; i++)
            {
                cout << ans[i];
            }
            cout << endl;
        }
        return; 
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == 0)
            {
                ans.push_back(i);
                visit[i] = 1;
                BackTracing();
                if (countnum >= 20) return;
                visit[i] = 0;
                ans.pop_back();
            }
        }
    }
 }

 int main() {

    cin >> n;
    memset(visit, 0, sizeof(int) * N);
    BackTracing();
 
    return 0;
 }
