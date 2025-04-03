/*
 * @Author: cdf
 * @Date: 2025-03-10 14:11:18
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 14:41:22
 * @Description: 并查集试炼之连通块中点的数量
 */

 #include <bits/stdc++.h>
 using namespace std;

 const int N = 100010;

 int father[N];
 int son[N];

 int find (int num)
 {
    if (father[num] == -1) return num;
    father[num] = find(father[num]);
    return father[num];
 }
 
 int main()
 {
    int n, m;
    cin >> n >> m;

    memset(father, -1, sizeof(father));
    memset(son, 0, sizeof(son));

    while (m--)
    {
        string option;
        cin >> option;

        if (option == "C")
        {
            int node1, node2;
            cin >> node1 >> node2;

            int fa1 = find(node1);
            int fa2 = find(node2);
            if (fa1 != fa2) {
                if (son[fa1] > son[fa2]) swap(fa1, fa2); // 判断结点个数，小树合并到大树
                father[fa1] = fa2;
                son[fa2] += (son[fa1] + 1);
                son[fa1] = 0;
            }
        }
        else if (option == "Q1")
        {
            int node1, node2;
            cin >> node1 >> node2;
            if (node1 == node2)
            {
                cout << "Yes" << endl;
                continue;
            }

            int fa1 = find(node1);
            int fa2 = find(node2);
            if (fa1 == fa2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else
        {
            int node;
            cin >> node;

            int fa = find(node);
            cout << son[fa] + 1 << endl;
        }
    }

    return 0;
 }