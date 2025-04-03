/*
 * @Author: cdf
 * @Date: 2025-02-17 15:41:41
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-17 15:49:33
 * @Description: 栈操作的合法性
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    int n, m;
    cin >> n >> m;

    while (n--)
    {
        string op;
        cin >> op;

        stack<int> sta;
        bool flag = true;
        for (char &ch : op)
        {
            if (ch == 'X')
            {
                if (!sta.empty()) sta.pop();
                else 
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (sta.size() < m) sta.push(1);
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && sta.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 
    return 0;
 }