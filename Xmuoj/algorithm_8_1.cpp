/*
 * @Author: cdf
 * @Date: 2025-04-21 20:26:21
 * @LastEditors: cdf
 * @LastEditTime: 2025-04-21 21:23:22
 * @Description: 算法设计与分析_实验8_法水力量
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int num;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int max_idx =  i + 1;
        for (int j = i + 1; j < n; j++)
        {
            ans = max (ans, min(nums[i], nums[j]) * (j - i));
        }
    }

    cout << ans << endl;

    return 0;
}
