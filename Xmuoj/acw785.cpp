/*
 * @Author: cdf
 * @Date: 2025-03-14 09:56:47
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 10:18:11
 * @Description: 快速排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 int partition (vector<int> &nums, int left, int right)
 {
    int i = left - 1;
    int p = nums[right];

    for (int j = left; j < right; j++)
    {
        if (nums[j] < p)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap (nums[i + 1], nums[right]);

    return i + 1;
 }

 void quick_sort (vector<int> &nums, int left, int right)
 {
    if (left < right)
    {
        int p = partition (nums, left, right);
        quick_sort (nums, left, p - 1);
        quick_sort (nums, p + 1, right);
    }
 }

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    quick_sort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0) cout << ' ';
        cout << nums[i] ;
    }

    return 0;
 }
