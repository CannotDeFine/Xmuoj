/*
 * @Author: cdf
 * @Date: 2025-02-21 22:55:42
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-25 17:07:49
 * @Description: 矩阵 A 乘以 B
 */

 #include<bits/stdc++.h>
 using namespace std;

 int main() {
 
    int ra, ca;
    cin >> ra >> ca;

    int a[ra][ca];
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            cin >> a[i][j];
        }
    }

    int rb, cb;
    cin >> rb >> cb;
    int b[rb][cb];
    for (int i = 0; i < rb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            cin >> b[i][j];
        }
    }

    if (ca != rb)
    {
        cout << "Error:" << ca << "!=" << rb << endl;
        return 0;
    }

    int ans[ra][cb];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            for (int k = 0; k < ca; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << ra << ' ' << cb << endl;

    for (int i = 0; i < ra; i ++)
    {
        for (int j = 0; j < cb; j++)
        {
            if (j == cb - 1) cout << ans[i][j];
            else cout << ans[i][j] << ' ';

        }
        cout << endl;
    }
 
    return 0;
 }
