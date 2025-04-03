/*
 * @Author: cdf
 * @Date: 2025-03-06 16:27:27
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-06 16:39:13
 * @Description: 二分查找
 */

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n, num;
    cin >> n >> num;

    vector <int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == num) right = mid - 1;
        else if (nums[mid] < num) left = mid + 1;
        else right = mid - 1;
        
    }

    cout << left + 1 << endl;

    return 0;
 }