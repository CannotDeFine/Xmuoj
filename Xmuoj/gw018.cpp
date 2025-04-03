/*
 * @Author: cdf
 * @Date: 2024-11-07 20:27:14
 * @LastEditors: cdf
 * @LastEditTime: 2024-11-07 20:39:54
 * @Description: xmuoj_整数序列的最大跨度值
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    auto maxnum = max_element(nums.begin(), nums.end());
    auto minnum = min_element(nums.begin(), nums.end()); // 返回类型为指针
    cout << *maxnum - *minnum << endl ;

    return 0;
}