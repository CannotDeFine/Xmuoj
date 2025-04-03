/*
 * @Author: cdf
 * @Date: 2025-02-27 14:41:23
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-27 15:18:19
 * @Description: 顺序存储的二叉树的最近的公共祖先问题
 */

 // 只需要检查刚开始是否是原来的结点
 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<int> tree(n + 1);
    for (int i = 1; i <= n; i++) cin >> tree[i];

    int ch1, ch2;
    cin >> ch1 >> ch2;
    if (tree[ch1] == 0) 
    {
        cout << "ERROR:T[" << ch1 << "] is NULL" << endl;
        return 0;
    }
    if (tree[ch2] == 0) 
    {
        cout << "ERROR:T[" << ch2 << "] is NULL" << endl;
        return 0;
    }

    while (1)
    {
        if (ch1 > ch2) 
        {
            ch1 = ch1 / 2;
            /*
            if (tree[ch1] == 0)
            {
                cout << "ERROR: T[" << ch1 << "] is NULL" << endl;
                return 0;
            }
            */
        }
        if (ch2 > ch1) 
        {
            ch2 = ch2 / 2;
            /*
            if (tree[ch2] == 0)
            {
                cout << "ERROR: T[" << ch2 << "] is NULL" << endl;
                return 0;
            }
            */
        }
        if (ch1 == ch2) break;
    }

    cout << ch1 << ' ' << tree[ch1] << endl;

    return 0;

 }