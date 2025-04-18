/*
 * @Author: cdf
 * @Date: 2025-03-10 22:21:07
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-10 22:40:44
 * @Description: 三数之和
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                cout << nums[first] << ',' << nums[second] << ',' << nums[third] << endl;
                //ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }

    return 0;
 }
