/*
 * @Author: cdf
 * @Date: 2025-01-19 21:11:10
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-19 21:16:08
 * @Description: 两数之和
 */

#include<bits/stdc++.h>
using namespace std;

int main() {

    int target,n;
    cin >> target >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int l = 0, r = n - 1;
    while (nums[l] + nums[r] != target && l < r)
    {
        int temp = nums[l] + nums[r];
        if (temp < target) l++;
        else r--;
    } 

    cout << l << ' ' << r << endl;
    return 0;
}