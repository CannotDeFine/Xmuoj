/*
 * @Author: cdf
 * @Date: 2025-03-14 10:30:09
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-14 10:55:24
 * @Description: 归并排序
 */

 #include <bits/stdc++.h>
 using namespace std;

 void merge (vector<int> &nums, int left, int mid, int right)
 {
    int i = left, j = mid, k = 0;

    vector<int> temp(right - left + 1);
    while (i < mid && j <= right)
    {
        if (nums[i] < nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++]; 
    }

    while (i < mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    for (int i = 0, j = left; j <= right; j++, i++) nums[j] = temp[i];

 }

 void merge_sort(vector<int> &nums, int left, int right)
 {
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort (nums, left, mid);
        merge_sort (nums, mid + 1, right);
        merge (nums, left, mid + 1, right);
    }
 }

 int main()
 {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    merge_sort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        if (i != 0) cout << ' ';
        cout << nums[i];
    }

    return 0;
 }
