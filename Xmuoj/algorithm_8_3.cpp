/*
 * @Author: cdf
 * @Date: 2025-04-22 10:34:10
 * @LastEditors: cdf
 * @LastEditTime: 2025-04-22 10:41:04
 * @Description: 传送能量2 -- 动态规划
 */

#include<bits/stdc++.h>
using namespace std;

const int INF = 0xffff;

int main() {

    vector<int> nums;
    int n;
    while (cin >> n) nums.push_back(n);

    vector<int> dp(nums.size(), INF);
    dp[0] = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if ((i - j) <= nums[j]) dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    cout << dp[nums.size() - 1] << endl;
    return 0;
}
