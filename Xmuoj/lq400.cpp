/*
 * @Author: cdf
 * @Date: 2025-03-14 14:17:09
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 21:05:11
 * @Description: 选择排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 void print (vector<int> &nums, int now, int min_idx)
 {
    printf("swap(a[%d], a[%d]):", now, min_idx);
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0) cout << ' ';
        cout << nums[i];
    }
    cout << endl;
 }

 void select_sort (vector<int> &nums)
 {
    for (int i = 0; i < nums.size(); i++)
    {
        // find the index of the min element
        int min_idx = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min_idx]) min_idx = j;
        }
        swap(nums[min_idx], nums[i]);
        print (nums, i, min_idx);
    }
 }

 int main()
 {
    int n;
    cin >> n;

    // input
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    select_sort(nums);

    return 0;
 }
