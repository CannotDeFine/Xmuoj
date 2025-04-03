/*
 * @Author: cdf
 * @Date: 2025-01-07 20:37:46
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-07 20:47:42
 * @Description: 单调栈
 */

// 解决找出左边第一个比当前数字小的问题

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];

    stack<int> sta;
    for (int i = 0; i < n; i++) {
        if (sta.empty()) cout << -1 << ' ';
        else {
            while (!sta.empty() && sta.top() >= nums[i]) {
                sta.pop();
            }

            if (sta.empty()) cout << -1 << ' ';
            else cout << sta.top() << ' ';
        }

        sta.push(nums[i]);
    }

    return 0;
}