/*
 * @Author: cdf
 * @Date: 2025-03-10 22:44:16
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-11 09:47:32
 * @Description: 调整数组顺序使奇数位于偶数前面
 */

 // 双指针但是不是稳定的排序算法

 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {
    int n;
    vector<int> nums;
    int count = 0;
    while (cin >> n)
    {
        if (n % 2 == 1) count ++; 
        nums.push_back(n);
    }

    int i = 0;
    while (i < n)
    {
        // 找到第一个偶数
        while (i < n && nums[i] % 2 == 1) i++;

        // 找到偶数后面的第一个奇数
        int j = i + 1;
        while (j < n && nums[j] % 2 == 0)
        {
            j++;
        }

        if (j >= n) break;  // 没找到后面的奇数
        else 
        {
            // 奇数前移，偶数逐位后移
            int temp = nums[j];
            for (int k = j; k > i; k--)
            {
                nums[k] = nums[k - 1];
            }
            nums[i] = temp;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0) cout << nums[0];
        else cout << ", " << nums[i];
    }

    return 0;
 }