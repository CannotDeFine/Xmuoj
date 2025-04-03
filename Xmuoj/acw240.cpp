/*
 * @Author: cdf
 * @Date: 2025-03-10 14:44:36
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 15:23:53
 * @Description: 并查集试炼之食物链
 */

 #include<bits/stdc++.h>
 using namespace std;

 const int N = 50010;

 int father[N];
 vector<vector<int>> eat(N);
 int son[N];

 int find (int num)  // 这只是一个查询的过程
 {
    if (father[num] == -1) return num;
    father[num] = find(father[num]);
    return father[num];
 }
 
 int main()
 {
    int n, k;
    cin >> n >> k;
    
    memset(son, 0, sizeof(son));
    memset(father, -1, sizeof(father));

    int ans = 0;
    while (k--)
    {
        int op;
        cin >> op;

        int x, y;
        cin >> x >> y;
        if (x > n || y > n) 
        {
            ans ++;
            continue;
        }

        if (op == 1)
        {
            if (x == y) continue;
            int fax = find(x);
            int fay = find(y);
            
            bool flag = true;
            for (auto elem : eat[fax])
            {
                if (elem == fay)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) {ans ++; continue;}
            
            for (auto elem : eat[fay])
            {
                if (elem == fax)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) {ans ++; continue;}

            if (son[fax] > son[fay]) swap(fax, fay);
            son[fay] += (son[fax] + 1);
            father[fax] = fay;
            son[fax] = 0;            
        }
        else
        {
            if (x == y)
            {
                ans++;
                continue;
            }

            int fax = find(x);
            int fay = find(y);

            if (fax == fay)
            {
                ans++;
                continue;
            }

            eat[fax].push_back(fay);
        }
    
    }

    cout << ans << endl;

    return 0;
 }