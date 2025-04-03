/*
 * @Author: cdf
 * @Date: 2025-01-19 21:25:21
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 22:20:04
 * @Description: 三数之和
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tar = 0, n;
    cin >> n;

    vector<int> nums(n);
    vector<int> remain_sum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        remain_sum[i] = tar - nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > tar) break;

        int l = i + 1, r = n - 1;
        int target = remain_sum[i];

        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                cout << nums[i] << ' ' << nums[l] << ' ' << nums[r] << endl;
                r--;
                l++;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r -  1]) r--;
            } 
            else if (nums[l] + nums[r] > target) r--;
            else l ++;
        }
    }
    return 0;
}