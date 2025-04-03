/*
 * @Author: cdf
 * @Date: 2025-02-16 15:44:04
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-16 16:20:46
 * @Description: 彩虹瓶
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    int n, m, k;
    cin >> n >> m >> k;

    while (k--)
    {
        // 输入顺序
        vector<int> order;
        stack<int> shell;
        for (int i = 0; i < n; i ++)
        {
            int num;
            cin >> num;
            order.push_back(num);
        }

        int now = 1 ,i = 0;
        bool flag = true;
        while (now <= n && flag)
        {
            if (order[i] == now)
            {
                i++;
                now++;
            }
            else
            {
                if (shell.size() != 0 && shell.top() == now )
                {
                    shell.pop();
                    now ++;
                }
                else
                {
                    if (shell.size() < m)
                    {
                        shell.push(order[i]);
                        i++;
                    }
                    else
                    {
                        flag = false; 
                    }
                }

            }
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
 
    return 0;
 }