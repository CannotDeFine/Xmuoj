/*
 * @Author: cdf
 * @Date: 2025-01-08 21:03:04
 * @LastEditors: cdf
 * @LastEditTime: 2025-01-08 21:20:18
 * @Description: 陶陶摘苹果
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
    }

    int height = nums[nums.size() - 1] + 30;
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] <= height)
            count++;
    }

    cout << count << endl;
    return 0;
}