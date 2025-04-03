/*
 * @Author: cdf
 * @Date: 2025-02-28 16:42:56
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-28 21:31:05
 * @Description: 小辈分
 */

 // 如果直接采用 find 来构建树，注意：这样的做法是不能压缩路径的
 // 所以我们直接采用深度搜索，不用递归构建很深的树

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> store[100005], v;
int maxdai = -1;
// dfs from the ancestor
void dfs(int root, int dai)
{
    // if the beifen is the min beifen
    if (dai == maxdai)
    {
        v.push_back(root);
    }
    // if find a new min beifen
    if (dai > maxdai)
    {
        v.clear();
        maxdai = dai;
        v.push_back(root);
    }
    // check the kid to find whether they have kid or not
    for (int i = 0; i < store[root].size(); i++)
    {
        dfs(store[root][i], dai + 1);
    }
}

int main()
{
    int n, temp, ans;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp == -1)  // find the ancestor
        {
            ans = i;
        }
        else             // remember the kid of father with the temp number
        {
            store[temp].push_back(i);
        }
    }
    dfs(ans, 1);

    sort(v.begin(), v.end());
    // print the answer
    cout << maxdai << endl;
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        cout << " " << v[i];
    }

    return 0;
}
