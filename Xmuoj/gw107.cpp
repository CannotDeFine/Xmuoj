/*
 * @Author: cdf
 * @Date: 2025-04-18 23:08:20
 * @LastEditors: cdf
 * @LastEditTime: 2025-04-18 23:14:00
 * @Description: 输出前面 K 大的数字
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int num;
    priority_queue<int,vector<int>> que;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        que.push(num);
    }

    int k;
    cin >> k;
    while (k--)
    {
        cout << que.top() << endl;
        que.pop();
    }
    

    return 0;
}
